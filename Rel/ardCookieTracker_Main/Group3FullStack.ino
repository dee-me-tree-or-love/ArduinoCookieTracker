// ej state, sysStatus = 3, machine gets the size of a full jar
void Group3Meth()
{
  delay(50);

  digitalWrite(TRIGPIN, LOW); //Set trigger pin low
  delayMicroseconds(2000); // let signal settle
  digitalWrite(TRIGPIN, HIGH); // set trigPin high
  delayMicroseconds(100); // delay in high state
  digitalWrite(TRIGPIN, LOW); // ping has now been sent
  delayMicroseconds(66); // delay in low state

  duration = pulseIn(ECHOPIN, HIGH); //calculates the ms 
  fullSize = emptySize - getDist(duration); // because fullStackDistance = emptyJar - fullSize
  numFullCookies = fullSize/cookieSize;
  numPrevCookies = numFullCookies;
  // Output the measurements
  Serial.print("Size of a full jar is: ");
  Serial.print(fullSize);
  Serial.print(" cm.");
  Serial.println("");
  
  Serial.print("The number of cookies is: ");
  Serial.print(numFullCookies);
  Serial.print(".");
  Serial.println("Press button SET if it's okay");
  Serial.println("*******");
  delay(300);
      if(BtnPressDetect() != -1)
      {
        //0 for set, 1 for rollback, 2 for reset
        switch(BtnPressDetect())
        {
          case 0:
            sysStatus = 4;
            break;
          case 1: 
            sysStatus = 3;
            break;
          case 2: 
            sysStatus = 0;
            break;
          
        }
        
      }
      else sysStatus = 3;
}
