#include "uop_msb.h"
using namespace uop_msb;

// You are to ONLY use this object to control the LEDs
PortOut traffic(PortC, 0b0000000001001100);

DigitalIn sw1(BTN1_PIN);
DigitalIn sw2(BTN2_PIN);
//The default flash rate is once per second for all tasks

int main()
{
    traffic = 0; // turn all leds off
    //1. Flash the red led 3 times
    for(int i = 0 ; i < 3 ; i ++){ // loop 3 times
        traffic = 0; // red led flashed off and on every second
        wait_us(1000000);
        traffic = 0b0000000000000100; // the binary value for the red led
        wait_us(1000000);
    }    
    traffic = 0;
    wait_us(1000000);
    //2. Using the bitwise OR and AND operators (|,&), flash the green LED on and off 3 times
    for(int x = 0; x < 3; x++){ // loops 3 times
        traffic = 0b0000000001000000 | traffic;
        wait_us(1000000);
        traffic = 0b0000000001000000 & 0b1111111110111111;
        wait_us(1000000);
    }
    traffic = 0;
    //3. Using the bitwise XOR operator (^), flash the yellow LED on and off 3 times
    for(int y = 0; y < 3; y++){ // loops 3 times
        traffic = traffic ^ 0b0000000000001000; // flashes yellow led on and off, this is binary vlaue for yellow
        wait_us(1000000);
        traffic = 0b0000000000001000 ^ 0b0000000000001000;
        wait_us(1000000);
    }
    //4. Using only bitwise operators, display the traffic light sequence red, red+yellow, green, yellow. Leave a 1s gap between each
    traffic = 0;
    while (true){
    traffic = 0b0000000000000100 | traffic;
    wait_us(1000000);
    traffic = traffic | 0b0000000000001000;
    wait_us(1000000);
    traffic = traffic & 0b0000000000000000; // reset
    traffic = traffic | 0b0000000001000000;
    wait_us(1000000);
    traffic = traffic & 0b0000000000000000; 
    traffic = traffic | 0b0000000000001000;
    wait_us(1000000);
    traffic = 0b0000000000000000;
    }
}