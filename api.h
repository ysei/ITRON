#ifndef API_H
#define API_H

enum {
    API_TWICE,
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
    } un;
#define pm_twice un.twice
} API_PARAM;

unsigned int api_twice(int param);
void worker(VP_INT exinf);

#endif
