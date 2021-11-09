#include "uop_msb.h"
using namespace uop_msb;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Write a for-loop to count from 0 to 100 in steps of 10 - print the results to the serial terminal
    for (int n = 0; n <= 100; n += 10){
        printf("%d\n", n);
    }
    // 2. Write a for-loop to count from 100 down to 10 in steps of 5 - print the results to the serial terminal
    for (int n = 100; n>=10; n -= 5){
        printf("%d\n", n);
    }
    // 3. Write some code to demonstrate nested for-loops (one loop within another)
    // This will loop 12 times, starting with 1 and ending with 12
    for (int n = 1; n <= 12; n ++){
        printf("The %d times table\n", n);
        // This also loops 12 times, starting with 1 and ending with 12, but using x as n will be used later.
        for (int x = 1; x <= 12 ; x ++){
            // timeses n by x to produce an answer which is then printed. This is repeated 12 times for every 1 loop of n, which is then looped 12 times.
            int ans = n * x;
            printf("%d * %d = %d\n", n, x, ans);
        }
    }
    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

