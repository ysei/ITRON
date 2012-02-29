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
    /*
     * タスクをキューイングしているので，
     * 登録した回数だけ，実行される
     */
	act_tsk(TSKID_SAMPLE1); /* 1回目 */
	act_tsk(TSKID_SAMPLE1); /* 2回目 */
	act_tsk(TSKID_SAMPLE1); /* 3回目 */
	act_tsk(TSKID_SAMPLE1); /* 4回目 */
	act_tsk(TSKID_SAMPLE1); /* 5回目 */
#endif
}


/* サンプルタスク */
int count = 1;

void Task1(VP_INT exinf)
{

    /* タスクメッセージ */
    Sci_PutChar('C');
    Sci_PutChar('o');
    Sci_PutChar('u');
    Sci_PutChar('n');
    Sci_PutChar('t');
    Sci_PutChar('0' + count);
    Sci_PutChar('\r');
    Sci_PutChar('\n');

    count++;

    ext_tsk();
}

static void Sci_PutChars( const char *str)
{
    const char *p = str;
    while (*p) Sci_PutChar(*p++);
}
void AlertTask(VP_INT exinf)
{
    for (;;) {
        slp_tsk();

        Sci_PutChars("STOP!\r\n");
    }
}
void MonitorTask(VP_INT exinf)
{
    int c;
    for (;;) {

        c = Sci_GetChar() | 0x20;

        switch (c) {
        case 'k':
        case 'i':
        case 'e':
        case 'n':
            wup_tsk(TSKID_ALERT);
            break;
        default:
            break;
        }
    }
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
