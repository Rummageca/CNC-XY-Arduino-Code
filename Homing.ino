void XLimit()
{
  cspd = 300;

  MOTOR_STEPS = 0;
  digitalWrite(DIRx, HIGH);
  HomeMotorsOn = true;

  while (HomeMotorsOn == true)
  {
    digitalWrite(STEPx, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPx, LOW);
    delayMicroseconds(cspd);
    MOTOR_STEPS++;

    if (digitalRead(HomeX) == LOW)
    {
      HomeMotorsOn = false;
    }
   
    //------------end estop--------------
    if (Serial.available() >0) 
    {   
       HomeMotorsOn = false;
       break;     
    }
  }

  Position = MOTOR_STEPS;
  EncoderX();
 
}
//-------------------------------Y limit ------------------------------------
void YLimit()
{
  cspd = 300;

  MOTOR_STEPS = 0;
  digitalWrite(DIRy, HIGH);
  HomeMotorsOn = true;

  while (HomeMotorsOn == true)
  {
    digitalWrite(STEPy, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPy, LOW);
    delayMicroseconds(cspd);
    MOTOR_STEPS++;

    if (digitalRead(HomeY) == LOW)
    {
      HomeMotorsOn = false;
    }
    
    //------------end estop--------------
    if (Serial.available() >0) 
    {   
       HomeMotorsOn = false;
       break;     
    }
  }

  Position = MOTOR_STEPS;
  EncoderY();
  
}
//-------------------------------Z limit ------------------------------------
void ZLimit()
{
  cspd = 300;

  MOTOR_STEPS = 0;
  digitalWrite(DIRz, HIGH);
  HomeMotorsOn = true;

  while (HomeMotorsOn == true)
  {
    digitalWrite(STEPz, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPz, LOW);
    delayMicroseconds(cspd);
    MOTOR_STEPS++;

    if (digitalRead(HomeZ) == LOW)
    {
      HomeMotorsOn = false;
    }
       
    //------------end estop--------------
    if (Serial.available() >0) 
    {   
       HomeMotorsOn = false;
       break;     
    }
  }

  Position = MOTOR_STEPS;
  EncoderZ();
  
}
//-------------------------------A limit ------------------------------------
void ALimit()
{
  cspd = 300;

  MOTOR_STEPS = 0;
  digitalWrite(DIRa, HIGH);
  HomeMotorsOn = true;

  while (HomeMotorsOn == true)
  {
    digitalWrite(STEPa, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPa, LOW);
    delayMicroseconds(cspd);
    MOTOR_STEPS++;

    if (digitalRead(HomeA) == LOW)
    {
      HomeMotorsOn = false;
    }
    
    //------------end estop--------------
    if (Serial.available() >0) 
    {   
       HomeMotorsOn = false;
       break;     
    }
  }

  Position = MOTOR_STEPS;
  EncoderA();
  
}
