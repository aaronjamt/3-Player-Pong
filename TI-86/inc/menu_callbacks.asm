OptionAExec:
	ld hl,Energy
	ld d,(hl)
	inc hl
	ld e,(hl)
	dec hl
	inc de
	call UpdateInt16
	ret
	
OptionBExec:
	ld hl,Energy
	ld d,(hl)
	inc hl
	ld e,(hl)
	dec hl
	dec de
	call UpdateInt16
	ret
	
OptionNextExec:
	ld a,(MenuOption)
	add a,%00001000
	and %11111000
	ld (MenuOption),a
	ret
	
OptionPrevExec:
	ld a,(MenuOption)
	sub %00001000
	and %11111000
	ld (MenuOption),a
	ret

MainMenuExec:
	ld a,%00000000
	ld (MenuOption),a
	ret

PaddleModExec:
	ld a,%00001000
	ld (MenuOption),a
	ret

BallModExec:
	ld a,%00010000
	ld (MenuOption),a
	ret

ScoreModExec:
	ld a,%00011000
	ld (MenuOption),a
	ret

DispModExec:
	ld a,%00100000
	ld (MenuOption),a
	ret