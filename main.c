#include <xc.h>
#include "pic18f4321-Config.h"
#define _XTAL_FREQ 1000000
typedef unsigned char u_char;

void main(void) 
{

    TRISA = 0xFF;
    TRISB = 0;
    TRISD = 0;
    
    PORTB = 0;
    PORTD = 0;
    
    ADCON0 = 0x01;
    ADCON1 = 0x0E;
    ADCON2 = 0xA2;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
   
    PIR1bits.ADIF = 0;  
    PIE1bits.ADIE = 1;
    
    u_char D1 = 0;
    u_char D0 = 0;
    
    for (;;) 
    {
        
        ADCON0bits.GO = 1;
        PIR1bits.ADIF = 0;
        
        while(ADCON0bits.GO == 1 || PIR1bits.ADIF == 0)
        {
            
            PORTD = ADRESH;
            PORTB = ADRESL;
            __delay_ms(100);
           
        }
        
    }   
    
}

