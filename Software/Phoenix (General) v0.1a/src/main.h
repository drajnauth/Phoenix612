#ifndef _MAIN_H_
#define _MAIN_H_

#define REMOVE_CLI
#define D612_HEADER 0xFEEDBEEF


// ADC is 10 bits, values 0-10235/1024*4096
// For Max 5V, conversion is 5/1025
// Use fixed point. 5/1024*4096=20
#define ADC_CONVERSION  20             
#define FIXED_POINT_CONVERSION 4096

#define SMETER_PIN A0
#define FWD_PIN A1
#define REV_PIN A2
#define PTT_OUT_PIN 9

#define SMETER_SAMPLES 20
#define SMETER_BASELINE_SAMPLES 200
#define SWR_SAMPLES 20

#define UPDATE_MEMORY_THRESHOLD 300000    // 5 minutes
#define UPDATE_SMETER_THRESHOLD 250       // 500ms

#define MAX_SMETER_BLOCKS 12
#define FWD_POWER_REFERENCE 5


#define MAX_MODES 3
#define LSB_MODE 0
#define USB_MODE 1
#define TUNE_MODE 2

//#define VFOA 0
//#define VFOB 1

#define RX_BFO_CLK 2
#define RX_LO_CLK 0

#define TX_BFO_CLK 0
#define TX_LO_CLK 2

#define RECEIVE 0
#define TRANSMIT 1


#define CALPLLFREQ 700000000UL
#define CALFREQ 10000000UL

//#define DEFAULT_USBBFO 4916007    // 4.9 Mhz IF
//#define DEFAULT_LSBBFO 4913007    // 4.9 Mhz IF
//#define DEFAULT_CWBFO 4915107    // 4.9 Mhz IF

#define DEFAULT_USBBFO 11999950      // 12 Mhz IF 
#define DEFAULT_LSBBFO 11995350      // 12 Mhz IF
#define DEFAULT_CWBFO 11997650       // 12 Mhz IF

//#define DEFAULT_BFO_PLL_MULT  142   // 4.9 Mhz IF pll multiplier
#define DEFAULT_BFO_PLL_MULT  64    // 12 Mhz IF pll multiplier


#define MAX_BANDS 5
#define EEPROM_OFFSET 256

#define BAND80M 0
#define BAND60M 1
#define BAND40M 2
#define BAND30M 3
#define BAND20M 4

#define BANDOFFSET0 "80m"
#define BANDOFFSET1 "60m"
#define BANDOFFSET2 "40m"
#define BANDOFFSET3 "30m"
#define BANDOFFSET4 "20m"


#define FREQUENCY_DISPLAY_SHIFT 7
#define VFOB_FREQUENCY_DISPLAY_SHIFT 4
#define MENU_DISPLAY_SHIFT 6
#define MENU_LARGEDISPLAY_SHIFT 8

// Menu Options
#define MAXMENU_ITEMS 9
#define MAXMENU_LEN 12

// Menu Options
#define RADIO 0
#define BFO_CORRECT 1
#define LO_CORRECT 2
#define Si_CORRECT 3
#define Sm_BASELIN 4
#define Sm_CORRECT 5
#define Fw_CORRECT 6
#define Rv_CORRECT 7
#define FACT_RESET 8

#define MAX_RADIO_SELECTION 5   // was 6 for RXTX mode change
#define RADIO_FREQ_MODE 0
#define RADIO_MODE 1
#define RADIO_VFOB_MODE 2
#define RADIO_BAND_MODE 3
#define RADIO_MENU_MODE 4

typedef struct {
  unsigned long flags;
  unsigned char BandOffset;
  unsigned char BandOffsetB;
  unsigned char VFO;
  unsigned char RxTx;
  unsigned long FreqA;
  unsigned long FreqB;
  int FwdCorrection;
  int RevCorrection;
  int correction;   // can be + or -
} D612_Struct;

