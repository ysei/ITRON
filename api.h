#ifndef API_H
#define API_H

enum {
    API_TWICE,
    API_PUTCHARS,
    API_PUTBINARY,
};

typedef struct {
    T_MSG pk_msg; /* OS管理領域 */
    unsigned char api;
    int result;
    ID id;

    union {
        struct {
            int param;
        } twice;

        struct {
            const char* param;
        } putchars;

        struct {
            char* buf;
            int buflen;
        } putbinary;
    } un;
#define pm_twice un.twice
#define pm_putchars un.putchars
#define pm_putbinary un.putbinary
} API_PARAM;

unsigned int api_twice(int param);
unsigned int api_putchars(const char* str);
unsigned int api_putbinary(char *buf,int buflen);
void worker(VP_INT exinf);

#endif
