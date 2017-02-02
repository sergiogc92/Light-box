

/*
fft_adc.pde
guest openmusiclabs.com 8.18.12
example sketch for testing the fft library.
it takes in data on ADC0 (Analog0) and processes them
with the fft. the data is sent out over the serial
port at 115.2kb.  there is a pure data patch for
visualizing the data.
*/

#define LIN_OUT 1 // use the linear output function
#define SCALE 125
#define FFT_N 64 // set to 64 point fft

#include <FFT.h> // include the library


void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  while(1) { // reduces jitter
    for (int i = 0 ; i < 128 ; i += 2) { // save 128 samples
      
      fft_input[i] = analogRead(A0); // put real data into even bins
      fft_input[i+1] = 0; // set odd bins to 0
    }
    fft_window(); // window the data for better frequency response
    fft_reorder(); // reorder the data before doing the fft
    fft_run(); // process the data in the fft
    fft_mag_lin(); // take the output of the fft

    if((int)fft_lin_out[2]>=7||(int)fft_lin_out[3]>=7||(int)fft_lin_out[4]>=7||(int)fft_lin_out[5]>=7){
      digitalWrite(11,0);
      digitalWrite(12,0);
    }else{
      digitalWrite(11,1);
      digitalWrite(12,1);
    }
    if(((int)fft_lin_out[6]>=7)||((int)fft_lin_out[7]>=7)||((int)fft_lin_out[8]>=7)||((int)fft_lin_out[9]>=7)||((int)fft_lin_out[10]>=7)||((int)fft_lin_out[11]>=7)||((int)fft_lin_out[12]>=7)||((int)fft_lin_out[13]>=7)){
      digitalWrite(10,0);
    }else{
      digitalWrite(10,1);
    }
    if(((int)fft_lin_out[15]>=7)||((int)fft_lin_out[16]>=7)||((int)fft_lin_out[17]>=7)||((int)fft_lin_out[18]>=7)||((int)fft_lin_out[19]>=7)||((int)fft_lin_out[20]>=7)||((int)fft_lin_out[21]>=7)||((int)fft_lin_out[22]>=7)){
      digitalWrite(7,0);
    }else{
      digitalWrite(7,1);
    }
    if(((int)fft_lin_out[24]>=7)||((int)fft_lin_out[25]>=7)||((int)fft_lin_out[26]>=7)||((int)fft_lin_out[27]>=7)||((int)fft_lin_out[28]>=7)||((int)fft_lin_out[29]>=7)||((int)fft_lin_out[30]>=7)||((int)fft_lin_out[31]>=7)){
      digitalWrite(6,0);
    }else{
      digitalWrite(6,1);
    }
  }
}


