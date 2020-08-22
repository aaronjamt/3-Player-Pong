; Convert 16-bit binary value to decimal, in ASCII format.
; HL = address to output 5-characters of ASCII + null to
; DE = value to convert to ASCII
Num2ASCII:
	ld	bc,-10000
	call	_Num1
	ld	bc,-1000
	call	_Num1
	ld	bc,-100
	call	_Num1
	ld	c,-10
	call	_Num1
	ld	c,b
_Num1:
	ld	a,'0'-1
_Num2:
	inc	a
	push hl
	ld h,d
	ld l,e
	add	hl,bc
	ld d,h
	ld e,l
	pop hl
	jr	c,_Num2
	push hl
	ld h,d
	ld l,e
	sbc	hl,bc
	ld d,h
	ld e,l
	pop hl

	ld	(hl),a
	inc	hl
	ld a,0
	ld (hl),a
	ret
	
; Shrinks ASCII number by removing leading ASCII 0's ($30)
; Inputs:
; HL = Address to start of ASCII string
; Destroys D, E, H, L, A
AsciiShrink:
	ld d,h
	ld e,l
_ZeroLoop:
	ld a,(hl)
	cp $00
	jp z,_ZeroDone
	cp '0'
	jp nz,_DoShrink
	inc hl
	jp _ZeroLoop
_DoShrink:
	ld (de),a
	inc de
	inc hl
	ld a,(hl)
	cp $00
	jp z,_Done
	jp _DoShrink
_ZeroDone:
	ld a,'0'
	ld (de),a
	inc de
_Done:
	ld a,0
	ld (de),a
	ret

; Calculates the length of an ASCII string, not including the null-terminator.	
; Inputs:
; HL = Address to start of ASCII string
; Outputs:
; B  = Length of ASCII string, not including the null-terminator
; Destroys:
; A
AsciiLength:
	ld a,0
	ld b,0
_Loop:
	ld a,(hl)
	cp 0
	jp z,_LengthDone
	inc b
	inc hl
	jp _Loop
_LengthDone:
	ret
