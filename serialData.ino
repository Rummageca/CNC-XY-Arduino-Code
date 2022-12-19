
void EncoderX()
{
  while (Serial.availableForWrite() > 0)
  {
    Serial.println("X");
    Serial.println(Position, DEC);//----------send data to C# program---------------------------------------------    
    return;
  }
}
void EncoderY()
{
  while (Serial.availableForWrite() > 0)
  {
    Serial.println("Y");
    Serial.println(Position, DEC);//----------send data to C# program---------------------------------------------    
    return;
 }
}

void EncoderA()
{
  while (Serial.availableForWrite() > 0)
  {
    Serial.println("A");
    Serial.println(Position, DEC);//----------send data to C# program---------------------------------------------    
    return;
  }
}

void EncoderZ()
{
  while (Serial.availableForWrite() > 0)
  {
    Serial.println("Z");
    Serial.println(Position, DEC);//----------send data to C# program---------------------------------------------    
    return;
  }
}

void ZeroX()
{
 while (Serial.availableForWrite() > 0)
  {
    Serial.println("X0");
    Serial.println("00");//----------send data to C# program---------------------------------------------    
    return;
  }
}

void ZeroY()
{
 while (Serial.availableForWrite() > 0)
  {
    Serial.println("Y0");
    Serial.println("00");//----------send data to C# program---------------------------------------------    
    return;
  }
}
void ZeroZ()
{
 while (Serial.availableForWrite() > 0)
  {
    Serial.println("Z0");
    Serial.println("00");//----------send data to C# program---------------------------------------------    
    return;
  }
}
void ZeroA()
{
 while (Serial.availableForWrite() > 0)
  {
    Serial.println("A0");
    Serial.println("00");//----------send data to C# program---------------------------------------------    
    return;
  }
}

void RPMUPdate()
{
  while (Serial.availableForWrite() > 0)
  {
    Serial.println("Thd");
    Serial.println(actualRPM);//, DEC);   
    return;
  } 
}
