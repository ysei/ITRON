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
    char count[9];
    char task_id[2];
    MESSAGE msg;
    ID this;

    memset(count,'0',sizeof(count));
    count[8] = task_id[1] = '\0';

    while (1) {
        if (++count[7] > '9') {
            count[7] = '0';
            if (++count[6] > '9') {
                count[6] = '0';
                if (++count[5] > '9') {
                    count[5] = '0';
                    if (++count[4] > '9') {
                        count[4] = '0';
                        if (++count[3] > '9') {
                            count[3] = '0';
                            if (++count[2] > '9') {
                                count[2] = '0';
                                if (++count[1] > '9') {
                                    count[1] = '0';
                                    if (++count[0] > '9') {
                                        count[0] = '0';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        strcpy(msg.buf,"This is test messages from Task");
        get_tid(&this);
        task_id[0] = this + '0';
        strcat(msg.buf,task_id);
        strcat(msg.buf,". count ");
        strcat(msg.buf,count);
        strcat(msg.buf,"\r\n");
        msg.len = strlen(msg.buf);
        msg.sender = this;

        snd_mbx(MID_TEST,(T_MSG *)&msg);

        slp_tsk();
    }
}
void driver(VP_INT exinf)
{

    char *ptr;
    char *limit;
    unsigned char c;
    MESSAGE *msg;

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
        rcv_mbx(MID_TEST,(T_MSG **)&msg);
        ptr = msg->buf;
        limit = &msg->buf[msg->len];
        while (ptr < limit) {
            while (!SCI1.SSR.BIT.TDRE);
            SCI1.TDR = *ptr++;
            SCI1.SSR.BIT.TDRE = 0;
        }
        wup_tsk(msg->sender);
    }
}


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
