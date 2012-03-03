#ifndef API_H
#define API_H

enum {
    API_TWICE,
    API_PUTCHARS,
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
    } un;
#define pm_twice un.twice
#define pm_putchars un.putchars
} API_PARAM;

unsigned int api_twice(int param);
void worker(VP_INT exinf);

#endif
