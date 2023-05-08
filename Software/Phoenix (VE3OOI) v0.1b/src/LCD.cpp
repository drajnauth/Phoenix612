
/*

  Program Written by Dave Rajnauth, VE3OOI to control the 4x20 LCD.
  
  Software is licensed (Non-Exclusive Licence) under a Creative Commons Attribution 4.0 International License.


 */

#include "Arduino.h"

#include <stdint.h>
#include <Wire.h>  // Comes with Arduino IDE

#include "main.h"   // Defines for this program
#include "LCD.h"
#include "Encoder.h"
#include "Timer.h"

//========================================================
// LCD Library
// Can use either LiquidCrystal or HD44780 library.
// define below selects which library to use
//========================================================
#define USE_HD44780     // if this is defined, will use the HD44780 libary
                        // if commented out, will use LiquidCrystal library

// LCD geometry
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

#ifdef USE_HD44780
#include <hd44780.h>                        // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h>  // i2c expander i/o class header
hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip

#else
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
#endif  //USE_HD44780
//========================================================


extern char header1[HEADER1];
extern char header2[HEADER2];

extern char clkentry [CLKENTRYLEN];

extern char clearlcdline[LCD_CLEAR_LINE_LENGTH];
extern char clearlcderrmsg[LCD_ERROR_MSG_LENGTH];

// Frequency Control variables
extern volatile unsigned long frequency_clk, PSKCarrierFrequency;
extern volatile long frequency_inc;
extern volatile long frequency_mult;
extern volatile long offset_inc;
extern volatile int calibration_mult;

// LCD Menu 
extern volatile unsigned char MenuSelection, ClkSelection;
extern char RootMenuOptions[MAXMENU_ITEMS][MAXMENU_LEN];

extern D612_Struct sg;
extern Band_Struct mem;
extern Band_Struct memB;

unsigned char lastLCDSelect[2];

void SetupLCD (void)
{
/*
  int status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
    status = -status; // convert negative status value to positive number

    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }
*/
  lcd.begin(LCD_COLS, LCD_ROWS);

  lcd.backlight();
  lcd.setCursor(0,0);                         //Goto at position 0 line 0
  lcd.noCursor(); 
  lcd.noBlink(); 
}

void LCDDisplayHeader (void) 
{
  unsigned char i;
  
  LCDClearScreen ();
  lcd.print(header1);
  lcd.setCursor(0,1);                         //Goto at position 0 line 1
  lcd.print(header2);
  
  lcd.setCursor(0, 2);
  for (i=0; i<19; i++) {
    lcd.print((char)0xFF);
    delay (50);
  }
  lcd.setCursor(0, 3);
  for (i=0; i<19; i++) {
    lcd.print((char)0xFF);
    delay (50);
  }
}

void LCDClearScreen (void)
{
  lcd.clear();   
  lcd.noCursor(); 
  lcd.noBlink(); 
}

void LCDClearLine (unsigned char pos) 
{
  lcd.setCursor(0,pos);
  memset (clkentry, 0x20, sizeof(clkentry));
  clkentry[CLKENTRYLEN-1] = 0;
  lcd.print( clkentry );

}


void LCDSelectLine (unsigned char pos, unsigned char line, unsigned char enable)
{
  if (enable) {
    lcd.setCursor(pos,line); 
    lcd.cursor(); 
    lcd.blink(); 
    lastLCDSelect[0] = pos;
    lastLCDSelect[1] = line;
  } else {
    lcd.setCursor(pos,line);
    lcd.noCursor(); 
    lcd.noBlink(); 
  }
}

void RestoreLCDSelectLine (void)
{
  lcd.setCursor( lastLCDSelect[0], lastLCDSelect[1] ); 
  lcd.cursor(); 
  lcd.blink(); 
}


void LCDDisplayBand (void)
{
  
  lcd.setCursor(BAND_START,2);                         //Goto at position 0 line 0
  switch (sg.BandOffset) {
    case 0:
      lcd.print(BANDOFFSET0);
      break;
      
    case 1:
      lcd.print(BANDOFFSET1);
      break;
      
    case 2:
      lcd.print(BANDOFFSET2);
      break;
      
    case 3:
      lcd.print(BANDOFFSET3);
      break;
      
    case 4:
      lcd.print(BANDOFFSET4);
      break;
      
  }
  LCDSelectLine (BAND_START,2,1);
 
}

void LCDDisplayMenuItem (unsigned char line)
{
  lcd.setCursor(MENU_START,3);                         //Goto at position 0 line 0
  lcd.print(RootMenuOptions[line]);
  LCDSelectLine (MENU_START,3,1);
  
}

