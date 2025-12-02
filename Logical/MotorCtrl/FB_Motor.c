
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
void FB_Motor(struct FB_Motor* inst)
{
	/*TODO: Add your code here*/
	inst->buf = (inst->u * (1/inst->ke) - inst->w)*(1/inst->Tm);
	
	inst->integrator.in = inst->buf;
	FB_Integrator(&inst->integrator);
	inst->w = inst->integrator.out;
	
	inst->integrator.in = inst->w;
	FB_Integrator(&inst->integrator);
	inst->phi = inst->integrator.out;
}
