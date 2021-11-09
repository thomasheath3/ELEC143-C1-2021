#include "uop_msb.h"
using namespace uop_msb;

DigitalIn BlueButton(USER_BUTTON);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
LCD_16X2_DISPLAY display;

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****
    int n = 1;
    //1. Use a while loop to wait for the blue button to be pressed, then released. For full marks, account for switch bounce.
    while (BlueButton == 0){ // wait for button to be pressed down
    }
    wait_us(100000); // wait for noise to settle to account for switch bounce
    while (BlueButton ==1){ // wait for button to be released
    }
    //2. Using a while-loop, flash the yellow LED on and off 5 times. Each flash should last 0.5s. 
    while (n <= 5){ // loop 5 times
        leds[1] = 1; // turn second led in array on
        wait_us(500000); // leave it on for 0.5 seconds
        leds[1] = 0; // turn led off
        wait_us(500000); // leave it off for 0.5 seconds
        n ++; // increase n by 1
    }
    n=1; // reset value of n to 1
    //3. Using a while-loop, flash the green LED on and off 10 times. Each flash should last 0.25s. 
    while (n <= 10){ //loop 10 times
        leds[2] = 1; // turn 3rd led in the array on
        wait_us(250000); // leave on for 0.25 seconds
        leds[2] = 0; // turn led off
        wait_us(250000); // leave off for 0.25 seconds
        n ++; //increase n by 1
    }
    n=1; // reset value of n
    //4. Using a while-loop, flash the red LED on and off 20 times. Each flash should last 0.125s. 
    while (n <= 20){ // loop 20 times
        leds[0] = 1; // turn 1st led in array on
        wait_us(125000); // leave on for 0.125 seconds
        leds[0] = 0; // turn led off
        wait_us(125000); // leave off for 0.125 seconds
        n ++; // increase n by 1
    }
    n=50; // set n to 50
    //5. Using a while-loop, count from 50 down to -50 in steps of 10 - print the results on row 1 of the LCD screen every 0.5 second 
    while (n >= -50){ //loop until n == -50
        display.cls(); // clear display
        display.locate(1, 0); // assign the first row to be used
        display.printf("%d", n); // print n on the display
        n -= 10; // minus 10 from n
        wait_us(500000); // wait 0.5 seconds

    }
    // ***** MODIFY THE CODE ABOVE HERE *****

    while (true) {

    }
}


