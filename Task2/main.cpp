#include "uop_msb.h"
using namespace uop_msb;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
LCD_16X2_DISPLAY display;

int main()
{
    leds = 0;
    display.cls();
    display.locate(0, 0);       //Row 0, column 0
    display.printf("Task 2");
    // ***** MODIFY THE CODE BELOW HERE *****
    int n = 0;
    // Using a do-while-loop, count from 0 to +50 in steps of 5 - print the results on row 2 of the LCD screen every 1 second 
    do{
        // clears the display and defines where n will be printed. Then n is printed.
        display.cls();
        display.locate(2, 0);
        display.printf("%d", n);
        // adds 5 to n and then waits 1 second.
        n += 5;
        wait_us(1000000);
    }
    while (n <= 50); // the condition to repeat the loop.
    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

