
/*#bit LCD_D4=0x06.4
#bit LCD_D5=0x06.5
#bit LCD_D6=0x06.6
#bit LCD_D7=0x06.7*/
#define LCD_D0 PIN_B0
#define LCD_D1 PIN_B1
#define LCD_D2 PIN_B2
#define LCD_D3 PIN_B3

void lcd_set_data(int8 dat){
   output_bit(LCD_D0,dat&0x01);
   output_bit(LCD_D1,dat&0x02);
   output_bit(LCD_D2,dat&0x04);
   output_bit(LCD_D3,dat&0x08);
   output_bit(LCD_D4,dat&0x10);
   output_bit(LCD_D5,dat&0x20);
   output_bit(LCD_D6,dat&0x40);
   output_bit(LCD_D7,dat&0x80);
}
void lcd_send_nib(int8 nib){
    //LCD_DATA=nib;
    lcd_set_data(nib);
    LCD_EN=0b1;
    delay_us(400); 
    LCD_EN=0b0;
}



void lcd_cmd(int8 cmd){
    //lcd_send_2nib(cmd);
    delay_us(400); 
    LCD_RS=0b0; 
    LCD_RW=0b0;
    lcd_send_nib(cmd);
    //RS=0b1;
}
void lcd_putChar(int8 dat){
    delay_us(400); 
 
    LCD_RS=0b1;
    LCD_RW=0b0;
    lcd_send_nib(dat);
    //Rs=0b0;

}
void lcd_move(int8 y, int8 x){
   int8 tmp; 

   //line = (line==0) ? 0 : 1; 
   //pos  = (pos >NCHAR_PER_LINE) ? NCHAR_PER_LINE : pos; 

   tmp = 0x80 + 0x40*(y-1) + x-1; 
   lcd_cmd(tmp); 
}

//
void lcd_init(void) 
{ 
        set_tris_B(0x00);
        set_tris_C(0x00);
       // output_low(LCD_E);              // Let LCD LCD_EN line low 
        LCD_EN=0b0;
      
      lcd_cmd(0x03);            // LCD 16x2, 5x7, 8bits data 
        delay_ms(15); 
      
      lcd_cmd(0x02);            // LCD 16x2, 5x7, 8bits data 
        delay_ms(15); 
      
        lcd_cmd(0x38);            // LCD 16x2, 5x7, 8bits data 
        delay_ms(15); 
        lcd_cmd(0x01);            // Clear LCD display 
        delay_ms(10); 
        lcd_cmd(0x0f);            // Open display & current 
        delay_ms(10); 
        lcd_cmd(0x06);            // Window fixed 
        delay_ms(10); 
}//end lcd_init() 
// 

void lcd_print_str(char str[]) 
{ 
     //int8 i; 
        for(int8 i=0; i<16; i++) 
                { 
                if(str[i] == '\0') break; 
                lcd_putChar(str[i]); 
                } 
}//end lcd_display_str() 

