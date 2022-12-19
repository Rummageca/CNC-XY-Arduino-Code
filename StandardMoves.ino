void captureIPM() {
  Position = 0;  //reset on new data incoming

  double ipm = dex[1].toDouble();
  if (ipm > 0) {
    cspd = 3000 / ipm;
    capturePulse();
  } else {
    return;
  }
}
//-----------------------------------Capture Pulse count-----------------------------------
void capturePulse() {
  if (dex[3] > "")
    ;
  {
    MOTOR_STEPS = dex[3].toInt();
    captureRotate();
  }
}
//-----------------------------------Captures Rotation from serial input----CCW or CW -----axis X or Y------
//-----------------------------------------------could trim some of this code-------------------------------
void captureRotate() {
  refresh();

  //------------------------------------------x Rotation-----------------------------
  if (dex[2] == "cwx") {
    digitalWrite(DIRx, HIGH);
    goX();
  }
  if (dex[2] == "ccwx") {
    digitalWrite(DIRx, LOW);
    goX();
  }
  //---------------------------------------y Rotation-------------------------------------
  if (dex[2] == "cwy") {
    digitalWrite(DIRy, HIGH);
    goY();
  }
  if (dex[2] == "ccwy") {
    digitalWrite(DIRy, LOW);
    goY();
  }
  //---------------------------------------Z Rotation-------------------------------------
  if (dex[2] == "cwz") {
    digitalWrite(DIRz, HIGH);
    goZ();
  }
  if (dex[2] == "ccwz") {
    digitalWrite(DIRz, LOW);
    goZ();
  }
  //---------------------------------------A Rotation-------------------------------------
  if (dex[2] == "cwa") {
    digitalWrite(DIRa, HIGH);
    goA();
  }
  if (dex[2] == "ccwa") {
    digitalWrite(DIRa, LOW);
    goA();
  }
}
//---------------------------------------x steps----------------------------------------
void goX() {

  for (int x = 0; x < MOTOR_STEPS; x++) {
    digitalWrite(STEPx, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPx, LOW);
    delayMicroseconds(cspd);

    if (Serial.available() >0) 
    {   
       break;     
    }
  }
  //--x Rotation ---------------------------
  if (dex[2] == "cwx") {
    Position = -MOTOR_STEPS;
    EncoderX();
  }
  //--x Rotation ----------------------------
  if (dex[2] == "ccwx") {
    Position = MOTOR_STEPS;
    EncoderX();
  }
}
//----------------------------------------y steps --------------------------------------
void goY() {
  for (int x = 0; x < MOTOR_STEPS; x++) {
    digitalWrite(STEPy, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPy, LOW);
    delayMicroseconds(cspd);

    if (Serial.available() >0) 
    {   
       break;     
    }
  }
  //- Y Rotation -----------------------------
  if (dex[2] == "cwy") {
    Position = -MOTOR_STEPS;
    EncoderY();
  }
  //-y Rotation-- -----------------------------
  if (dex[2] == "ccwy") {
    Position = MOTOR_STEPS;
    EncoderY();
  }
}
//----------------------------------------Z steps --------------------------------------
void goZ() {
  for (int x = 0; x < MOTOR_STEPS; x++) {
    digitalWrite(STEPz, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPz, LOW);
    delayMicroseconds(cspd);

    if (Serial.available() >0) 
    {   
       break;     
    }
  }
  //---z Rotation--------------------------
  if (dex[2] == "cwz") {
    Position = -MOTOR_STEPS;
    EncoderZ();
  }
  //---z Rotation--------------------------
  if (dex[2] == "ccwz") {
    Position = MOTOR_STEPS;
    EncoderZ();
  }
}
//----------------------------------------A steps --------------------------------------
void goA() {
  for (int x = 0; x < MOTOR_STEPS; x++) {
    digitalWrite(STEPa, HIGH);
    delayMicroseconds(cspd);
    digitalWrite(STEPa, LOW);
    delayMicroseconds(cspd);

    if (Serial.available() >0) 
    {   
       break;     
    }
  }
  //---a Rotation---------------------
  if (dex[2] == "cwa") {
    Position = -MOTOR_STEPS;
    EncoderA();
  }
  //---a Rotation---------------------
  if (dex[2] == "ccwa") {
    Position = MOTOR_STEPS;
    EncoderA();
  }
}
