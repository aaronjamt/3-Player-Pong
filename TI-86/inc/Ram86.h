; ACZ include file: RAM locations
; Assembly Coder's Zenith - http://www.acz.org/
; version: January 30, 1999

_RAMStart             equ         0C000h
_kbdScanCode          equ         0C000h	; key code
_kbdLGSC              equ         0C001h
_kbdPSC               equ         0C002h	; previous scan code
_kbdWUR               equ         0C003h
_kbdDebncCnt          equ         0C004h
_kbdkey               equ         0C005h
_kbdGetKy             equ         0C006h
_keyextend            equ         0C007h
_contrast             equ         0C008h	; contrast (0-31)
_APDSubTimer          equ         0C009h	; APD sub-timer
_APDTimer             equ         0C00Ah	; APD timer
_APDWarmUp            equ         0C00Bh
_viet                 equ         0C00Ch
_curTime              equ         0C00Eh	; cursor time counter
_curRow               equ         0C00Fh	; cursor row
_curCol               equ         0C010h	; cursor column
_curUnder             equ         0C011h	; char under cursor
_undelBufLen          equ         0C012h	; undelete buffer lenght
_undelBuf             equ         0C013h	; undelete buffer
_P_tokVarPtr          equ         0C077h
_toklen               equ         0C07Ah
_TOK_B3               equ         0C07Ch
_DETOK_H3             equ         0C07Dh
_MEMPRE_H3            equ         0C07Eh
_indicMem             equ         0C07Fh
_indicCounter         equ         0C087h
_indicBusy            equ         0C088h	; busy indicator
_OP1                  equ         0C089h	; OP registers begin
_OP1EXPM              equ         0C08Ah	;
_OP1EXPL              equ         0C08Bh	;
_OP1M                 equ         0C08Ch	;
_OP1EXT               equ         0C093h	;	
_LOGKP                equ         0C094h	;
_OP2                  equ         0C094h	; op2
_OP2EXPM              equ         0C095h	;
_OP2EXPL              equ         0C096h	;
_OP2M                 equ         0C097h	;
_OP2EXT               equ         0C09Eh	;
_OP3                  equ         0C09Fh	; op3
_LOGKM                equ         0C09Fh	;
_OP3EXPM              equ         0C0A0h	;
_OP3EXPL              equ         0C0A1h	;
_OP3M                 equ         0C0A2h	;
_OP3EXT               equ         0C0A9h	;
_CORDFLG1             equ         0C0AAh	;
_OP4                  equ         0C0AAh	; op4
_OP4EXPM              equ         0C0ABh	;
_OP4EXPL              equ         0C0ACh	;
_OP4M                 equ         0C0ADh	;
_OP4EXT               equ         0C0B4h	;
_EK                   equ         0C0B5h	;
_CORDFLG              equ         0C0B5h	;
_OP5                  equ         0C0B5h	; op5
_OP5EXPM              equ         0C0B6h	;
_SF                   equ         0C0B6h	;
_EL                   equ         0C0B6h	;
_OP5EXPL              equ         0C0B7h	;
_EM                   equ         0C0B7h	;
_OP5M                 equ         0C0B8h	;
_EMM1                 equ         0C0B8h	;
_EITS                 equ         0C0B9h	;
_ENM2                 equ         0C0BAh	;
_ENA                  equ         0C0BBh	;
_EEN                  equ         0C0BCh	;
_OP5EXT               equ         0C0BFh	;
_EN                   equ         0C0C0h	;
_OP6                  equ         0C0C0h	; op6
_EJ                   equ         0C0C1h	;
_OP6EXPM              equ         0C0C1h	;
_OP6EXPL              equ         0C0C2h	;
_EEI                  equ         0C0C2h	;
_OP6M                 equ         0C0C3h	;
_ELOW                 equ         0C0C5h	;
_EIGH                 equ         0C0C6h	;
_OP6EXT               equ         0C0CAh	; OP registers end
_OP7                  equ         0C0CCh	;
_CPLXTRG              equ         0C0D7h
_IOFLAG               equ         0C0D7h
_P_IMATHPTR1          equ         0C0D8h
_P_IMATHPTR2          equ         0C0DBh
_P_IMATHPTR3          equ         0C0DEh
_P_IMATHPTR4          equ         0C0E1h
_P_IMATHPTR5          equ         0C0E4h
_CHKDELPTR1           equ         0C0E7h
_P_CHKDELPTR1         equ         0C0E7h
_P_CHKDELPTR2         equ         0C0EAh
_P_INSDELPTR          equ         0C0EDh
_P_UPDOWNPTR          equ         0C0F0h
_STDRNGSGN            equ         0C0F3h
_POLRNGSGN            equ         0C0F4h
_PARRNGSGN            equ         0C0F5h
_DIFRNDSGN            equ         0C0F6h
_USRRNGSGN            equ         0C0F7h
_STATSGN              equ         0C0F8h
_textShadow           equ         0C0F9h	; text mem
_textShadCur          equ         0C1A1h	; _textShadow's cursors
_textShadTop          equ         0C1A3h	;
_textShadAlph         equ         0C1A4h	;
_textShadIns          equ         0C1A5h	;
_textAccent           equ         0C1A6h
_cxMain               equ         0C1A7h
_cxPPutAway           equ         0C1A9h
_cxPutAway            equ         0C1ABh
_cxRedisp             equ         0C1ADh
_cxErrorEP            equ         0C1AFh
_cxSizeWind           equ         0C1B1h
_cxPage               equ         0C1B3h
_CXCURAPP             equ         0C1B4h	; current calc state
_cxPrev               equ         0C1B5h
_monQH                equ         0C1C4h
_monQT                equ         0C1C5h
_monQueue             equ         0C1C6h
_onSP                 equ         0C1D6h
_onCheckSum           equ         0C1D8h
_promptRow            equ         0C1DAh
_promptCol            equ         0C1DBh
_promptIns            equ         0C1DCh
_promptShift          equ         0C1DDh
_promptRet            equ         0C1DEh
_promptValid          equ         0C1E0h
_P_promptTop          equ         0C1E2h
_P_promptCursor       equ         0C1E5h
_P_promptTail         equ         0C1E8h
_P_promptBtm          equ         0C1EBh
_varType              equ         0C1EEh	; current variable type
_varCurrent           equ         0C1EFh	; current variable
_varFAFlags           equ         0C1F8h
_varClass             equ         0C1FAh
_catCurrent           equ         0C1FBh	; current catlg entry ptr
_menuActive           equ         0C1FDh	; number of active menus
_menu2Hilite          equ         0C1FEh	; selected entry (1-5)
_menuSingle           equ         0C1FFh
_menuAppStack         equ         0C201h	; stack of menu applications
_menuAppPtr           equ         0C20Dh	; pointer to end of stack
_menuAppDepth         equ         0C20Fh	; depth of menu app stack
_menuSysStack         equ         0C210h	; stack of menus
_menuSysPtr           equ         0C21Ch	; pointer to end of stack
_menuSysDepth         equ         0C21Eh	; depth (# of menus, limit=3)
_menuPrvStack         equ         0C21Fh
_menuPrvPtr           equ         0C22Bh
_menuPrvDepth         equ         0C22Dh
_m2i                  equ         0C22Eh	; active menu entries
_menuDyn1             equ         0C242h	; Dynamic menu entries
_menuDyn5             equ         0C26Ah	; ie, program menu and solver
_userMenu1            equ         0C274h
_userMenuTitle        equ         0C275h
_userMenu2            equ         0C27Ch
_userMenu3            equ         0C284h
_userMenu4            equ         0C28Ch
_userMenu5            equ         0C294h
_userMenuSA           equ         0C29Ch
_XSTATSAV             equ         0C31Ch
_ioPrompt             equ         0C324h
_YSTATSAV             equ         0C326h
_FSTATSAV             equ         0C330h
_IOSNDTYP             equ         0C33Ah
_SNDRECSTATE          equ         0C33Bh
_IOERRSTATE           equ         0C33Ch
_HEADER               equ         0C33Dh
_IODATA               equ         0C346h
_BAKHEADER            equ         0C352h
_TBLRNGSGN            equ         0C35Bh
_calc_id              equ         0C35Ch
_penCol               equ         0C37Ch	; pen column
_penRow               equ         0C37Dh	; pen row
_P_RCLQUEUE           equ         0C37Eh
_ERRNO                equ         0C381h	; error number
_ERRSP                equ         0C382h	; error stack pointer
_errOffset            equ         0C384h	; error offset
_ram_to_use           equ         0C386h
_offerr_sav_bc        equ         0C390h
_ABS_SRC_ADDR         equ         0C392h	; 3 byte ABS address pointer
_ABS_DEST_ADDR        equ         0C395h	; 3 byte ABS address pointer
_MM_NUM_BYTES         equ         0C398h	; 3 byte block move counter
_mm_tmp1              equ         0C39Bh
_mm_tmp2              equ         0C39Dh
_mm_tmp3              equ         0C39Fh
_mm_tmp4              equ         0C3A1h
_mm_tmp5              equ         0C3A3h
_ram_cache            equ         0C3A5h
_Flags                equ         0C3E5h	; system flags
_ram_to_use1          equ         0C40Ah	; user flags
_statReg              equ         0C414h
_STATVARS             equ         0C415h	; free if res statsvalid,(iy+statflags)
_STCounter            equ         0C555h	; self test counter
_curgstyle            equ         0C555h
_curGY                equ         0C556h
_curGX                equ         0C557h
_curGY2               equ         0C558h
_curGX2               equ         0C559h
_curgstyle_save       equ         0C55Ah
_curgstylesave        equ         0C55Bh
_plotflagsave         equ         0C55Ch
_XMINPTR              equ         0C55Dh	; pointers
_XMAXPTR              equ         0C55Fh	;
_XSCLPTR              equ         0C561h	;
_YMINPTR              equ         0C563h	;
_YMAXPTR              equ         0C565h	;
_YSCLPTR              equ         0C567h	;
_DIF1STCURINC         equ         0C569h
_TRACEPLOT            equ         0C56Bh
_BOXPLOTINFO          equ         0C56Ch
_SCURINC              equ         0C56Dh
_CURINC               equ         0C56Fh
_YPIXEL               equ         0C571h
_ORGXMIN              equ         0C572h
_PANSHIFT             equ         0C57Ch
_USRRNGSIZE           equ         0C586h
_UTHETMIN             equ         0C588h
_STSP                 equ         0C58Dh
_STRAMStart           equ         0C58Dh
_UTHETMAX             equ         0C592h
_UTHETSTEP            equ         0C59Ch
_UTPLOT               equ         0C5A6h
_UTMIN                equ         0C5B0h
_UTMAX                equ         0C5BAh
_UTSTEP               equ         0C5C4h
_UXMIN                equ         0C5CEh
_UXMAX                equ         0C5D8h
_UXSCL                equ         0C5E2h
_UYMIN                equ         0C5ECh
_UYMAX                equ         0C5F6h
_UYSCL                equ         0C600h
_UXRES                equ         0C60Ah
_XRES_INT             equ         0C614h
_HDERIV               equ         0C615h
_TOL                  equ         0C61Fh	; tol(tolerance)
_XFACT                equ         0C629h
_YFACT                equ         0C633h
_DELTAX               equ         0C63Dh	; delta x
_DELTAY               equ         0C647h	; delta y
_SHORTX               equ         0C651h	
_SHORTY               equ         0C65Bh
_FUNRNGSIZE           equ         0C665h
_FLAGSF               equ         0C667h	; settings for Func Mode
_XMINF                equ         0C668h	;
_XMAXF                equ         0C672h	;
_XSCLF                equ         0C67Ch	;
_YMINF                equ         0C686h	;
_YMAXF                equ         0C690h	;
_YSCLF                equ         0C69Ah	;
_LOWER                equ         0C6A4h	;
_UPPER                equ         0C6AEh	;
_XRES                 equ         0C6B8h	; Func Mode settings end
_POLRNGSIZE           equ         0C6C2h
_FLAGSPOL             equ         0C6C4h	; settings for Pol Mode
_THETAMIN             equ         0C6C5h	;
_THETAMAX             equ         0C6CFh	;
_THETASTEP            equ         0C6D9h	;
_XMINPOL              equ         0C6E3h	;
_XMAXPOL              equ         0C6EDh	;
_XSCLPOL              equ         0C6F7h	;
_YMINPOL              equ         0C701h	;
_YMAXPOL              equ         0C70Bh	;
_YSCLPOL              equ         0C715h	; Pol Mode settings end
_PARRNGSIZE           equ         0C71Fh	
_FLAGSPAR             equ         0C721h	; settings for Param Mode
_TMINPAR              equ         0C722h	;
_TMAXPAR              equ         0C72Ch	;
_TSTEPPAR             equ         0C736h	;
_XMINPAR              equ         0C740h	;
_XMAXPAR              equ         0C74Ah	;
_XSCLPAR              equ         0C754h	;
_YMINPAR              equ         0C75Eh	;
_YMAXPAR              equ         0C768h	;
_YSCLPAR              equ         0C772h	; Param mode settings end
_DIFRNGSIZE           equ         0C77Ch
_FLAGSDIF             equ         0C77Eh	; settings for DifEq Mode
_TOLERDIF             equ         0C77Fh	;
_TPLOTDIF             equ         0C789h	;
_TMINDIF              equ         0C793h	;
_TMAXDIF              equ         0C79Dh	;
_TSTEPDIF             equ         0C7A7h	;
_XMINDIF              equ         0C7B1h	;
_XMAXDIF              equ         0C7BBh	;
_XSCLDIF              equ         0C7C5h	;
_YMINDIF              equ         0C7CFh	;
_YMAXDIF              equ         0C7D9h	;
_YSCLDIF              equ         0C7E3h	;
_XAXISDIF             equ         0C7EDh	;
_YAXISDIF             equ         0C7EEh	; DifEq Settings end
_SLOPEF_EQU           equ         0C7EFh
_DIRF_X               equ         0C7F0h
_DIRF_Y               equ         0C7F1h
_DIRF_TIME            equ         0C7F2h
_FRES                 equ         0C7FCh
_INTS                 equ         0C806h
_DNEQ                 equ         0C810h
_P_XOUTSYM            equ         0C811h
_P_XOUTDAT            equ         0C814h
_P_YOUTSYM            equ         0C817h
_P_YOUTDAT            equ         0C81Ah
_P_INPUTSYM           equ         0C81Dh
_P_INPUTDAT           equ         0C820h
_P_FOUTDAT            equ         0C823h
_PREVDATA             equ         0C826h
_PREVDATA_EXT         equ         0C862h
_P1TYPE               equ         0C86Ch
_SavX1List            equ         0C86Dh
_SavY1List            equ         0C876h
_SavF1List            equ         0C87Fh
_P1FRQONOFF           equ         0C888h
_P2TYPE               equ         0C889h
_SavX2List            equ         0C88Ah
_SavY2List            equ         0C893h
_SavF2List            equ         0C89Ch
_P2FRQONOFF           equ         0C8A5h
_P3TYPE               equ         0C8A6h
_SavX3List            equ         0C8A7h
_SavY3List            equ         0C8B0h
_SavF3List            equ         0C8B9h
_P3FRQONOFF           equ         0C8C2h
_oldtype              equ         0C8C3h
_oldxlist             equ         0C8C4h
_oldylist             equ         0C8CDh
_oldflist             equ         0C8D6h
_uppery               equ         0C8D6h
_oldonoff             equ         0C8DFh
_tblpsrow             equ         0C8E0h
_tblscroll            equ         0C8E1h
_INPUTDAT_PG0         equ         0C8E3h
_TblLine              equ         0C8EDh
_OldTblMin            equ         0C8F7h
_TBLRNGSIZE           equ         0C901h
_TblMin               equ         0C903h
_TblStep              equ         0C90Dh
_TABLESGN             equ         0C917h
_TableYPtr            equ         0C918h
_curTblcol            equ         0C919h
_curTblrow            equ         0C91Ah
_dspTblcol            equ         0C91Bh
_dspTblrow            equ         0C91Ch
_higTblcol            equ         0C91Dh
_higTblrow            equ         0C91Eh
_TABLEXDATA           equ         0C920h
_TBLMATRIX            equ         0C920h
_TABLEYDATA           equ         0C95Ch
_TABLETEMPLATE        equ         0C9D4h
_SavedEqTok           equ         0C9D5h
_SavedEqNum1          equ         0C9D7h
_SavedEqTok1          equ         0C9D8h
_SaveAppFlags         equ         0C9DAh
_SaveCurFlags         equ         0C9DBh
_SaveCurGstyle        equ         0C9DCh
_SaveGraphFlags       equ         0C9DDh
_evalflevel           equ         0C9DEh
_TmpMatCols           equ         0C9DFh
_ES                   equ         0C9DFh
_TmpMatRows           equ         0C9E0h
_P_DERIVPTR           equ         0C9E1h
_DTMPThresh           equ         0C9E4h
_ELCPLXLCNT           equ         0C9E6h
_DERIVLEVEL           equ         0C9E8h
_P_DIFFEQPTR          equ         0C9E9h	; absolute address to diff eq
_P_DSOLVPTR           equ         0C9EBh	; absolute address to solver eq
_SOLVAR               equ         0C9EEh	; length byte, current solver variable
_P_QUADPTR            equ         0C9F7h
_plotSScreen          equ         0C9FAh	; graph mem
_SEED1                equ         0CDFAh
_SEED2                equ         0CE04h
_PARSEVAR             equ         0CE0Eh	; last parsed variable
_P_BEGPC              equ         0CE18h
_P_CURPC              equ         0CE1Bh
_P_ENDPC              equ         0CE1Eh
_ELCNT                equ         0CE21h	; end of line count
_COLCNT               equ         0CE23h	; column count
_ROWCNT               equ         0CE24h	; row count
_LCOUNT               equ         0CE25h
_EOS_ASAP_2ND         equ         0CE27h
_EXEC_CONV_SAVE       equ         0CE28h
_LASTENTRYPTR         equ         0CE2Ah	; pointer to end of stack
_LASTENTRYSTK         equ         0CE2Ch	; last entry stack
_numlastentries       equ         0CEACh	; number of entries
_currlastentry        equ         0CEADh
_FREESAVEY            equ         0CEAEh
_FREESAVEX            equ         0CEAFh
_STRACESAVE_TYPE      equ         0CEB0h
_STRACESAVE           equ         0CEB1h
_TRACESAVE            equ         0CEB3h
_DIF_T_SAVE           equ         0CEB5h
_A_B_SAVE             equ         0CEBFh
_A_B_TYPE             equ         0CEC0h
_GS_DELX              equ         0CEC1h
_GS_D1_YINC           equ         0CEC2h
_GS_D2_YINC           equ         0CEC3h
_GS_DELY              equ         0CEC4h
_GS_MAX_Y_PIX         equ         0CEC5h
_CURRENT_STYLE        equ         0CEC6h	; current graph style
_CL_X1                equ         0CEC7h
_CL_X2                equ         0CEC8h
_CL_Y_DAT             equ         0CEC9h
_PREV_POINT           equ         0CECBh
_RESSAVE              equ         0CECDh
_DREQU_X              equ         0CECEh
_DREQU_XINIT          equ         0CECFh
_DREQU_Y              equ         0CED9h
_DREQU_YINIT          equ         0CEDAh
_DREQU_XLIST          equ         0CEE4h
_DREQU_YLIST          equ         0CEE7h
_DREQU_tLIST          equ         0CEEAh
_DREQU_COUNT          equ         0CEEDh
_GY1                  equ         0CEEFh
_GX1                  equ         0CF21h
_GR1                  equ         0CF53h
_GQ1                  equ         0CF85h
_EQU_EDIT_SAVE        equ         0CF8Ah	; 
_FORMULA_BITMAP       equ         0CF8Bh	; Solver buffer
_MENUCMD_M2I          equ         0CFABh	; menu shadow
_cmdShadow            equ         0CFABh	; _cmdShadow
_MENUCMD_ITEMS        equ         0CFC9h
_MENUCMD_NUMROWS      equ         0D041h
_MENUCMD_CURROW       equ         0D042h
_cmdShadCur           equ         0D053h	; shadow cursors
_cmdShadAlph          equ         0D055h	;
_cmdShadIns           equ         0D056h	;
_cmdCursor            equ         0D057h	; cursor
_P_editTop            equ         0D059h	; Program editor top
_P_EDITCURSOR         equ         0D05Ch	; program editor cursor
_P_editTail           equ         0D05Fh
_P_editBtm            equ         0D062h	; Program editor bottom
_curmatcol            equ         0D065h
_curmatrow            equ         0D066h
_curlstrow            equ         0D067h
_numedTbl             equ         0D069h
_curlistel            equ         0D069h
_curlstrowh           equ         0D06Ah
_higmatcol            equ         0D06Bh
_higmatrow            equ         0D06Ch
_higlstrow            equ         0D06Dh
_maxdsprow            equ         0D06Fh
_ForCurMat            equ         0D070h
_higlstrowh           equ         0D070h
_ForDspCol            equ         0D072h
_forerrornum          equ         0D074h
_P_editSym            equ         0D075h
_P_editDat            equ         0D078h
_DspMatCol            equ         0D07Bh
_DspMatRow            equ         0D07Ch
_TmpMatCol            equ         0D07Dh
_TmpMatRow            equ         0D07Eh
_numoflist            equ         0D07Fh	; num of lists in buffer
_num1stlist           equ         0D080h	; num of first list
_NumCurList           equ         0D081h	; num of current list
_STATED_CUT_COL       equ         0D082h
_listnamebuffer       equ         0D083h	; list buffer(numbered)
_LastName             equ         0D12Eh
_modeRoot             equ         0D137h
_modeCount            equ         0D139h
_modeItem             equ         0D13Ah
_modePtr              equ         0D13Bh
_winTop               equ         0D13Dh	; first homescreen row
_winBtm               equ         0D13Eh	; last homescreen row
_winLeftEdge          equ         0D13Fh	
_winLeft              equ         0D140h
_winAbove             equ         0D142h
_winRow               equ         0D144h
_winCol               equ         0D146h
_fmtDigits            equ         0D148h
_fmtString            equ         0D149h
_fmtConv              equ         0D18Ah
_fmtLeft              equ         0D19Eh
_fmtIndex             equ         0D1A0h
_P_fmtMatSym          equ         0D1A2h
_P_fmtMatMem          equ         0D1A5h
_EQS                  equ         0D1A8h
_LSTINDEX             equ         0D1AAh
_LSTSIZE              equ         0D1ACh
_EQUINDEX             equ         0D1AEh
_order                equ         0D1B0h	; polynomial degree
_xnamesav             equ         0D1B1h
_ynamesav             equ         0D1BAh
_CustMType            equ         0D1C3h	; type=09(new) or 08(sub)
_MCustM               equ         0D1C3h	; 
_CustMLen             equ         0D1C4h	; number of custmnames
_CustMSav             equ         0D1C5h	; pointers to names
_custmnames           equ         0D1E3h	; the menu entries
_VARSAVECNT           equ         0D279h
_DELADJAMT            equ         0D27Ah
_TEMPINPUT            equ         0D27Dh
_TSYMPTR1             equ         0D27Eh
_TSYMPTR2             equ         0D280h
_P_CHKDELPTR3         equ         0D282h
_P_CHKDELPTR4         equ         0D285h
_P_TEMPMEM            equ         0D288h
_FPBASE               equ         0D28Bh
_FPS                  equ         0D28Dh	; fp stack pointer
_OPBASE               equ         0D28Fh
_OPS                  equ         0D291h	; op stack pointer
_PTempCnt             equ         0D293h
_CLEANTMP             equ         0D295h
_P_PTEMP              equ         0D297h
_PTEMP_END            equ         0D29Ah
_FREE_MEM             equ         0D29Dh	; available user memory
_newdataptr           equ         0D2A0h
_SavBotRow            equ         0D2A3h
_curstatplot          equ         0D2B8h
_curstatplotprompt    equ         0D2B9h
_difeqfieldmode       equ         0D2BAh
_matedoldtype         equ         0D2BBh
_modesave1            equ         0D2BCh
_statansfirst         equ         0D2BDh
_statanslast          equ         0D2BFh
_statanscur           equ         0D2C1h
_charmap              equ         0D2C3h
_altcharmap           equ         0D2CBh
_toktmp1              equ         0D2D3h
_toktmp2              equ         0D2D4h
_IOSAVOP1             equ         0D2D5h
_DELVAR_SAV_F         equ         0D2DFh
_DEL_SAV_OP1          equ         0D2E0h
_alt_asm_exec_btm     equ         0D2EBh
_altlfontptr          equ         0D2EDh	; user font pointer
_altsfontptr          equ         0D2F0h
_altonptr             equ         0D2F3h
_altslinkptr          equ         0D2F6h
_alt_ret_status       equ         0D2F9h
_alt_ret_jmp_page     equ         0D2FAh
_alt_ret_jmp_addr     equ         0D2FBh
_alt_int_chksum       equ         0D2FDh	; checksum for interrupt
_alt_interrupt_exec   equ         0D2FEh	; interrupt
_alt_slink_chksum     equ         0D3C6h	; checksum for slink_exec
_alt_slink_exec       equ         0D3C7h	; slink
_alt_on_chksum        equ         0D48Fh	; checksum for on_exec
_alt_on_exec          equ         0D490h	; executed when turned on
_alt_off_chksum       equ         0D558h	; checksum for off_exec
_alt_off_exec         equ         0D559h	; executed when turned off
_altram_end           equ         0D621h
_asm_exec_btm         equ         0D621h
_ASAP_IND             equ         0D623h
_asm_reg_af           equ         0D624h	; saved registers start
_asm_reg_a            equ         0D625h	;
_asm_reg_l            equ         0D626h	;
_asm_reg_hl           equ         0D626h	;
_asm_reg_h            equ         0D627h	;
_asm_reg_bc           equ         0D628h	;
_asm_reg_c            equ         0D628h	;
_asm_reg_b            equ         0D629h	;
_asm_reg_de           equ         0D62Ah	;
_asm_reg_e            equ         0D62Ah	;
_asm_reg_d            equ         0D62Bh	; saved registers end
_mPrgmMATH            equ         0D62Ch
_mMath                equ         0D64Ch	; pointers math menu entries
_mMath_asap1          equ         0D65Ah	; ptrs to math menu asaps
_mMath_asap2          equ         0D65Ch	;
_mMath_asap3          equ         0D65Eh	;
_iASAP1               equ         0D66Ch	; space for asap entries
_iASAP2               equ         0D678h	;
_iASAP3               equ         0D684h	;
_iASAP4               equ         0D690h	;
_iASAP5               equ         0D69Ch	;
_iASAP6               equ         0D6A8h	;
_iASAP7               equ         0D6B4h	;
_iASAP8               equ         0D6C0h	;
_iASAP9               equ         0D6CCh	; end of space for asaps
_asapnames            equ         0D6D8h	;
_asap_nl1             equ         0D6D8h	; names of asap programs
_asap_nl2             equ         0D6E1h	; for tokens
_asap_nl3             equ         0D6EAh	;
_asapvar              equ         0D6FCh	; name of the current asm prog
_tokspell_asap1       equ         0D706h	; pointers to tables of
_tokspelltblptr       equ         0D706h	; token spelling
_tokspell_asap2       equ         0D708h	;
_tokspell_asap3       equ         0D70Ah	;
_numtokens            equ         0D70Eh	; number of tokens in each
_numtok_asap1         equ         0D70Eh	; asap
_numtok_asap2         equ         0D70Fh	;
_numtok_asap3         equ         0D710h	;
_eostblptr            equ         0D712h	; ponters to table of
_eostbl_asap1         equ         0D712h	; token code
_eostbl_asap2         equ         0D714h	;
_eostbl_asap3         equ         0D716h	;
_Amenu_offset         equ         0D71Ah
_reinstall_asap1      equ         0D722h
_reinstall_vec        equ         0D722h
_reinstall_asap2      equ         0D724h
_reinstall_asap3      equ         0D726h
_asap1_ram            equ         0D72Ah
_asap2_ram            equ         0D734h
_asap3_ram            equ         0D73Eh
_checkStart           equ         0D748h
_asm_exec_ram         equ         0D748h	; start address for all ASM programs

.end
;;___________________________________________________________
;;(C)1999 ACZ - Assembly Coder's Zenith - http://www.acz.org/
