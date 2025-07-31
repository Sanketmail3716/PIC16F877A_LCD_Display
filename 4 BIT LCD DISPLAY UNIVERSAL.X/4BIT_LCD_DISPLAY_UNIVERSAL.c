#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection

#include <xc.h>
#include<PIC16F877A.h>
#define _XTAL_FREQ 20000000
#define LCD_PORT PORTD
//#define LCD_CONTROL IOPIN1
#define RS RC0
#define EN RC1
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
//#define LCD_CONTROL_PIN ((1<<RS)|(1<<EN))
#define LCD_DATA_PIN ((1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7))

void LCD_Init();
void bit_sep(char nibble);
void command(char cmd);
void LCD_Char(char data);
void LCD_string(unsigned char *dat);
void main()
{
    TRISC0=0;
    TRISC1=0;
    TRISD&=~((1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7));
   
    
    LCD_Init();
    
	command(0xC0);
    LCD_string("PALLAVI");
    command(0x80);
    LCD_string("BAHULEKAR");
	while(1)
	{
	}
}

void LCD_Init()
{
	__delay_ms(10);
	command(0x28);
	command(0x0C);
    command(0x06);
	command(0x01);	
}

void bit_sep(char nibble)
{
	LCD_PORT&=~(LCD_DATA_PIN);
	LCD_PORT|=(((nibble>>0x00)&0x01)<<LCD_D4);
	LCD_PORT|=(((nibble>>0x01)&0x01)<<LCD_D5);
	LCD_PORT|=(((nibble>>0x02)&0x01)<<LCD_D6);
	LCD_PORT|=(((nibble>>0x03)&0x01)<<LCD_D7);
}

void command(char cmd)
{
	bit_sep((cmd>>0x04)&0x0F);
	RS=0;							 						
	EN=1;        				
	__delay_ms(10);
	EN=0;       
	
	bit_sep(cmd&0x0F);
	RS=0;													
	EN=1;        				
	__delay_ms(10);
	EN=0;        
}

void LCD_Char(char data)
{
	bit_sep((data>>0x04)&0x0F);
	RS=1;							 
    EN=1;
	__delay_ms(10);
	EN=0;        
	
	bit_sep(data&0x0F);
	RS=1;					 								
	EN=1;        				
	__delay_ms(10);
	EN=0;           
}
void LCD_string(unsigned char *dat)
{
    while(*dat!='\0')
    {
        LCD_Char(*dat);
        dat++;
    }
}