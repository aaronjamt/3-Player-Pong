TryReceive:
	in A,(7)
	and 3
	cp 3
	jp nz,recv
	ret
recv:						
	call ReceiveByte
	call c,ProcessData ; Defined in main file
	ret

;======================================================
; ReceiveByte                 [Assembly Coder's Zenith]
;  Originally by Pascal Bouron and Jimmy Mardell
;
; out: A = received byte    carry set = error
; destroyed: all registers, OP1
;======================================================
ReceiveByte:
 ld hl,0
 ld (_OP1),hl
 ld 	 e,1			 ; for the OR
 ld 	 c,0			 ; byte receive
 ld 	 b,8			 ; counter
 ld 	 a,$C0
 out	 (7),a
rb_w_Start:
 in 	 a,(7)
 and 3
 cp  3
 jr 	 nz,rb_get_bit
 call rbTest_ON
 jr 	 rb_w_Start
rb_get_bit:
 cp 	 2
 jr 	 z,rb_receive_zero
 ld 	 a,c
 or 	 e
 ld 	 c,a
 ld 	 a,$D4
 out	 (7),a
 jr 	 rb_waitStop
rb_receive_zero:
 ld 	 a,$E8
 out	 (7),a
rb_waitStop:
 call rbTest_ON
 in 	 a,(7)
 and	 3
 jr 	 z,rb_waitStop
 ld 	 a,$c0
 out	 (7),a
 rl 	 e
 djnz 	 rb_w_Start
 ld 	 a,c
 ret
rbTest_ON:
 ld a,(_OP1)
 inc a
 ld (_OP1),a
 cp 255
 ret nz
 pop hl  ;Back to the place you were before.	Gotta love it!
 xor a
 ret

;======================================================
; SendByte                 	  [Assembly Coder's Zenith]
;  Originally by Pascal Bouron and Jimmy Mardell
;
; in: A = byte to send
; out: carry set = error
; destroyed: all registers, OP1
;======================================================
SendByte:
 ld hl,0
 ld (_OP1),hl
 ld 	 b,8
 ld 	 c,a			 ;byte to send
 ld 	 a,$C0
 out	 (7),a
sbw_setport3:
 in 	 a,(7)
 and 3
 cp  3
 jr 	 z,sbcalc_bit
 call sbSendTest_ON
 jr 	 sbw_setport3
sbcalc_bit:
 ld 	 a,c
 and	 1
 jr 	 z,sbsend_one
sbsend_zero:
 ld 	 a,$E8
 out	 (7),A
 jr 	 sbwait_setport
sbsend_one:
 ld 	 a,$D4
 out	 (7),A
sbwait_setport:
 call sbSendTest_ON
 in 	 a,(7)
 and	 3
 jr 	 nz,sbwait_setport
 ld 	 a,$C0
 out	 (7),A
 srl c
 djnz sbw_setport3
 xor a
 ret
sbSendTest_ON:
 ld a,%00111111
 out (1),a
 nop
 nop
 in a,(1)
 bit 6,a
 ret nz
 pop hl
; pop hl		; instead of returning, jump to
; jp Quit		; some program exit code
 ret