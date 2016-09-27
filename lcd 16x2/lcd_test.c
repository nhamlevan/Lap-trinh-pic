
#include <16F877.h>                           // PIC16F877 header file 
#device *=16   
#use delay(clock=4000000)                       // for 4Mhz crystal 

#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT

#define LCD_D4 PIN_B4
#define LCD_D5 PIN_B5
#define LCD_D6 PIN_B6
#define LCD_D7 PIN_B7

#byte LCD_DATA =0x06
#bit LCD_RS=0x07.0
#bit LCD_RW=0x07.1
#bit LCD_EN=0x07.2

#use fast_io(B)
#use fast_io(C)

#include "lcd_8bit_lib.c" //gh

/*=======================================*/ 
void main(void) 
{ 
        char LINE2[] = { "PIC16F877 CCSC " }; 
        //int8 i; 

        lcd_init(); 
        char a[16];
        //sprintf(a,"%5u",511);
        lcd_putChar('b');
        lcd_putChar('b');
        lcd_move(2,0);
        lcd_print_str(LINE2);
        //lcd_print_str(LINE2);
}//end main() 
