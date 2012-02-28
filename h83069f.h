/* ------------------------------------------------------------------------- */
/*  H8/3069F 用 ヘッダファイル                                               */
/*  注意！EMCビットが１(初期値)でアドバンスドモードのメモリマップです。		 */
/*  全てのデバイスで検証をしている訳では無いので、使用にあたっては十分注意   */
/*  が必要です。                                                             */
/*  この辺が個人の限界と言う事で、バグ報告待ってます。                       */
/*                                                                           */
/*  日立統一ヘッダーファイル バージョン２との違い                            */
/*  日立のヘッダーファイルでは16bit長のフィールドは intで表しています。      */
/*  このヘッダーファイルもそれに倣おうかとも思いましたが、shortで表す事に    */
/*  しました。と言うのも SHなんかも結構 H8で作成したコーディングそのまま動   */
/*  いちゃう事が多いのですが(特に SCI等)、例えば ADはやはり10bitでその長さ   */
/*  は H8も SHも変わらず、レジスタは16bitでアクセスします。あっちは intで    */
/*  こっちは shortとなるのがイマイチ嫌なので、両方とも揃える為に shortで宣   */
/*  言しています。                                                           */
/*  また、日立コンパイラー バージョン３以上では問題とならないビットフィー    */
/*  ルドの省略ですが、秋月コンパイラ、つまり日立コンパイラ バージョン２の    */
/*  サブセットではコンパイルエラーとなるので、適当なフィールド名を充ててい   */
/*  ます。                                                                   */
/*                                                                           */
/*                                   Copyright (C) 1998-2002 by Project HOS  */
/* ------------------------------------------------------------------------- */


#ifndef __PROJECT_HOS__H8_3069_H_
#define __PROJECT_HOS__H8_3069_H_

/* IO デバイスアドレス定義 */
#define	P1DDR	(*(volatile unsigned char *)0xfee000)	/* PORT1データディレクションレジスタ */
#define	P2DDR	(*(volatile unsigned char *)0xfee001)	/* PORT2データディレクションレジスタ */
#define	P3DDR	(*(volatile unsigned char *)0xfee002)	/* PORT3データディレクションレジスタ */
#define	P4DDR	(*(volatile unsigned char *)0xfee003)	/* PORT4データディレクションレジスタ */
#define	P5DDR	(*(volatile unsigned char *)0xfee004)	/* PORT5データディレクションレジスタ */
#define	P6DDR	(*(volatile unsigned char *)0xfee005)	/* PORT6データディレクションレジスタ */
#define	P8DDR	(*(volatile unsigned char *)0xfee007)	/* PORT8データディレクションレジスタ */
#define	P9DDR	(*(volatile unsigned char *)0xfee008)	/* PORT9データディレクションレジスタ */
#define	PADDR	(*(volatile unsigned char *)0xfee009)	/* PORT Aデータディレクションレジスタ */
#define	PBDDR	(*(volatile unsigned char *)0xfee00a)	/* PORT Bデータディレクションレジスタ */

#define	__MDCR_ADD__	0xfee011	/* MDCRレジスタスタートアドレス */
#define	__SYSCR_ADD__	0xfee012	/* SYSCRレジスタスタートアドレス */

#define	__BSC_ADD__		0xfee012	/* BSCレジスタスタートアドレス */

#define	__INTC_ADD__	0xfee014	/* INTCレジスタスタートアドレス */

#define	__DASTCR_ADD__	0xfee01a	/* DAスタンバイコントロールレジスタ */

#define	__DIVCR_ADD__	0xfee01b	/* DIVCRレジスタスタートアドレス */
#define	__MSTCR_ADD__	0xfee01c	/* MSTCRレジスタスタートアドレス */


#define	__P2PCR_ADD__	0xfee03c	/* PORT2レジスタスタートアドレス */
#define	__P4PCR_ADD__	0xfee03e	/* PORT4レジスタスタートアドレス */
#define	__P5PCR_ADD__	0xfee03f	/* PORT5レジスタスタートアドレス */

#define	__FLASH_ADD__	0xfee076	/* FLASHレジスタスタートアドレス */

#define	__DMAC0A_ADD__	0xffff20	/* DMAC0Aレジスタスタートアドレス */
#define	__DMAC0B_ADD__	0xffff28	/* DMAC0Bレジスタスタートアドレス */
#define	__DMAC1A_ADD__	0xffff30	/* DMAC1Aレジスタスタートアドレス */
#define	__DMAC1B_ADD__	0xffff38	/* DMAC1Bレジスタスタートアドレス */
#define	__DMAC0_ADD__	0xffff20	/* DMAC0レジスタスタートアドレス */
#define	__DMAC1_ADD__	0xffff30	/* DMAC1レジスタスタートアドレス */

#define	__ITU_COMM_ADD__	0xffff60	/* ITU共通レジスタスタートアドレス */
#define	__ITU0_ADD__	0xffff68	/* ITU0レジスタスタートアドレス */
#define	__ITU1_ADD__	0xffff70	/* ITU1レジスタスタートアドレス */
#define	__ITU2_ADD__	0xffff78	/* ITU2レジスタスタートアドレス */

#define	__TMR01_ADD__	0xffff80	/* 8bit タイマー01、レジスタスタートアドレス */
#define	__TMR23_ADD__	0xffff90	/* 8bit タイマー23、レジスタスタートアドレス */

#define	__TMR0_ADD__	0xffff80	/* 8bit タイマー0、レジスタスタートアドレス */
#define	__TMR1_ADD__	0xffff81	/* 8bit タイマー1、レジスタスタートアドレス */
#define	__TMR2_ADD__	0xffff90	/* 8bit タイマー2、レジスタスタートアドレス */
#define	__TMR3_ADD__	0xffff91	/* 8bit タイマー3、レジスタスタートアドレス */

#define	__WDT_ADD__		0xffff8c	/* WDTレジスタスタートアドレス */
	
#define	__DA_ADD__		0xffff9c	/* DAレジスタスタートアドレス */

#define	__TPC_ADD__		0xffffa0	/* TPCレジスタスタートアドレス */

#define	__SCI0_ADD__	0xffffb0	/* SCI0レジスタスタートアドレス */
#define	__SCI1_ADD__	0xffffb8	/* SCI1レジスタスタートアドレス */
#define	__SCI2_ADD__	0xffffc0	/* SCI2レジスタスタートアドレス */
#define	__SMCI0_ADD__	0xffffb0	/* SCIM0レジスタスタートアドレス */
#define	__SMCI1_ADD__	0xffffb8	/* SCIM1レジスタスタートアドレス */
#define	__SMCI2_ADD__	0xffffc0	/* SCIM2レジスタスタートアドレス */

