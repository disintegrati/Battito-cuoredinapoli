//Sketch battito migliorato per spegnere completamente i led nel punto morto del battito, senza che rimangano accesi (anche se minimamente)
//Upgrade per far partire la pulsazione precisamente ogni 2 secondi. Abbiamo una tolleranza di 8 microsecondi

unsigned long previousCheck = 0; // last time update
long interval = 2000000; // interval at which to do something (milliseconds)
unsigned long time1;
unsigned long time2;
int brightness = 0;    
int fadeAmount = 35;   
int counter = 0;
int ledPin1 = 6;
float pulse = 0.7;
bool check = false;

void setup(){
  Serial.begin(9600);
pinMode(ledPin1, OUTPUT);
  brightness = 255;
}


void loop(){
  unsigned long currentCheck = micros();

  if(currentCheck - previousCheck > interval) {
     previousCheck = currentCheck;  
      time1 = time2;
    time2 = micros();
  
  check = true;

  }

if (check == true) {
  pulsa();
  }
  
}

void pulsa(){
  analogWrite(ledPin1, brightness);
  brightness = brightness - (fadeAmount * pulse);

  if (brightness <= 0 && counter == 0) {
    brightness = 255 ;

    counter = 1;
    fadeAmount = 5;
  }
  else if (brightness <= 0 && counter == 1) {
    delay(32 * 10);
    brightness = 255;
    counter = 0;
    fadeAmount = 35;
    check = false;
    Serial.println(time2 - time1);
  }

  delay(2 * 10);
}

