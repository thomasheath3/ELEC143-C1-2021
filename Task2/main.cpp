#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // Using a while-loop, count from 10 down to 0 in steps of 1 - print the results to the serial terminal

    // Using a do-while-loop, count from -20 to +20 in steps of 2 - print the results to the serial terminal

    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

