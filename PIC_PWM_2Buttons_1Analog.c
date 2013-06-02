#include <stdio.h>
#include <stdlib.h>
#include <htc.h>

#define _XTAL_FREQ 8000000

#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/8000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/8000.0)))

/*   PIC Configuration Bit:
**   INTIO     - Using Internal RC No Clock
**   WDTDIS    - Watchdog Timer Disable
**   PWRTEN    - Power Up Timer Enable
**   MCLREN    - Master Clear Enable
**   UNPROTECT - Code Un-Protect
**   UNPROTECT - Data EEPROM Read Un-Protect
**   BORDIS    - Borwn Out Detect Disable
**   IESODIS   - Internal External Switch Over Mode Disable
**   FCMDIS    - Monitor Clock Fail Safe Disable
*/
// CONFIG               //INTRCIO
#pragma config FOSC = INTRCIO  // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF       // Brown-out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

void main(void)
{
  unsigned int ipwm;

  TRISA = 0b00000111;        // Input for RA0 and RA1 og RA2 einnig
  TRISB = 0b11110000;        // B to digital i/o input
  TRISC = 0b00000000;        // Set All on PORTC as Output ekki sem input

  ANSEL = 0b00000001;        // Set PORT AN0 to analog input AN1 to AN7 digital I/O
  ANSELH = 0b00000000;       // Set PORT AN8 to AN11 as Digital I/O
  PORTC = 0b00000000;        // Turn Off all PORTC, byrja low

  TRISBbits.TRISB4 = 0; //set RB4 sem output
  TRISBbits.TRISB5 = 0; //set RB5 sem output
  TRISBbits.TRISB7 = 0; //set RB7 sem output

 // CCP1CON=0b00001111;  // Single PWM mode; P1A, P1B, P1C, P1D
  CCP1CON=0b00001100;  // Single PWM mode; P1A, P1C active-high; P1B, P1D active-high
  CCPR1L=0;            // Start with zero Duty Cycle

  T2CON=0b00000101;     // Postscale: 1:1, Timer2=On, Prescale = 1:1  0b00000100
  PR2=0b00011000;       // Frequency: 19.61 kHz,  0x65 20 khz
  TMR2=0b00000000;       // Start with zero Counter

  /* Init ADC */
  ADCON0=0b00000000;   // Select Left justify result. ADC port channel 0
  ADCON1=0b00110000;   // Select the FRC for 8 MHz
  ADON=1;	        // turn on the ADC conversion module

  ipwm=0;

  PORTBbits.RB4 = 0;    //vinstra ljos slokkt
  PORTBbits.RB5 = 0;    //haegra ljos slokkt
  PORTBbits.RB7 = 0;    //keyrslu ljos kveikt

  PSTRCON=0b00000000;   // full stop til ad byrja


  for(;;)
  {
      if (PORTAbits.RA1 == 0 && PORTAbits.RA2 == 0)     //vinstri takki verdur virkur
      {
          PORTBbits.RB4 = 0;    //ljos
          PORTBbits.RB5 = 0;
          PORTBbits.RB7 = 1;
          PSTRCON=0b00000000;   //full stop
          __delay_ms(100);
      }
      else if (PORTAbits.RA1 == 1 && PORTAbits.RA2 == 0)     //vinstri takki verdur virkur
      {
          PORTBbits.RB4 = 1;    //ljos
          PORTBbits.RB5 = 0;
          PORTBbits.RB7 = 0;
          PSTRCON=0b00001000;   //full stop
          __delay_ms(100);
      }
      else if (PORTAbits.RA1 == 0 && PORTAbits.RA2 == 1) //haegri takki verdur virkur
      {
          PORTBbits.RB4 = 0;    //ljos
          PORTBbits.RB5 = 1;
          PORTBbits.RB7 = 0;
          PSTRCON=0b00000100;   //full stop
          __delay_ms(100);
      }
      else if (PORTAbits.RA1 == 1 && PORTAbits.RA2 == 1) //badir takkar verda virkir
      {
          PORTBbits.RB4 = 1;    //ljos
          PORTBbits.RB5 = 1;
          PORTBbits.RB7 = 1;
          PSTRCON=0b00000000;   //full stop
          __delay_ms(100);
      }
      
    GO_DONE=1;	              // initiate conversion on the channel 0
    while(GO_DONE) continue;        // Wait conversion done

    ipwm = ADRESH;           // Get the highest 8 bit MSB result, ignore the 2 bit LSB
    CCPR1L=ipwm;             // Set the Duty Cycle base on the ADC result
    }
}
//Lykkja fyrir haekkandi og laekkandi PWM
/*  for(;;) {
    ipwm=0;
    while (ipwm < 255) {
      CCPR1L=++ipwm;
       __delay_ms(50);   // Delay 5 millisecond
    }
    ipwm=0xff;
    while (ipwm > 0) {
      CCPR1L=--ipwm;
       __delay_ms(50);   // Delay 5 millisecond
    }
     __delay_ms(100);   // Delay 100 millisecond
  }*/



