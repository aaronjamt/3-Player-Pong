OptionAExec:
	ld hl,Energy
	ld d,(hl)
	inc hl
	ld e,(hl)
	dec hl
	inc de
	call UpdateInt16
	call DispStatus
	ret
	
OptionBExec:
	ld hl,Energy
	ld d,(hl)
	inc hl
	ld e,(hl)
	dec hl
	dec de
	call UpdateInt16
	call DispStatus
	ret
	
OptionNextExec:
	ld a,(MenuOption)
	add a,%00001000
	ld (MenuOption),a
	ret
	
OptionPrevExec:
	ld a,(MenuOption)
	sub %00001000
	ld (MenuOption),a
	ret
