/**Algorithm 1: Read IO Function
 * 
 * Description: 
 * The algorithm will take the input coordinates of the current checker 
 * location and the next new position coordinates from the keyboard. The 
 * input coordinates will be saved in the data structure so that
 * the move decision function can fetch it and do operation on them. 
 *
 * Pseudocode:
 * Initialise local variable x, y, newX, newY
 * 
 *      Begin:
 *          Print message to ask for current checker location
 *          Scan input from keyboard and push x and y location into stack
 *          Print message to ask for the next checker move
 *          Scan input from keyboard and push coordinates into stack
 *      
 *      Complete Read IO function
 * */

#include "main.h"
#include <math.h>

void read_IO(struct motor_mode *input)
{
	int x,y;
		x = input->loop;
		y = 1;
    //print message to ask for input

    //error checking
        //x and y cannot be more than 8 or less than 1
        
    //check input coordinates
    input->Xcoord = x;
    input->Ycoord = y;
    //Push coordinates into the stack

}
