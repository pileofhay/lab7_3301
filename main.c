#include <xc.h>
#include <pic18f4321.h>
#include "pic18f4321-Config.h"
#define _XTAL_FREQ 1000000
typedef unsigned char u_char;

void main(void) 
{

    TRISA = 0xFF;
    TRISB = 0;
    TRISD = 0;
    OSCCON = 0x70;
    
    PORTB = 0;
    PORTD = 0;
    
    ADCON0 = 0x01;
    ADCON1 = 0x0E;
    ADCON2 = 0xA2;
    
    
    
    for (;;) 
    {
        
        ADCON0bits.GO = 1;
        
        while(ADCON0bits.GO)
        {
            
            PORTD = ADRESH;
            PORTB = ADRESL;
            __delay_ms(100);
           
        }
        

    }   
    
}