#define BAND_HEADER 0xBA0DDA0A
typedef struct {
  unsigned long flags;
  unsigned long FreqLow;
  unsigned long FreqHigh;
  unsigned long Freq;
  unsigned long FreqInc;
  unsigned char Mode;
  unsigned long BFOFreq;
  unsigned long USBBFOFreq;
  unsigned long LSBBFOFreq;
  unsigned long CWBFOFreq;
  int LOOffset;
  int USBBFOOffset;
  int LSBBFOOffset;
  int CWBFOOffset;
  unsigned int SmeterBaseline;
  int SmeterCorrection;
  unsigned int MSN_a;   // Multisynth
  unsigned int PLL_a;   // PLL divider   
} Band_Struct;



// General Flags
#define BFLAGS 1
#define MFLAGS 0

#define CHANGE_FREQ             0x1
#define CHANGE_BAND             0x2
#define CHANGE_RXTX             0x4
#define CHANGE_MODE             0x8
#define CHANGE_VFOB             0x10
#define CHANGE_MENU             0x20

#define UPDATE_MEMORY           0x40
#define OPTION_CHANGED          0x80
#define DISABLE_BUTTONS         0x100

#define CHANGE_SmB              0x00200000
#define CHANGE_SmC              0x00400000
#define CHANGE_Fw               0x00800000
#define CHANGE_Rw               0x01000000
#define CHANGE_Si               0x02000000
#define CHANGE_BFO              0x04000000
#define CHANGE_LO               0x08000000
#define ANY_MENU_OPTIONS        0x0FF00000

#define ROTARY_CW             0x01
#define ROTARY_CCW            0x02
#define ROTARY_PUSH           0x04
#define PBUTTON1_PUSHED       0x08
#define PBUTTON2_PUSHED       0x10
#define PTT_PUSHED            0x20
#define PTT_CLEAR             0x40
#define MASTER_RESET          0x80
#define ANY_BUTTON            0xFF


#define MAX_MESSAGES 2
#define AUTOSAVE_MEMORY_MS 2000

#define MAXCLK 3

// Mesages
#define NESSAGE1 20
#define HEADER1 20
#define HEADER2 11
#define CLKENTRYLEN 20

#define LCD_CLEAR_LINE_LENGTH 21
#define LCD_ERROR_MSG_LENGTH 9

#define DEFAULT_FREQUENCY_MULTIPLIER 1000
#define MAXIMUM_FREQUENCY_MULTIPLIER 100000
#define MINIMUM_FREQUENCY_MULTIPLIER 1


void UpdateBFOFrequency (void);
void UpdateLOFrequency (void);
unsigned char FrequencyDigitUpdate (long inc);
void SetBFOFrequency (void) ;

void SetupBFOMSNDividers (void); 
void SetupLOMSNDividers (void);
void SetupAllMSNDividers (void);

void Reset (void);
void getBandData(unsigned char band, unsigned char vfo);
void putBandData (unsigned char band);
void printBandData(void);
void resetFlash (void);
void putConfigData (void);
void getConfigData (void);

void MenuDisplayMode(void);
void RadioUpdateFreq (void);
void RadioUpdateFreqB (void);
void RadioUpdateOther (void);
void PTT (unsigned char ptt);
void ResetMenuMode (void);

void RefreshLCD (void);
void LoadMemory (void);

unsigned int getSmeterValue (unsigned char samples);
void getPmeterValue (unsigned char samples);
void updateSmeter (void);
void updatePmeter (void);
void drainSmeterCap (unsigned int dly);

unsigned char GetRotaryNumber (int lnum, int hnum, int maxinc);

unsigned char checkFlag (unsigned char type, unsigned long bitmask);
void setFlag (unsigned char type, unsigned long bitmask);
void clearFlag (unsigned char type, unsigned long bitmask);



//long absl (long v);

//void printMem (void);
//void printCurrentMem (void);
//void printGlobalMem (void);


void ClearFlags(void);
unsigned char checkClearFlag(unsigned char type, unsigned long bitmask);
void ChangeRadioSelection(void);
void doMenuSelection(void);

#endif // _MAIN_H_
