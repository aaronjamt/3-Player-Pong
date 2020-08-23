;
; SOME VERY NICE LINK ROUTINES MADE BY PASCAL BOURON
;
; I've made some modifications so it fits ZTetris
;

TryReceive:
	in A,(7)
	and 3
;	and 1			;DEBUG
	cp 3
	jp nz,recv
	ret
recv:						
	call ReceiveByte
	call c,ProcessData ; Defined in main file
	ret

ReceiveByte:
	ld hl,0
	ld (lcounter),hl

	ld e,1
	ld c,0					; byte receive
	ld b,8					; counter
	ld a,$C0
	out (7),a
rb_w_Start:
	push de
	ld de,$07FF				; timeout
timeoutloop1:
	dec de
	ld a,d
	or e
	cp 0
	jp z,timeout
	in a,(7)
	and 3
;	and 1			;DEBUG
	cp 3
	jr nz,rb_get_bit
	jr timeoutloop1
rb_get_bit:
	pop de
	cp 2
	jr z,rb_receive_zero
	ld a,c
	or e
	ld c,a
	ld a,$D4
	out (7),a
	jr rb_waitStop
rb_receive_zero:
	ld a,$E8
	out (7),a
rb_waitStop:
	ld d,$FF				; timeout
timeoutloop2:
	dec d
	ld a,d
	cp 0
	jp z,timeout
	in a,(7)
	and 3
	jr z,timeoutloop2
	ld a,$c0
	out (7),a
	rl e
	djnz rb_w_Start
	ld a,c
	scf
	ret
timeout:
	ld a,$ff
	ccf
	ret

SendByte:
	ld hl,0
	ld (lcounter),hl
	ld b,8
	ld (sbyte),a
	ld c,a			;byte to send
	ld a,$C0
	out (7),a
w_setport3:
	in a,(7)
	and 3
	cp 3
	jr z,calc_bit
	jr w_setport3
calc_bit:
	ld a,c
	and 1
	jr z,send_one
send_zero:
	ld a,$E8
	out (7),A
	jr wait_setport
send_one:
	ld a,$D4
	out (7),A
wait_setport:
	in a,(7)
	and 3
	jr nz,wait_setport
	ld a,$C0
	out (7),A
	srl c
	djnz w_setport3
	xor a
	ld (sbyte),a
	ret
