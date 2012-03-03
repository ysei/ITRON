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
#include <string.h>
#include "api.h"
#include "lib.h"

#define XON 0x11
#define XOFF 0x13


/* メイン関数 */
int main()
{
	
	sta_hos();
	
	return 0;
}


/* 初期化ハンドラ */
void Initialize(VP_INT exinf)
{
	/* SCIの初期化 */
	Sci_Initialize(exinf);
}

typedef struct {
    T_MSG pk_msg; /* OS管理領域 */
    int len;
    ID sender; /* 送信元タスクID */
    char buf[64];
} MESSAGE;

/* サンプルタスク */
void appli(VP_INT exinf)
{
    int result;
    while (1) {
        result = api_test(exinf);
        putdval(result,0);
    }
}
void driver(VP_INT exinf)
{

    char *ptr;
    char *limit;
    unsigned char c;
    MESSAGE *msg;
    T_MSG *pk_msg;

    while (1) {
        if (SCI1.SSR.BIT.RDRF) {
            c = SCI1.RDR;
            SCI1.SSR.BIT.RDRF = 0;
            while (c == XOFF) {
                while (!SCI1.SSR.BIT.RDRF);
                c = SCI1.RDR;
                SCI1.SSR.BIT.RDRF = 0;
                if (c == XON) break;
            }
        }
        rcv_mbx(MID_TEST,&pk_msg);
        msg = (MESSAGE *)pk_msg;

        ptr = msg->buf;
        limit = &msg->buf[msg->len];
        while (ptr < limit) {
            while (!SCI1.SSR.BIT.TDRE);
            SCI1.TDR = *ptr++;
            SCI1.SSR.BIT.TDRE = 0;
        }
        /* メモリブロック開放 */
        rel_mpf(MPID_TEST,(VP)msg);
    }
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
