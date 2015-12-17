int brightness = 0;    // how bright the LED is
int fadeAmount = 35;    // how many points to fade the LED by
int counter = 0;
int ledPin1 = 1;

float pulse = 0.7;

void setup()  {
  pinMode(ledPin1, OUTPUT);
  brightness = 255;
  Serial.begin(9600);
}

void loop()  {
  analogWrite(ledPin1, brightness);
  brightness = brightness - (fadeAmount * pulse);

  if (brightness <= 10 && counter == 0) {
    brightness = 255 ;

    counter = 1;
    fadeAmount = 5;
  }
  else if (brightness <= 10 && counter == 1) {
    delay(32 * 10);
    brightness = 255;
    counter = 0;
    fadeAmount = 35;
  }

  delay(2 * 10);
}


