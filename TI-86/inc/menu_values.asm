MenuOption:
	.db 00h									; Bottom 3 bits = currently selected option number (0=top)
											; Top 5 bits = current menu number
MenuOptionsTable:
	.dw MenuA, MenuB, 0						; Lists all of the menus in order of their ID's
	
MenuA:
	.dw MenuOptionA, MenuOptionB, MenuOptionNext, 0			; Lists all options in the menu, followed by null to indicate the end.
MenuB:
	.dw MenuOptionC, MenuOptionD, MenuOptionPrev, 0			; Lists all options in the menu, followed by null to indicate the end.

;-------------------------------------------------------------------------------------------------------------------------------;
;																																;
;							Place menu options below here. They should be ASCII and null-terminated.							;
;																																;
;-------------------------------------------------------------------------------------------------------------------------------;

MenuOptionA:
	.dw OptionAExec
	.db "Option A (++)",0
MenuOptionB:
	.dw OptionBExec
	.db "Option B (--)",0
MenuOptionC:
	.dw OptionAExec
	.db "Option C",0
MenuOptionD:
	.dw OptionBExec
	.db "Option D",0
MenuOptionNext:
	.dw OptionNextExec
	.db "Next",0
MenuOptionPrev:
	.dw OptionPrevExec
	.db "Previous",0
