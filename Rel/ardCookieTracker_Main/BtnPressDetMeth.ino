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



// waits for user to press a button and shows a message
// parameters are: message to show and current state
// to be used
void WaitForInput(String message, int state)
{
  if(bInd != -1)
      {
        pauseInd = 0;
        //0 for set, 1 for rollback, 2 for reset
        switch(bInd)
        {
          case 0:
            // wait for an input once more
            sysStatus = state+1;
            break;
          case 1: 
            sysStatus = state;
            break;
          case 2: 
            sysStatus = 0;
            notifNr = 0;
            break;
          
        }
        
      }
}

