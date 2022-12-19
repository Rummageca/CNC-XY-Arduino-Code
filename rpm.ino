//-------------------------------------------------encoder X loop-----------------------------------------------------
void EncodeRPM() {  
  
  if (cycletimes >= 10 && actualRPM >= 40 && actualRPM <= 500)
  {    
    RPMUPdate();        
    cycletimes = 0;
  }
  if (cycletimes >= 20 && actualRPM >= 501 && actualRPM <= 1500)
  {    
    RPMUPdate();        
    cycletimes = 0;
  }
  if (cycletimes >= 40 && actualRPM >= 1501 && actualRPM <= 4500)
  {    
    RPMUPdate();        
    cycletimes = 0;
  }
  if (cycletimes >= 80 && actualRPM >= 4501 && actualRPM <= 13500)
  {    
    RPMUPdate();        
    cycletimes = 0;
  }  
  cycletimes++;
}

void dorpmA() {

  if (digitalRead(rpmPinA) == HIGH)
  {
    enabletimer();
  }
}

//--------------------------------------Enable-------------------------------------------
void enabletimer() {

  currentMillis = millis();

  if (currentMillis >= previousMillis) //---aka 1 seconds
  {
    double timetook = 60000 / (currentMillis - previousMillis);

    actualRPM  = (timetook);
    EncodeRPM();// turn off
    previousMillis = currentMillis;
  }
}
