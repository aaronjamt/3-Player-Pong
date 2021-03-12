#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <psxgpu.h>
#include <psxpad.h>
#include <psxsio.h>
#include <psxetc.h>
#include <psxgte.h>
#include <psxapi.h>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_CENTER_X SCREEN_WIDTH/2
#define SCREEN_CENTER_Y SCREEN_HEIGHT/2

typedef struct {
	int x,y;
} Vector2;

/* Pad input buffer*/
char padbuff[2][34];

unsigned char game_start_delay = 100;

#define SIO_BUFFER 128

static volatile char SIO_CMD = 0;
static volatile char SIO_CMD_PARAM[SIO_BUFFER];
static volatile char SIO_CMD_PARAM_IDX = 0;

// Define display/draw environments for double buffering
DISPENV disp[2];
DRAWENV draw[2];
int db;

/* Once a command has been fully handled, call this to reset vars. */
void clearCmd() {
	SIO_CMD = 0;
	memset(&SIO_CMD_PARAM[0], 0, sizeof(SIO_CMD_PARAM));
	SIO_CMD_PARAM_IDX = 0;
}

void addCmdByte(char byte) {
	if (SIO_CMD == 0) {
		SIO_CMD = byte;
	} else if (SIO_CMD_PARAM_IDX < SIO_BUFFER) {
		SIO_CMD_PARAM[SIO_CMD_PARAM_IDX] = byte;
		SIO_CMD_PARAM_IDX++;
	}
}

void checkCmd() {
    unsigned char cmd = SIO_CMD & 0xFF;
	switch (cmd) {
		case 0x1B: // ASCII ESC (escape)
		case 'q':
		case 'Q':
			__asm__("j 0x801ecd94");
			break;
		case 0xff:
			break;
		default:
			printf("Unknown cmd: 0x%02hhx\n", cmd);
			break;
	}
	clearCmd(); // Clear the current command. If the command requires more data,
				// return sooner. If we get here, we assume the data has been fully processed.
}

void _sioCallback() {
	unsigned char read = _sio_control(0, 4, 0);
	_sio_control(2, 1, 0);
	addCmdByte(read);
	checkCmd();
}

//////////////////////////////////////////////////////////////
// Random Number Generator                                  //
// -------------------------------------------------------- //
// returns a random number that does                        //
// not exceed the maximum parsed value                      //
// -------------------------------------------------------- //
// EG: Random(5) will return either 0,1,2,3 or 4            //
//////////////////////////////////////////////////////////////
int Random(int max)
{
	srand(GetRCnt(0)); // initialise the random seed generator
	return(rand()%max); // return a random number based off of max
}

void TurnOnAnalog(void)
{
	EnterCriticalSection();

	// Enter configuration mode
	_PadSetPort(0);

	if( _PadExchng(0x01) & 0x100 )
	{
		ExitCriticalSection();
		return;
	}

	if( _PadExchng(0x43) & 0x100 )
	{
		ExitCriticalSection();
		return;
	}

	_PadExchng(0x00);
	_PadExchng(0x01);

	while( !(_PadExchng(0) & 0x100) );

	_PadSetPort(2);

	ExitCriticalSection();
	VSync(0);
	EnterCriticalSection();

	// Set analog state
	_PadSetPort(0);

	_PadExchng(0x01);
	_PadExchng(0x44);
	_PadExchng(0x00);
	_PadExchng(0x01);	// 0 - analog off, 1 - analog on
	_PadExchng(0x02);

	while( !(_PadExchng(0) & 0x100) );

	_PadSetPort(2);

	ExitCriticalSection();
	VSync(0);
	EnterCriticalSection();

	// Exit configuration mode
	_PadSetPort(0);

	_PadExchng(0x01);
	_PadExchng(0x43);
	_PadExchng(0x00);
	_PadExchng(0x00);

	while( !(_PadExchng(0) & 0x100) );

	_PadSetPort(2);

	ExitCriticalSection();
	VSync(0);
}

