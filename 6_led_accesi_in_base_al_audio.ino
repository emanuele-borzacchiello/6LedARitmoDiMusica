//https://www.youtube.com/watch?v=Y0S0HW8fU1M

const int OUT_PIN = 2;
int blu = 3;
int verde = 4;
int giallo = 5;
int giallo2 = 6;
int rosso = 7;
int rosso2 = 8;
int analogico = 0;
int i = 0;
int base = 660;

void setup() {
  for (i = 3; i <= 9; i++)pinMode (i, OUTPUT);
    //i = 3;
  Serial.begin (9600);
}

void loop() {
  analogico = readAnalogAudio();
  Serial.println (analogico);
  for (i = 3; i <= 9; i++)digitalWrite (i, LOW);
  if (analogico >= base + 0) digitalWrite (blu, HIGH);
  if (analogico >= base + 150) digitalWrite (verde, HIGH);
  if (analogico >= base + 300) digitalWrite (giallo, HIGH);
  if (analogico >= base + 450) digitalWrite (giallo2, HIGH);
  if (analogico >= base + 600) digitalWrite (rosso, HIGH);
  if (analogico >= base + 750) digitalWrite (rosso2, HIGH);
  //i = 3;
  delay(15);
}

/*********Variabili per lettura audio*********/
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;
int max_audio = 0;
/*********************************************/
//https://arduino-tutorials.net/tutorial/drawing-sound-sensor-data-on-serial-plotter
int readAnalogAudio(){
  int analog_audio = 0;
 
  while(analog_audio == 0){
    millisCurrent = millis();
    millisElapsed = millisCurrent - millisLast;

    if (digitalRead(OUT_PIN) == LOW)
      sampleBufferValue++;

    if (millisElapsed > SAMPLE_TIME) {
      analog_audio = sampleBufferValue;
      sampleBufferValue = 0;
      millisLast = millisCurrent;
    }
  }
  return analog_audio;
}
