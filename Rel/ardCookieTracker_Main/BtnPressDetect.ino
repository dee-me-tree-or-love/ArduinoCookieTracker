// returns which button was pressed: 0 for set, 1 for rollback, 2 for reset
// if nothing was pressed returns -1
int BtnPressDetect(){

  int BtnIndex = -1;

  lastBtnSetState = btnSetState;
  lastBtnRbState = btnRbState;
  lastBtnResetState = btnResetState;


  btnSetState = digitalRead(BTNSETPIN);
  btnRbState = digitalRead(BTNRBPIN);
  btnResetState = digitalRead(BTNRESETPIN);
    // Detects whether the button was pressed
  if(btnSetState == HIGH && lastBtnSetState != HIGH){
    // set -> 0
    delay(200);  
    BtnIndex = 0;
  }
  if(btnRbState == HIGH && lastBtnRbState != HIGH){
    // rb -> 1
    delay(200);
    BtnIndex = 1;
    }  
  if(btnResetState == HIGH && lastBtnResetState != HIGH){
    // reset -> 2
    delay(200);
    BtnIndex = 2;
    }

  // output
  return BtnIndex;
}

