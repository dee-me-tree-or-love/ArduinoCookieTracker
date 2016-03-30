void Group6Meth()
{


  // to do

  if(pauseInd == 0)
  {
    Serial.print("TO BE DONE !!!!!");
    pauseInd = 1;
  }
  
  int bInd = BtnPressDetect();   
  if(bInd != -1)
      {
        pauseInd = 0; // something was pressed, thus read again
        //0 for set, 1 for rollback, 2 for reset
        switch(bInd)
        {
          case 0:
            sysStatus = 0;
            break;
          case 1: 
            sysStatus = 0;
            break;
          case 2: 
            sysStatus = 0;
            notifNr = 0;
            break;
          
        }
        
      }
}
