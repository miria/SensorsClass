
const int sensorPin = A5; 

void setup() {
   Serial.begin(9600);
}

void loop() {
   int reading = analogRead(sensorPin);
  
   Serial.print("Pin reading: ");
   Serial.print(reading); 

   delay(1000);
}
