void testing() 
{

  HomeMotorsOn = true; 
  
  while (HomeMotorsOn == true)
  {     

    if (digitalRead(HomeZ) == LOW)
    {
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      digitalWrite(ledPin, LOW);
    }
  }
}
