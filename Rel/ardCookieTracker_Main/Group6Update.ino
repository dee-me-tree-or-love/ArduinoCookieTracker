void Group6Meth()
{


  // to do

  delay(150);
  if(waitForPls==0) // wait for please is needed for waiting for a user message please to continue
  {
    if(pauseInd == 0 )
    {
      if(numCurCookies >= 1 )
      {
        numPrevCookies = numCurCookies;
        
        digitalWrite(TRIGPIN, LOW); //Set trigger pin low
        delayMicroseconds(2000); // let signal settle
        digitalWrite(TRIGPIN, HIGH); // set trigPin high
        delayMicroseconds(100); // delay in high state
        digitalWrite(TRIGPIN, LOW); // ping has now been sent
        delayMicroseconds(66); // delay in low state
      
        duration = pulseIn(ECHOPIN, HIGH); //calculates the ms 
        curSize = emptySize - getDist(duration); // because fullStackDistance = emptyJar - fullSize
        numCurCookies = curSize/cookieSize; // this value is not to be changed once set! 
        numTakeCookies = numPrevCookies - numCurCookies;
        // turns the servo to the full position
        // Output the measurements
        if(numTakeCookies < 0)
        {
          numTakeCookies = numTakeCookies * -1; // means that you have refilled the 
        }
        
        Serial.print("Current size of a jar is: ");
        Serial.print(curSize);
        Serial.print(" cm.");
        Serial.println("");
        Serial.print("Servo position is: ");
        Serial.print(getServoPos(numCurCookies));
        Serial.println("");
        
        Serial.print("The number of cookies is: ");
        Serial.println(numCurCookies);
        //to react on changes
        if(numCurCookies<=5)
        {
          Serial.println("Our people are hungry, mylord");
        }
        if(numCurCookies>numPrevCookies)
        {
           Serial.print("You have put: ");
           Serial.print(numTakeCookies);
          Serial.print(" cookies.");
        }
        else
        {
          Serial.print("You have taken: ");
          Serial.print(numTakeCookies);
          Serial.print(" cookies.");
          cookieIntake+=numTakeCookies;
          if(numTakeCookies>=3)
          {
            Serial.println("Sir, you are on a diet...");
            Serial.println("Say please, or I will not open! Do not forget to start with # and end with %");
            waitForPls = 1;
            myServoLock.write(90); // locked
          }
        }
        if(numCurCookies!=0)
        {
          Serial.println("Press button SET/RB to take more");
        }
        else
        {
          Serial.println("We are out of cookies, please press RESET and start again");
        }
        Serial.println("*******");
        pauseInd = 1;
      }
      else
      {
        Serial.println("We are out of cookies, please press RESET and start again");
        pauseInd = 1;
      }
    }
  }
  else // if we are waiting for please:
  {
    if(pauseInd == 0 )
    {
      Serial.println("Say please, or I will not open! Do not forget to start with # and end with %");
        pauseInd = 1;

      // get a message from a serial monitor
       if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                // check what you got:
                char receivedCharacter = (char) incomingByte;
                switch(receivedCharacter)
                {
                  case '#':
                    receivedMessage = "";
                    mesGet = true;
                    // added this as a mean of checking the input
                    sharpRecd = true;
                    break;
                  case '%':
                    mesGet = false;
                    break;
                  default:
                    receivedMessage += receivedCharacter;
                    break;
                }
                receivedMessage.toUpperCase();        
                if(mesGet == false && sharpRecd == true && receivedMessage.length()>0 )
                {
                  if(receivedMessage.startsWith("PLEASE"))
                  {
                    myServoLock.write(0); // opened
                    waitForPls = 0;
                  }
                }
      
              } // end of reading
          }
  }

  // wait for buttons
  int bInd = BtnPressDetect();   
  if(bInd != -1)
      {
        pauseInd = 0; // something was pressed, thus read again
        //0 for set, 1 for rollback, 2 for reset
        switch(bInd)
        {
          case 0:
            sysStatus = 6;
            break;
          case 1: 
            sysStatus = 6;
            break;
          case 2: 
            sysStatus = 0;
            Serial.print("Sir, you have eaten: ");
            Serial.print(cookieIntake);
            Serial.println(" this time.");
            for(int i = 0; i<cookieIntake; i++)
            {
              Serial.print("*");
            }
            Serial.println("");
            Serial.println("That's that many! Consider switching to a healthier lifestyle");
            delay(300);
            notifNr = 0;
            break;
          
        }
        
      }
}
