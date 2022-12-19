
void captureAllIPM()
{
  Position = 0;      //reset on new data incoming

  double ipm1 = dex[1].toInt();
  if (ipm1 > 0)
  {
    cspd = 3000 / ipm1;
  }
  double ipm2 = dex[6].toInt();
  if (ipm2 > 0)
  {
    cspd2 = 3000 / ipm2;
  }
  else
  {
    return;
  }
  captureAllPulse();
}
//-----------------------------------Capture ALL Pulse counts-----------------------------------
void captureAllPulse()
{
  if (dex[3] > "");
  {
    MOTOR_STEPS  = dex[3].toInt();
  }
  if (dex[8] > "");
  {
    MOTOR_STEPS2  = dex[8].toInt();
  }
  if (MOTOR_STEPS > 0 && MOTOR_STEPS2 > 0)
  {
    captureAllRotate();
  }
}
//-----------------------------------Captures Rotation from serial input----CCW or CW -----axis X or Y------
//-----------------------------------------------could trim some of this code-------------------------------
void captureAllRotate()
{
  //-------------------------------------------------------------------------
  if (dex[2] == "cwx"){digitalWrite(DIRx, HIGH); Steplong = STEPx;}
  if (dex[2] == "cwy"){digitalWrite(DIRy, HIGH); Steplong = STEPy;}
  if (dex[2] == "cwz"){digitalWrite(DIRz, HIGH); Steplong = STEPz;}  
  
  if (dex[2] == "ccwx"){digitalWrite(DIRx, LOW); Steplong = STEPx;}
  if (dex[2] == "ccwy"){digitalWrite(DIRy, LOW); Steplong = STEPy;}
  if (dex[2] == "ccwz"){digitalWrite(DIRz, LOW); Steplong = STEPz;}
  
  delay(Dtime);
  //-------------------------------------------------------------------------      
  if (dex[7] == "cwx"){digitalWrite(DIRx, HIGH); Stepshort = STEPx;}
  if (dex[7] == "cwy"){digitalWrite(DIRy, HIGH); Stepshort = STEPy;}
  if (dex[7] == "cwz"){digitalWrite(DIRz, HIGH); Stepshort = STEPz;}

  if (dex[7] == "ccwx"){digitalWrite(DIRx, LOW); Stepshort = STEPx;}
  if (dex[7] == "ccwy"){digitalWrite(DIRy, LOW); Stepshort = STEPy;}
  if (dex[7] == "ccwz"){digitalWrite(DIRz, LOW); Stepshort = STEPz;}  
  //------------------------------------------------------------------------- 

  goDual();
}

void goDual() {
  
  refresh();

  int divide = (dex[5].toInt());

  int lng  = MOTOR_STEPS / divide;
  int shrt = MOTOR_STEPS2 / divide;
  //-------------------------------------------------

  for (int i = 0; i < lng; i++)
    {
    for (int i = 0; i < divide; i++)
    {
      digitalWrite(Steplong, HIGH);
      delayMicroseconds(cspd);
      digitalWrite(Steplong, LOW);
      delayMicroseconds(cspd);
    }
    digitalWrite(Stepshort, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(Stepshort, LOW);
    delayMicroseconds(cspd);

    if (Serial.available() >0) 
    {   
       break;     
    }
    }
  
  //-------------------------------------------------
  int DROlong  = lng * divide;
  int DROshort = shrt * divide;   

  if (dex[2].startsWith("cw"))
  {
    Position = -DROlong;    
    if (dex[2].endsWith("x")){EncoderX();}
    if (dex[2].endsWith("y")){EncoderY();}
    if (dex[2].endsWith("z")){EncoderZ();}    
  }
  if (dex[2].startsWith("ccw"))
  {
    Position = DROlong;
    if (dex[2].endsWith("x")){EncoderX();}
    if (dex[2].endsWith("y")){EncoderY();}
    if (dex[2].endsWith("z")){EncoderZ();}
  }
  
  delay(Dtime);
  //-----------------------------------------second------------------------  
   
  if (dex[7].startsWith("cw"))
  {
    Position = -DROshort;    
    if (dex[7].endsWith("x")){EncoderX();}
    if (dex[7].endsWith("y")){EncoderY();}
    if (dex[7].endsWith("z")){EncoderZ();}    
  }
  if (dex[7].startsWith("ccw"))
  {
    Position = DROshort;    
    if (dex[7].endsWith("x")){EncoderX();}
    if (dex[7].endsWith("y")){EncoderY();}
    if (dex[7].endsWith("z")){EncoderZ();}    
  }
  //----------------------------------------------------------------------- 
  
  delay(Dtime);
  
}
