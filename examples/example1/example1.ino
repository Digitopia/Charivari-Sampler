// This example plays a looping "wav" file

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "AudioSamplePizzicatoa3w.h"

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=169,203
AudioOutputI2S           i2s1;           //xy=393,210
AudioConnection          patchCord1(playMem1, 0, i2s1, 0);
AudioConnection          patchCord2(playMem1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=412,288
// GUItool: end automatically generated code

void setup(){
  AudioMemory(8);
  playMem1.play(AudioSamplePizzicatoa3w); 
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.707);
}

void loop(){
  if(!playMem1.isPlaying()) playMem1.play(AudioSamplePizzicatoa3w);
}
