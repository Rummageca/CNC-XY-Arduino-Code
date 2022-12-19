#include <LiquidCrystal_I2C.h>

//----------------------------------------------enable motor----------------------------------------------------
int Enab = 50;
int Estop = 49;
int ToolProbe = 45;
int ledPin = 13;

//------------------------------------------encoder rpm variables-----------------------------------------------
int rpmPinA = 19;  //14  on Due
long actualRPM = 0;
int checkmofo = 0;
//------------------------------------------------Millis---------------------------------------------------------

unsigned long currentMillis = 0;
unsigned long previousMillis = 0; // will store last time Millis was updated

int runonce = 0;

int cycletimes = 0;

//----------------------------------------------stepper motor----------------------------------------------------

long cspd = 1;
long cspd2 = 1;

long MOTOR_STEPS = 0;
long MOTOR_STEPS2 = 0;

bool motorsON = false;
bool HomeMotorsOn = false;
bool ToolSetMotorsOn = false;

//------------------------------------------------Mega----------------------------------------------------------

//LiquidCrystal_I2C lcd(0x27, 20 , 4);

//-------------------------------------------------Due----------------------------------------------------------

#define BACKLIGHT_PIN 3
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);

//---------------------------------------------serial read from C# program index--------------------------------
String readit1;
String dex[9];
long Position = 0;
int Steplong = 0;
int Stepshort = 0;

//-------------------------------------------------Stepper X variables------------------------------------------
int HomeX = 40;
int DIRx = 30;
int STEPx = 31;
//-------------------------------------------------Stepper Y variables-----------------------------------------
int HomeY = 41;
int DIRy = 34;
int STEPy = 35;
//-------------------------------------------------Stepper Z variables-----------------------------------------
int HomeZ = 42;
int DIRz = 32;
int STEPz = 33;
//-------------------------------------------------Stepper A variables-----------------------------------------
int HomeA = 43;
int DIRa = 36;
int STEPa = 37;
//-----------------------------------------------------------------------------------------------------THE SETUP--------------------------------------------------

String Clearing = "";
int TheMotor = STEPx;
int Dtime = 15;

void setup() {

  Serial.begin(115200, SERIAL_8N1);

  pinMode(Enab, OUTPUT);
  digitalWrite(Enab, HIGH);
  pinMode(ledPin, OUTPUT);
  pinMode(Estop, INPUT_PULLUP);

  //--------------------------Encoder rpm--------------------------------------
  pinMode(rpmPinA, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(rpmPinA), dorpmA, CHANGE);
  //attachInterrupt(rpmPinA, dorpmA, CHANGE);// encoder pin on interrupt 0 (pin 2)

  //-------------changes between Due and Mega---------------------------------
  //----Due----------
  lcd.begin (20, 4);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  //---mega----------
  //lcd.init();
  //lcd.backlight();
  //-----------------------------------------------------------------------------
  setbackground();
  pinMode(ToolProbe, INPUT_PULLUP);
  //-------------------------X Axis---------------------
  pinMode(DIRx, OUTPUT);
  pinMode(STEPx, OUTPUT);
  pinMode(HomeX, INPUT_PULLUP);
  //-------------------------Y Axis---------------------
  pinMode(DIRy, OUTPUT);
  pinMode(STEPy, OUTPUT);
  pinMode(HomeY, INPUT_PULLUP);
  //-------------------------Z Axis---------------------
  pinMode(DIRz, OUTPUT);
  pinMode(STEPz, OUTPUT);
  pinMode(HomeZ, INPUT_PULLUP);
  //-------------------------A Axis---------------------
  pinMode(DIRa, OUTPUT);
  pinMode(STEPa, OUTPUT);
  pinMode(HomeA, INPUT_PULLUP);

}
//----------------------------------------------THE LOOP-----------------------------------------------------
void loop()
{
  number();
  
  while (digitalRead(Estop) == LOW)
  {
    Serial.println("Estop");
    Serial.println("Estop");
    delay(1000);
  }
}

//-------------------in the loop ------ watching serial input from outside program----------------------------
void number() {

  if (Serial.available() > 0)
  {
    for (int i = 1; i < 9; i++)
    {
      readit1 = Serial.readStringUntil('\r');
      dex[i] = readit1;
      
    }
    Serial.setTimeout(20);
    PathtoRun();
  }

}
//----------------serial data on IPM--------sets delay in stepper motors per pulse---------------------------
void PathtoRun()
{

  if (dex[4].startsWith("Manual On"))
  {
    ManualIPM(); //ManualMove
  }
  if (dex[4].startsWith("Taper"))
  {
    captureAllIPM();//DualMotors
  }
  if (dex[4] == "ToolSet")
  {
    Toolset();//ToolSetMoves
  }
  if (dex[4] == "LimitX")
  {
    XLimit();
  }
  if (dex[4] == "LimitY")
  {
    YLimit();
  }
  if (dex[4] == "LimitZ")
  {
    ZLimit();
  }
  if (dex[4] == "LimitA")
  {
    ALimit();
  }
  if (dex[4] == "E-Stop")
  {   
     captureIPM();   
  }
  if (dex[4] == "")
  {
    captureIPM();//Motors
  }
  else
  {
    return;
  }
}
