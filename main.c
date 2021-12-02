#define F_CPU 3200000UL
#define dit 200
#include <avr/io.h>
#include <util/delay.h>

void dot(void){

    PORTC_OUT = 0b00000000;
    _delay_ms(dit);
    PORTC_OUT = 0b00000001;
    _delay_ms(dit);

}

void dash(void){

    PORTC_OUT = 0b00000000;
    _delay_ms(dit*3);
    PORTC_OUT = 0b00000001;
    _delay_ms(dit*3);
    
}

void makeS(void){

    int count = 0;
    while (count < 3){
        dot();
        count++;
    }
    _delay_ms(dit*2);

}

void makeB(void){

    int count = 0;
    dash();
    while (count < 3){
        dot();
        count++;
    }
    _delay_ms(dit*2);

}

void makeU(void){

    dot();
    dot();
    dash();
    _delay_ms(dit*2);
    
}

int main(void){

    PORTA_DIR = 0b11111111;
    PORTA_OUT = 0b11000000;
    PORTC_DIR = 0b00000001;
    while (1){
        makeS();
        makeB();
        makeU();
        _delay_ms(dit);
    }
    return (0);

}