#define	__P1DR_ADD__	0xffffd0	/* PORT1レジスタスタートアドレス */
#define	__P2DR_ADD__	0xffffd1	/* PORT2レジスタスタートアドレス */
#define	__P3DR_ADD__	0xffffd2	/* PORT3レジスタスタートアドレス */
#define	__P4DR_ADD__	0xffffd3	/* PORT4レジスタスタートアドレス */
#define	__P5DR_ADD__	0xffffd4	/* PORT5レジスタスタートアドレス */
#define	__P6DR_ADD__	0xffffd5	/* PORT6レジスタスタートアドレス */
#define	__P7DR_ADD__	0xffffd6	/* PORT7レジスタスタートアドレス */
#define	__P8DR_ADD__	0xffffd7	/* PORT8レジスタスタートアドレス */
#define	__P9DR_ADD__	0xffffd8	/* PORT9レジスタスタートアドレス */
#define	__PADR_ADD__	0xffffd9	/* PORT Aレジスタスタートアドレス */
#define	__PBDR_ADD__	0xffffda	/* PORT Bレジスタスタートアドレス */

#define	__AD_ADD__		0xffffe0	/* ADレジスタスタートアドレス */

/* IOポート */
/*DDRレジスタ、DRレジスタは共通で利用できる*/
union __IO_PORT_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char B7:1;			/*bit7*/
		unsigned char B6:1;			/*bit6*/
		unsigned char B5:1;			/*bit5*/
		unsigned char B4:1;			/*bit4*/
		unsigned char B3:1;			/*bit3*/
		unsigned char B2:1;			/*bit2*/
		unsigned char B1:1;			/*bit1*/
		unsigned char B0:1;			/*bit0*/
	} BIT;
};
#define	P1DR	(*(volatile union __IO_PORT_REG__ *)__P1DR_ADD__)
#define	P2PCR	(*(volatile union __IO_PORT_REG__ *)__P2PCR_ADD__)
#define	P2DR	(*(volatile union __IO_PORT_REG__ *)__P2DR_ADD__)
#define	P3DR	(*(volatile union __IO_PORT_REG__ *)__P3DR_ADD__)
#define	P4PCR	(*(volatile union __IO_PORT_REG__ *)__P4PCR_ADD__)
#define	P4DR	(*(volatile union __IO_PORT_REG__ *)__P4DR_ADD__)
#define	P6DR	(*(volatile union __IO_PORT_REG__ *)__P6DR_ADD__)
#define	P7DR	(*(volatile union __IO_PORT_REG__ *)__P7DR_ADD__)
#define	PADR	(*(volatile union __IO_PORT_REG__ *)__PADR_ADD__)
#define	PBDR	(*(volatile union __IO_PORT_REG__ *)__PBDR_ADD__)

union __IO_PORT_5_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:4;		/*該当bit無し*/
		unsigned char B3:1;			/*bit3*/
		unsigned char B2:1;			/*bit2*/
		unsigned char B1:1;			/*bit1*/
		unsigned char B0:1;			/*bit0*/
	} BIT;
};
#define	P5PCR	(*(volatile union __IO_PORT_5_REG__ *)__P5PCR_ADD__)
#define	P5DR	(*(volatile union __IO_PORT_5_REG__ *)__P5DR_ADD__)

union __IO_PORT_8_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:3;		/*該当bit無し*/
		unsigned char B4:1;			/*bit4*/
		unsigned char B3:1;			/*bit3*/
		unsigned char B2:1;			/*bit2*/
		unsigned char B1:1;			/*bit1*/
		unsigned char B0:1;			/*bit0*/
	} BIT;
};
#define	P8DR	(*(volatile union __IO_PORT_8_REG__ *)__P8DR_ADD__)

union __IO_PORT_9_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:2;		/*該当bit無し*/
		unsigned char B5:1;			/*bit5*/
		unsigned char B4:1;			/*bit4*/
		unsigned char B3:1;			/*bit3*/
		unsigned char B2:1;			/*bit2*/
		unsigned char B1:1;			/*bit1*/
		unsigned char B0:1;			/*bit0*/
	} BIT;
};
#define	P9DR	(*(volatile union __IO_PORT_9_REG__ *)__P9DR_ADD__)


/* モードコントロールレジスタ */
union __MDCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:5;		/*予約*/
		unsigned char MDS:3;		/*モードセレクト*/
	} BIT;
};
#define	MDCR	(*(volatile union __MDCR_REG__ *)__MDCR_ADD__)	/* ビットフィールド用 */

/* システムコントローラー */
union __SYSCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char SSBY:1;		/*ソフトウエアスタンバイ*/
		unsigned char STS:3;		/*スタンバイタイマセレクタ*/
		unsigned char UE:1;			/*ユーザービットイネーブル*/
		unsigned char NMIEG:1;		/*NMIエッジセレクト*/
		unsigned char SSOE:1;		/*ソフトウエアスタンバイ出力ポートイネーブル*/
		unsigned char RAME:1;		/*RAMイネーブル*/
	} BIT;
};
#define	SYSCR	(*(volatile union __SYSCR_REG__ *)__SYSCR_ADD__)	/* ビットフィールド用 */

union __DIVCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:6;		/*予約*/
		unsigned char DIV:2;		/*分周比*/
	} BIT;
};
#define	DIVCR	(*(volatile struct __DIVCR_REG__ *)__DIVCR_ADD__)	/* ビットフィールド用 */

union __MSTCR_REG__
{
	unsigned short WORD;			/*Word Access*/
	struct							/*Byte Access*/
	{
		unsigned char H;			/*上位*/
		unsigned char L;			/*下位*/
	} BYTE;
	struct
	{
		unsigned char PSTOP:1;		/*システムクロックの出力をストップ*/
		unsigned char rsv1:4;		/*予約*/
		unsigned char _SCI2:1;		/*SCI2 モジュールスタンバイ*/
		unsigned char _SCI1:1;		/*SCI1 モジュールスタンバイ*/
		unsigned char _SCI0:1;		/*SCI0 モジュールスタンバイ*/
		unsigned char _DMAC:1;		/*DMAC モジュールスタンバイ*/
		unsigned char rsv2:1;		/*予約*/
		unsigned char _DRAM:1;		/*DRAM モジュールスタンバイ*/
		unsigned char _ITU:1;		/*ITU モジュールスタンバイ*/
		unsigned char _TMR01:1;		/*TMR01 モジュールスタンバイ*/
		unsigned char _TMR23:1;		/*TMR23 モジュールスタンバイ*/
		unsigned char rsv3:1;		/*予約*/
		unsigned char _AD:1;		/*AD モジュールスタンバイ*/
	} BIT;
};
#define	MSTCR	(*(volatile union __MSTCR_REG__ *)__MSTCR_ADD__)	/* ビットフィールド用 */

