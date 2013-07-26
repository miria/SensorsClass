
const int sensorPin = 2;

void setup() {
   Serial.begin(9600); 
}

void loop() { 
   int reading = digitalRead(sensorPin);
  
   Serial.print("Pin reading: ");
   Serial.println(reading);
  
   delay(10);
}


