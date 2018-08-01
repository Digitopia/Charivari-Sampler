// This example changes a looping "wav" file's length using a potentiometer

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "AudioSamplePizzicatoa3w.h"


// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=104,215
AudioEffectGranular      granular1;      //xy=238,214
AudioOutputI2S           i2s1;           //xy=393,210
AudioConnection          patchCord1(playMem1, granular1);
AudioConnection          patchCord2(granular1, 0, i2s1, 0);
AudioConnection          patchCord3(granular1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=412,288
// GUItool: end automatically generated code

#define GRANULAR_MEMORY_SIZE 5120  // 12800 is enough for 290 ms at 44.1 kHz
int16_t granularMemory[GRANULAR_MEMORY_SIZE];
int counter = 0; 
int len = 700; // sample duration in ms 

void setup(){
  AudioMemory(50);
  // the Granular effect requires memory to operate
  granular1.begin(granularMemory, GRANULAR_MEMORY_SIZE); 
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.707);
  //randomSeed(analogRead(A0));
}

void loop(){
  if(!playMem1.isPlaying()){
    playMem1.play(AudioSamplePizzicatoa3w);
    granular1.beginFreeze(len);
  }
  counter++;
  if (counter > len){
    counter = 0;
    len = 1 + (analogRead(A0) >> 1);
    playMem1.stop();
  }
  delay(1);
}
