 const int clockPin = 2;
 const int outPins[3] = {3,4,5};
 const int inPins[3] = {6,7,8};
 volatile bool isRisingEdge = true;
  

void setup() {
  pinMode(clockPin, INPUT);
  for(int i=0;i<3;i++){
    pinMode(outPins[i], OUTPUT);
    pinMode(inPins[i], INPUT);  
  }
  attachInterrupt(digitalPinToInterrupt(clockPin), handleClock, CHANGE);
}

void loop() {
 
}

void handleClock(){
  if(digitalRead(clockPin) == HIGH){
    isRisingEdge = true;
    receiveData();
  } else {
    isRisingEdge = false;
    sendData();
  }
}

void sendData(){
  //hier sollen die 3 Output Pins gesetzt werden
  digitalWrite(outPins[0], HIGH);
  digitalWrite(outPins[1], LOW);
  digitalWrite(outPins[2], HIGH);
}

void receiveData(){
  //hier sollen die 3 Input Pins gesetzt werden
  int receivedBits[3];
  //receivedBits[0] = digitalWrite(inPins[0]);
  //receivedBits[1] = digitalWrite(inPins[1]);
  //receivedBits[2] = digitalWrite(inPins[2]);
}
