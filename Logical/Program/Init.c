
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	enable = 0;
	cnt = 0;
	speed = 0;
	
	fb_motor.dt = 0.02;
	fb_motor.ke = 43.98;
	fb_motor.Tm = 0.173;
	
	fb_motor_noreg.dt = 0.02;
	fb_motor_noreg.ke = 43.98;
	fb_motor_noreg.Tm = 0.173;
	
	fb_regulator.dt = 0.02;
	fb_regulator.k_p = 2.174;
	fb_regulator.k_i = 12.56;
	fb_regulator.max_abs_value = 24;
}
