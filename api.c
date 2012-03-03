#include "kernel.h"
#include "kernel_id.h"
#include "h8_sci.h"
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
unsigned int api_twice(int ap)
{

    API_PARAM param;
    API_PARAM *res;
    int result;

    param.api = API_TWICE;
    param.pm_twice.param = ap;
    get_tid(&param.id);

    snd_mbx(MID_WORKER,(T_MSG *)&param);
    slp_tsk();

    rcv_mbx(MID_APP,(T_MSG **)&res);
    result = res->result;

    return result;
}

unsigned int api_putchars(const char* str)
{

    API_PARAM param;
    API_PARAM *res;
    int result;

    param.api = API_PUTCHARS;
    param.pm_putchars.param = str;
    get_tid(&param.id);

    snd_mbx(MID_WORKER,(T_MSG *)&param);
    slp_tsk();

    rcv_mbx(MID_APP,(T_MSG **)&res);
    result = res->result;

    return result;
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
        default:
            break;
        }
        wup_tsk(param->id);
        snd_mbx(MID_APP,(T_MSG *)param);
    }
}
