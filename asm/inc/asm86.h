;==================================================================
;These lines are used to 'fix' TI's include files to work with TASM
;==================================================================
#DEFINE equ 							=
#DEFINE EQU 							=
#DEFINE 0FCH							0FCh
#DEFINE 0D4H							0D4h
#DEFINE 0E8H    						0E8h
#DEFINE 0C0H							0C0h

;====================================================================
;These are common zshell and usgard calls that are known on the TI-86
;If possible, use the call that is commented next to the one you want
;====================================================================
MUL_HL = $4547

CP_HL_DE = $403C
LD_HL_MHL = $4010
GET_KEY = $5371
UNPACK_HL = $4044

D_HL_DECI = $4a33

BUSY_OFF = $4ab1			;_runindoff
BUSY_ON = $4aad				;_runindicon
D_ZT_STR = $4a37			;_puts
D_LT_STR = $4a3b			;_putps
TX_CHARPUT = $4a2b			;_putc
D_ZM_STR = $4aa5			;_vputs
D_LM_STR = $4aa9			;_vputsn
M_CHARPUT = $4aa1			;_vputmap
CLEARLCD = $4a7e			;_clrLCD


;========================================================
;These are memory addresses common for zshell programming
;If possible, use the one on the right
;========================================================

CONTRAST = $c008			
CURSOR_ROW = $c00f			;_curRow
CURSOR_COL = $c010			;_curCol
BUSY_COUNTER = $c087 
BUSY_BITMAP	= $c088
TEXT_MEM = $c0f9			;_textShadow
CURSOR_X = $c37c			;_penCol
CURSOR_Y = $c37d			;_penRow
GRAPH_MEM = $c9fa			;_plotSScreen
TEXT_MEM2 = $cfab			;_cmdShadow
VAT_END = $d298
VAT_START = $8000
VIDEO_MEM = $fc00

;==================================================================
;all the keys are used with <call GET_KEY>, not TI's <call _getkey>
;==================================================================
K_NOKEY       =$00    ;No key
K_DOWN        =$01    ;Down
K_LEFT        =$02    ;Left
K_RIGHT       =$03    ;Right
K_UP          =$04    ;Up
K_ENTER       =$09    ;Enter
K_PLUS        =$0A    ;+                      X
K_MINUS       =$0B    ;-                      T
K_STAR        =$0C    ;*                      O
K_SLASH       =$0D    ;/                      J
K_RAISE       =$0E    ;^                      E
K_CLEAR       =$0F    ;Clear
K_SIGN        =$11    ;(-)                    Space
K_3           =$12    ;3                      W
K_6           =$13    ;6                      S
K_9           =$14    ;9                      N
K_RIGHTPAR    =$15    ;)                      I
K_TAN         =$16    ;Tan                    D
K_CUSTOM      =$17    ;Custom
K_DOT         =$19    ;.                      Z
K_2           =$1A    ;2                      V
K_5           =$1B    ;5                      R
K_8           =$1C    ;8                      M
K_LEFTPAR     =$1D    ;(                      H
K_COS         =$1E    ;Cos                    C
K_PRGM        =$1F    ;Prgm
K_DEL         =$20    ;Del
K_0           =$21    ;0                      Y
K_1           =$22    ;1                      U
K_4           =$23    ;4                      Q
K_7           =$24    ;7                      L
K_EE          =$25    ;EE                     G
K_SIN         =$26    ;Sin                    B
K_TABLE       =$27    ;Table		  ;Used to be Stat on the TI-85, now K_TABLE
K_XVAR        =$28    ;x-Var                  x
K_ON          =$29    ;On
K_STO         =$2A    ;Sto                    =
K_COMMA       =$2B    ;,                      P
K_SQUARE      =$2C    ;x^2                    K
K_LN          =$2D    ;Ln                     F
K_LOG         =$2E    ;Log                    A
K_GRAPH       =$2F    ;Graph
K_ALPHA       =$30    ;Alpha
K_F5          =$31    ;F5
K_F4          =$32    ;F4
K_F3          =$33    ;F3
K_F2          =$34    ;F2
K_F1          =$35    ;F1
K_SECOND      =$36    ;2nd
K_EXIT        =$37    ;EXIT
K_MORE        =$38    ;MORE
