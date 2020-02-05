// 2930 bytes
//2916 bytes
//2670 bytes

int timeTill = 400;

const byte buttonPin = 3;
const byte victoryLight = 2;
const byte light1 = 9;
const byte light2 = 10;
const byte lightGreen = 11;
const byte light3 = 12;
const byte light4 = 13;

bool isLit = false;
bool Pressed = false;
void setup() {
  pinMode(victoryLight, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT); 
  pinMode(lightGreen, OUTPUT);
  pinMode(light3, OUTPUT); 
  pinMode(light4, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), VictoryCheck, RISING);
  Serial.begin(9600);
}
  
void loop() {
  digitalWrite(victoryLight, LOW);
  digitalWrite(light1, HIGH);
  
  delay(timeTill);
  
  digitalWrite(light1, LOW);
  digitalWrite(light2, HIGH);

  delay(timeTill);

  digitalWrite(light2, LOW);
  digitalWrite(lightGreen, HIGH);


  delay(timeTill);
  if(isLit)
  {
    Winner();
    isLit = false;
    return;
  }
  digitalWrite(lightGreen, LOW);
  digitalWrite(light3, HIGH);
  delay(timeTill);
  digitalWrite(light3, LOW);
  digitalWrite(light4, HIGH);
  delay(timeTill);
  digitalWrite(light4, LOW);
  delay(timeTill);
}
void Winner()
{
  digitalWrite(victoryLight, HIGH);
  timeTill = (timeTill/2)+20;
  int flashDelay = 200;
  Serial.print("VICTORY");

  for(int i=0; i<10; i+=1)
  {
      digitalWrite(light2, LOW);
      digitalWrite(light3, LOW);
      digitalWrite(light1, HIGH);
      digitalWrite(light4, HIGH);
      delay(flashDelay);
      digitalWrite(light1, LOW);
      digitalWrite(light4, LOW);
      digitalWrite(light2, HIGH);
      digitalWrite(light3, HIGH);
      delay(flashDelay);
   }
   digitalWrite(lightGreen, LOW);
   digitalWrite(light1, LOW);
   digitalWrite(light2, LOW);
   digitalWrite(light3, LOW);
   digitalWrite(light4, LOW);
   digitalWrite(victoryLight, LOW);
}

void VictoryCheck()
{
  isLit = digitalRead(lightGreen) == HIGH;
}
