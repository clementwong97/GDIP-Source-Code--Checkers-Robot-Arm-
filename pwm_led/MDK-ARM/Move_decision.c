/**Algorithm 3: Move Decision
 * 
 * Description: 
 * The algorithm will work as an arithmetic function where it computes the
 * input coordinates from read IO function and approximate the angle of 
 * each motor types of the robot.
 *
 * Pseudocode:
 * Initialise local variable x, y, newX and newY
 * 
 *      Begin:
 *          Pull the input coordinates from the stack
 *          Define the dimension (in metres) of the checker board
 *          Compute the angle and distance between coordinate (x,y) and the 
 *          target location with coordinate of newX and newY
 *          Determine the angle of movement required for each motors to 
 *          move to that location
 *          Store the computed angle of movement each motors in the stack
 * 
 *      Complete Move Decision Function
 * */
#include "main.h"
#include <math.h>
#define PI 3.14159265358979323846

void Move_Decision(struct motor_mode *decision)
{
    //Pull coordinates from stack
    int x = decision->Xcoord;
    int y = decision->Ycoord;
    //Define the dimension of the checker board in terms of metres
    //Reference Point (A1, (1,1))
    double ref_x = 14.5;
    double ref_y = 15.5;
    double ref_x_op = 1.75;
    double ref_z = 10.0; 
    
    //height of board + base
    double a_1 = 9.15;
    //length of upper arm
    double a_2 = 22.0;
    //length of forearm
    double a_3 = 25.5;
    //width of one cell
    double gap = 3;
    double opposite, adjacent, theta1, theta2, theta3, theta4, r_1, r_2, r_3;
        
    //Define base motor angle (Theta 1)
    if (x > 4)
    {
        double opposite = ref_y + (y - 1)*gap;
        double adjacent = ref_x_op + (x - 5)*gap;
        double theta_op;
        theta_op = atan(adjacent/opposite);
        theta1 = PI/2 + theta_op;
        r_1 = sqrt(pow(opposite, 2) + pow(adjacent, 2));
        r_2 = ref_z - a_1;
        double omega_2 = atan(r_2/r_1);
        r_3 = sqrt(pow(r_1, 2) + pow(r_2, 2));
        double omega_1 = acos((pow(a_3, 2) - pow(a_2, 2) - pow(r_3, 2))/(-2*a_2*r_3));
        theta2 = omega_2 + omega_1;
        double omega_3 = acos((pow(r_3, 2) - pow(a_2, 2) - pow(a_3, 2))/(-2*a_2*a_3));
        theta3 = PI - omega_3;
        theta4 = theta2 - omega_3;
    }
    else 
    {
        double opposite = ref_y + (y - 1)*gap;
        double adjacent = ref_x + (x - 1)*gap;
        theta1 = atan(opposite/adjacent);
        r_1 = sqrt(pow(opposite, 2) + pow(adjacent, 2));
        r_2 = ref_z - a_1;
        double omega_2 = atan(r_2/r_1);
        r_3 = sqrt(pow(r_1, 2) + pow(r_2, 2));
        double omega_1 = acos((pow(a_3, 2) - pow(a_2, 2) - pow(r_3, 2))/(-2*a_2*r_3));
        theta2 = omega_2 + omega_1;
        double omega_3 = acos((pow(r_3, 2) - pow(a_2, 2) - pow(a_3, 2))/(-2*a_2*a_3));
        theta3 = PI - omega_3;
        theta4 = theta2 - omega_3;
    }

    //compute the angle and distance between current location and next location
    decision->motor1_angle = (theta1/PI)*180;
    decision->motor2_angle = (theta2/PI)*180;
    decision->motor3_angle = (theta3/PI)*180;
    decision->motor4_angle = (theta4/PI)*180;
    //Store the angle details in the stack 

}