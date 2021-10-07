/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_AS3, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, 0, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_AS3,0, NOTE_AS3, NOTE_F4, NOTE_DS4, 0
  ,NOTE_C4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, 0, NOTE_AS3, NOTE_AS3, NOTE_C5,NOTE_AS4, 0, 0 ,NOTE_C4,
  NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_AS3, NOTE_F4, 0, NOTE_DS4, NOTE_DS4, 0, 
  NOTE_C4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, 0, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_AS3, 0, NOTE_AS3, NOTE_F4, NOTE_DS4, 0 , NOTE_AS3,
  NOTE_C4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, 0, NOTE_AS3, NOTE_AS3, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, 0,0,NOTE_C4,
  NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_AS3, NOTE_F4, 0, NOTE_DS4, NOTE_DS4, 0,
  NOTE_AS4, 0, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_F4, 0, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_DS4, 0, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_AS4,
  NOTE_GS4, 0, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_B4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4, 0, NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_G4, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_DS4,
  NOTE_AS4, 0, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_B4, 0, NOTE_B4, NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_D4, NOTE_AS3, NOTE_F4, NOTE_G4, 0, NOTE_C4, NOTE_AS4,
  NOTE_GS4, NOTE_G4, NOTE_AS3, NOTE_F4, 0, NOTE_DS4, NOTE_DS4, 0,
  NOTE_AS4, NOTE_GS4, NOTE_DS4, 0, NOTE_AS4, NOTE_GS4,NOTE_CS4, 0, NOTE_AS4, NOTE_GS4, NOTE_DS4, 0, NOTE_DS4, NOTE_FS4, NOTE_GS4, NOTE_F4, NOTE_DS4, NOTE_AS3, 0, NOTE_AS3, NOTE_CS4,
  NOTE_DS4, NOTE_DS4, 0, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_AS3, 0, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_FS4,0, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, 0,
  
  NOTE_AS4, 0, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_F4, 0, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_DS4, 0, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_AS4,
  NOTE_GS4, 0, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_B4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4, 0, NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_G4, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_DS4,
  NOTE_AS4, 0, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_B4, 0, NOTE_B4, NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_D4, NOTE_AS3, NOTE_F4, NOTE_G4, 0, NOTE_C4, NOTE_AS4,
  NOTE_GS4, NOTE_G4, NOTE_AS3, NOTE_F4, 0,

   NOTE_AS3, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, 0, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_AS3,0, NOTE_AS3, NOTE_F4, NOTE_DS4, 0
  ,NOTE_C4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, 0, NOTE_AS3, NOTE_AS3, NOTE_C5,NOTE_AS4, 0, 0 ,NOTE_C4,
  NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_AS3, NOTE_F4, 0, NOTE_DS4, NOTE_DS4, 0
};

// note durations: 1 = whole note, 1.5= 3 beat note, 2 = half note, 3 = dotted note, 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = { 
  16, 1.5, 12, 12, 12, 4, 4, 8, 8, 8, 2, 8,8,8,1.5, 4,
  1.5, 12, 12, 12, 4, 4, 8, 8, 8, 1.5, 4, 1.5, 16,
  6, 6, 4, 4, 1.7, 4, 8, 1, .8,
  1.5, 12, 12, 12, 4, 3.5,16, 8, 8, 8, 1.75, 8, 8, 8, 1.5, 3.5, 16,
  1.5, 12, 12, 12, 4, 3.5, 8, 8, 8, 3, 16, 2, 4, 1.5, 16,
  6, 6, 4, 4, 1.9, 4, 8, .9, 1,
  4, 4, 8, 8, 8, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 4,
  8, 8, 8, 8, 4, 4, 8, 8, 4, 8, 8, 3, 16, 16, 3, 16, 16, 4, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 8, 8, 3, 8, 8, 8, 8, 8, 4, 4, 4, 4, 2, 4, 8, 6,
  6, 4, 4, 1.7, 4, 8, 1, .8,
  6,6,2,8,6,6,2,8,6,6,4,8,16,16,8,6,6,3,8,16,16,
  8,4,8,8,8,8,4,3,8,8,8,4,4,8,8,8,8,1.5,4,

  4, 4, 8, 8, 8, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 4,
  8, 8, 8, 8, 4, 4, 8, 8, 4, 8, 8, 3, 16, 16, 3, 16, 16, 4, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 8, 8, 3, 8, 8, 8, 8, 8, 4, 4, 4, 4, 2, 4, 8, 6,
  6, 4, 4, 1.3, 8,

  16, 1.5, 12, 12, 12, 4, 4, 8, 8, 8, 2, 8,8,8,1.5, 4,
  1.5, 12, 12, 12, 4, 4, 8, 8, 8, 1.5, 4, 1.5, 16,
  6, 6, 4, 4, 2, 4, 8, 1, .8
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 308; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
