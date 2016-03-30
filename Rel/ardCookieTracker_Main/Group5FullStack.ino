// ej state, sysStatus = 5, machine gets the size of a full jar
void Group5Meth()
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
    pauseInd = 1;
  }
   WaitForInput(sysStatus);
      
}
