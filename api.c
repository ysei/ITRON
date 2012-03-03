#include "kernel.h"
#include "kernel_id.h"
#include "h8_sci.h"
#include "api.h"

unsigned int api_test(int ap)
{

    API_PARAM param;
    API_PARAM *res;
    int result;

    param.param = ap;

    snd_mbx(MID_WORKER,(T_MSG *)&param);

    rcv_mbx(MID_APP,(T_MSG **)&res);
    result = res->result;

    return result;
}

void worker(VP_INT exinf)
{

    API_PARAM *param;
    API_PARAM res;

    while (1) {
        rcv_mbx(MID_WORKER,(T_MSG **)&param);
        res.result = param->param * 10;
        dly_tsk(1000);

        snd_mbx(MID_APP,(T_MSG *)&res);
    }
}
