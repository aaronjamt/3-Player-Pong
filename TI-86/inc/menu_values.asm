MenuOption:
	.db 00h					; Bottom 3 bits = currently selected option number (0=top)
							; Top 5 bits = current menu number
								
MenuOptionsTable:			; Lists all of the menus in order of their ID's
	.dw MainMenu, PaddleModMenu, BallModMenu, ScoreModMenu, DispModMenu, 0
	
MainMenu:					; Lists all options in the menu, followed by null to indicate the end.
	.dw PaddleModOption, BallModOption, ScoreModOption, DispModOption, 0

PaddleModMenu:
	.dw MainMenuOption, 0

BallModMenu:
	.dw MainMenuOption, 0

ScoreModMenu:
	.dw MainMenuOption, 0

DispModMenu:
	.dw MainMenuOption, 0

;-------------------------------------------------------------------------------------------------------------------------------;
;																																;
;							Place menu options below here. They should be ASCII and null-terminated.							;
;																																;
;-------------------------------------------------------------------------------------------------------------------------------;

MainMenuOption:
	.dw MainMenuExec
	.db "Back to Main Menu   ",0

PaddleModOption:
	.dw PaddleModExec
	.db "Paddle Modifiers    ",0

BallModOption:
	.dw BallModExec
	.db "Ball Modifiers      ",0

ScoreModOption:
	.dw ScoreModExec
	.db "Score Modifiers     ",0

DispModOption:
	.dw DispModExec
	.db "Display Modifiers   ",0

MenuOptionA:
	.dw OptionAExec
	.db "Option A (++)       ",0
MenuOptionB:
	.dw OptionBExec
	.db "Option B (--)       ",0
MenuOptionC:
	.dw OptionAExec
	.db "Option C            ",0
MenuOptionD:
	.dw OptionBExec
	.db "Option D            ",0
MenuOptionNext:
	.dw OptionNextExec
	.db "Next                ",0
MenuOptionPrev:
	.dw OptionPrevExec
	.db "Previous            ",0
