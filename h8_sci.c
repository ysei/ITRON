/* ------------------------------------------------------------------------ */
/*  H8/3048用 SCI制御ライブラリ                                             */
/*                                                                          */
/*                                  Copyright (C) 1998-2002 by Project HOS  */
/*                                  http://sourceforge.jp/projects/hos/     */
/* ------------------------------------------------------------------------ */



#include "kernel.h"
//#include "h8_3048.h"
#include "h83069f.h"

#include "h8_sci.h"

#define RECV_BUFSIZE    32      /* 受信バッファのサイズ */

static unsigned char recv_buf[RECV_BUFSIZE];
static int head;
static int tail;

/* SCI初期化 */
void Sci_Initialize(unsigned char rate)
{
    volatile int v;
    int i;

    /* SCI初期化 */
    SCI1.SCR.BYTE = 0x00 ;  // TE, RE ビットクリアー

    SCI1.SMR.BYTE = 0x00 ;  // 0000 0000
                            // |||| ||||
                            // |||| ||++-- クロックФ
                            // |||| |+---- マルチプロセッサー禁止
                            // |||| +----- 1 Stop
                            // |||+------- Parity ( ODD ) Disable
                            // ||+-------- Parity 無し
                            // |+--------- Data Length 8 bit
                            // +---------- 調歩同期

    SCI1.BRR      = rate ;  // Bit rate の設定

    // １ビット期間待ち
    for ( i = 0; i < 280; i++ )
        v++;

    SCI1.SCR.BYTE = 0x70 ;  // 0111 0000
                            // |||| ||||
                            // |||| ||++--- 00:内部クロック
                            // |||| |+----- 0:送信割り込み禁止
                            // |||| +------ 0:マルチプロセッサ割り込み禁止状態
                            // |||+-------- 1:受信動作を許可
                            // ||+--------- 1:送信動作を許可
                            // |+---------- 1:受信データフル割り込み（RXI）要求
                            // +----------- 0:送信データエンプティ割り込み（TXI）要求の禁止


    /* 受信バッファ初期化 */
    head = 0;
    tail = 0;
}


/* １文字出力 */
void Sci_PutChar(char c)
{
    // 送信レジスターの空きを待つ
    while ( !( SCI1.SSR.BIT.TDRE == 1 ) ) {
        ;
    }

    SCI1.TDR = c;           // データを送信データレジスターにセットする。
    SCI1.SSR.BIT.TDRE = 0 ; // TDRE ビットをクリアーする。
                            // TDRE が 1→0 になるとシフトレジスターにデータを転送する。
}


/* １文字入力 */
int Sci_GetChar(void)
{
    unsigned char c ;

    if ( head == tail ) {
        return -1;
    }

    c = recv_buf[head++] ;
    if ( head >= RECV_BUFSIZE ) {
        head = 0 ;
    }

    return c ;
}


/* SCI受信割り込み */
// エラー処理は別途記述のこと。
void Sci_RxiHandler(VP_INT exinf)
{
    unsigned char c;
    int next;

    /* 1文字受信 */
    c = SCI1.RDR;           // 受信データレジスターより読み込み。
    SCI1.SSR.BIT.RDRF = 0 ;

    /* 次の末尾位置を計算 */
    next = tail + 1;
    if ( next >= RECV_BUFSIZE )
    {
        next = 0;
    }

    /* オーバーフローチェック */
    if ( next == head )
    {
        return;
    }

    /* 受信バッファに格納 */
    recv_buf[tail] = c;
    tail = next;
}

void Sci_PutChars( char *str)
{
    while( *str ) {
        Sci_PutChar( *str++ ) ;
    }
}

/* ------------------------------------------------------------------------ */
/*  Copyright (C) 1998-2002 by Project HOS                                  */
