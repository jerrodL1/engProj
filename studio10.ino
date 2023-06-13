#include <Adafruit_CircuitPlayground.h>



bool leftButtonPressed = 0;
volatile bool leftButtonFlag = 0;
int leftButtonPin= 4;

bool rightButtonPressed = 0;
volatile bool rightButtonFlag = 0;
int rightButtonPin = 5;

int values[2] = {0, 0};
int pattern[2] = {3,5};



int leftButtonCount = 0;
int rightButtonCount = 0;

void setup() {
  CircuitPlayground.begin();
  pinMode(leftButtonPin, INPUT_PULLDOWN);
  Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(leftButtonPin), left, RISING);

pinMode (rightButtonPin, INPUT_PULLDOWN);
attachInterrupt(digitalPinToInterrupt(rightButtonPin), right, RISING);
delay(5000);
pattern3();
}

void loop() {
//left side

  if (values[0]==pattern[0]){  //compare value to sequence. this is what happens when its the same
    delay(2000); 
    for(int i=0; i<5; i++){
      CircuitPlayground.setPixelColor( i, 0,0, 255); //flash blue on left side
      
    }
    delay(2000); //wait then clear pixels. if user presses again theyll have to restart
      CircuitPlayground.clearPixels();

   
    
    delay(200);
    CircuitPlayground.clearPixels();
          pattern[0]=13; //set new values 
      
      values[0]=0;
  values[1]=0;
    delay(200);
  }  
  else if (values[0]>pattern[0]){ //if user presses too many times, flash red, reset values
  for(int i=0; i<5; i++){
      CircuitPlayground.setPixelColor( i, 255,0, 0);
    }
     CircuitPlayground.playTone(440,100); //play a tone 
  delay(3000);
  values[0]=0;
  values[1]=0;
  CircuitPlayground.clearPixels();
  }
else{CircuitPlayground.clearPixels();}

//right side

if (values[1]==pattern[1]){  //compare value to sequence. this is what happens when its the same
    for(int i=5; i<10; i++){
      CircuitPlayground.setPixelColor( i, 0,0, 255);  //flash blue on left side
    }
    delay(2000);
    CircuitPlayground.clearPixels();
    values[1]=0;
    pattern[1]=7;
    
  }
  else if (values[1]>pattern[1]){ //if user presses too many times, flash red and reset values. 
  for(int i=5; i<10; i++){
      CircuitPlayground.setPixelColor( i, 255,0, 0);
    }
    CircuitPlayground.playTone(440,100);

  delay(3000);
  values[0]=0;
  values[1]=0;
  CircuitPlayground.clearPixels();
  }
  else{CircuitPlayground.clearPixels();}

}






void left(){  // when user presses left button, add 1 to value[0]
  leftButtonFlag=1;
  values[0]++;
  Serial.println(values[0]);
  leftButtonFlag=0;
 }

 void right(){ // when user presses right button add 1 to value [1]
   rightButtonFlag = 1;
values[1]++;
Serial.println(values[1]);
   rightButtonFlag = 0;
 }

//predetermined initial pattern, 3 blinks on left , 5 right 
 void pattern3(){
  
    for (int i = 0; i<3;  ++i){
      CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(200));
      delay (200);
      CircuitPlayground.clearPixels();
      

    }
    for (int i = 10; i>4; --i){
      CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(200));
      delay (200);


    }
    
  }
//secondary pattern, 3 blinks left, 4 blinks right but much faster. 
 void pattern4(){

   if (pattern[1]=7){

delay(3000);

for (int i = 2; i<5;  ++i){
      CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(200));
      delay (50);
      CircuitPlayground.clearPixels();
      

    }
    for (int i = 5; i>9; --i){
      CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(200));
      delay (50);
    
    
  }
   }
      
 }
 

