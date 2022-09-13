/*****************************************************************************
* switch.c - This program is for turning on an LED at low brightness when switch one is 
* pressed. When switch 2 is pressed, the LED is turned on with increased brightness. When
* both switches are pressed the LED is turned on with maximum brightness.
* Revision
* Date          Author              Revision
* 04/12/2022    Khushkumar Jajoo    Writing the code
* 04/19/2022    Khushkumar Jajoo    Touching up the code and adding comments
* 04/13/2022    Khushkumar Jajoo    Running the code on arduino and testing it on the circuit

REFERENCE
* ECE 231 Spring 22, Lecture slides 16,17,18 from the professor, David McLaughlin
******************************************************************************/
# include <avr/io.h>
# include <util/delay.h>
# define DURATION 200

int main(void){
    DDRB=0; 
    DDRD = 1<<DDD5; // setting the pin 5 of port D as output
    PORTB = 1<<PORTB5 | 1<<PORTB4 ;  // setting the pin 5 of port B as input and pin 4 of port B as input
    
    // Initialize timer0 for FAST PWM, /64 prescaler
    TCCR0A = 0x23;   
    TCCR0B = 0x03;     
    
    while(1){

        if((!(PINB & (1<<PINB4)))&&((PINB & (1<<PINB5)))){ // if switch 1 is pressed and switch 2 is not pressed
            // loading value into OCR0B
            OCR0B = 32; // 32 is 12.5% of 256 so 12.5% duty cycle
            DDRD = 1<<DDD5; // turn on the LED with minimum brightness
            
        }
         if((!(PINB & (1<<PINB5)))&&((PINB & (1<<PINB4)))){ // if switch 2 is pressed and switch 1 is not pressed
            // loading value into OCR0B 
            OCR0B = 150; // 150 is 58.5% of 256 so 58.5% duty cycle
            DDRD = 1<<DDD5; // turn on the LED with more brightness
            
        }
         if((!(PINB & (1<<PINB4))) && (!(PINB & (1<<PINB5)))){ // if both switches are pressed
            // loading value into OCR0B 
            OCR0B = 255; // 255 is nearly 100% of 256 so nearly 100% duty cycle
            DDRD = 1<<DDD5; // turn on LED with maximum brightness

        }
        else{ // if no switch is pressed

            DDRD = ~(1<<DDD5); // turn off the LED
        }
    }

    return 0;
}