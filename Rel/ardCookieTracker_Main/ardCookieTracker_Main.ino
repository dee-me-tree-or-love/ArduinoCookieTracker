#include <Servo.h>

const int TRIGPIN = 13; //the pin for the US trigger connection - white mother jumper green father jumper
// trigger is input
const int ECHOPIN = 12; //the pin for the US echo connection - orange mother jumper yellow father jumper
// echo is output
const int SERVOINDPIN = 9; // to control the indicator servo (empty-full) - yellow jumper

const int BTNSETPIN = 2; // used to continue; green jumper - right
const int BTNRBPIN = 4; // used to cancle; blue jumper - middle
const int BTNRESETPIN = 7; // used to finish/restart; yellow jumper - left


// thus it will vary from 0 to 180deg with 0cookies to FS of cookies respectively
Servo myServo;

// variables to be used for calculations
float duration;  //time for ping to travel from sensor to target and return
float emptySize;  //Size (distance to the first obstacle) of an empty jar in cm (counted twice), thus the formula to be used
// is distance = SPOSOUND * duration / 2
float cookieSize;  //Size (distance to the first obstacle) of a cookie in cm
float fullSize;  //Size (distance to the first obstacle) of a full jar in cm
float curSize;  //Size (distance to the first obstacle) of a jar with some cookies in cm
float numFullCookies; //number of cookies total
float numPrevCookies; //number of cookies at the last check
float numCurCookies; //number of cookies current check
const float SPOSOUND = 0.0346; //Speed of sound in cm/ms

// BTN states:
int btnSetState = LOW; 
int btnRbState = LOW;
int btnResetState = LOW;

int lastBtnSetState = LOW; 
int lastBtnRbState = LOW;
int lastBtnResetState = LOW;

int sysStatus = 0; // current process group 
                   // 0 - initialize
                   // 1 - get empty jar
                   // 2 - get one cookie
                   // 3 - get full stack
                   // 4 - read updated info



//END VAR DECLARATION

void setup() {

            // initialize serial communication:
  Serial.begin(9600);
                      // set up the connections
  myServo.attach(SERVOINDPIN);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  
  myServo.write(0);
  pinMode(BTNSETPIN,INPUT);    // set btn input
  pinMode(BTNRBPIN,INPUT);     // set btn input
  pinMode(BTNRESETPIN,INPUT);  // set btn input

}


//BEGIN

void loop() {
  // Get in what process group to be:
  switch(sysStatus)
  {
    // init
    case 0:
      Group0Meth(); // gets this method from a tab
      break;

    // empty jar  
    case 1:
      Group1Meth();
      break;

    // one cookie  
    case 2:
      Group2Meth();
      break;

    // full stack  
    case 3:
      Group3Meth();
      break;

    // changing numcookies  
    case 4:
    //
    Serial.println("To Be DONE");
    Serial.println("+_+_+_+_+_+_+");
    //
      break;
  }

}

//END


//METHODS DECLARATION: 
// check tabs for it

//// returns which button was pressed: 0 for set, 1 for rollback, 2 for reset
//// if nothing was pressed returns -1
//int BtnPressDetect(){
//
//  int BtnIndex = -1;
//
//  lastBtnSetState = btnSetState;
//  lastBtnRbState = btnRbState;
//  lastBtnResetState = btnResetState;
//
//
//  btnSetState = digitalRead(BTNSETPIN);
//  btnRbState = digitalRead(BTNRBPIN);
//  btnResetState = digitalRead(BTNRESETPIN);
//    // Detects whether the button was pressed
//  if(btnSetState == HIGH && lastBtnSetState != HIGH){
//    // set -> 0
//    delay(200);  
//    BtnIndex = 0;
//  }
//  if(btnRbState == HIGH && lastBtnRbState != HIGH){
//    // rb -> 1
//    delay(200);
//    BtnIndex = 1;
//    }  
//  if(btnResetState == HIGH && lastBtnResetState != HIGH){
//    // reset -> 2
//    delay(200);
//    BtnIndex = 2;
//    }
//
//  // output
//  return BtnIndex;
//}








