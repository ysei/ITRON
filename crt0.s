; --------------------------------------------------------------------------- 
;  Hyper Operating System V4  日立 H8 用 サンプルプログラム                   
;    スタートアップルーチン                                                   
;                                                                             
;                                   Copyright (C) 1998-2002 by Project HOS    
;                                   http://sourceforge.jp/projects/hos/       
; --------------------------------------------------------------------------- 



				.h8300h

; -------------------------------------
;  スタートアップルーチン
; -------------------------------------
				.text
				.align 2
				.global _startup
_startup:
		; ----- スタック初期化
				mov.l	#_stack,er7

		; ----- .data セクションコピー （DATAが64kbyte以下と仮定）
				mov.l	#___dtors_end,er5
				mov.l	#___data,er6
				mov.w	#data_size,r4
copy_dsec:	eepmov.w
				mov.w	r4,r4
				bne	copy_dsec
				
		; ----- .bss セクションクリア（BSSが64kbyte以下と仮定）
				mov.l	#_bss_start,er5
				mov.l	#_bss_start+1,er6
				mov.w	#bss_size,r4
				mov.b	#0,r0l
				mov.b	r0l,@er5
clr_bsec:		eepmov.w
				mov.w	r4,r4
				bne	clr_bsec

		; ----- 初期化ルーチン呼び出し
				jsr	@_main
idle_loop:
				bra	idle_loop


				.global	_kernel_int_sp
				.section .rodata
				.align 2
_kernel_int_sp:
				.long	_stack		/* 割り込み時の er7 保存用 */


				.end



; --------------------------------------------------------------------------- 
;  Copyright (C) 1998-2002 by Project HOS                                     
; --------------------------------------------------------------------------- 
