typedef void (*callback_function)(void);

void runfor(uint32_t duration, callback_function patternCode){
  uint32_t timer = millis();
  while ((millis()-timer)<=duration) {
    //get these commands from caller function
    patternCode();
  }
}

void pattern1() {
  // Light pattern #1
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("hi");
  delay(100);
}

void pattern2() {
  // Light pattern #2
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("there");
  delay(100);
}

void setup() {
  // Setup code
  Serial.begin(115200);
}

void loop() {
  runfor(1000, pattern1);
  runfor(2000, pattern2);
}
