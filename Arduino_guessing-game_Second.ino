int buttonPin1=7;
int buttonPin2=6;
int buttonState1=LOW;
int lastButtonState1 = LOW;
int buttonState2=LOW;
int lastButtonState2=LOW;
long lastDebounceTime = 0;  
long debounceDelay = 50;    
int numero=0;

void binario(int count){ //função para representar o número binário através dos lEDs
  for (int led=8; led<=12;led++){
  int binario=(count>>(led-8))& 1;
  digitalWrite(led, binario);
  }
}






void leds( int estado){    //acender/desligar leds
  for(int led=8; led<=12; led++){
  digitalWrite(led, estado);
  }
 
}
void iniciojogo(){ //piscar 3 vezes para anunciar o inicio do jogo
for(int i=0;i<=2;i++){
      leds(HIGH);
      delay(300);
      leds(LOW);
      delay(300);
     
     
    }

}



 
void setup() {
  Serial.begin(9600);
 
  for(int led=8; led<=12; led++){ //pinmodelEDS
    pinMode(led,OUTPUT);
 
  }
  pinMode(buttonPin1,INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
 
  //comeca ligadoo
  leds(HIGH);
 
 }
 
 

void loop() {
  if (Serial.available()>0){
  char incomingLetra=Serial.read();
    if (incomingLetra=='S'){ //esta função é chamada quando receber a letra "S"
      numero=0  
      iniciojogo();
  }
    else if(incomingLetra=='N'){  //quando recebe a letra "N" desliga todos os leds e pode tentar outra vez
      leds(LOW);
      numero=0;
 
    }
   
    if(incomingLetra=='Y'){  //quando recebe o Y liga os leds e espera por um inicio novo
      leds(HIGH);
      numero=0;
     
    }
   
  }
 
 
 
           
 
  int reading1= !digitalRead(buttonPin1);//debounce botao1=botaoescolher o nr
 
  if (reading1!=lastButtonState1){  
    lastDebounceTime=millis();
   
  }

  if ((millis()-lastDebounceTime)> debounceDelay){
    if(reading1!=buttonState1){
      buttonState1= reading1;
     
      if (reading1==HIGH){ //escolha no numero binario
        numero+=1;
        binario(numero);
        if (numero==31){
        numero=0;
         
        }
       
     
     
      }
     
       
    }
  }
  lastButtonState1= reading1;
 
int reading2 = !digitalRead(buttonPin2);  //debounce2 botao tentativa
  if (reading2!=lastButtonState2){  
  lastDebounceTime=millis();

  }

  if ((millis()-lastDebounceTime)> debounceDelay){
    if(reading2!=buttonState2){
      buttonState2= reading2;
         
          if (reading2==HIGH){  //vai mandar a letra n
           Serial.write(numero);            
         
          }
           
         
        }
  }
       
 
 
lastButtonState2= reading2;
 
}