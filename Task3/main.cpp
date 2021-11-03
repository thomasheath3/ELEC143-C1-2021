#include "uop_msb.h"
using namespace uop_msb;

DigitalIn BlueButton(USER_BUTTON);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
LCD_16X2_DISPLAY display;

int main()
{

    // ***** MODIFY THE CODE BELOW HERE *****

    //1. Use a while loop to wait for the blue button to be pressed, then released. For full marks, account for switch bounce.

    //2. Using a while-loop, flash the yellow LED on and off 5 times. Each flash should last 0.5s. 

    //3. Using a while-loop, flash the green LED on and off 10 times. Each flash should last 0.25s. 

    //4. Using a while-loop, flash the red LED on and off 20 times. Each flash should last 0.125s. 

    //5. Using a while-loop, count from 50 down to -50 in steps of 10 - print the results on row 1 of the LCD screen every 0.5 second 

    // ***** MODIFY THE CODE ABOVE HERE *****

    while (true) {

    }
}


