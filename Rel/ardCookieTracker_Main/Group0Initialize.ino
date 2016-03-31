// initial state, sysStatus = 0, machine waits for the user to start
void Group0Meth()
{
  // reainitialize the variables and servo position:
  delay(100);
        duration = 0;  
        emptySize = 0;
        cookieSize = 0;  
        fullSize = 0;  
        curSize = 0;  
        cookieIntake = 0;
        numFullCookies = 0; //number of cookies total
        numPrevCookies = 0; //number of cookies at the last check
        numCurCookies = 0; //number of cookies current check
        numTakeCookies = 0; // number of taken cookies
        cookieIntake = 0;
        if(myServo.read()!= 0)
        {
          myServo.write(0);
        }
        // Instructions
        if(notifNr==0)
        {
          Serial.println("Hello.");
          Serial.println("First measure the size of an empty jar. ");
          Serial.println("Then measure the size of a jar with one cookie. ");
          Serial.println("Then measure the size of a jar full of cookies. ");
          Serial.println("Press SET to start");
          Serial.println("*******");
          notifNr++;
        }
  int bInd = BtnPressDetect();
  if(bInd != -1)
      {
        //0 for set, 1 for rollback, 2 for reset
        switch(bInd)
        {
          case 0:
            sysStatus = 1;
            break;
          case 1: 
            sysStatus = 0;
            break;
          case 2: 
            sysStatus = 0;
            break;
          
        }
        
      }
}

