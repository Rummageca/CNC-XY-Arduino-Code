void Toolset() {
  captureIPMTS();
}

void captureIPMTS() {
  Position = 0;  //reset on new data incoming

  double ipm = dex[1].toDouble();
  if (ipm > 0) {
    cspd = 3000 / ipm;
    capturePulseTS();
  } else {
    return;
  }
}

void capturePulseTS() {
  if (dex[3] > "")
    ;
  {
    MOTOR_STEPS = dex[3].toInt();
    captureRotateTS();
  }
}

void captureRotateTS() {
  refresh();

  //------------------------------------------x Rotation-----------------------------
  if (dex[2] == "cwx") {
    digitalWrite(DIRx, HIGH);
    Clearing = "X";
    TheMotor = STEPx;
  }
  if (dex[2] == "ccwx") {
    digitalWrite(DIRx, LOW);
    Clearing = "X";
    TheMotor = STEPx;
  }
  //---------------------------------------y Rotation-------------------------------------
  if (dex[2] == "cwy") {
    digitalWrite(DIRy, HIGH);
    Clearing = "Y";
    TheMotor = STEPy;
  }
  if (dex[2] == "ccwy") {
    digitalWrite(DIRy, LOW);
    Clearing = "Y";
    TheMotor = STEPy;
  }
  //---------------------------------------Z Rotation-------------------------------------
  if (dex[2] == "cwz") {
    digitalWrite(DIRz, HIGH);
    Clearing = "Z";
    TheMotor = STEPz;
  }
  if (dex[2] == "ccwz") {
    digitalWrite(DIRz, LOW);
    Clearing = "Z";
    TheMotor = STEPz;
  }
  //---------------------------------------A Rotation-------------------------------------
  if (dex[2] == "cwa") {
    digitalWrite(DIRa, HIGH);
    Clearing = "A";
    TheMotor = STEPa;
  }
  if (dex[2] == "ccwa") {
    digitalWrite(DIRa, LOW);
    Clearing = "A";
    TheMotor = STEPa;
  }

  Toolsense();
}


void Toolsense() {
  MOTOR_STEPS = 0;
  HomeMotorsOn = true;

  while (HomeMotorsOn == true) {
    digitalWrite(TheMotor, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(TheMotor, LOW);
    delayMicroseconds(cspd);
    MOTOR_STEPS++;

    if (digitalRead(ToolProbe) == LOW || digitalRead(HomeX) == LOW || digitalRead(HomeY) == LOW || digitalRead(HomeZ) == LOW) {
      HomeMotorsOn = false;
    }

    //------------end estop--------------
    if (Serial.available() > 0) {
      HomeMotorsOn = false;
      break;
    }
  }
  delay(100);

  if (Clearing == "X") {
    ZeroX();
  }
  if (Clearing == "Y") {
    ZeroY();
  }
  if (Clearing == "Z") {
    ZeroZ();
  }
  if (Clearing == "A") {
    ZeroA();
  }

  delay(100);

 //---------------------------------------Z Rotation-------------------------------------
  if (dex[2] == "cwx") { digitalWrite(DIRx, LOW); }
  if (dex[2] == "ccwx") { digitalWrite(DIRx, HIGH); }
  //---------------------------------------Z Rotation-------------------------------------
  if (dex[2] == "cwy") { digitalWrite(DIRy, LOW); }
  if (dex[2] == "ccwy") { digitalWrite(DIRy, HIGH); }
 
  //---------------------------------------Z Rotation-------------------------------------
  if (dex[2] == "cwz") { digitalWrite(DIRz, LOW); }
  if (dex[2] == "ccwz") { digitalWrite(DIRz, HIGH); }
  //---------------------------------------A Rotation-------------------------------------
  if (dex[2] == "cwa") { digitalWrite(DIRa, LOW); }
  if (dex[2] == "ccwa") { digitalWrite(DIRa, HIGH); }



  for (int x = 0; x < MOTOR_STEPS; x++) {
    digitalWrite(TheMotor, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(TheMotor, LOW);
    delayMicroseconds(cspd);

    if (Serial.available() >0) 
    {   
       break;     
    }
  }
  //--x Rotation ---------------------------
  if (dex[2] == "cwx") {
    MOTOR_STEPS = dex[3].toInt();
    Position = MOTOR_STEPS;
    EncoderX();
  }
  //--x Rotation ----------------------------
  if (dex[2] == "ccwx") {
    MOTOR_STEPS = dex[3].toInt();
    Position = -MOTOR_STEPS;
    EncoderX();
  }
   //- Y Rotation -----------------------------
  if (dex[2] == "cwy") {
    MOTOR_STEPS = dex[3].toInt();
    Position = MOTOR_STEPS;
    EncoderY();
  }
  //-y Rotation-- -----------------------------
  if (dex[2] == "ccwy") {
    MOTOR_STEPS = dex[3].toInt();
    Position = -MOTOR_STEPS;
    EncoderY();
  }
   //---z Rotation--------------------------
  if (dex[2] == "cwz") {
    MOTOR_STEPS = dex[3].toInt();
    Position = MOTOR_STEPS;
    EncoderZ();
  }
  //---z Rotation--------------------------
  if (dex[2] == "ccwz") {
    MOTOR_STEPS = dex[3].toInt();
    Position = -MOTOR_STEPS;
    EncoderZ();
  }

}