// Init function
void init(void)
{
	// This not only resets the GPU but it also installs the library's
	// ISR subsystem to the kernel
	ResetGraph(0);

	/* Initialize Serial I/O */
	AddSIO(115200);
	Sio1Callback(_sioCallback);

	// Define display environments, first on top and second on bottom
	SetDefDispEnv(&disp[0], 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SetDefDispEnv(&disp[1], 0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Define drawing environments, first on bottom and second on top
	SetDefDrawEnv(&draw[0], 0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT);
	SetDefDrawEnv(&draw[1], 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set and enable clear color
	setRGB0(&draw[0], 0, 96, 0);
	setRGB0(&draw[1], 0, 96, 0);
	draw[0].isbg = 1;
	draw[1].isbg = 1;

	// Clear double buffer counter
	db = 0;

	// Apply the GPU environments
	PutDispEnv(&disp[db]);
	PutDrawEnv(&draw[db]);

	// Load test font
	FntLoad(960, 0);

	FntOpen(0, 8, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 128);

	/* Initialize Pads (Controllers) */
	InitPAD(padbuff[0], 34, padbuff[1], 34);
	StartPAD();
	ChangeClearPAD(0);

	TurnOnAnalog();
}

#define PADDLE_SPEED 2
#define PADDLE_WIDTH 8
#define PADDLE_HEIGHT 32
#define PADDLE_OFFSET 16
Vector2 paddle_left = {.x = PADDLE_OFFSET, .y = SCREEN_CENTER_Y};
Vector2 paddle_right = {.x = SCREEN_WIDTH - PADDLE_OFFSET, .y = SCREEN_CENTER_Y};

#define BALL_DIAMETER 16
#define BALL_RADIUS (BALL_DIAMETER/2)

TILE tile;

unsigned short ball_x = SCREEN_CENTER_X;
unsigned short ball_y = SCREEN_CENTER_Y;
signed char ball_accel_x = 0;
signed char ball_accel_y = 0;
signed char lastScore = -1;

unsigned short energy, score1, score2 = 0;

void score(signed char side) {
	ball_x = SCREEN_CENTER_X;
	ball_y = SCREEN_CENTER_Y;
	ball_accel_x = 0;
	ball_accel_y = 0;
	paddle_left.y = SCREEN_CENTER_Y;
	paddle_right.y = SCREEN_CENTER_Y;
	lastScore = side;
	if (side < 0) {
		score1++;
	} else if (side > 0) {
		score2++;
	}
	game_start_delay = 100;

	// Update score on calculator
	printf("\x02%c%c\x03%c%c", score1 >> 8, score1 & 0xff, score2 >> 8, score2 & 0xff);
}

void moveBall() {
	if (game_start_delay > 0) return;
	if (ball_accel_x == 0) {
		ball_accel_x = -lastScore;
	}
	if (ball_accel_y == 0) {
		ball_accel_y = 1;
	}

	ball_x += ball_accel_x;
	ball_y += ball_accel_y;

	if (ball_x < (PADDLE_OFFSET + (PADDLE_WIDTH/2) + BALL_RADIUS)
	&& (ball_y < (paddle_left.y+PADDLE_HEIGHT)) && (ball_y > (paddle_left.y-PADDLE_HEIGHT))) {
		ball_accel_x = abs(ball_accel_x) + 1; // Makes acceleration positive and faster
	}

	if (ball_x > (SCREEN_WIDTH - PADDLE_OFFSET - (PADDLE_WIDTH/2) - BALL_RADIUS)
	&& (ball_y < (paddle_right.y+PADDLE_HEIGHT)) && (ball_y > (paddle_right.y-PADDLE_HEIGHT))) {
		ball_accel_x = -abs(ball_accel_x) - 1; // Makes acceleration negative and faster
	}

	if (ball_x < 0 + BALL_RADIUS) {
		// Right scores a point
		score(1);
	} else if (ball_x > SCREEN_WIDTH - BALL_RADIUS) {
		// Left scores a point
		score(-1);
	}

	/*if (ball_x > SCREEN_WIDTH - BALL_DIAMETER) {
		ball_accel_x = -abs(ball_accel_x);
	} else if (ball_x < 0 + BALL_DIAMETER) {
		ball_accel_x = abs(ball_accel_x);
	}*/

	if (ball_y > SCREEN_HEIGHT - BALL_RADIUS) {
		ball_accel_y = -abs(ball_accel_y);
	} else if (ball_y < 0 + BALL_RADIUS) {
		ball_accel_y = abs(ball_accel_y);
	}
}

void movePaddle(Vector2* paddle, PADTYPE* pad) {
	if (game_start_delay > 0) return;
	signed char move = 0;
	if (pad->type == 7) {
		signed char analog_y = (pad->ls_y)-128;
		if (abs(analog_y) < 24) analog_y = 0;
		move = analog_y / 16;
	} else {
		if ((~(pad->btn)) & PAD_UP) {
			move = -4;
		} else if ((~(pad->btn)) & PAD_DOWN) {
			move = 4;
		}
	}
	paddle->y += move;
	if (paddle->y < PADDLE_HEIGHT) {
		paddle->y = PADDLE_HEIGHT;
	} else if (paddle->y > SCREEN_HEIGHT-PADDLE_HEIGHT) {
		paddle->y = SCREEN_HEIGHT-PADDLE_HEIGHT;
	}
	FntPrint(-1, "MOVE=%d\n", move);
}

// Display function
void display()
{
	setTile(&tile);

	setWH(&tile, BALL_DIAMETER, BALL_DIAMETER);
	setXY0(&tile, ball_x - BALL_RADIUS, ball_y - BALL_RADIUS);
	setRGB0(&tile, 255, 255, 255);
	DrawPrim(&tile);

	setWH(&tile, PADDLE_WIDTH, PADDLE_HEIGHT);
	setXY0(&tile, PADDLE_WIDTH/2, paddle_left.y - (PADDLE_HEIGHT/2));
	setRGB0(&tile, 0, 0, 0);
	DrawPrim(&tile);

	setWH(&tile, PADDLE_WIDTH, PADDLE_HEIGHT);
	setXY0(&tile, SCREEN_WIDTH - (PADDLE_WIDTH/2), paddle_right.y - (PADDLE_HEIGHT/2));
	setRGB0(&tile, 0, 0, 0);
	DrawPrim(&tile);

	// Draw the last created text stream
	FntFlush(-1);

	// Flip buffer index
	db = !db;

	// Wait for all drawing to complete
	DrawSync(0);

	// Wait for vertical sync to cap the logic to 60fps (or 50 in PAL mode)
	// and prevent screen tearing
	VSync(0);

	// Switch pages
	PutDispEnv(&disp[db]);
	PutDrawEnv(&draw[db]);

	// Enable display output, ResetGraph() disables it by default
	SetDispMask(1);

}

int main(int argc, const char *argv[])
{
	init();

	unsigned int init_cooldown = 50; // Cooldown before processing controller input
	unsigned short btn = 0;
	unsigned short lastBtn = 0;
	PADTYPE* pad;

	unsigned int counter = 0;
	unsigned short energy_counter = 0;

	while (true) {
/*
		if (init_cooldown == 0) {
			lastBtn = btn;
			pad = ((PADTYPE*)padbuff[0]);
			btn = ~pad->btn;
		}
*/
		if (game_start_delay == 0 && energy_counter >= 50) {
			energy++;
			energy_counter = 0;
			printf("\x01%c%c", energy >> 8, energy & 0xff);
		}
		energy_counter++;
		// Screen is 40 characters wide (320 pixels wide, 8 pixels per character)
		// 40 wide - left score(5) - right score(5) = 30
		// can't center 5-digits in 30, so add $ to make it 6
		// center 6 = (30/2)-(6/2) = 15-3 = 12
		FntPrint(-1, "%05d           $%05d           %05d\n", score1, energy, score2);
		/*FntPrint(-1, "\n");
		FntPrint(-1, "1234567890123456789012345678901234567890\n");
		FntPrint(-1, "\n");
		FntPrint(-1, "ENERGY=%d\n", energy);*/
		FntPrint(-1, "\n");
		FntPrint(-1, "COUNTER=%d\n", counter);
		counter++;

		// Update display
		movePaddle(&paddle_left, (PADTYPE*)padbuff[0]);
		movePaddle(&paddle_right, (PADTYPE*)padbuff[1]);
		moveBall();
		display();

		if (init_cooldown) init_cooldown--;
		if (game_start_delay) game_start_delay--;
	}

	return 0;
}
