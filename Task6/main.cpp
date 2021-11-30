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

// this is my first solution using a function and comparitive if statements

void switches(int isSW1, int isSW2, int isSW3, int isSW4, int isSW5){
    static int sequence = 0; // values for sequence and counter are set to 0 first time function is used
    static int counter = 0;
    while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)){ // wait for all buttons to be released
        }
    wait_us(10000); // debounce
    while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)){ // wait for any button to be pressed
        }
    wait_us(10000);// debounce
    if((SW1 == isSW1) && (SW2 == isSW2) && (SW3 == isSW3) && (SW4 == isSW4) && (SW5 == isSW5)){ // only adds a value to sequence if a specific button is pressed
        sequence += 1;
    }
    wait_us(10000); // debounce
    counter += 1; // counter is always incremented by 1
    if(counter == 4){ // checks if the function has been ran same number of times as number of buttons in the sequence
        if(sequence == 4){ // checks if all the buttons pressed were correct
            for(int n = 0; n <= 2; n++){ // loops 3 times
                leds[2] = 1; // flashes leds on and off
                wait_us(1000000);
                leds[2] = 0;
                wait_us(1000000);
            }
        }
        else{ // if any buttons pressed in the sequence were incorrect
            leds[0] = 1; // turns on red led
            alarm.playTone("A", Buzzer::HIGHER_OCTAVE); // plays buzzer noise for 5 seconds
            wait_us(5000000);
            alarm.rest();
        }
        counter = 0; // reset value for counter and sequence to go again
        sequence = 0;
    }

}

int main()
{

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

        printf("\n"); // prints a new line

        // this is my second solution to the task using arrays to store the correct and the users's sequence

        int actualSequence[4][5]= { // the correct sequence stored as an array
            {1, 1, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 1, 0},
            {0, 1, 1, 0, 0}
        };

        int userSequence[4][5] = { // a blank array which will be used to store the user's sequence
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };

        int wrong = 0; // sets wrong to equal 0, will be ued towards the end

        while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)); // waits for all buttons to be released
        wait_us(10000); // debounce

        for(int n = 0; n <= 3; n++){ // loops for the number of button presses
            while((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)); // waits for any button to be pressed
            wait_us(20000); // debounce
            int inputs[5] = {SW1, SW2, SW3, SW4, SW5}; // creates an array which stores the state of each button
            for(int z = 0; z <= 4; z++){ // loops for the number of columns in the sequence arrays
                userSequence[n][z] = inputs[z]; // writes each button state to the nth row of the array in order
            }
            while((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)); // waits for all buttons to be released
            wait_us(20000); // debounce
        }
        // this prints out the buttons that were pressed from the user, it was added because there was an issue where when buttons were meant to be pressed together,
        // only one of them would be pressed.

        for(int z = 0; z<=3; z++){ // loops 4 times, number of different button presses for the sequence
            for(int j = 0; j<=4; j++){ // loops number of buttons there are
                printf("%d ", userSequence[z][j]); // this prints each row of the buttons pressed and then a new line to present all values in matrix form
        }
            printf("\n");
    }
        // goes through each cell of the actual and the user's sequence matrix and compares them.
        for(int h = 0; h <= 3; h++){
            for(int t = 0; t <= 4; t++){
                if(userSequence[h][t] != actualSequence[h][t]){ // if any cell is not identical then wrong is set to 1.
                    wrong = 1;
                }
            }
        }

        if(wrong == 1){ // if wrong is 1, then the user's sequence is not identical to the actual sequence so this code runs
            leds[0] = 1; // turns on red led
            alarm.playTone("A", Buzzer::HIGHER_OCTAVE); // plays buzzer noise for 5 seconds
            wait_us(5000000); 
            alarm.rest(); // turn off buzzer
        }

        else{ // only other alternative is that the user's and actual 
            for(int n = 0; n <= 2; n++){ // loops 3 times
                leds[2] = 1; // flashes green led on and off, one second on and one second off.
                wait_us(1000000);
                leds[2] = 0;
                wait_us(1000000);
            }
        }

        switches(1, 1, 0, 0, 0); // calls the function 4 times with the specific buttons that need to be pressed
        switches(0, 0, 0, 0, 1);
        switches(0, 0, 0, 1, 0);
        switches(0, 1, 1, 0, 0);
        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


