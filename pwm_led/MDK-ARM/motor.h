#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "main.h"

struct motor_mode
{
	double motor1_angle;
    double motor2_angle;
    double motor3_angle;
    double motor4_angle;
    double motor5_angle;
    double dutyCycle1;
    int Xcoord;
    int Ycoord;
};