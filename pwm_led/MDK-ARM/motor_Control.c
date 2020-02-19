/**Algorithm 5: Motor Control
 * 
 * Description: 
 * The algorithm will take the angle of movement of each motor from each 
 * motor function (E.g Shoulder Function) and send PWM signals to each 
 * motor for rotation.
 *
 * Pseudocode:
 * Initialise local variable Theta
 * 
 *      Begin:
 * 
 *          Pull the angle of movement(theta) of each motor from the stack
 *          Rotate the motors according to the angle of movement 
 *          
 *      Complete Motor Control Function
 * */

#include "main.h"
#include <math.h>

void motor_Control(struct motor_mode *control)
{
		double dutyCycle = 0;
    //full range of motion is 180 deg
    //duty cycle 5% to 15% to go from 0 deg to 180 deg
    //1 deg per 0.055
    double unit_deg = 10*control->motor1_angle/180;
    control->dutyCycle1 = (5 + unit_deg)*100;
    double unit_deg2 = 10*control->motor2_angle/180;
    control->dutyCycle2 = 5 + unit_deg2;
    double unit_deg3 = 10*control->motor3_angle/180;
    control->dutyCycle3 = 5 + unit_deg3;
    double unit_deg4 = 10*control->motor4_angle/180;
    control->dutyCycle4 = 5 + unit_deg4;
}