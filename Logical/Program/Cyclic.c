
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if(enable) {
		speed = 5;
		cnt++;
	} else {
		speed = 0;
	}
	fb_regulator.e = speed - fb_motor.w;
	fb_motor.u = fb_regulator.u * fb_motor.ke;
	fb_motor_noreg.u = speed * fb_motor_noreg.ke;
	FB_Motor(&fb_motor);
	FB_Motor(&fb_motor_noreg);
	FB_Regulator(&fb_regulator);
}