void LCDDisplayRxTx (void)
{
  lcd.setCursor(RXTX_START,0);                         //Goto at position 0 line 0
  if (sg.RxTx == RECEIVE) {
    lcd.print("Rx");   
  } else {
    lcd.print("Tx");   
  }
  RestoreLCDSelectLine();
}

void LCDDisplayMenuSmallNumbner (int number, int inc)
{
  unsigned char pos;
  
  pos = FrequencyDigitUpdate(inc) + MENU_DISPLAY_SHIFT;
  
  lcd.setCursor(MENU_NUMBER_START,3);
  memset (clkentry, 0, sizeof(clkentry));         // Terminate the string  
  sprintf (clkentry, "%03d", number);
  lcd.print( clkentry );
  LCDSelectLine (pos, 3, 1);
}

void LCDDisplayMenuLargeNumbner (int number, int inc)
{
  unsigned char pos;
  
  pos = FrequencyDigitUpdate(inc) + MENU_LARGEDISPLAY_SHIFT;
  
  lcd.setCursor(MENU_NUMBER_START,3);
  memset (clkentry, 0, sizeof(clkentry));         // Terminate the string  
  sprintf (clkentry, "%05d", number);
  lcd.print( clkentry );
  LCDSelectLine (pos, 3, 1);
  
}



void LCDDisplayFreq (void)
{
  unsigned char pos;
  pos = FrequencyDigitUpdate(mem.FreqInc) + FREQUENCY_DISPLAY_SHIFT;
  
  lcd.setCursor(FREQ_START,0);
  memset (clkentry, 0, sizeof(clkentry));         // Terminate the string  
  sprintf (clkentry, "VFO%c:%08lu", sg.VFO, mem.Freq);
  lcd.print( clkentry );
  LCDSelectLine (pos, 0, 1);
}


void LCDDisplayVFOBFreq (void)
{
  unsigned char pos;
  char vfo;
  pos = FrequencyDigitUpdate(memB.FreqInc) + VFOB_FREQUENCY_DISPLAY_SHIFT;
  
  lcd.setCursor(VFOB_START,2);
  memset (clkentry, 0, sizeof(clkentry));         // Terminate the string  
  if (sg.VFO == 'A') {
    vfo = 'B';
  } else {
    vfo = 'A';
  }
  sprintf (clkentry, "VFO%c:%08lu", vfo, sg.FreqB);
  lcd.print( clkentry );
  LCDSelectLine (pos, 2, 1);
}



void LCDDisplayMode (void)
{
  lcd.setCursor(MODE_START,0);                         //Goto at position 0 line 0
  switch (mem.Mode) {
    case LSB_MODE:
      lcd.print("LSB");
      break;
      
    case USB_MODE:
      lcd.print("USB");
      break;
      
    case TUNE_MODE:
      lcd.print("TUN");
      break;
  }
  LCDSelectLine (MODE_START,0,1);

}


void LCDDisplaySmeter (unsigned char num)
{
  char sbuf[SMETER_SIZE+1];
  memset (sbuf, 0x20, sizeof(sbuf));
  memset (sbuf, 0xFF, num);
  sbuf[SMETER_SIZE] = 0;
  
  lcd.setCursor(SMETER_START,1);
  lcd.print(sbuf);    
  LCDSelectLine (SMETER_START,1,0);
}

void LCDClearSWR (void)
{
  lcd.setCursor(SWR_START,1);
  memset (clkentry, 0, sizeof(clkentry));         // Terminate the string  
  memset (clkentry, 0x20, (20-SWR_START));         // Terminate the string  
  lcd.print( clkentry );
}


void LCDDisplaySWR (double swr)
{
  char temp[5];
  memset (temp, 0, sizeof(temp));                 // Terminate the string  
  if (swr == -999) {
    strcpy(temp, ">9  ");
  } else if (swr <= 0) {
    strcpy(temp, "-.--");
  } else {
    dtostrf(swr, 4, 2, temp);
  }
  lcd.setCursor(SWR_START,1);
  memset (clkentry, 0, sizeof(clkentry));         // Terminate the string  
  sprintf (clkentry, "SWR:%s", temp);
  lcd.print( clkentry );

}

void LCDDisplaySValue (unsigned char num)
{

  lcd.setCursor(SWR_START,1);
  memset (clkentry, 0, sizeof(clkentry));         // Terminate the string  
  sprintf (clkentry, "S:%02d", num);
  lcd.print( clkentry );

}


void LCDDisplayMenuOption (unsigned char line) 
{  
  lcd.setCursor(MENU_START, 3);                         //Goto at position 7 line 2
  lcd.print( RootMenuOptions[line] );
  LCDSelectLine (MENU_START,3,1);
}
