;#include "inc/ti86asm.inc"
#include "inc/ultimate86.inc"

lcounter  = $C130      ; WORD

sbyte	  = $C138      ; BYTE

hsflag	  = $C135      ; BYTE

.org _asm_exec_ram
	call reset_values
	call _clrLCD
	ld a,0
	ld (_curRow),a
	ld a,0
	ld (_curCol),a
	set indiconly,(iy+indicflags)
	call RedrawDisp
	;ld de,$0001

loop:
	;push de
	call TryReceive
	;pop de

	;dec de
	;ld a,d
	;or e
	;cp 0
	;jp nz,kbd_check
	;ld de,$2FFF

	;call RedrawDisp

kbd_check:
	ld a,%10111111
	out (kbdPort),a
	nop
	nop
	in a,(kbdPort)
	bit 6,a
	jp z,Quit

	ld a,%11111101
	out (kbdPort),a
	nop
	nop
	in a,(kbdPort)
	ld c,a
	ld hl,LastKeys
	inc hl
	push bc
	ld b,(hl)
	xor b

	bit 0,a				; Enter
	push af
	call nz,EnterKey
	pop af
	pop bc
	ld hl,LastKeys
	inc hl
	ld (hl),c

	ld a,%11111110
	out (kbdPort),a
	nop
	nop
	in a,(kbdPort)
	ld c,a
	ld hl,LastKeys
	push bc
	ld b,(hl)
	xor b

	bit 0,a				; Down
	push af
	call nz,DownKey
	pop af
	bit 3,a				; Up
	call nz,UpKey
	pop bc
	ld hl,LastKeys
	ld (hl),c
	jp loop

DownKey:
	bit 0,c
	ret z
	call MenuTryDown
	ret

UpKey:
	bit 3,c
	ret z
	call MenuTryUp
	ret

EnterKey:
	bit 0,c
	ret z
	call MenuSelectOption
	ret

RedrawDisp:
	call DispStatus
	call DispMenu
	ret

; Destroys h, l
DispStatus:
	; Clear top line of display
	ld a,0
	ld (_curRow),a
	ld (_curCol),a
	ld a,' '
	ld b,20
_ClearLoop:
	call _putc
	djnz _ClearLoop
	
	ld a,0
	ld (_curCol),a
	ld hl,Player1Score+2
	call _puts
	
	ld hl,Player2Score+2
	call AsciiLength
	ld a,20
	sub b
	ld (_curCol),a
	call _puts
  
	; Calculate beginning column to center text
	ld hl,Energy+2
	call AsciiLength
	ld d,b
	ld hl,Energy_Label
	call AsciiLength
	ld a,d
	add a,b
	srl a
	ld b,a
	ld a,10
	sub b
	ld (_curCol),a

	; Print energy label + value
	ld hl,Energy_Label
	call _puts
	ld hl,Energy+2
	call _puts
	ret

; When TryReceive says there's data waiting, it should call this.
; This will process the data in the Accumulator from TryReceive
; and possibly call ReceiveByte to fetch all the data.
ProcessData:
	cp 01
	jp z,ReceiveEnergy
	cp 02
	jp z,ReceiveScore1
	;cp 03
	;jp z,ReceiveScore2
	ret

ReceiveEnergy:
	call ReceiveByte
	ret nc
	ld d,a
	ld e,0
	push de
	call ReceiveByte
	pop de
	ret nc
	ld e,a

	ld hl,Energy
	call UpdateInt16
	call DispStatus
	ret

ReceiveScore1:
	call ReceiveByte
	ret nc
	ld d,a
	ld e,0
	push de
	call ReceiveByte
	pop de
	ret nc
	ld e,a
	
	ld hl,Player1Score
	call UpdateInt16
	call DispStatus
	ret

; HL = Address of value to update
; DE = New value for address
; Destroys a, b, c, d, e, h, l
UpdateInt16:
	ld (hl),d
	inc hl
	ld (hl),e
	inc hl
	push hl
	call Num2ASCII
	pop hl
	call AsciiShrink
	ret

; Quits the program.
Quit:
	res indiconly,(iy+indicflags)
	call _clrLCD
	ld a,0
	ld (_curRow),a
	ld a,0
	ld (_curCol),a
	ret

reset_values:
	ld hl,Energy
	ld de,0
	call UpdateInt16

	ld a,0
	ld hl,Division_Mod10
	ld (hl),a
	inc hl
	ld (hl),a
	inc hl

	ld hl,Division_Value
	ld (hl),a
	inc hl
	ld (hl),a
	inc hl

	ld a,$FF
	ld (LastKeys),a
	ld (LastKeys+1),a
	ret

#include "inc/ascii.asm"
#include "inc/menu.asm"
#include "inc/linkrout.asm"

Energy:
	.db 00h, 00h		; Allocate 2 bytes (16 bits) for energy counter. Stored as an uint16 in (high byte, low byte) format.
	.db "00000",0		; Allocate 5 bytes (plus null) in ASCII format for _puts. This will be calculated whenever the value
						; is updated to save time when it's needed for _puts.
Player1Score:
	.db 00h, 00h		; See Energy for infomation on the format
	.db "00000", 0
Player2Score:
	.db 00h, 00h		; See Energy for infomation on the format
	.db "00000", 0
Energy_Label:
	.db "$",0
LastKeys:
	.db $FF, $FF		; All binary 1's (aka $FF) = no keys pressed. All 0's ($00) would mean all keys pressed.

Division_Mod10:
	.db 00h, 00h
Division_Value:
	.db 00h, 00h

.END
