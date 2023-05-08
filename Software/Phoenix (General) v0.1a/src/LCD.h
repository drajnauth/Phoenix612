#ifndef _MyLCD_H_
#define _MyLCD_H_


#define SMETER_START 0
#define SMETER_SIZE 11
#define MODE_START 17
#define VFOB_START 0
#define FREQ_START 3
#define RXTX_START 0
#define BAND_START 14
#define SWR_START 12
#define MENU_START 0 
#define MENU_NUMBER_START 12

void SetupLCD (void);
void LCDClearScreen (void);

void LCDDisplayHeader (void);
void LCDClearClockWindow (void);
void LCDClearLine (unsigned char pos); 


void LCDSelectLine (unsigned char pos, unsigned char line, unsigned char enable);
void RestoreLCDSelectLine (void);

void LCDDisplayRxTx (void);
void LCDDisplayBand (void);
void LCDDisplayMode (void);
void LCDDisplaySmeter (unsigned char num);
void LCDDisplaySValue (unsigned char num);

void LCDDisplayVFOBFreq (void);
void LCDDisplayMenuOption (unsigned char line);
void LCDDisplayFreq (void);
void LCDDisplaySWR (double swr);
void LCDClearSWR (void);
void LCDDisplayMenuItem (unsigned char line);

void LCDDisplayMenuSmallNumbner (int number, int inc);
void LCDDisplayMenuLargeNumbner (int number, int inc);


#endif // _MyLCD_H_
