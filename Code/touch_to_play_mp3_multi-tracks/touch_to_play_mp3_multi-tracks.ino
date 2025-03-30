//touch value
int currentTouch0 = 0;
int currentTouch1 = 0;
int currentTouch2 = 0;
int currentTouch3 = 0;
int currentTouch4 = 0;
int currentTouch5 = 0;

//storage value
int lastTouch0 = 0;
int lastTouch1 = 0;
int lastTouch2 = 0;
int lastTouch3 = 0;
int lastTouch4 = 0;
int lastTouch5 = 0;

//the number change of touched and before touch
int TouchSensitivity = 5;

void setup() {
  Serial.begin(115200);
  
  //touch pins
  for (int i = A0; i <= A5; i++) {
    pinMode(i, INPUT);
  }
}

void loop() {
  //assign reading to the name we create
  currentTouch0 = 1024 - analogRead(A0);
  currentTouch1 = 1024 - analogRead(A1);
  currentTouch2 = 1024 - analogRead(A2);
  currentTouch3 = 1024 - analogRead(A3);
  currentTouch4 = 1024 - analogRead(A4);
  currentTouch5 = 1024 - analogRead(A5);

  // Format data to send to Processing: sensor_index,activation_status
  if ((currentTouch0 - lastTouch0) >= TouchSensitivity) {
    Serial.println("0,1");
  } else if ((currentTouch0 - lastTouch0) <= -TouchSensitivity) {
    Serial.println("0,0");
  }
  
  if ((currentTouch1 - lastTouch1) >= TouchSensitivity) {
    Serial.println("1,1");
  } else if ((currentTouch1 - lastTouch1) <= -TouchSensitivity) {
    Serial.println("1,0");
  }
  
  if ((currentTouch2 - lastTouch2) >= TouchSensitivity) {
    Serial.println("2,1");
  } else if ((currentTouch2 - lastTouch2) <= -TouchSensitivity) {
    Serial.println("2,0");
  }
  
  if ((currentTouch3 - lastTouch3) >= TouchSensitivity) {
    Serial.println("3,1");
  } else if ((currentTouch3 - lastTouch3) <= -TouchSensitivity) {
    Serial.println("3,0");
  }
  
  if ((currentTouch4 - lastTouch4) >= TouchSensitivity) {
    Serial.println("4,1");
  } else if ((currentTouch4 - lastTouch4) <= -TouchSensitivity) {
    Serial.println("4,0");
  }
  
  if ((currentTouch5 - lastTouch5) >= TouchSensitivity) {
    Serial.println("5,1");
  } else if ((currentTouch5 - lastTouch5) <= -TouchSensitivity) {
    Serial.println("5,0");
  }

  //storage for last loop touch data
  lastTouch0 = currentTouch0;
  lastTouch1 = currentTouch1;
  lastTouch2 = currentTouch2;
  lastTouch3 = currentTouch3;
  lastTouch4 = currentTouch4;
  lastTouch5 = currentTouch5;

  //delay 0.1s
  delay(100);
}