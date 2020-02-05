// 2930 bytes
//2916 bytes

int timeTill = 400;

const int buttonPin = 3;
const int victoryLight = 2;
const int light1 = 9;
const int light2 = 10;
const int lightGreen = 11;
const int light3 = 12;
const int light4 = 13;

int buttonState = 0;
bool Pressed = false;
void setup() {
  pinMode(victoryLight, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT); 
  pinMode(lightGreen, OUTPUT);
  pinMode(light3, OUTPUT); 
  pinMode(light4, OUTPUT);
  Serial.begin(9600);
}
  
void loop() {
  Pressed = false;
  digitalWrite(victoryLight, LOW);
  digitalWrite(light1, HIGH);
  delay(timeTill);
  digitalWrite(light1, LOW);
  digitalWrite(light2, HIGH);
  buttonStatus();
  delay(timeTill);
  buttonStatus();
  digitalWrite(light2, LOW);
  digitalWrite(lightGreen, HIGH);
  Serial.print(buttonState);
  VictoryCheck();
  delay(timeTill/2);
  VictoryCheck();
  delay(timeTill/2);
  VictoryCheck();
  digitalWrite(lightGreen, LOW);
  digitalWrite(light3, HIGH);
  delay(timeTill);
  digitalWrite(light3, LOW);
  digitalWrite(light4, HIGH);
  delay(timeTill);
  digitalWrite(light4, LOW);
  delay(timeTill);
}
void buttonStatus()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    Pressed = true;
  }
  else
  {
    Pressed = false;
  }
}
void VictoryCheck()
{
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH && Pressed == false )
  {
    timeTill = (timeTill/2)+50;
      int flashDelay = 200;
      Serial.print("VICTORY");
      digitalWrite(2, HIGH);
      for(int i=0; i<10; i+=1)
      {
        digitalWrite(10, LOW);
        digitalWrite(12, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(13, HIGH);
        delay(flashDelay);
        digitalWrite(9, LOW);
        digitalWrite(13, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(12, HIGH);
        delay(flashDelay);
      }
      digitalWrite(2, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
        
    return;
  }
}
