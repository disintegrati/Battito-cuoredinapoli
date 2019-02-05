int brightness = 0;    // how bright the LED is
int fadeAmount = 35;    // how many points to fade the LED by
int counter = 0;
int ledPin = 11;
int controlPin = 8;
float pulse = 0.7;
int booleano = 0;

void setup() {
  //start serial connection
  //Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(controlPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
brightness = 255;
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(controlPin);

  if (sensorVal == HIGH && booleano==0) {
      booleano = 1;
        

      pulsa();
  } else if (sensorVal == LOW) {
    booleano = 0;
    digitalWrite(ledPin, LOW);
  }
}

void pulsa() {
  delay(100);
  
  for (int i=0; i<255; i++){
    analogWrite(ledPin, i);
    delay(1);
  }
  for (int i=255; i>0; i--){
    analogWrite(ledPin, i);
    delay(1);
  }
  for (int i=0; i<255; i++){
    analogWrite(ledPin, i);
    delay(1);
  }
  delay(20);
  
  for (int i=255; i>=0; i--){
    analogWrite(ledPin, i);
    delay(3);
  }
}
