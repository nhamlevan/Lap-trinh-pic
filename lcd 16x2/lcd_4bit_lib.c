//thu vien giao tiep lcd 4 bit
void lcd_set_data(int8 dat){
   //byte z=dat;
   output_bit(LCD_D4,dat&0x01);
   output_bit(LCD_D5,dat&0x02);
   output_bit(LCD_D6,dat&0x04);
   output_bit(LCD_D7,dat&0x08);
  
  
  /* output_bit(LCD_D4,dat&0x01);
   output_bit(LCD_D5,(dat>>1)&0x01);
   output_bit(LCD_D6,(dat>>2)&0x01);
   output_bit(LCD_D7,(dat>>3)&0x01);*/
}
void lcd_send_2nib(int8 nib){
    //LCD_DATA=(nib);
   lcd_set_data(nib>>4);
    LCD_EN=0b1;
    delay_us(10); 
    LCD_EN=0b0;
    
    //LCD_DATA=nib<<4;
    lcd_set_data(nib);
    LCD_EN=0b1;
    delay_us(10); 
    LCD_EN=0b0;
}



void lcd_cmd(int8 cmd){
    delay_us(400); 
    LCD_RS=0b0; 
    LCD_RW=0b0;
    lcd_send_2nib(cmd);
}
void lcd_putChar(int8 dat){
    delay_us(400); 
 
    LCD_RS=0b1;
    LCD_RW=0b0;
    lcd_send_2nib(dat);
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
        set_tris_B(0x0F);
        set_tris_C(0x00);
       // output_low(LCD_E);              // Let LCD E line low 
        LCD_EN=0b0;     
        LCD_RS=0b0;
        LCD_RW=0b0;
        
        lcd_send_2nib(0x03);
        delay_ms(1);
        lcd_send_2nib(0x02);
        
        lcd_cmd(0x28);            // LCD 16x2, 5x7, 4bits data 
        delay_ms(15); 
        lcd_cmd(0x01);            // Clear LCD display 
        delay_ms(10); 
        lcd_cmd(0x0f);            // Open display & current 
        delay_ms(10); 
        lcd_cmd(0x06);            // Window fixed 
        delay_ms(10); 
        lcd_cmd(0x0c);            // Window fixed 
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

