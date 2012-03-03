#include "kernel.h"
#include "kernel_id.h"
#include "h8_sci.h"
#include "lib.h"

void
putc(unsigned char c)
{
    Sci_PutChar(c);
}
void
puts(unsigned char* str)
{
    while (*str)
        putc(*str++);
}

#define HEXCHAR(num) ("0123456789ABCDEF"[num])

int
putxval(unsigned long value,int column)
{
    char buf[9]/*hex max + 1*/;
    unsigned long v;
    char* p;
    int i;

    p = &buf[sizeof(buf) -1];
    *p-- = '\0';/*終端分*/
    *p-- = HEXCHAR(value & 0xF);/*1桁目*/

    v = value >> 4;
    if (column == 0) {
        while (v) {
            *p-- = HEXCHAR(v & 0xf);
            v >>= 4;
        }
    } else {
        for (i = 0; v || i < column - 1; i++) {
            *p-- = HEXCHAR(v & 0xf);
            v >>= 4;
        }
    }
    puts(p + 1);

    return 0;
}


/* 32ビットの除算は別途ライブラリが必要になる*/
int
putdval(unsigned int value,int column)
{
    char buf[6];/*dec max + 1*/
    unsigned int v;
    char* p;
    int i;

    p = &buf[sizeof(buf)-1];
    *p-- = '\0';/*終端分*/
    *p-- = '0' + (value % 10);/*1桁目*/

    v = value / 10;
    if (column == 0) {
        while (v) {
            *p-- = '0' + (v % 10);
            v /= 10;
        }
    } else {
        for (i = 0; v || i < column - 1; i++) {
            *p-- = '0' + (v % 10);
            v /= 10;
        }
    }
    puts(p + 1);

    return 0;
}
