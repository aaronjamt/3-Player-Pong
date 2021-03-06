DispMenu:
	call ClearMenu							; Clears the menu area (prevents longer text poking out)

	ld a,0									; Set current row to 0 (AKA top line) and column to 0
	ld (_curRow),a							; (AKA beginning of line)
	ld (_curCol),a							; ...
	
	call CalculateMenuAddr					; Calculate which menu to display by ID
	call DispMenuLine						; Display calculated menu
	ret

; Clears the space for the menu
ClearMenu:
	ld a,0					; First colunm, second row
	ld (_curCol),a			; ...
	ld a,1					; ...
	ld (_curRow),a			; ...
	ld b,7					; Outer loop runs 7 times
_ClearLoopOuter:
	ld a,0					; Begining of line
	ld (_curCol),a			; ...
	ld a,b
	ld (_curRow),a			; Move to the next line (Bottom to top)
	ld c,b					; Store B register in C
	ld b,20					; Inner loop runs 19 times
	ld a,' '				; Using spaces
_ClearLoopInner:
	call _putc				; Put a space
	djnz _ClearLoopInner	; Loop (inner)
	ld b,c					; Inner loop finished, get the outer loop counter
	djnz _ClearLoopOuter	; Loop (outer)
	ret
	
; Calculates the address of the current menu's lookup table.
; Output:
; HL = lookup table address
; Destroys:
; a, b, c
CalculateMenuAddr:
	ld a,(MenuOption)
	
	and %11111000				; Get current menu id
	srl a						; Shift right 3 times to compensate for the `and`
	srl a						; since this value is the upper 5 bits of the byte.
	srl a						; `srl` shifts the register right
	ld hl,MenuOptionsTable
_MenuLookupLoop:
	cp 0
	jp z,_MenuLookupFound
	ld b,a						; Save A register for later
	ld a,(hl)					; Get value at address (HL)		
	cp 0						; Compare with 0
	jp z,_MenuLookupInvalid		; Value is 0, invalid (AKA end of table)

	inc hl						; Increment HL, check this byte
	ld a,(hl)					; Get value at address (HL)		
	cp 0						; Compare with 0
	jp z,_MenuLookupInvalid		; Value is 0, invalid (AKA end of table)
	ld a,b						; Retrieve A register value (Both bytes are valid)
	inc hl						; Increment HL (each element is 2 bytes)
	dec a
	jp _MenuLookupLoop
_MenuLookupFound:
	; Load address from lookup table into BC
	ld c,(hl)
	inc hl
	ld b,(hl)
	; Load address in BC into HL
	ld h,b
	ld l,c
	; HL contains the address of the current menu.
	ret
_MenuLookupInvalid:
	ld a,(MenuOption)
	and %00000111
	ld (MenuOption),a
	ld hl,MenuOptionsTable
	jp _MenuLookupFound

