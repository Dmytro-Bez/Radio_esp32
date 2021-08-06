#include <Wire.h>

float f = 105.4;                                //Частота сприймання
unsigned int freqB;
byte freqH, freqL;
byte arr[5] = { 0, 0, 0xB0, 0x10, 0x00 };      //Массив для відправки I2C

void work_radio();

void setup() {
  work_radio();
}

void loop() {
  ;
}

void work_radio(){
  Wire.begin();
  freqB = 4 * (f * 1000000 + 225000) / 32768;  //Запуск радио
  freqH = freqB >> 8;
  freqL = freqB & 0XFF;
  arr[0]= freqH;
  arr[1]= freqL;
  Wire.beginTransmission(0x60);
  for(int i = 0; i < 5; i++) {
     Wire.write(arr[i]);
  }
  Wire.endTransmission();
}
