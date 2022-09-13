# include <avr/io.h>
# include <util/delay.h>

int main(void){
    DDRD = 1<<DDD5;

    TCCR0A = 0x23;
    TCCR0B = 0x03;

    OCR0B = 10;

    while(1);
}