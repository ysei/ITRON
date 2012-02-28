# --------------------------------------------------------------------------- 
#  Hyper Operating System V4  サンプルプログラム                              
#    メイクファイル（h8300-hms  GNUCコンパイラ版）                            
#                                                                             
#                                   Copyright (C) 1998-2002 by Project HOS    
#                                   http://sourceforge.jp/projects/hos/       
# --------------------------------------------------------------------------- 


# FreeBSD 4.6R付属make、GNU make 3.79.1にて動作確認しています。


# パス
HOSROOT  = ../..
INCDIR   = $(HOSROOT)/include
PACDIR   = $(HOSROOT)/include/h83
LIBDIR   = $(HOSROOT)/lib/h83/gcc


# ツール
CC     = h8300-hms-gcc
CPP    = h8300-hms-gcc
ASM    = h8300-hms-gcc
LINK   = h8300-hms-gcc
OBJCNV = h8300-hms-objcopy -O srec
HOSCFG = ../../config/hos4cfg


# オプション
CFLAGS   = -Os -Wall -I$(INCDIR) -I$(PACDIR) -mh -c -pipe
CPPFLAGS = -E -mh -x c
AFLAGS   = -mh -c
LFLAGS   = -mh -mrelax -nostartfiles -nostdlib -Wl,-Map,$(TARGET).map \
		-Wl,-T$(LDSCRIPT) -L$(LIBDIR)
LIBS	 = -lgcc -lh4h83
# ターゲット
TARGET = sample

#インクルードファイル
INCS = kernel_id.h sample.h h8_sci.h

#リンカスクリプト
LDSCRIPT = h83069.x

# オブジェクトファイル
OBJS = crt0.o vector.o sample.o h8_sci.o kernel_cfg.o ostimer.o


# ターゲットモジュール生成
$(TARGET).mot: $(OBJS) $(LDSCRIPT)
	$(LINK) $(LFLAGS) -o $(TARGET).coff $(OBJS) $(LIBS)
	$(OBJCNV) $(TARGET).coff $(TARGET).mot


# オブジェクト生成
kernel_cfg.o: kernel_cfg.c $(INCS)
	$(CC) $(CFLAGS) kernel_cfg.c

vector.o: vector.s
	$(ASM) $(AFLAGS) vector.s

crt0.o: crt0.s
	$(ASM) $(AFLAGS) crt0.s

sample.o: sample.c $(INCS)
	$(CC) $(CFLAGS) sample.c

h8_sci.o: h8_sci.c $(INCS)
	$(CC) $(CFLAGS) h8_sci.c

ostimer.o: ostimer.c $(INCS)
	$(CC) $(CFLAGS) ostimer.c

kernel_cfg.c kernel_id.h: system.cfg
	$(CPP) $(CPPFLAGS) system.cfg | $(HOSCFG) -

# フラッシュ書き込み
write:
	h8write -3069 -f20 $(TARGET).mot /dev/ttyUSB0


# クリーンナップ
clean:
	rm  -f  $(TARGET).coff $(TARGET).mot $(TARGET).map \
		$(OBJS) kernel_id.h kernel_cfg.c *~


# --------------------------------------------------------------------------- 
#  Copyright (C) 1998-2002 by Project HOS                                     
# --------------------------------------------------------------------------- 
