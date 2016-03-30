// ej state, sysStatus = 1, machine gets the size of an empty jar
void Group1Meth()
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
    emptySize = getDist(duration);
    // Output the measurements
    Serial.print("Size of an empty jar is: ");
    Serial.print(emptySize);
    Serial.print(" cm.");
    Serial.println("");
    Serial.println("Press button SET if it's okay");
    Serial.println("*******");
    pauseInd = 1;
  }
  int bInd = BtnPressDetect();
  
     
  if(bInd != -1)
      {
        pauseInd = 0;
        //0 for set, 1 for rollback, 2 for reset
        switch(bInd)
        {
          case 0:
            // wait for an input once more
            sysStatus = 2;
            break;
          case 1: 
            sysStatus = 1;
            break;
          case 2: 
            sysStatus = 0;
            notifNr = 0;
            break;
          
        }
        
      }
}




