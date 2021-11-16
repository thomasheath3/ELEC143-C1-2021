#include "uop_msb.h"
using namespace uop_msb;


// You are to use these ojects to read the switch inputs
DigitalIn SW1(USER_BUTTON);
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);

// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

//Use this to sound an error
Buzzer alarm;

int main()
{
    int sequence[6];
    int total = 0;

    while (true)
    {
        leds = 0;

        //Beep
        alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(250000);
        alarm.rest();

        //Wait for the blue button using a while loop
        while (SW1==0);

        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW1 and SW2, SW5, SW4, SW2 and SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of inputs was entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, debounce the switches and use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****
        wait_us(10000); //debounce
        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){ // wait for all buttons to be released
        }
        wait_us(10000); // debounce

        while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){ // wait for any button to be pressed
        }
        if((SW1 == 1) && (SW2 == 1) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){ // only adds a value to sequence if a specific button is pressed
            sequence[0] = 1;
        }
        wait_us(10000); // debounce

        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){ // wait for all buttons to be released
        }
        wait_us(10000); // debounce

        while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){// wait for any button to be pressed
        }
        if((SW1 == 0) && (SW2 == 1) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){
            sequence[1] = 1;
        }
        wait_us(10000); // debounce

        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){// wait for all buttons to be released
        }
        wait_us(10000); // debounce

        while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){
        }
        if((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 1)){
            sequence[2] = 1;
        }
        wait_us(10000); // debounce

        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){// wait for all buttons to be released
        }
        wait_us(10000); // debounce

        while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){
        }
        if((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 1) && (SW5 == 0)){
            sequence[3] = 1;
        }
        wait_us(10000); // debounce

        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){// wait for all buttons to be released
        }
        wait_us(10000); // debounce

        while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){
        }
        if((SW1 == 0) && (SW2 == 1) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){
            sequence[4] = 1;
        }
        wait_us(10000); // debounce

        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){// wait for all buttons to be released
        }
        wait_us(10000); // debounce

        while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){
        }
        if((SW1 == 0) && (SW2 == 0) && (SW3 == 1) && (SW4 == 0) && (SW5 == 0)){
            sequence[5] = 1;
        }
        wait_us(10000); // debounce

        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){// wait for all buttons to be released
        }
        wait_us(10000); // debounce

        for(int i = 0; i<=5; i++){
            total += sequence[i];
        }
        if(total== 6){
            for(int x = 0; x<=2; x++){
                leds[2] = 1;
                wait_us(1000000);
                leds[2] = 0;
                wait_us(1000000);
            }
        }
        else{
            leds[0] = 1;
            alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
            wait_us(5000000);
            alarm.rest();
        }

        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


