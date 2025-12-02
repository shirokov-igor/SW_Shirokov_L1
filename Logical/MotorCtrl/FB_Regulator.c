
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCtrl.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{
	/*TODO: Add your code here*/		
	inst->buf_up = inst->e * inst->k_p;
	if(inst->buf_up > inst->max_abs_value || inst->buf_up < -inst->max_abs_value)
	{
		if (inst->buf_up > 0) {
			inst->buf_up = inst->max_abs_value;
		} else if (inst->buf_up < 0){
			inst->buf_up = -inst->max_abs_value;
		}
	}
	
	inst->buf_down = inst->e * inst->k_i + inst->iyOld;
	
	inst->integrator.in = inst->buf_down;
	FB_Integrator(&(inst->integrator));
	inst->buf_down = inst->integrator.out;
	
	inst->sum = inst->buf_up + inst->buf_down;
	
	if(inst->sum > inst->max_abs_value || inst->sum < -inst->max_abs_value)
	{
		if (inst->sum > 0) {
			inst->sum = inst->max_abs_value;
		} else if (inst->sum < 0) {
			inst->sum = -inst->max_abs_value;
		}
	}
	inst->u = inst->sum;
	inst->iyOld = inst->u - inst->sum;
}
