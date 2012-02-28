/* ------------------------------------------------------------------------ */
/*  H8/3048用 SCI制御ライブラリ                                             */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



#ifndef __PROJECT_HOS__h8_sci_h__
#define __PROJECT_HOS__h8_sci_h__



/* SCI通信速度定義 (16MHzのとき) */
#if 0
#define SCI_2400   207
#define SCI_4800   103
#define SCI_9600    51
#define SCI_19200   25
#define SCI_31250   15
#define SCI_38400   12
#define SCI_57600    8		/* 誤差 -3.5% ぎりぎりいけるかも (^^;; */
#else
#define SCI_9600    64
#define SCI_19200   32
#define SCI_31250   19
#define SCI_38400   15
#endif



/* SCI */
void Sci_Initialize(unsigned char rate);	/* SCI初期化 */
void Sci_PutChar(char c);					/* １文字出力 */
int  Sci_GetChar(void);						/* １文字入力 */
void Sci_RxiHandler(VP_INT exinf);			/* SCI受信割り込み */


#endif	/* __PROJECT_HOS__h8_sci_h__ */


/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
/* ------------------------------------------------------------------------ */
