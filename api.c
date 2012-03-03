#include "kernel.h"
#include "kernel_id.h"
#include "h8_sci.h"
#include "lib.h"
#include "api.h"

static void raw_twice(API_PARAM *param)
{
    param->result = param->pm_twice.param * 2;
}
static void raw_putchars(API_PARAM *param)
{
    Sci_PutChars(param->pm_putchars.param);
    param->result = 0;
}
static void raw_putbinry(API_PARAM *param)
{
    int i;
    for (i = 0; i < param->pm_putbinary.buflen; i++)
        putdval(param->pm_putbinary.buf[i],0);
    Sci_PutChars("\r\n");

    param->result = 0;
}
static int execute(API_PARAM *param)
{
    API_PARAM *res;

    get_tid(&param->id);

    snd_mbx(MID_WORKER,(T_MSG *)param);
    slp_tsk();

    rcv_mbx(MID_APP,(T_MSG **)&res);
    return res->result;
}
unsigned int api_twice(int ap)
{

    API_PARAM param;

    param.api = API_TWICE;
    param.pm_twice.param = ap;

    return execute(&param);
}

unsigned int api_putchars(const char* str)
{

    API_PARAM param;

    param.api = API_PUTCHARS;
    param.pm_putchars.param = str;

    return execute(&param);
}

unsigned int api_putbinary(char *buf,int buflen)
{
    API_PARAM param;

    param.api = API_PUTBINARY;
    param.pm_putbinary.buf = buf;
    param.pm_putbinary.buflen = buflen;

    return execute(&param);
}

void worker(VP_INT exinf)
{

    API_PARAM *param;

    while (1) {
        rcv_mbx(MID_WORKER,(T_MSG **)&param);
        switch (param->api) {
        case API_TWICE:
            raw_twice(param);
            break;
        case API_PUTCHARS:
            raw_putchars(param);
            break;
        case API_PUTBINARY:
            raw_putbinry(param);
            break;
        default:
            param->result = -1;
            break;
        }
        wup_tsk(param->id);
        snd_mbx(MID_APP,(T_MSG *)param);
    }
}
