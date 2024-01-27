int buttonPin = 7;
int RandNum;
int guess;
int ledState = HIGH;
int buttonState = LOW;
int lastButtonState = LOW;

long lastDebounceTime = 0;
long debounceDelay = 50;



void setup(){
Serial.begin(9600);
    for (int ledPin = 8; ledPin <= 12; ledPin++) { //pinmodelEDS
    pinMode(ledPin, OUTPUT);
  }
  light_leds();
  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(0));  
 
}

void loop(){
   int reading = !digitalRead(buttonPin);// debounce do botão
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        Serial.write('S');
        RandNum = random(32);
        Binary(RandNum);
        Serial.println(RandNum);

      }
    }
  }
  lastButtonState = reading;
  guess_binary();
}


void Binary(int number) {
  for (int ledPin = 8; ledPin <= 12; ledPin++) {
    int bit = (number >> (ledPin - 8)) & 1;
    digitalWrite(ledPin, bit);
  }
}// esta função vai escolher o "least important bit" do numero, acendendo o led devidamente, depois vai mover o numero para a direita e repetir o processo
void light_leds() { 
  for (int ledPin = 8; ledPin <= 12; ledPin++) {
    digitalWrite(ledPin, HIGH);
  } // esta função vai ligar os leds do 8 ao 12
}
void guess_binary(){
  if (Serial.available()>0){
    int guess = Serial.read();
    if (guess != RandNum){
      Serial.write('N');
    }
    else{
      Serial.write('Y');
      light_leds();
    }
  }// esta função vai enviar "Y" ou "N" consoante a advinha feita pelo secundário
    
}