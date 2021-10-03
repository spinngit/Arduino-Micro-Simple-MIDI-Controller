//
// SL1200 USBMIDI Fader mk2
// by spinn.teramoto (Akihabara Housing, Ltd.) 2021
//
// note: Pitch fader of SL-1200 mkII is "A Curve" potentiometer.
//       So it need to be converted to "B Curve"
//
//       0                 833                 1023
//       |------------------+-------------------|     :Original Scale (A curve(Log))
//                           
//       0                 64                  127
//       |------------------+-------------------|     :Converted Scale (B curve(Linear))
//

#include "MIDIUSB.h"         // include MIDIUSB library

const int FADER = A0;        //  Pitch Fader pin
const int LED = 12;          //　Center LED pin
const int SWITCH1 = 3;       //  Deck A selector pin
const int SWITCH2 = 5;       //  Deck B selector pin
const int BEND1 = 8;         //  Bend Down pin
const int BEND2 = 10;        //  Bend UP pin

int analogval =0;            // original fader val (0-1023)
float s0 = 0;                // Internal val for curve conversion
float s1 = 0;                // Internal val for curve conversion
float adjustval = 2.4287;    // Log((1023-833/1023), 0.5), "833" is original fader value of center position
int faderval = 0;            // Pitch Fader Val (0-127)
int faderval_old =0;         // Fader Val Old

int switchval_1 = 0;         // Switch 1 value
int switchval_1_old = 0;     // Switch 1 value old
int switchval_2 = 0;         // Switch 2 value
int switchval_2_old = 0;     // Switch 2 value old
int bendval_1 = 0;           // Bend 1 value
int bendval_2 = 0;           // Bend 2 value

int val0= 0;                 // Internal val for Fader
int val1= 0;                 // Internal val for Switch 1
int val2= 0;                 // Internal val for Switch 2


void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(SWITCH1, INPUT_PULLUP);  // Connecting Toggle Switch with pullup mode
  pinMode(SWITCH2, INPUT_PULLUP);  //
  pinMode(BEND1, INPUT_PULLUP);    // Connecting Bend Switch with pullup mode
  pinMode(BEND2, INPUT_PULLUP);    //
  Serial.begin(9600);
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

 
void loop() 
{

//////// Pitch Fader

// Calculating fader value
  int analogval = analogRead(FADER);                  // Read fader value
  float s0 = (float)(1023 - analogval)/1023.0;        // Convert A curve to B curve
  float s1 = pow(s0,1.0/adjustval);                   
  int faderval = 127 - int(s1*127);                   // Set Fader value in B curve scale

// Light LED up when fader position is middle
  if ( faderval == 64 ) {
  digitalWrite( LED, HIGH );
  } else {
  digitalWrite( LED, LOW );
  }

// sending control change
  int val0 = faderval - faderval_old;
  if ( not( val0 == 0 )) {
      controlChange(5, 16, faderval);   // Channel 6, Control Change 016, Fader value
      MidiUSB.flush();
  }
  faderval_old = faderval;
  

/////// Deck Selector

// Reading Switch Value
  int switchval_1 = digitalRead(SWITCH1);
  int switchval_2 = digitalRead(SWITCH2);

// Sending note by Switch 1
  int val1 = switchval_1 - switchval_1_old;
  if ( not(val1 == 0) ) {
    if ( switchval_1 == 1 ) {  
          noteOn(5, 48, 64);   // Channel 6, C3, normal velocity
          MidiUSB.flush();
          delay(500);
          noteOff(5, 48, 64);  // Channel 6, C3, normal velocity
          MidiUSB.flush();
     }
  switchval_1_old = switchval_1;
  }

// Sending note by Switch 2
  int val2 = switchval_2 - switchval_2_old;
  if ( not(val2 == 0) ) {
    if ( switchval_2 == 1 ) {  
          noteOn(5, 50, 64);   // Channel 6, D3, normal velocity
          MidiUSB.flush();
          delay(500);
          noteOff(5, 50, 64);  // Channel 6, D3, normal velocity
          MidiUSB.flush();
     }
  switchval_2_old = switchval_2;
  }


/////// Pitch Bender

// Reading Switch Value
  int bendval_1 = digitalRead(BEND1);    //  On=0, Off=1
  int bendval_2 = digitalRead(BEND2);    //  On=0, Off=1

// Sending note by Bend 1 (down)
  
   if ( bendval_1 == 0 ) {  
          noteOn(5, 52, 64);   // Channel 6, E3, normal velocity
          MidiUSB.flush();
          delay(50);
          noteOff(5, 52, 64);  // Channel 6, E3, normal velocity
          MidiUSB.flush();
  }

// Sending note by Bend 2 (up)
   if ( bendval_2 == 0 ) {  
          noteOn(5, 53, 64);   // Channel 6, F3, normal velocity
          MidiUSB.flush();
          delay(50);
          noteOff(5, 53, 64);  // Channel 6, F3, normal velocity
          MidiUSB.flush();
  }
}
