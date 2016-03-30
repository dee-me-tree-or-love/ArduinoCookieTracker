// gets the distance from the US to the target
float getDist(float ms)
{
  
  float distance = SPOSOUND * ms / 2; 
  delay(100);
  /*
   * this seems to be working poorly
   * and often gives unstable, rapidly changing results
   * and does not read the values for the distances less than 
   * 3cm properly.
   */
   return distance;
}
