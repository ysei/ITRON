#if 0
typedef struct {
    T_MSG pk_msg; /* OS管理領域 */
    union {
        struct {
            int result;
            int param;
        } api_1;
    } un;
#define pm_api_1 un.api_1
} API_PARAM;
#else
typedef struct {
    T_MSG pk_msg; /* OS管理領域 */
    int result;
    int param;
} API_PARAM;
#endif

unsigned int api_test(int param);
void worker(VP_INT exinf);
