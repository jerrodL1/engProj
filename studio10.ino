#include <Adafruit_CircuitPlayground.h>

// Constants
int NUM_FLASHES = 3;
int BUTTON_DELAY = 500; 
 // Delay between button presses in milliseconds
bool leftButtonPressed = 0;
volatile bool leftButtonFlag = 0;
int leftButtonPin= 4;

bool rightButtonPressed = 0;
volatile bool rightButtonFlag = 0;
int rightButtonPin = 5;

int values[2] = {0, 0};
int pattern[2] = {2,2};

pinMode(leftButtonPin, INPUT_PULLDOWN);
attachInterrupt(digitalPinToInterrupt(leftButtonPin), left, RISING);

pinMode (rightButtonPin, INPUT_PULLDOWN);
attachInterrupt(digitalPinToInterrupt(rightButtonPin), right, RISING);

int leftButtonCount = 0;
int rightButtonCount = 0;

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  if (values==pattern){
    for (int i = 0, i<10; i++;){
      CircuitPlayground.setPixel( i, 255, 255);
    }
    delay(200);
  }
}
void left(){
  leftButtonFlag=1;
  values[0]++;
  leftButtonFlag=0;
 }

 void right(){
   rightButtonFlag = 1;
values[1]++;
   rightButtonFlag = 0;
 }
  // Wait for left button press
 

