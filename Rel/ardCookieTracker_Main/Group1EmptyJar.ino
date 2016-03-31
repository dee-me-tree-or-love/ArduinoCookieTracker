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
    Serial.println("Relocate the sensor and press RB if not");
    Serial.println("*******");
    pauseInd = 1;
  }
  WaitForInput(sysStatus);
}




