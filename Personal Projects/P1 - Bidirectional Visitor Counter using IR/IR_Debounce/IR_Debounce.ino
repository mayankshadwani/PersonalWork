int prevBtnUp1 = HIGH, prevBtnUp2 = HIGH;
int buttonUpState1 = 0, buttonUpState2 = 0;
unsigned long lastBtnUp1 = 0, lastBtnUp2 = 0;
unsigned long transInt = 50;
int count=0;
const int IRsensor1=2, IRsensor2=3;

void setup(){
  Serial.begin(9600);
  pinMode (IRsensor1, INPUT);
  pinMode (IRsensor2, INPUT);
}

void loop(){
  IRdebounce1();
  IRdebounce2();
}

void IRdebounce1(){
  buttonUpState1 = digitalRead(IRsensor1); 
  if (buttonUpState1 == HIGH && prevBtnUp1 == LOW){
    if ((millis() - lastBtnUp1) > transInt){
      Serial.println("Person IN");
      count=count+1;
      lastBtnUp1 = millis();
    }
   Serial.println(count);
  }
 prevBtnUp1 = buttonUpState1;
}

void IRdebounce2(){
  buttonUpState2 = digitalRead(IRsensor2); 
  if (buttonUpState2 == HIGH && prevBtnUp2 == LOW){
    if ((millis() - lastBtnUp2) > transInt){
      Serial.println("Person OUT");
      count=count-1;
      lastBtnUp2 = millis();
    }
   Serial.println(count);
  }
 prevBtnUp2 = buttonUpState2;
}