/* バスコントローラー */
struct __BSC_REG__
{
	char	rsv1;						/*アライメント調整*/
	union								/*BRCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char A23E:1;		/*アドレス23 イネーブル*/
			unsigned char A22E:1;		/*アドレス22 イネーブル*/
			unsigned char A21E:1;		/*アドレス21 イネーブル*/
			unsigned char A20E:1;		/*アドレス20 イネーブル*/
			unsigned char rsv1:3;		/*予約*/
			unsigned char BRLE:1;		/*バスリリースイネーブル*/
		} BIT;
	} BRCR;
	char	rsv2[ 0xfee01e - 0xfee013 - 1 ];	/*空き*/
	union								/*CSCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:6;		/*予約*/
			unsigned char ADRCTL:1;		/*アドレスコントロールビット*/
		} BIT;
	} ADRCR;
	union								/*CSCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CS7E:1;		/*チップセレクトイネーブル 7*/
			unsigned char CS6E:1;		/*チップセレクトイネーブル 6*/
			unsigned char CS5E:1;		/*チップセレクトイネーブル 5*/
			unsigned char CS4E:1;		/*チップセレクトイネーブル 4*/
			unsigned char rsv1:4;		/*予約*/
		} BIT;
	} CSCR;
	union								/*ABWCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char ABW7:1;		/*エリア バス幅 コントロール 7*/
			unsigned char ABW6:1;		/*エリア バス幅 コントロール 6*/
			unsigned char ABW5:1;		/*エリア バス幅 コントロール 5*/
			unsigned char ABW4:1;		/*エリア バス幅 コントロール 4*/
			unsigned char ABW3:1;		/*エリア バス幅 コントロール 3*/
			unsigned char ABW2:1;		/*エリア バス幅 コントロール 2*/
			unsigned char ABW1:1;		/*エリア バス幅 コントロール 2*/
			unsigned char ABW0:1;		/*エリア バス幅 コントロール 0*/
		} BIT;
	} ABWCR;
	union								/*ASTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char AST7:1;		/*アクセスステートコントロールレジスタ 7*/
			unsigned char AST6:1;		/*アクセスステートコントロールレジスタ 6*/
			unsigned char AST5:1;		/*アクセスステートコントロールレジスタ 5*/
			unsigned char AST4:1;		/*アクセスステートコントロールレジスタ 4*/
			unsigned char AST3:1;		/*アクセスステートコントロールレジスタ 3*/
			unsigned char AST2:1;		/*アクセスステートコントロールレジスタ 2*/
			unsigned char AST1:1;		/*アクセスステートコントロールレジスタ 2*/
			unsigned char AST0:1;		/*アクセスステートコントロールレジスタ 0*/
		} BIT;
	} ASTCR;
	union								/*WCRレジスタ*/
	{
		unsigned short WORD;			/*Word Access*/
		struct
		{
			unsigned char	H;
			unsigned char	L;
		} BYTE;
		struct							/*Bit Access*/
		{
			unsigned short W7:2;		/*ウエイトモードセレクト*/
			unsigned short W6:2;		/*ウエイトモードセレクト*/
			unsigned short W5:2;		/*ウエイトモードセレクト*/
			unsigned short W4:2;		/*ウエイトモードセレクト*/
			unsigned short W3:2;		/*ウエイトモードセレクト*/
			unsigned short W2:2;		/*ウエイトモードセレクト*/
			unsigned short W1:2;		/*ウエイトモードセレクト*/
			unsigned short W0:2;		/*ウエイトモードセレクト*/
		} BIT;
	} WCR;
	union								/*BCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char ICIS1:1;		/*アイドルサイクル挿入 1*/
			unsigned char ICIS0:1;		/*アイドルサイクル挿入 0*/
			unsigned char BROME:1;		/*バーストROMイネーブル*/
			unsigned char BRSTS1:1;		/*バーストサイクルセレクト*/
			unsigned char BRSTS0:1;		/*バーストサイクルセレクト*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char RDEA:1;		/*エリア分割単位*/
			unsigned char WAITE:1;		/*端子 WAIT入力禁止/許可*/
		} BIT;
	} BCR;
	char	rsv3;
	union								/*DRCRAレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DRAS:3;		/*DRAMエリアセレクト*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char BE:1;			/*バーストアクセスイネーブル*/
			unsigned char RDM:1;		/*RASダウンモード*/
			unsigned char SRFMD:1;		/*セルフリフレッシュモード*/
			unsigned char RFSHE:1;		/*リフレッシュ端子イネーブル*/
		} BIT;
	} DRCRA;
	union								/*DRCRBレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char MXC:2;		/*マルチプレックスコントロール*/
			unsigned char CSEL:1;		/* CAS出力端子選択*/
			unsigned char RCYCE:1;		/*リフレッシュサイクルイネーブル*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char _TPC:1;		/* TPサイクルコントロール*/
			unsigned char RCW:1;		/* RAS CAS間 WAIT*/
			unsigned char RLW:1;		/*リフレッシュサイクル WAITコントロール*/
		} BIT;
	} DRCRB;
	union								/*RTMCSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CMF:1;		/*コンペアマッチフラグ*/
			unsigned char CMIE:1;		/*コンペアマッチ割込みイネーブル*/
			unsigned char CKS:3;		/*リフレッシュカウンタクロックセレクト*/
			unsigned char rsv1:3;		/*予約*/
		} BIT;
	} RTMCSR;
	unsigned char	RTCNT;				/*リフレッシュタイマカウンタ*/
	unsigned char	RTCOR;				/*リフレッシュタイムコンスタントレジスタ*/
};
#define	BSC		(*(volatile struct __BSC_REG__ *)__BSC_ADD__)	/* ビットフィールド用 */


