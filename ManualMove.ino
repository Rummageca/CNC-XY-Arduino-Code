void ManualIPM() {
  Position = 0;  //reset on new data incoming

  double ipm = dex[1].toDouble();
  if (ipm > 0) {
    cspd = 3000 / ipm;
    ManualRotate();
  } else {
    return;
  }
}
//-----------------------------------Captures Rotation from serial input----CCW or CW -----axis X or Y------
//-----------------------------------------------could trim some of this code-------------------------------
void ManualRotate() {
  refresh();

  //------------------------------------------x Rotation-----------------------------
  if (dex[2] == "cwx") {
    digitalWrite(DIRx, HIGH);
    TheMotor = STEPx;   
  }
  if (dex[2] == "ccwx") {
    digitalWrite(DIRx, LOW);
    TheMotor = STEPx;    
  }
  //---------------------------------------y Rotation-------------------------------------
  if (dex[2] == "cwy") {
    digitalWrite(DIRy, HIGH);
    TheMotor = STEPy;    
  }
  if (dex[2] == "ccwy") {
    digitalWrite(DIRy, LOW);
    TheMotor = STEPy;    
  }
  //---------------------------------------Z Rotation-------------------------------------
  if (dex[2] == "cwz") {
    digitalWrite(DIRz, HIGH);
    TheMotor = STEPz;
  }
  if (dex[2] == "ccwz") {
    digitalWrite(DIRz, LOW);
    TheMotor = STEPz;
  }
  //---------------------------------------A Rotation-------------------------------------
  if (dex[2] == "cwa") {
    digitalWrite(DIRa, HIGH);
    TheMotor = STEPa;
  }
  if (dex[2] == "ccwa") {
    digitalWrite(DIRa, LOW);
    TheMotor = STEPa;
  }
  motorsON = true;
  manual();
}
//-------------------------------------X move---------------------------------------------------------
void manual() {
  MOTOR_STEPS = 0;

  while (motorsON == true) {
    digitalWrite(TheMotor, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(TheMotor, LOW);
    delayMicroseconds(cspd);
    MOTOR_STEPS++;
    if (Serial.available() > 0) {
      readit1 = Serial.readStringUntil('\r');
      dex[4] = readit1;

      if (dex[4].startsWith("Manual Off")) {
        motorsON = false;
        refresh();
      }
    }
  }
  //------------------------------------------x Rotation- 1nd----------------------------
  if (dex[2] == "cwx") {
    Position = -MOTOR_STEPS;
    EncoderX();
  }
  //------------------------------------------x Rotation- 1nd----------------------------
  if (dex[2] == "ccwx") {
    Position = MOTOR_STEPS;
    EncoderX();
  }
  //---------------------------------------y Rotation--1nd-----------------------------------
  if (dex[2] == "cwy") {
    Position = -MOTOR_STEPS;
    EncoderY();
  }
  //---------------------------------------y Rotation--1nd-----------------------------------
  if (dex[2] == "ccwy") {
    Position = MOTOR_STEPS;
    EncoderY();
  }
//---------------------------------------z Rotation--1nd-----------------------------------
  if (dex[2] == "cwz") {
    Position = -MOTOR_STEPS;
    EncoderZ();
  }
  //---------------------------------------z Rotation--1nd-----------------------------------
  if (dex[2] == "ccwz") {
    Position = MOTOR_STEPS;
    EncoderZ();
  }
//---------------------------------------a Rotation--1nd-----------------------------------
  if (dex[2] == "cwa") {
    Position = -MOTOR_STEPS;
    EncoderA();
  }
  //---------------------------------------a Rotation--1nd-----------------------------------
  if (dex[2] == "ccwa") {
    Position = MOTOR_STEPS;
    EncoderA();
  }
}
