#include "msp.h"
#include "csHFXT.h"
#include "lcd.h"
#include "sysTickDelays.h"

void initGPIO(void){
    /* Configure GPIO for speaker */
    P2->DIR |= BIT4;            // set P2.4 as output
    P2->SEL0 |= BIT4;           // P2.4 set to TA0.1
    P2->SEL1 &= ~BIT4;
}


/**
 * main.c
 */
void main(void) {
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    /* Sets MCLK and SMCLK to 48MHz HFXT */
    configHFXT();

    initGPIO();
    initLCD();
}



void RFIDinput(void) {
    int input = 0; // Make this the code from RFID

    switch (input) {
    case '0':
        //play song 1
        printString("song name");
        break;

    case '1':
        //play song 2
        printString("song name");
        break;
    }

}