/* 割込みコントローラー */
struct __INTC_REG__
{
	union								/*ISCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*予約*/
			unsigned char IRQ5SC:1;		/*IRQセンスコントロール 5*/
			unsigned char IRQ4SC:1;		/*IRQセンスコントロール 4*/
			unsigned char IRQ3SC:1;		/*IRQセンスコントロール 3*/
			unsigned char IRQ2SC:1;		/*IRQセンスコントロール 2*/
			unsigned char IRQ1SC:1;		/*IRQセンスコントロール 1*/
			unsigned char IRQ0SC:1;		/*IRQセンスコントロール 0*/
		} BIT;
	} ISCR;
	union								/*IERレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*予約*/
			unsigned char IRQ5E:1;		/*IRQイネーブルレジスタ 5*/
			unsigned char IRQ4E:1;		/*IRQイネーブルレジスタ 4*/
			unsigned char IRQ3E:1;		/*IRQイネーブルレジスタ 3*/
			unsigned char IRQ2E:1;		/*IRQイネーブルレジスタ 2*/
			unsigned char IRQ1E:1;		/*IRQイネーブルレジスタ 1*/
			unsigned char IRQ0E:1;		/*IRQイネーブルレジスタ 0*/
		} BIT;
	} IER;
	union
	{								/*ISRレジスタ*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*予約*/
			unsigned char IRQ5F:1;		/*IRQステータスレジスタ 5*/
			unsigned char IRQ4F:1;		/*IRQステータスレジスタ 4*/
			unsigned char IRQ3F:1;		/*IRQステータスレジスタ 3*/
			unsigned char IRQ2F:1;		/*IRQステータスレジスタ 2*/
			unsigned char IRQ1F:1;		/*IRQステータスレジスタ 1*/
			unsigned char IRQ0F:1;		/*IRQステータスレジスタ 0*/
		} BIT;
	} ISR;
	char	rsv1;						/*空き*/
	union								/*IPRAレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char _IRQ0:1;		/*IREQ0 割込みのプライオリティレベル設定*/
			unsigned char _IRQ1:1;		/*IREQ1 割込みのプライオリティレベル設定*/
			unsigned char _IRQ23:1;		/*IREQ23 割込みのプライオリティレベル設定*/
			unsigned char _IRQ45:1;		/*IREQ45 割込みのプライオリティレベル設定*/
			unsigned char _WDT:1;		/*WDT、リフレッシュコントロラーの割込みのプライオリティレベル設定*/
			unsigned char _ITU0:1;		/*ITU0 割込みのプライオリティレベル設定*/
			unsigned char _ITU1:1;		/*ITU1 割込みのプライオリティレベル設定*/
			unsigned char _ITU2:1;		/*ITU2 割込みのプライオリティレベル設定*/
		} BIT;
	} IPRA;
	union
	{								/*IPRBレジスタ*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char _TMR01:1;		/* 8bitタイマー、チャネル0,1 割込みのプライオリティレベル設定*/
			unsigned char _TMR23:1;		/* 8bitタイマー、チャネル2,3 割込みのプライオリティレベル設定*/
			unsigned char _DMAC:1;		/*DMAC0、1 割込みのプライオリティレベル設定*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char _SCI0:1;		/*SCI0 割込みのプライオリティレベル設定*/
			unsigned char _SCI1:1;		/*SCI1 割込みのプライオリティレベル設定*/
			unsigned char _SCI2:1;		/*SCI2 割込みのプライオリティレベル設定*/
			unsigned char rsv2:1;		/*予約*/
		} BIT;
	} IPRB;
};
#define	INTC	(*(volatile struct __INTC_REG__ *)__INTC_ADD__)	/* ビットフィールド用 */

/* DMAコントローラー */
/* ショートアドレス */
struct __DMAC_SHORT_REG__
{
	void	*MAR;						/*メモリアドレスレジスタ*/
	unsigned short	ETCR;				/*転送カウントレジスタ*/
	unsigned char	IOAR;				/*I/O アドレスレジスタ*/
	union								/*DTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTE:1;		/*データトランスファイネーブル*/
			unsigned char DTSZ:1;		/*データトランスファサイズ*/
			unsigned char DTID:1;		/*データトランスファインクリメント/デクリメント*/
			unsigned char RPE:1;		/*リピートイネーブル*/
			unsigned char DTIE:1;		/*データトランスファインタラプトイネーブル*/
			unsigned char DTS:3;		/*データトランスファセレクト*/
		} BIT;
	} DTCR;
};
/* フルアドレス */
struct __DMAC_FULL_REG__
{
	void	*MARA;						/*メモリアドレスレジスタ*/
	unsigned short	ETCRA;				/*転送カウントレジスタ*/
	char	rsv1;						/*空き*/
	union								/*DTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTE:1;		/*データトランスファイネーブル*/
			unsigned char DTSZ:1;		/*データトランスファサイズ*/
			unsigned char SAID:1;		/*ソースアドレスインクリメント/デクリメント*/
			unsigned char SAIDE:1;		/*ソースアドレスインクリメント/デクリメントイネーブル*/
			unsigned char DTIE:1;		/*データトランスファインタラプトイネーブル*/
			unsigned char DTS:3;		/*データトランスファセレクト*/
		} BIT;
	} DTCRA;
	void	*MARB;						/*メモリアドレスレジスタ*/
	unsigned short	ETCRB;				/*転送カウントレジスタ*/
	char	rsv2;						/*空き*/
	union								/*DTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTME:1;		/*データトランスファマスタイネーブル*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char DAID:1;		/*ディスティネーションアドレスインクリメント/デクリメント*/
			unsigned char DAIDE:1;		/*ディスティネーションアドレスインクリメント/デクリメントイネーブル*/
			unsigned char TMS:1;		/*トランスファモードセレクト*/
			unsigned char DTS:3;		/*データトランスファセレクト*/
		} BIT;
	} DTCRB;
};
#define	DMAC0A	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC0A_ADD__)	/* ビットフィールド用 */
#define	DMAC0B	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC0B_ADD__)	/* ビットフィールド用 */
#define	DMAC1A	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC1A_ADD__)	/* ビットフィールド用 */
#define	DMAC1B	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC1B_ADD__)	/* ビットフィールド用 */
#define	DMAC0	(*(volatile struct __DMAC_FULL_REG__ *)__DMAC0_ADD__)	/* ビットフィールド用 */
#define	DMAC1	(*(volatile struct __DMAC_FULL_REG__ *)__DMAC1_ADD__)	/* ビットフィールド用 */



