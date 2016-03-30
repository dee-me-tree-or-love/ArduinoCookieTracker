// initial state, sysStatus = 0, machine waits for the user to start
void Group0Meth()
{
  // reainitialize the variables and servo position:
        duration = 0;  
        emptySize = 0;
        cookieSize = 0;  
        fullSize = 0;  
        curSize = 0;  
        myServo.write(0);
        // Instructions
        Serial.print("Press SET to start.");
        Serial.print("First measure the size of an empty jar.");
  if(BtnPressDetect() != -1)
      {
        //0 for set, 1 for rollback, 2 for reset
        switch(BtnPressDetect())
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

