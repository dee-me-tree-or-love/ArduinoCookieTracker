// one cookie state, sysStatus = 3, machine gets the size of a cookie
void Group3Meth()
{
  delay(150);
  if(pauseInd == 0)
  {
    digitalWrite(TRIGPIN, LOW); //Set trigger pin low
    delayMicroseconds(2000); // let signal settle
    digitalWrite(TRIGPIN, HIGH); // set trigPin high
    delayMicroseconds(100); // delay in high state
    digitalWrite(TRIGPIN, LOW); // ping has now been sent
    delayMicroseconds(66); // delay in low state
  
    duration = pulseIn(ECHOPIN, HIGH); //calculates the ms 
    cookieSize = emptySize - getDist(duration); // because oneCookieDistance = emptyJar - cookie size
    // Output the measurements
    Serial.print("Size of a cookie is: ");
    Serial.print(cookieSize);
    Serial.print(" cm.");
    Serial.println("");
    Serial.println("Press button SET if it's okay");
    Serial.println("*******");
    
    pauseInd = 1;
  }
  WaitForInput(sysStatus);
//  int bInd = BtnPressDetect();   
//  if(bInd != -1 && cookieSize != 0)
//      {
//        pauseInd = 0; // something was pressed, thus read again
//        //0 for set, 1 for rollback, 2 for reset
//        switch(bInd)
//        {
//          case 0:
//            sysStatus = 6;
//            break;
//          case 1: 
//            sysStatus = 5;
//            break;
//          case 2: 
//            sysStatus = 0;
//            notifNr = 0;
//            break;
//          
//        }
//        
//      }
    
}