/* ITU */
/*ITU共通レジスタ*/
struct __ITU_COMMON_REG__
{
	union								/*TSTRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*未使用*/
			unsigned char STR2:1;		/*カウンタスタート 2*/
			unsigned char STR1:1;		/*カウンタスタート 1*/
			unsigned char STR0:1;		/*カウンタスタート 0*/
		} BIT;
	} TSTR;
	union								/*TSNCレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*未使用*/
			unsigned char SYNC2:1;		/*タイマ同期 2*/
			unsigned char SYNC1:1;		/*タイマ同期 1*/
			unsigned char SYNC0:1;		/*タイマ同期 0*/
		} BIT;
	} TSNC;
	union								/*TMDRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char MDF:1;		/*位相係数モード*/
			unsigned char FDIR:1;		/*フラグディレクション*/
			unsigned char rsv2:2;		/*未使用*/
			unsigned char PWM2:1;		/*PWMモード 2*/
			unsigned char PWM1:1;		/*PWMモード 1*/
			unsigned char PWM0:1;		/*PWMモード 0*/
		} BIT;
	} TMDR;
	union
	{									/*TOLR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char rsv1:2;		/*未使用*/
			unsigned char TOB2:1;		/*TOB2*/
			unsigned char TOA2:1;		/*TOA2*/
			unsigned char TOB1:1;		/*TOB1*/
			unsigned char TOA1:1;		/*TOA1*/
			unsigned char TOB0:1;		/*TOB0*/
			unsigned char TOA0:1;		/*TOA0*/
		} BIT;
	} TOLR;
	union
	{									/*TISRA*/
		unsigned char BYTE;				/*Byte Access*/
		struct							/*Bit  Access*/
		{
			unsigned char rsv1:1;		/*予約*/
			unsigned char IMIEA2:1;		/*IMIEA2*/
			unsigned char IMIEA1:1;		/*IMIEA2*/
			unsigned char IMIEA0:1;		/*IMIEA2*/
			unsigned char rsv2:1;  		/*予約*/
			unsigned char IMFA2 :1;		/*IMFA2*/
			unsigned char IMFA1 :1;		/*IMFA1*/
			unsigned char IMFA0 :1;		/*IMFA0*/
		} BIT;
	} TISRA;
	union								/* TISRB */
	{
		unsigned char BYTE;                 /*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*予約*/
			unsigned char IMIEB2:1;		/*IMIEB2*/
			unsigned char IMIEB1:1;		/*IMIEB2*/
			unsigned char IMIEB0:1;		/*IMIEB2*/
			unsigned char rsv2:1;		/*予約*/
			unsigned char IMFB2 :1;		/*IMFB2 */
			unsigned char IMFB1 :1;		/*IMFB1 */
			unsigned char IMFB0 :1;		/*IMFB0 */
		} BIT;
	} TISRB;
	union								/* TISRC */
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*予約*/
			unsigned char OVIE2:1;		/*OVIE2*/
			unsigned char OVIE1:1;		/*OVIE2*/
			unsigned char OVIE0:1;		/*OVIE2*/
			unsigned char rsv2:1;		/*予約*/
			unsigned char OVF2 :1;		/*OVF2 */
			unsigned char OVF1 :1;		/*OVF1 */
			unsigned char OVF0 :1;		/*OVF0 */
		} BIT;
	} TISRC;
};

#define	ITU		(*(volatile struct __ITU_COMMON_REG__ *)__ITU_COMM_ADD__)	/* ビットフィールド用 */

/*ITU個別レジスタ*/
struct __ITU_TYPE0_REG__
{
	union								/*TCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char CCLR:2;		/*カウンタクリア*/
			unsigned char CKEG:2;		/*クロックエッジ*/
			unsigned char TPSC:3;		/*タイマプリスケーラ*/
		} BIT;
	} TCR;
	union								/*TIORレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char IOB:3;		/*I/O コントロール*/
			unsigned char rsv2:1;		/*未使用*/
			unsigned char IOA:3;		/*I/O コントロール*/
		} BIT;
	} TIOR;
	unsigned short	TCNT;				/*16bit タイマカウンタ*/
	unsigned short	GRA;				/*ジェネラルレジスタ A*/
	unsigned short	GRB;				/*ジェネラルレジスタ B*/
};

#define	ITU0	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU0_ADD__)	/* ビットフィールド用 */
#define	ITU1	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU1_ADD__)	/* ビットフィールド用 */
#define	ITU2	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU2_ADD__)	/* ビットフィールド用 */


/*TMR01レジスタ*/
struct __TMR01_REG__
{
	union
	{									/*TCR0*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMIEB:1;		/*CMIEB*/
			unsigned char CMIEA:1;		/*CMIEA*/
			unsigned char OVIE :1;		/*OVIE */
			unsigned char CCLR :2;		/*CCLR */
			unsigned char CKS  :3;		/*CKS  */
		} BIT;
	} TCR0;
	union
	{									/* TCR1 */
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMIEB:1;		/*CMIEB*/
			unsigned char CMIEA:1;		/*CMIEA*/
			unsigned char OVIE :1;		/*OVIE */
			unsigned char CCLR :2;		/*CCLR */
			unsigned char CKS  :3;		/*CKS  */
		} BIT;
	} TCR1;
	union
	{									/* TCSR0   */
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMFB:1;		/*CMFB */
			unsigned char CMFA:1;		/*CMFA */
			unsigned char OVF :1;		/*OVF  */
			unsigned char ADTE:1;		/*ADTE */
			unsigned char OS  :4;		/*OS   */
		} BIT;
	} TCSR0;
	union
	{									/* TCSR1   */
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMFB:1;		/*CMFB*/
			unsigned char CMFA:1;		/*CMFA*/
			unsigned char OVF :1;		/*OVF*/
			unsigned char ICE :1;		/*ICE*/
			unsigned char OS  :4;		/*OS*/
		} BIT;
	} TCSR1;
	 unsigned short		TCORA;			/*TCORA*/
	 unsigned short		TCORB;			/*TCORB*/
	 unsigned short		TCNT;			/*TCNT*/
};
#define	TMR01	(*(volatile struct __TMR01_REG__ *)__TMR01_ADD__)	/* ビットフィールド用 */

