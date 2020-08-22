; ACZ include file: ROM calls
; Assembly Coder's Zenith - http://www.acz.org
; version: January 18, 1999

_ldhlind				equ		4010h	; ld hl,(hl)
_chkON					equ		4028h	; bit onInterrupt,(iy+onflags)
_bitgrffuncm			equ		402Ch	; bit grffuncm,(iy+grfmodeflags)
_bitgrfpolarm			equ		4030h	; bit grfpolarm,(iy+grfmodeflags)
_bitgrfparamm			equ		4034h	; bit grfparamm,(iy+grfmodeflags)
_bitgrfrecurm			equ		4038h	; bit grfrecurm,(iy+grfmodeflags)
_cphlde					equ		403Ch	; cp hl,de
_put_colon				equ		4040h	; disp ":"
_divHLby10				equ		4044h	; hl = hl/10
_divHLbyA				equ		4048h	; hl = hl/a
_divAHLby10				equ		404Ch	; ahl = ahl/10
_timeout				equ		4058h	; dec timeout counter. if 0, turn calc off
_resetAPD				equ		4060h	; reset APD counter
_scan_code				equ		4064h	; keyboard handler (read keyboard)
_get_key				equ		4068h	; a = key code
_jforcecmdnochar		equ		409Ch	; force out of program
_pPutAwayPrompt			equ		40B5h	; put home screen edit away
_call_cxPPutAway		equ 	40BDh
_call_cxPutAway			equ		40C1h
_call_cxSizeWind		equ		40C5h
_call_cxErrorEP			equ		40C9h
_call_cxMain			equ		40CDh
_cxNull					equ		40D1h
_p_cxNull				equ		40D2h
_err_handler			equ		40DDh	; default error handler
_set_cx_100				equ		40E1h
_set_cx_50				equ		40E5h
_set_cx_dec				equ		40E9h
_set_context			equ		40EDh	; init the State Monitor with a new set of context vectors
_off					equ		4101h	; turn calc off normally
_reset					equ		4109h	; reset calculator
_removTok				equ		4119h	; remove all user tokens
_errAxes				equ		412Dh	; error 35 AXES
_errFldOrder			equ		4130h	; error 36 FLD-ORDER
_errStatPlot			equ		4133h	; error 34 STAT PLOT
_errOverflow			equ		4136h	; error 01 OVERFLOW
_errDivBy0				equ		4139h	; error 02 DIV BY 0
_errSingularMat			equ		413ch	; error 03 SINGULAR MAT
_errDomain				equ		413fh	; error 04 DOMAIN
_errIncrement			equ		4142h	; error 05 INCREMENT
_errSyntax				equ		4145h	; error 07 SYNTAX
_errNumberBase			equ		4148h	; error 08 NUMBER BASE
_errMode				equ		414Bh	; error 09 MODE
_errDataType			equ		414eh	; error 10 DATA TYPE
_errArgument			equ		4151h	; error 11 ARGUMENT
_errDimMismatch			equ		4154h	; error 12 DIM MISMATCH
_errDimension			equ		4157h	; error 13 DIMENSION
_errUndefined			equ		415Ah	; error 14 UNDEFINED
_errReserved			equ		4169h	; error 16 RESERVED
_errInvalid				equ		416ch	; error 17 INVALID
_errIllegalNest			equ		416fh	; error 18 ILLEGAL NEST
_errBound				equ		4172h	; error 19 BOUND
_errGraphWindow			equ		4175h	; error 20 GRAPH WINDOW
_errZoom				equ		4178h	; error 21 ZOOM
_errBreak				equ		417bh	; error 06 BREAK
_errStat				equ		417eh	; error 23 STAT
_errConversion			equ		4181h	; error 24 CONVERSION
_errSolver				equ		4184h	; error 25 SOLVER
_errIterations			equ		4187h	; error 28 ITERATIONS
_errBadGuess			equ		418ah	; error 29 BAD GUESS
_errDifEqSetup			equ		418dh	; error 30 DIF EQ SETUP
_errPoly				equ		4190h	; error 32 POLY
_errTolNotMet			equ		4193h	; error 33 TOL NOT MET
_errLink				equ		4196h	; error 37 LINK
_errorA					equ		4199h	; invoke error message, a = error #
_error					equ		419Ch	; invoke error message, _ERRNO = error #
_instError				equ		41A1h	; install error handler (HL=ptr)
_removError				equ		41A4h	; remove error handler
_ld_de_fp0				equ		41B7h	; (de) = fp0
_ld_de_fp1				equ		41BBh	; (de) = fp1
_mulHL10				equ		41BFh	; hl = hl x 10
_ckop1cplx				equ		41C3h	; check if op1 is cplx
_ckcplx					equ		41C7h	; check if A & $1f = $01
_ckop1real				equ		41CBh	; get type of op1 in a
_cpop1op2				equ		41FBh	; cp op1,op2
_op3toop4				equ		4203h	; move 11 bytes at op3 to op4
_op1toop4				equ		4207h	; move 11 bytes at op1 to op4
_op2toop4				equ		420Bh	; move 11 bytes at op2 to op4
_movtoop4				equ		420Fh	; move 11 bytes at (hl) to op4
_op4toop2				equ		4213h	; move 11 bytes at op4 to op2
_op4toop3				equ		4217h	; move 11 bytes at op4 to op3
_op3toop2				equ		421Bh	; move 11 bytes at op3 to op2
_op1toop3				equ		421Fh	; move 11 bytes at op1 to op3
_movfrop1				equ		4223h	; move 11 bytes at op1 to (de)
_op5toop2				equ		4227h	; move 11 bytes at op5 to op2
_op5toop6				equ		422Bh	; move 11 bytes at op5 to op6
_op5toop4				equ		422Fh	; move 11 bytes at op5 to op4
_op1toop2				equ		4233h	; move 11 bytes at op1 to op2
_movtoop2				equ		4237h	; move 11 bytes at (hl) to op2
_op6toop2				equ		423Bh	; move 11 bytes at op6 to op2
_op6toop1				equ		423Fh	; move 11 bytes at op6 to op1
_op4toop1				equ		4243h	; move 11 bytes at op4 to op1
_op5toop1				equ		4247h	; move 11 bytes at op5 to op1
_op3toop1				equ		424Bh	; move 11 bytes at op3 to op1
_op4toop5				equ		424Fh	; move 11 bytes at op4 to op5
_op3toop5				equ		4253h	; move 11 bytes at op3 to op5
_op2toop5				equ		4257h	; move 11 bytes at op2 to op5
_movtoop5				equ		425Bh	; move 11 bytes at (hl) to op5
_op2toop6				equ		425Fh	; move 11 bytes at op2 to op6
_op1toop6				equ		4263h	; move 11 bytes at op1 to op6
_movtoop6				equ		4267h	; move 11 bytes at (hl) to op6
_op1toop5				equ		426Bh	; move 11 bytes at op1 to op5
_op2toop1				equ		426Fh	; move 11 bytes at op2 to op1
_movtoop1				equ		4273h	; move 11 bytes at (hl) to op1
_mov11b					equ		4277h	; move 11 bytes at (hl) to (de)
_mov10b					equ		427Bh	; move 10 bytes at (hl) to (de)
_mov9b					equ		427Fh	; move 9 bytes at (hl) to (de)
_mov9b_					equ		4283h	; move 9 bytes at (hl) to (de)
_mov8b					equ		4287h	; move 8 bytes at (hl) to (de)
_mov7b					equ		428Bh	; move 7 bytes at (hl) to (de)
_mov7b_					equ		428Fh	; move 7 bytes at (hl) to (de)
_mov6b					equ		4293h	; move 6 bytes at (hl) to (de)
_mov5b					equ		4297h	; move 5 bytes at (hl) to (de)
_mov4b					equ		429Bh	; move 4 bytes at (hl) to (de)
_mov3b					equ		429Fh	; move 3 bytes at (hl) to (de)
_mov2b					equ		42A3h	; move 2 bytes at (hl) to (de)
_op4toop2m				equ		42A7h
_op2toop3				equ		42CBh	; move 11 bytes at op2 to op3
_movtoop3				equ		42CFh	; move 11 bytes at (hl) to op3
_op4toop6				equ		42D3h	; move 11 bytes at op4 to op6
_mov10toop1				equ		42D7h	; move 10 bytes at (hl) to op1
_mov10toop1op2			equ		42DBh	; move 10 to op1, 10 to op2
_mov10toop2				equ		42DFh	; move 10 bytes at (hl) to op2
_movfroop1				equ		42E3h	; move 10 bytes at op1 to (de)
_op4set1				equ		42E7h	; op4 = floating point 1
_op3set1				equ		42EBh	; op3 = floating point 1
_op2set8				equ		42EFh	; op2 = floating point 8
_op2set5				equ		42F7h	; op2 = floating point 5
_op2set4				equ		42FBh	; op2 = floating point 4
_op2set3				equ		4303h	; op2 = floating point 3
_op1set1				equ		430Fh	; op1 = floating point 1
_op1set4				equ		4313h	; op1 = floating point 4
_op1set3				equ		4317h	; op1 = floating point 3
_op3set2				equ		431Bh	; op3 = floating point 2
_op1set2				equ		431Fh	; op1 = floating point 2
_op2set2				equ		4323h	; op2 = floating point 2
_op2set1				equ		432Fh	; op2 = floating point 1
_ld_hl_8z				equ		4343h	; 8 zeros to (hl)
_ld_hl_8a				equ		4347h	; 8 a to (hl)
_ld_hlplus1_7a			equ		434Bh	; 7 a to (hl+1)
_ld_hl_7a				equ		434Fh	; 7 a to (hl)
_op4set0				equ		4353h	; op4 = floating point 0
_op3set0				equ		4357h	; op3 = floating point 0
_op2set0				equ		435Bh	; op2 = floating point 0
_op1set0				equ		435Fh	; op1 = floating point 0
_ld_hl_fp0				equ		4363h	; (hl)= fp0
_zeroop1m				equ		4367h	; mantissa op1 = 0
_zeroop1				equ		436Bh	; 11 bytes op1 = 0
_zeroop2				equ		436Fh	; 11 bytes op2 = 0
_zeroop3				equ		4373h	; 11 bytes op3 = 0
_ld_hl_11z				equ		4377h	; 11 zeros to (hl)
_ld_hl_bz				equ		437Bh	; B zeros to (hl)
_shracc					equ		4383h	; shift bits in A four to the right
_shlacc					equ		438Bh	; shift bits in A four to the left
_ex_op2_op6				equ		446Fh	; swap op2,op6
_ex_op5_op6				equ		4473h	; swap op5,op6
_ex_op1_op5				equ		4477h	; swap op1,op5
_ex_op1_op6				equ		447Bh	; swap op1,op6
_ex_op2_op4				equ		447Fh	; swap op2,op4
_ex_op2_op5				equ		4483h	; swap op2,op5
_ex_op1_op3				equ		4487h	; swap op1,op3
_ex_op1_op4				equ		448Bh	; swap op1,op4
_ex_op1_op2				equ		448Fh	; swap op1,op2
_ckop1fp0				equ		449Bh	; set Z if op1 = fp 0
_ckop2fp0				equ		44A3h	; set Z if op2 = fp 0
_ckop1int				equ		44B3h	; set Z if op1 = fp integer
_ckint					equ		44B7h	; set Z if (hl)= fp integer
_ckop1odd				equ		44BBh	; set Z if op1 is even
_ckodd					equ		44BFh	; set Z if (hl) is even
_ckop2pos				equ		450Bh	; set Z if op2 is positive
_ckop1pos				equ		450Fh	; set Z if op1 is positive
_absop2					equ		4513h	; op2 = abs(op2)
_inco1exp				equ		4527h	; op1 = op1 x 10
_HtimesL				equ		4547h	; hl = h * l
_findsym_error			equ		458Fh	; just like findsym, error if undefined
_invsub					equ		45E3h
_PLUS1					equ		45EBh	; op1 = op1 + 1
_inc_ptr_ade			equ		45EFh	; ade = ade + 1
_ex_ahl_bde				equ		45F3h	; swap ahl and bde
_get_size_word			equ		460Bh	; get size word of var at bde
_setXXop1				equ		4613h	; convert hex # in A to flt point in op1
_setXXop2				equ		4617h	; convert hex # in A to flt point in op2
_setXXXXop2				equ		461Bh	; convert hex # in HL to flt point in op2
_load_ram_ahl			equ		462Fh	; decode ABS ahl, load the RAM page and set hl = offset
_conv_ahl				equ		4633h	; decode ABS ahl, a = RAM page, hl = offset
_inc_ptr_ahl			equ		4637h	; ahl = ahl + 1
_dec_ptr_ahl			equ		463Bh	; ahl = ahl - 1
_inc_ptr_bde			equ		463Fh	; bde = bde - 1
_dec_ptr_bde			equ		4643h	; bde = bde - 1
_set_abs_src_addr		equ		4647h	; ahl -> (_abs_src_addr)
_get_free_mem			equ		464Bh	; (_FREE_MEM) -> ahl
_set_mm_num_bytes		equ		464Fh	; ahl -> (_mm_num_bytes)
_round_OP1				equ		4657h
_check_asm				equ		46AFh	; set Z if prog at (bde) is asm
_jump_table				equ		46B7h	; hl->table _asap_ind=index
_memchk					equ		46BBh	; ahl = # bytes of free memory
_dec_ptr_ade			equ		46BFh	; ade = ade - 1
_getb_ahl				equ		46C3h	; a = (ABS ahl), hl = asic address
_cp_ahl_bde				equ		46C7h	; cp ahl,bde
_findsym				equ		46CBh	; look up var op1
_copy_fwd				equ		46D3h
_del_temp_vars			equ		46D7h	; delete temp vars
_createreal				equ		46EBh	; create real var op1
_createrconst			equ		46EFh	; create real constant var op1
_createcconst			equ		46F3h	; create cplx constant var op1
_createcplx				equ		46F7h	; create cplx var op1
_creatervect_temp		equ		46FBh
_creatervect			equ		46FFh	; create real vector op1, L = # elements
_createcvect_temp		equ		4703h
_createcvect			equ		4707h	; create cplx vector op1, L = # elements
_createrlist_temp		equ		470Bh
_createrlist			equ		470Fh	; create real list op1, HL = # elements
_createclist_temp		equ		4713h
_createclist			equ		4717h	; create cplx list op1, HL = # elements
_creatermat_temp		equ		471Bh
_creatermat				equ		471Fh	; create real matrix op1, HL = row,col
_createcmat_temp		equ		4723h
_createcmat				equ		4727h	; create cplx matrix op1, HL = row,col
_createstrng_temp		equ		472Bh
_createstrng			equ		472Fh	; create string op1, HL = # bytes
_createequ_temp			equ		4733h
_createequ				equ		4737h	; create equation op1, HL = # bytes
_createpict				equ		473Bh	; create picture var op1
_createprog				equ		474Fh	; create program var op1, HL = # bytes
_copy_bkwd				equ		475Bh
_delvar					equ		475Fh	; delete var
_update_VAT_ptrs		equ		476Fh
_get_size				equ		477Bh
_get_var_size			equ		477Fh
_push_bc_OPS			equ		4783h
_check_STACK_mem		equ		4787h
_pop_bc_OPS				equ		478Bh
_push_a_OPS				equ		478Fh
_pop_a_OPS				equ		4793h
_popop1					equ		479Fh	; pop real or complex to op1/op2
_poprealo6				equ		47A3h	; pop real num op6 from fp stack
_poprealo5				equ		47A7h	; pop real num op5 from fp stack
_poprealo4				equ		47ABh	; pop real num op4 from fp stack
_poprealo3				equ		47AFh	; pop real num op3 from fp stack
_poprealo2				equ		47A3h	; pop real num op2 from fp stack
_poprealo1				equ		47A7h	; pop real num op1 from fp stack
_sub_FPS_20				equ		47CBh
_sub_FPS_10				equ		47CFh
_sub_FPS_bc				equ		47D3h
_deallocfps1			equ		47DBh
_ram_page_1				equ		47E3h	; load RAM page 1, FPS page
_load_ram_OPS			equ		47E7h
_load_ram_ES			equ		47EBh
_load_ram_FPS			equ		47EFh
_ram_page_7				equ		47F3h	; load RAM page 7, symbol table page
_pushrealo1				equ		4813h	; push real num op1 to fp stack
_cpyto2fpst				equ		4893h
_cpyto1fpst				equ		4897h
_cpyto2fps1				equ		48AFh
_cpyto2fps2				equ		48C3h
_cpyo2tofpst			equ		48D7h
_cpyo6tofpst			equ		48DBh
_cpyo1tofpst			equ		48DFh
_cpydetofpst			equ		48E3h
_cpydetohlt				equ		48E7h
_cpydetohlc				equ		48EBh
_cpyo5tofps2			equ		48EFh
_cpyo2tofpsto1tofps1	equ		48F3h
_cpyo1tofps1			equ		48F7h
_cpydetofps1			equ		48FBh
_cpydetohl1				equ		48FFh
_cpyo2tofps2			equ		4903h
_cpyo3tofps2			equ		4907h
_cpyo6tofps2			equ		490Bh
_cpyo1tofps2			equ		490Fh
_cpydetofps2			equ		4913h
_cpydetohl2				equ		4917h
_cpyo5tofps3			equ		491Bh
_cpyo2tofps2o1tofps3	equ		491Fh
_cpyo1tofps3			equ		4923h
_cpydetofps3			equ		4927h
_cpydetohl3				equ		492Bh
_cpyo1tofps4			equ		492Fh
_cpydetofps4			equ		4933h
_cpydetohl4				equ		4937h
_cpyo1tofps6			equ		493Bh
_cpyo1tofps7			equ		493Fh
_cpyo1tofps8			equ		4943h
_ask_self_test			equ		494Fh
_self_test				equ		4953h
_strlen					equ		4957h	; bc = length of string (hl)
_strcpy					equ		495Bh	; hl->source, de->destination
_strcat					equ		495Fh	; hl->source, de->destination
_strcmp					equ		4963h	; compare (hl) to (de), length bytes first
_find_bit				equ		496Bh	; hl+=a/8 a=1<<(a%8)
_cursorOff				equ		498Ch	; turn off blinking cursor
_cursorOn				equ		4994h	; turn on blinking cursor
_reset_MATH				equ		49A0h
_disp_GRAPH				equ		49B0h
_flushallmenus			equ		49DCh	; clear the menu key stacks
_disp_menu				equ		49E8h
_exec_pg1				equ		4A0Ah
_putmap					equ		4A27h	; display a character (A=char)
_putc					equ		4A2Bh	; display a character and advance cursor
_dispAHL				equ		4A33h	; disp ahl deci
_puts					equ		4A37h	; display a zero-terminated string (HL=ptr)
_putps					equ		4A3Bh	; display a string with leading length byte
_newline				equ		4A5Fh	; move cursor to next line
_clrLCD					equ		4A7Eh	; clear LCD screen
_clrScrn				equ		4A82h	; clear LCD screen and _textShadow
_clrWindow				equ		4A86h	; clear between _winTop and _winBtm
_clrLine				equ		4A8Ah	; clear to end of line
_homeup					equ		4A95h	; cursor to top left of home screen
_vputmap				equ		4AA1h	; display variable width character (A=char)
_vputs					equ		4AA5h	; display a string of variable width characters
_vputsn					equ		4AA9h	; display B characters of string at (HL)
_runindicon				equ		4AADh	; turn on run indicator
_runindicoff			equ		4AB1h	; turn off run indicator
_clrText				equ		4AB5h
_exec_pg2				equ		4B1Bh
_binopexec1				equ		4B1Fh
_tofrac					equ		4B93h	; convert op1 to op1/op2
_gfudydx				equ		4B9Fh	; op1 = dy/dx
_INTOP1					equ		4C2Fh
_ahl_plus_2_pg3			equ		4C3Fh	; ahl = ahl + 2
_exec_basic				equ		4C47h	; basic program in op1
_stoAns					equ		4C9Fh	; store op1 to 'Ans' var
_stoY					equ		4CB3h	; store op1 to 'y' var
_stoX					equ		4CBBh	; store op1 to 'x' var
_stoOther				equ		4CBFh	; store pushed op to op1 var
_rclY					equ		4CDFh	; rcl 'y' var to op1
_rclX					equ		4CE3h	; rcl 'x' var to op1
_rclVarSym				equ		4CE7h	; rcl op1 var to op1
_get_token				equ		4D13h	; get byte from _P_CURPC to A
_get_varname			equ		4D1Bh	; get var name from _P_CURPC to A
_disp					equ		4D3Fh	; TI-BASIC "Disp" command
_pause					equ		4D43h	; TI-BASIC "Pause" command
_PDspGrph				equ		4D6Fh
_horizCmd				equ		4D73h	; op1 = y value
_vertCmd				equ		4D77h	; op1 = x value
_unpack_hex				equ		4DAFh	; a(hex) -> bc(dec)
_grbufcpy				equ		4E39h
_ILine					equ		4E51h
_IPoint					equ		4E59h
_geqnamea				equ		4E71h	; op1 = name of current EQ
_set_app_title			equ		4FA8h
_FindAlphaUp			equ		514Bh	; search VAT
_FindAlphaDn			equ		514Fh
_dispOP1				equ		515Bh	; display op1 as result
_dispDone				equ		515Fh	; print 'Done' right justified
_formReal				equ		5191h	; format real # op1 to displayable str op3-op4 (a=max width)
_CLine					equ		51E9h
_get_abs_src_addr		equ		5209h	; (_abs_src_addr) -> ahl
_get_word_ahl			equ		521Dh	; ld de,(ahl)  ahl = ahl + 2
_set_word_ahl			equ		5221h	; ld (ahl),de  ahl = ahl + 2
_abs_mov10toop1			equ		5235h	; ahl -> (_abs_src_addr) mov 10b (_abs_src_addr) -> OP1
_abs_mov10toop1_noset	equ		5239h	; move 10 bytes (_abs_src_addr) -> OP1
_abs_mov10b_set_d		equ		523Dh	; ahl -> (_abs_dest_addr) mov 10b (_abs_src_addr)->(_abs_dest_addr)
_abs_mov10b				equ		5249h	; move 10 bytes (_abs_src_addr) -> (_abs_dest_addr)
_abs_movfrop1_set_d		equ		5241h	; ahl -> (_abs_dest_addr) mov 10b OP1 -> (_abs_dest_addr)
_abs_movfrop1			equ		5245h	; move 10 bytes from OP1 -> (_abs_dest_addr)
_set_abs_dest_addr		equ		5285h	; ahl -> (_abs_dest_addr)
_RcPicGrph				equ		52B5h
_mm_ldir				equ		52EDh	; 24bit ldir
_mm_lddr				equ		52F1h	; 24bit lddr
_get_statvar			equ		5369h	; load (_STATVAR+10*a) to op1
_getky					equ		5371h
_low_battery			equ		5398h	; low battery message (ret to homescreen)
_mov10op2add			equ		5464h
_INTGR					equ		5468h	; op1 = intgr(op1)
_MINUS1					equ		5470h	; op1 = op1 - 1
_FPSUB					equ		5474h	; op1 = op1 - op2
_FPADD					equ		5478h	; op1 = op1 + op2
_TIMESPT5				equ		5484h	; op1 = .5 x op1
_FPSQUARE				equ		5488h	; op1 = op1^2
_FPMULT					equ		548Ch	; op1 = op1 x op2
_invop1op2				equ		5490h
_invop1s				equ		5494h	; op1 = -op1
_invop2s				equ		5498h	; op2 = -op2
_FRAC					equ		549Ch	; op1 = frac(op1)
_FPRECIP				equ		54A4h	; op1 = 1/op1
_FPDIV					equ		54A8h	; op1 = op1/op2
_SQROOT					equ		54ACh	; op1 = sqrt(op1), neg# -> error
_SQROOTP				equ		54B0h	; op1 = sqrt(op1), neg# -> complex
_RNDGUARD				equ		54BCh	; round op1 to 12 digits
_ROUND					equ		54C0h
_LNX					equ		54C4h	; op1 = ln(op1), neg# -> error
_LNXP					equ		54C8h	; op1 = ln(op1), neg# -> complex
_LOGXP					equ		54CCh	; op1 = log(op1), neg# -> error
_LOGX					equ		54D0h	; op1 = log(op1), neg# -> complex
_ETOX					equ		54D4h	; op1 = e^op1
_TENX					equ		54D8h	; op1 = 10^op1
_SIN					equ		54E0h	; op1 = sin(op1)
_COS					equ		54E4h	; op1 = cos(op1)
_TAN					equ		54E8h	; op1 = tan(op1)
_TANH					equ		54F0h	; op1 = hyp tan(op1)
_COSH					equ		54F4h	; op1 = hyp cos(op1)
_SINH					equ		54F8h	; op1 = hyp sin(op1)
_ACOS					equ		5508h	; op1 = inv cos(op1), no complex
_ACOSP					equ		550Ch	; op1 = inv cos(op1), complex ok
_ATAN					equ		5510h	; op1 = inv tan(op1)
_ASIN					equ		5514h	; op1 = inv sin(op1)
_ATANH					equ		551Ch	; op1 = inv hyp tan(op1)
_ASINH					equ		5524h	; op1 = inv hyp sin(op1)
_ACOSH					equ		5528h	; op1 = inv hyp cos(op1)
_YTOX					equ		5538h	; op1 = op1^op2
_randint				equ		5544h	; op1 = random int between op1 and fps
_writeb_inc_ahl			equ		5567h	; c -> (ABS ahl), ahl = ahl + 1
_convop1				equ		5577h	; op1 -> de,a  (max 9999)
_set_mode				equ		557Bh	; a = function ($56-$79)
_asmComp				equ		55a3h
_getkey					equ		55AAh
_random					equ		55DAh	; op1 = random number (0-1)
_vputspace				equ		5643h	; a = ' '  _vputmap
_get_char				equ		569Dh	; get char A bitmap to _charmap (5x7 font)
_get_vchar				equ		56A1h	; get char A bitmap to _charmap (variable width font)
_call_user_on			equ		56EAh	; execute user on routine
_call_user_off			equ		56EDh	; execute user off routine
_call_sqrtexpr			equ		56F0h	; execute (sqrt)EXPR prog
_call_sqrtparse			equ		56F3h	; execute (sqrt)PARSE prog
_call_sqrtexec			equ		56F6h	; execute (sqrt)EXEC prog
_call_sqrtform			equ		56F9h	; execute (sqrt)FORM prog
_call_sqrtcmdtok		equ		56FCh	; execute (sqrt)CMDTOK prog
_call_sqrthome			equ		56FFh	; execute (sqrt)HOME prog
_call_sqrtkey			equ		5702h	; execute (sqrt)KEY prog
_call_sqrtgrf			equ		5705h	; execute (sqrt)GRF prog
_exec_pg4				equ		5718h	; rom page 4 asm jump table routine
_exec_pg3				equ		5714h	; rom page 3 asm jump table routine
_linkExec				equ		571Ch	; link routines (use _ASAP_IND)
_exec_assembly			equ		5730h	; exec assembly prog op1
_errNoSignChng			equ		5732h	; error 27 NO SIGN CHNG
_instTok				equ		575Ch	; OP1=funcname bc=endofprog de=symtab hl=menutab

.end
;;__________________________________________________________
;;(C)1999 ACZ - Assembly Coder's Zenith - http://www.acz.org
