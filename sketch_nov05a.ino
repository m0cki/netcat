
const int clockPin = 2;
const int outPins[3] = {3,4,5};
const int inPins[3] = {6,7,8};
volatile bool isRisingEdge = true;

void setup() {
  pinMode(clockpin, INPUT);
  for(int i=0;i<3;i++){
    pinMode(outPins[i], OUTPUT);
    pinMode(inPins[i], INPUT);  
  }
  attachInterrupt(digitalPinToInterrupt(clockPin), handleClock, CHANGE)
}

void loop() {
  // put your main code here, to run repeatedly:

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
}

void receiveData(){
  //hier sollen die 3 Input Pins gesetzt werden
  int receivedBits[3];
  //receivedBits[0] =
  //receivedBits[1] =
  //receivedBits[2] =
}