/*TMR23レジスタ*/
struct __TMR23_REG__
{
	union
	{									/*TCR2*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMIEB:1;		/*CMIEB*/
			unsigned char CMIEA:1;		/*CMIEA*/
			unsigned char OVIE :1;		/*OVIE */
			unsigned char CCLR :2;		/*CCLR */
			unsigned char CKS  :3;		/*CKS  */
		} BIT;
	} TCR2;
	union
	{									/* TCR3 */
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMIEB:1;		/*CMIEB*/
			unsigned char CMIEA:1;		/*CMIEA*/
			unsigned char OVIE :1;		/*OVIE */
			unsigned char CCLR :2;		/*CCLR */
			unsigned char CKS  :3;		/*CKS  */
		} BIT;
	} TCR3;
	union
	{									/* TCSR0   */
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMFB:1;		/*CMFB */
			unsigned char CMFA:1;		/*CMFA */
			unsigned char OVF :1;		/*OVF  */
			unsigned char rsv1:1;		/*空き*/
			unsigned char OS  :4;		/*OS   */
		} BIT;
	} TCSR2;
	union
	{									/* TCSR1   */
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMFB:1;		/*CMFB*/
			unsigned char CMFA:1;		/*CMFA*/
			unsigned char OVF :1;		/*OVF*/
			unsigned char ICE :1;		/*ICE*/
			unsigned char OS  :4;		/*OS*/
		} BIT;
	} TCSR3;
	 unsigned short		TCORA;			/*TCORA*/
	 unsigned short		TCORB;			/*TCORB*/
	 unsigned short		TCNT;			/*TCNT*/
};
#define	TMR23	(*(volatile struct __TMR23_REG__ *)__TMR23_ADD__)	/* ビットフィールド用 */


/*TMR0レジスタ*/
struct __TMR0_REG__
{
	union
	{									/*TCR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMIEB:1;		/*CMIEB*/
			unsigned char CMIEA:1;		/*CMIEA*/
			unsigned char OVIE :1;		/*OVIE*/
			unsigned char CCLR :2;		/*CCLR*/
			unsigned char CKS  :3;		/*CKS*/
		} BIT;
	} TCR;
	char rsv1;							/**/
	union
	{									/*TCSR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*BitAccess*/
			unsigned char CMFB:1;		/*CMFB*/
			unsigned char CMFA:1;		/*CMFA*/
			unsigned char OVF :1;		/*OVF*/
			unsigned char ADTE:1;		/*ADTE*/
			unsigned char OS:4;			/*OS*/
		} BIT;
	} TCSR;
	char rsv2;
	unsigned char	TCORA;				/*TCORA*/
	char rsv3;							/**/
	unsigned char	TCORB;				/*TCORB*/
	char rsv4;							/**/
	unsigned char	TCNT;				/*TCNT*/
};
#define	TMR0	(*(volatile struct __TMR0_REG__ *)__TMR0_ADD__)	/* ビットフィールド用 */

/*TMR1レジスタ*/
struct __TMR1_REG__
{
	union
	{									/*TCR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMIEB:1;		/*CMIEB*/
			unsigned char CMIEA:1;		/*CMIEA*/
			unsigned char OVIE :1;		/*OVIE*/
			unsigned char CCLR :2;		/*CCLR*/
			unsigned char CKS  :3;		/*CKS*/
		} BIT;
	} TCR;
	char rsv1;							/**/
	union
	{									/*TCSR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*BitAccess*/
			unsigned char CMFB:1;		/*CMFB*/
			unsigned char CMFA:1;		/*CMFA*/
			unsigned char OVF :1;		/*OVF*/
			unsigned char ICE:1;		/*ICE*/
			unsigned char OS:4;			/*OS*/
		} BIT;
	} TCSR;
	char rsv2;
	unsigned char	TCORA;				/*TCORA*/
	char rsv3;							/**/
	unsigned char	TCORB;				/*TCORB*/
	char rsv4;							/**/
	unsigned char	TCNT;				/*TCNT*/
};
#define	TMR1	(*(volatile struct __TMR1_REG__ *)__TMR1_ADD__)	/* ビットフィールド用 */
#define	TMR3	(*(volatile struct __TMR1_REG__ *)__TMR3_ADD__)	/* ビットフィールド用 */

/*TMR2レジスタ*/
struct __TMR2_REG__
{
	union
	{									/*TCR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char CMIEB:1;		/*CMIEB*/
			unsigned char CMIEA:1;		/*CMIEA*/
			unsigned char OVIE :1;		/*OVIE*/
			unsigned char CCLR :2;		/*CCLR*/
			unsigned char CKS  :3;		/*CKS*/
		} BIT;
	} TCR;
	char rsv1;							/**/
	union
	{									/*TCSR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*BitAccess*/
			unsigned char CMFB:1;		/*CMFB*/
			unsigned char CMFA:1;		/*CMFA*/
			unsigned char OVF :1;		/*OVF*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char OS:4;			/*OS*/
		} BIT;
	} TCSR;
	char rsv2;
	unsigned char	TCORA;				/*TCORA*/
	char rsv3;							/**/
	unsigned char	TCORB;				/*TCORB*/
	char rsv4;							/**/
	unsigned char	TCNT;				/*TCNT*/
};
#define	TMR2	(*(volatile struct __TMR2_REG__ *)__TMR2_ADD__)	/* ビットフィールド用 */


