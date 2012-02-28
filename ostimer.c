/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  サンプルプログラム                           */
/*    H8/3048 用 OSタイマ (ITU0を利用)                                      */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */


#include "kernel.h"
#include "kernel_id.h"
#if 0
#include "h8_3048.h"
#else
#include "h83069f.h"
#endif
#include "ostimer.h"



/* OSタイマの初期化 */
void OsTimer_Initialize(VP_INT exinf)
{
	/* ITU0 (システムタイマ）初期化 */

    ITU.TSNC.BIT.SYNC0 = 0 ;    // channel 0 独立動作
    ITU0.TCR.BYTE      = 0x03 ; // CCLR:16TCNT のクリア禁止, CKEG:立ち上がり、TPSC:Clock 1/8
    ITU0.TCR.BIT.CCLR  = 1 ;    // GRA でクリア
    ITU0.TIOR.BIT.IOA  = 0 ;    // GRA コンペア、出力無し

    ITU.TISRA.BIT.IMIEA0 = 1 ;  // channel 0 割り込み許可

    ITU0.GRA = 2499 ;           // 1 msec = 1/20MHz * 8 * 25000-1 
    ITU.TSTR.BIT.STR0 = 0 ;     // カウンター停止
    ITU0.TCNT = 0 ;             // カウンター値クリアー
    ITU.TSTR.BIT.STR0 = 1 ;     // カウンター動作開始

}


/* タイマ用割り込みハンドラ */
void OsTimer_TimerHandler(VP_INT exinf)
{
	/* 割り込み要因クリア */
    ITU.TISRA.BIT.IMFA0 = 0 ;
	
	/* タイムティック供給 */
	isig_tim();
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
