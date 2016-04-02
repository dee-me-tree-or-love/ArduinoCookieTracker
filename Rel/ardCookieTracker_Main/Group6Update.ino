void Group6Meth()
{


  // to do

  delay(150);
  while(waitForPls != 0)
  {
    
    
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
                if(mesGet == false 
                // this is additional condition to detect a message
                    && sharpRecd == true && receivedMessage.length()>0 )
                {
                  if(receivedMessage.startsWith("PLEASE"))
                  {
                    Serial.print("Okay, okay, that's the last time... ");
                    myServoLock.write(5);
                    waitForPls = 0;
                  }
                }
              }
       int bInd = BtnPressDetect();
       if(bInd == 2)
       {
            waitForPls = 0;
            sysStatus = 0;
            Serial.print("Sir, you have eaten: ");
            Serial.print(cookieIntake);
            Serial.println(" this time.");
            for(int i = 0; i< cookieIntake - 1 ; i++)
            {
              Serial.print("O ");
            }
            Serial.println("");
            Serial.println("That's that many! Consider switching to a healthier lifestyle");
            delay(300);
            notifNr = 0;
       }
  }

  {

    myServoLock.write(5);
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
        
        Serial.print("The number of cookies is: ");
        Serial.println(numCurCookies);
        //to react on changes
        if(numCurCookies<=5)
        {
          Serial.println("Our people are hungry");
        }
        if(numCurCookies>numPrevCookies)
        {
           Serial.print("You have put: ");
           Serial.print(numTakeCookies);
          Serial.print(" cookies.");
          if(numCurCookies>numFullCookies)
          {
            numFullCookies = numCurCookies;
          }
        }
        else
        {
          Serial.print("You have taken: ");
          Serial.print(numTakeCookies);
          Serial.print(" cookies.");
          cookieIntake+=numTakeCookies;
          if(numTakeCookies>=3)
          {
            Serial.println("You are on a diet... Say #PLEASE% to continue");
            myServoLock.write(90);
            waitForPls = 1;
          }
        }
            Serial.print("Servo position is: ");
        Serial.print(getServoPos(numCurCookies));
        Serial.println("");
        if(numCurCookies>=1)
        {
          Serial.println("Press button SET/RB if you have taken more, RESET to finish eating for today");
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
            Serial.print("Well, you have eaten: ");
            Serial.print(cookieIntake);
            Serial.println(" this time.");
            for(int i = 0; i< cookieIntake - 1 ; i++)
            {
              Serial.print("O ");
            }
            Serial.println("");
            Serial.println("That's that many! Consider switching to a healthier lifestyle");
            delay(300);
            notifNr = 0;
            break;
          
        }
        
      }
}