/*プログラマブルタイミングパターンコントローラー*/
struct __TPC_REG__
{
	union								/*TPMRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*未使用*/
			unsigned char G3NOV:1;		/*グループ 3 ノンオーバーラップ*/
			unsigned char G2NOV:1;		/*グループ 2 ノンオーバーラップ*/
			unsigned char G1NOV:1;		/*グループ 1 ノンオーバーラップ*/
			unsigned char G0NOV:1;		/*グループ 0 ノンオーバーラップ*/
		} BIT;
	} TPMR;
	union								/*TPCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char G3CMS:2;		/*グループ 3 コンペアマッチセレクト*/
			unsigned char G2CMS:2;		/*グループ 2 コンペアマッチセレクト*/
			unsigned char G1CMS:2;		/*グループ 1 コンペアマッチセレクト*/
			unsigned char G0CMS:2;		/*グループ 0 コンペアマッチセレクト*/
		} BIT;
	} TPCR;
	union								/*NDERBレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B15:1;		/*bit 15*/
			unsigned char B14:1;		/*bit 14*/
			unsigned char B13:1;		/*bit 13*/
			unsigned char B12:1;		/*bit 12*/
			unsigned char B11:1;		/*bit 11*/
			unsigned char B10:1;		/*bit 10*/
			unsigned char B9:1;			/*bit 9*/
			unsigned char B8:1;			/*bit 8*/
		} BIT;
	} NDERB;
	union								/*NDERAレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit 7*/
			unsigned char B6:1;			/*bit 6*/
			unsigned char B5:1;			/*bit 5*/
			unsigned char B4:1;			/*bit 4*/
			unsigned char B3:1;			/*bit 3*/
			unsigned char B2:1;			/*bit 2*/
			unsigned char B1:1;			/*bit 1*/
			unsigned char B0:1;			/*bit 0*/
		} BIT;
	} NDERA;
	union								/*NDRB1レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B15:1;		/*bit 15*/
			unsigned char B14:1;		/*bit 14*/
			unsigned char B13:1;		/*bit 13*/
			unsigned char B12:1;		/*bit 12*/
			unsigned char B11:1;		/*bit 11*/
			unsigned char B10:1;		/*bit 10*/
			unsigned char B9:1;			/*bit 9*/
			unsigned char B8:1;			/*bit 8*/
		} BIT;
	} NDRB1;
	union								/*NDRA1レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit 7*/
			unsigned char B6:1;			/*bit 6*/
			unsigned char B5:1;			/*bit 5*/
			unsigned char B4:1;			/*bit 4*/
			unsigned char B3:1;			/*bit 3*/
			unsigned char B2:1;			/*bit 2*/
			unsigned char B1:1;			/*bit 1*/
			unsigned char B0:1;			/*bit 0*/
		} BIT;
	} NDRA1;
	union								/*NDRB2レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*未使用*/
			unsigned char B11:1;		/*bit 11*/
			unsigned char B10:1;		/*bit 10*/
			unsigned char B9:1;			/*bit 9*/
			unsigned char B8:1;			/*bit 8*/
		} BIT;
	} NDRB2;
	union								/*NDRA2レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*未使用*/
			unsigned char B3:1;			/*bit 3*/
			unsigned char B2:1;			/*bit 2*/
			unsigned char B1:1;			/*bit 1*/
			unsigned char B0:1;			/*bit 0*/
		} BIT;
	} NDRA2;
};
#define	TPC	(*(volatile struct __TPC_REG__ *)__TPC_ADD__)	/*ビットフィールド用*/


/*ウオッチドッグタイマー*/
union __WDT_REG__
{
	/*読み込み専用*/
	struct
	{
		union								/*DTSCRレジスタ*/
		{
			unsigned char BYTE;				/*Byte Access*/
			struct
			{
				unsigned char OVF:1;		/*オーバーフローフラグ*/
				unsigned char WTIT:1;		/*タイマモードセレクト*/
				unsigned char TME:1;		/*タイマイネーブル*/
				unsigned char rsv1:2;		/*予約*/
				unsigned char CKS:3;		/*クロックセレクト*/
			} BIT;
		} TSCR;
		unsigned char	TCNT;				/*TCNTレジスタ*/
		char	rsv1;						/*空き*/
		union								/*RSTCSRレジスタ*/
		{
			unsigned char BYTE;				/*Byte Access*/
			struct
			{
				unsigned char WRST:1;		/*ウオッチドッグタイマリセット*/
				unsigned char rsv1:7;		/*予約*/
			} BIT;
		} RSTCSR;
	} READ;
	/*書き込み専用*/
	struct
	{
		unsigned short	TSCR;
		unsigned short	RSTCSR;
	} WRITE;
};
#define	WDT		(*(volatile union __WDT_REG__ *)__WDT_ADD__)	/*ビットフィールド用*/


/*シリアルコミュニケーションインターフェース*/
struct __SCI0_REG__
{
	union								/*SMRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CA:1;			/*コミュニケーションモード、(注)スマートカードインタフェースではGMとなる*/
			unsigned char CHR:1;		/*キャラクタレングス*/
			unsigned char PE:1;			/*パリティイネーブル*/
			unsigned char OE:1;			/*パリティモード*/
			unsigned char STOP:1;		/*ストップビットレングス*/
			unsigned char MP:1;			/*マルチプロセッサモード*/
			unsigned char CKS:2;		/*クロックセレクト*/
		} BIT;
	} SMR;
	unsigned char	BRR;				/*ビットレートレジスタ*/
	union								/*SCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TIE:1;		/*トランスミットインタラプトイネーブル*/
			unsigned char RIE:1;		/*レシーブインタラプトイネーブル*/
			unsigned char TE:1;			/*トランスミットイネーブル*/
			unsigned char RE:1;			/*レシーブイネーブル*/
			unsigned char MPIE:1;		/*マルチプロセッサインタラプトイネーブル*/
			unsigned char TEIE:1;		/*トランスミットエンドインタラプトイネーブル*/
			unsigned char CKE:2;		/*クロックイネーブル*/
		} BIT;
	} SCR;
	unsigned char	TDR;				/*トランスミットデータレジスタ*/
	union								/*SSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TDRE:1;		/*トランスミットデータレジスタエンプティ*/
			unsigned char RDRF:1;		/*レシーブデータレジスタフル*/
			unsigned char ORER:1;		/*オーバーランエラー*/
			unsigned char FER:1;		/*フレーミングエラー、(注)スマートカードインタフェースではERSとなる*/
			unsigned char PER:1;		/*パリティエラー*/
			unsigned char TEND:1;		/*トランスミットエンド*/
			unsigned char MPB:1;		/*マルチプロセッサビット*/
			unsigned char MPBT:1;		/*マルチプロセッサビットトランスファ*/
		} BIT;
	} SSR;
	unsigned char	RDR;				/*レシーブデータレジスタ*/
	/*スマートカードインタフェース*/
	union								/*SCMRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*予約*/
			unsigned char SDIR:1;		/*スマートカードデータトランスファディレクション*/
			unsigned char SINV:1;		/*スマートカードデータインバート*/
			unsigned char rsv2:1;		/*予約*/
			unsigned char SMIF:1;		/*スマートカードインタフェースモードセレクト*/
		} BIT;
	} SCMR;
};
#define	SCI0	(*(volatile struct __SCI0_REG__ *)__SCI0_ADD__)	/*ビットフィールド用*/
#define	SCI1	(*(volatile struct __SCI0_REG__ *)__SCI1_ADD__)	/*ビットフィールド用*/