; Displays an option for the menu.
; Input:
; HL = Address to menu options
; Destroys:
; A, B, C, D, E
DispMenuLine:
	push hl								; If the line number is bad, we need to be able to recover HL
	ld a,(MenuOption)					; Load A with byte at MenuOption
	ld b,%00000111						; Only keep bottom 3 bits (currently selected option #)
	and b								; to use as a counter before inverting colors
	inc a								; Increment A since `dec` comes before `cp`
	ld c,0								; Set to 1 when selected line is drawn. Used to make sure 
										; a valid line number is selected.
_DispLineLoop:
	ld b,a								; Save A for later
	ld a,(_curRow)						; Get current row (AKA line), increment it
	inc a								; (AKA move to next line), and put new value
	ld (_curRow),a						; back
	ld a,0								; Set current column to 0 (AKA beginning of line)
	ld (_curCol),a						; ...
	ld a,b								; Retrieve saved A value
	
	ld e,(hl)							; Load DE with the bytes at HL and HL+1
	inc hl								; ...
	ld d,(hl)							; ...
	inc hl								; ...
	ld b,a								; Copy A register to B
	ld a,d								; Copy D to A and or with E: A will be zero only if
	or e								; D and E are both zero
	cp 0								; Reached null?
	jp z,_DispLineDone					; If so, we're done.
	ld a,b								; Otherwise, copy B back to A and decrease counter
	dec a								; ...
	cp 0								; If A is 0, this line should be highlighted.
	call z,_SwapColor					; ...
	call nz,_ResetColor					; Otherwise, reset color to normal.
	push hl								; _puts requires using HL, so push it to the stack,
	ld h,d								; load it with DE, and then call _puts. There is no
	ld l,e								; `ld hl,de`, so split it into 2 commands.
	inc hl								; The option label starts with a 2-byte pointer to
	inc hl								; a subroutine, inc twice to get to the string.
	call _puts							; Finally, display the line
	pop hl								; Pop HL from stack so it can be used again	
	jp _DispLineLoop					; Continue the loop
_DispLineDone:
	ld a,c								; Checks C flag: if 0, no line was highlighted, so selected
	cp 0								; line number is bad and needs to be reset.
	call z,_BadLine						; ...
	call _ResetColor					; Ensure colors are set back in case last line was selected
	pop hl								; Pop HL so that we return to the right spot. Also means we don't
										; destroy it, nice side benefit.
	ret									; Done
_ResetColor:
	res textInverse,(iy+textFlags)
	ret
_SwapColor:
	ld c,1
	set textInverse,(iy+textFlags)
	ret
_BadLine:
	ld a,0								; Set current row to 0 (AKA top line) and column to 0
	ld (_curRow),a						; (AKA beginning of line) as it would normally be on
	ld a,0								; entry to this subroutine.
	ld (_curCol),a						; ...
	
	ld a,(MenuOption)					; Uh-oh! Line number was bad! Gotta reset it to 0!
	ld b,%11111000						; Keep current menu number, but set option number
	and b								; to 0.
	ld (MenuOption),a					; Save new value
	
	pop de								; We need to pop HL, but the location for ret is on top.
	pop hl								; HL was pushed at the begining of the subroutine, so pop it,
	push hl								; but make sure to copy it back since it's popped again later.
	push de								; Make sure we put back the ret location!
	ld c,1								; Set the C flag to 1 so that if something goes terribly wrong
	inc a								; we don't create a fork bomb. Then increment A as detailed above
	jp _DispLineLoop					; and try again.
	ret

; Calculates the length of a menu (AKA number of options)
; Input:
; HL = Menu Address
; Output:
; B = Length of menu
; Destroys:
; A, H, L
CalculateMenuLength:
	ld b,255				; First command is an inc, 255 will make it overflow to 0
_MenuLengthLoop:
	inc b
	ld a,(hl)
	cp 0
	ret z
	inc hl
	inc hl
	jp _MenuLengthLoop

; Trys to move the menu cursor down, but does boundry checking to prevent invalid cursor IDs
; Destroys:
; A, B, C
MenuTryDown:
	call CalculateMenuAddr			; Finds the starting address of the current menu, puts it in HL
	call CalculateMenuLength		; Uses the address to find the length or max ID, puts it in B
	ld a,(MenuOption)				; Gets the current cursor position, ignoring the rest
	ld c,%00000111					; ...
	and c							; ...
	;ld c,a							; Swap A and B to make the comparison easier. Without this,
	;ld a,b							; we would have to check the result of the carry and zero
	;ld b,c							; flags. With it, we only need to check the carry.
	inc a							; Moves the cursor down and checks if it is still valid
	cp b							; ...
	jp nc,MenuTop					; If carry set, (current option+1) > length, so wrap to top
	ld b,a
	ld a,(MenuOption)				; Otherwise, add menu ID back, save changes to MenuOption,
	ld c,%11111000					; call DispMenu to redraw the menu, and ret.
	and c							; ...
	or b							; ...
	ld (MenuOption),a				; ...
	call DispMenu					; ...
	ret								; ...
	
; Trys to move the menu cursor up, but does boundry checking to prevent underflows
; Destroys:
; A, B, C
MenuTryUp:
	ld a,(MenuOption)
	ld b,%00000111
	and b
	cp 0
	jp z,MenuBottom
	dec a
	ld c,a
	ld a,(MenuOption)
	ld b,%11111000
	and b
	or c
	ld (MenuOption),a
	call DispMenu
	ret

; Moves the cursor to the top of the menu. Used for wraparound.
; Destroys A, B
; Super simple since top=0
MenuTop:
	ld a,(MenuOption)
	ld b,%11111000
	and b
	ld (MenuOption),a
	call DispMenu
	ret

; Moves the cursor to the bottom of the menu. Used for wraparound.
; Destroys A
MenuBottom:
	push BC							; This would destroy so many registers, so may as well
	push DE							; implement push/pop to mitigiate that somewhat.
	push HL							; ...

	call CalculateMenuAddr			; Finds the starting address of the current menu, puts it in HL
	call CalculateMenuLength		; Uses the address to find the length or max ID, puts it in B
	ld a,b							; Only want bottom 3 bits
	ld b,%00000111					; ...
	and b							; ...
	ld b,1							; The length of the menu is 1-indexed, while the
	sub b							; ID of the item is 0-indexed, so subtract 1.
	ld c,a							; Save so we can use it later
	ld a,(MenuOption)				; Get the current MenuOption
	ld b,%11111000					; Keep only the Menu #, not the Cursor Position
	and b							; ...
	add a,c							; Add the length of the menu
	ld (MenuOption),a				; Save to (MenuOption)
	call DispMenu

	pop HL							; This would destroy so many registers, so may as well
	pop DE							; implement push/pop to mitigiate that somewhat.
	pop BC							; ...
	ret

MenuSelectOption:
	call CalculateMenuAddr
	ld a,(MenuOption)
	ld b,%00000111
	and b
_MenuSelectLoop:
	cp 0
	jp z,_MenuSelectItem
	dec a
	inc hl
	inc hl
	jp _MenuSelectLoop
_MenuSelectItem:
	; This section gets the address of the menu item's callback (don't ask)
	ld e,(hl)
	inc hl
	ld d,(hl)
	ld h,d
	ld l,e
	ld e,(hl)
	inc hl
	ld d,(hl)
	ld h,d
	ld l,e
	; End of section
	ld de,RedrawDisp			; Need to RedrawDisp after callback, so push it to the stack and then when
	push de						; the callback RETs, it will go to RedrawDisp, which will ret back to main loop
	jp (hl)						; Jump to the callback
	ret							; Shouldn't ever get here, but just in case...

#include "../inc/menu_values.asm"
#include "../inc/menu_callbacks.asm"
