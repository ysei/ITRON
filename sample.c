/* ------------------------------------------------------------------------ */
/*  Hyper Operating System V4  サンプルプログラム                           */
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
#include "h8_sci.h"



/* メイン関数 */
int main()
{
	/* SCIの初期化 */
	Sci_Initialize(SCI_19200);
	
	/*
	ASTCR = 0xff;
	WCR   = 0xf0;
	*/
	
	/* 開始メッセージ */
	Sci_PutChar('H');
	Sci_PutChar('O');
	Sci_PutChar('S');
	Sci_PutChar('\r');
	Sci_PutChar('\n');
	
	sta_hos();
	
	return 0;
}


/* 初期化ハンドラ */
void Initialize(VP_INT exinf)
{
	act_tsk(TSKID_SAMPLE1);
}


/* サンプルタスク */
void Task1(VP_INT exinf)
{
	SYSTIM st;
	
	for ( ; ; )
	{
		/* タイマ値取得 */
		get_tim(&st);
		
		/* タイマ値出力 */
		Sci_PutChar('0' + (st.ltime / 10000) % 10);
		Sci_PutChar('0' + (st.ltime / 1000) % 10);
		Sci_PutChar('0' + (st.ltime / 100) % 10);
		Sci_PutChar('0' + (st.ltime / 10) % 10);
		Sci_PutChar('0' + (st.ltime / 1) % 10);
		Sci_PutChar(':');
		
		/* タスクメッセージ */
		Sci_PutChar('T');
		Sci_PutChar('a');
		Sci_PutChar('s');
		Sci_PutChar('k');
		Sci_PutChar('1');
		Sci_PutChar('\r');
		Sci_PutChar('\n');
		
		/* 1秒待つ */
		dly_tsk(1000);
	}
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