/*ADコンバーター*/
struct __AD_REG__
{
	unsigned short	ADDRA;				/*ADDRAレジスタ*/
	unsigned short	ADDRB;				/*ADDRBレジスタ*/
	unsigned short	ADDRC;				/*ADDRCレジスタ*/
	unsigned short	ADDRD;				/*ADDRDレジスタ*/
	union								/*ADCSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char ADF:1;		/*A/Dエンドフラグ*/
			unsigned char ADIE:1;		/*A/Dインタラプトイネーブル*/
			unsigned char ADST:1;		/*A/Dスタート*/
			unsigned char SCAN:1;		/*スキャンモード*/
			unsigned char CKS:1;		/*クロックセレクト*/
			unsigned char CH:3;			/*チャネルセレクト*/
		} BIT;
	} ADCSR;
	union								/*ADCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TRGE:1;		/*トリガイネーブル*/
			unsigned char rsv1:7;		/*予約*/
		} BIT;
	} ADCR;
};
#define	AD		(*(volatile struct __AD_REG__ *)__AD_ADD__)	/*ビットフィールド用*/


/*DAコンバーター*/
union __DASTCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:7;		/*未使用*/
		unsigned char DASTE:1;		/*D/Aスタンバイイネーブル*/
	} BIT;
};
#define	DASTCR	(*(volatile struct __DASTCR_REG__ *)__DASTCR_ADD__)	/*ビットフィールド用*/

struct __DA_REG__
{
	unsigned char	DADR0;
	unsigned char	DADR1;
	union								/*DACRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DAOE1:1;		/*D/Aアウトプットイネーブル 1*/
			unsigned char DAOE0:1;		/*D/Aアウトプットイネーブル 0*/
			unsigned char DAE:1;		/*D/Aイネーブル*/
			unsigned char rsv1:5;		/*未使用*/
		} BIT;
	} DACR;
};
#define	DA		(*(volatile struct __DA_REG__ *)__DA_ADD__)	/*ビットフィールド用*/


/*ROM*/
struct __FLASH_REG__
{
	char	rsv1;						/*アライメント調整*/
	union
	{									/*RAMCR*/
		unsigned char BYTE;
		struct
		{
			unsigned char rsv1:4;		/*予約*/
			unsigned char RAMS:1;		/*RAMS*/
			unsigned char RAM :3;		/*RAM*/
		} BIT;
	} RAMCR;
	char	rsv2[ 0xfee0b0 - 0xfee077 - 1 ];	/*空き*/
	union
	{									/*FCCS*/
		unsigned char BYTE;
		struct
		{
			unsigned char FWE :1;		/*FWE*/
			unsigned char rsv1:2;		/*予約*/
			unsigned char FLER:1;		/*FLER*/
			unsigned char rsv2:3;		/*予約*/
			unsigned char SCO :1;		/*SCO*/
		} BIT;
	} FCCS;
	union
	{									/*FPCS*/
		unsigned char BYTE;
		struct
		{
			unsigned char rsv1:7;		/*予約*/
			unsigned char PPVS:1;		/*PPVS*/
		} BIT;
	} FPCS;
	union
	{									/*FECS*/
		unsigned char BYTE;
		struct
		{
			unsigned char rsv1:7;		/*予約*/
			unsigned char EPVB:1;		/*EPVB*/
		} BIT;
	} FECS;
	char	rsv3;						/*予約*/
	unsigned char FKEY;					/*FKEY*/
	unsigned char FMATS;				/*FMATS*/
	char	rsv4;						/*予約*/
	union
	{									/*FVACR*/
		unsigned char BYTE;
		struct
		{
			unsigned char FVCHGE:1;		/*FVCHGE*/
			unsigned char rsv1:3;		/*予約*/
			unsigned char FVSEL :4;		/*FVSEL*/
		} BIT;
	} FVACR;
	unsigned char FVADRR;				/*FVADRR*/
	unsigned char FVADRE;				/*FVADRE*/
	unsigned char FVADRH;				/*FVADRH*/
	unsigned char FVADRL;				/*FVADRL*/
};
#define	FLASH	(*(volatile struct __FLASH_REG__ *)__FLASH_ADD__)	/*ビットフィールド用*/

/*SMCI*/
struct __SMCI_REG__
{
	union
	{									/*SMR*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char	GM:1;		/*GM*/
			unsigned char	CHR:1;		/*CHR*/
			unsigned char	PE:1;		/*PE*/
			unsigned char	OE:1;		/*O/E*/
			unsigned char	STOP:1;		/*STOP*/
			unsigned char	MP:1;		/*MP*/
			unsigned char	CKS :2;		/*CKS*/
		}BIT;
	} SMR;
	unsigned char	BRR;				/*BRR*/
	union
	{									/*SCR*/
		unsigned char	BYTE;			/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char	TIE:1;		/*TIE*/
			unsigned char	RIE:1;		/*RIE*/
			unsigned char	TE:1;		/*TE*/
			unsigned char	RE:1;		/*RE*/
			unsigned char	MPIE:1;		/*MPIE*/
			unsigned char	TEIE:1;		/*TEIE*/
			unsigned char	CKE :2;		/*CKE*/
		}BIT;
	} SCR;
	unsigned char	TDR;				/*TDR*/
	union
	{									/*SSR*/
		unsigned char	BYTE;			/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char	TDRE:1;		/*TDRE*/
			unsigned char	RDRF:1;		/*RDRF*/
			unsigned char	ORER:1;		/*ORER*/
			unsigned char	ERS:1;		/*ERS*/
			unsigned char	PER:1;		/*PER*/
			unsigned char	TEND:1;		/*TEND*/
			unsigned char	MPB:1;		/*MPB*/
			unsigned char	MPBT:1;		/*MPBT*/
		} BIT;
	} SSR;
	unsigned char	RDR;				/*RDR*/
	union
	{									/*SCMR*/
		unsigned char	BYTE;			/*Byte Access*/
		struct
		{								/*Bit  Access*/
			unsigned char	rsv1:4;		/*予約*/
			unsigned char	SDIR:1;		/*SDIR*/
			unsigned char	SINV:1;		/*SINV*/
			unsigned char	rsv2:1;		/*予約*/
			unsigned char	SMIF:1;		/*SMIF*/
		} BIT;
	} SCMR;
};
#define	SMCI0	(*(volatile struct __SMCI_REG__ *)__SMCI0_ADD__)	/*ビットフィールド用*/
#define	SMCI1	(*(volatile struct __SMCI_REG__ *)__SMCI1_ADD__)	/*ビットフィールド用*/
#define	SMCI2	(*(volatile struct __SMCI_REG__ *)__SMCI2_ADD__)	/*ビットフィールド用*/

#endif /*__PROJECT_HOS__H8_3069_H_*/
