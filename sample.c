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
#if 0
	act_tsk(TSKID_SAMPLE1);
#endif
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
		Sci_PutChar('0' + exinf);
		Sci_PutChar('\r');
		Sci_PutChar('\n');
		
		/*
         * 1秒待つ
         * 処理時間を考慮していないので，1秒周期とはならない
         */
		dly_tsk(1000);
	}
}

static void Sci_PutChars( const char *str)
{
    const char *p = str;
    while (*p) Sci_PutChar(*p++);
}
void NewTask(VP_INT exinf)
{
    for (;;) {
        Sci_PutChars("HOS - V4 by Project HOS!\r\n");
        dly_tsk(1000);
    }
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
