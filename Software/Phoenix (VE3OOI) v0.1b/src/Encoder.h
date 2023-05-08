#ifndef _ENCODER_H_
#define _ENCODER_H_

/* Rotary encoder Pins*/
/* Arduino Pin 10, 11
 * PortB PB2, PB3 (i.e bit 2 and bit 3 of the 8 bit PortB)
 * Need to right shift 2 to get values as LSB (or bottom 2 bits)
 * However need to mask off bottom two bits when reading since bottom 2 bits is Tx/Rx
 * 
 */
#define ENC_A 10
#define ENC_B 11
#define ENC_PB 12

#define ENC_PORT PINB
#define ENC_PBPORT PINB
#define CW           1        // Encoder rotated clockwise
#define CCW          0        // Encoder rotated counter clockwise

//Push Buttons
#define BUTTON_ON_DEFAULT
#define PBUTTON1 5
#define PBUTTON2 6
#define PTT_BUTTON 8


#define PBUTTON_STATE LOW

#define PUSH_BUTTON_RESET 200
#define PUSH_BUTTON_RELAXATION 60

#define PBDEBOUNCE 30
#define PTTDEBOUNCE 10

#define PB1ENABLED 0x1
#define PB2ENABLED 0x2
#define PB3ENABLED 0x4

// Encoder Routines
void ResetEncoder (void);
void SetupEncoder (void);
int ReadEncoder(void);
void ReadPBEncoder(void);
void CheckEncoder (void);
void CheckPushButtons (void);


#endif // _ENCODER_H_
