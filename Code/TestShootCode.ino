int state=0;
void setup() {

  for (int i = 0;i<14;i++){
    pinMode(i, OUTPUT); // pin will be used to for output
  }

    Serial.begin(9600); // same as in your c++ script

  for (int i = 0;i<14;i++){
    digitalWrite(i, HIGH);
  }
}

void loop() {

  for (int i = 0;i<14;i++){
    digitalWrite(i, LOW);
    delay(100);
   }

  setup();
  
  

}
