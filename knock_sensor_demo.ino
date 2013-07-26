
const int sensorPin = A5;               

void setup() {
   Serial.begin(9600);
}

void loop() {
   int reading = analogRead(sensorPin);     

   Serial.print("Pin reading ");
   Serial.println(reading);
  
   delay(100);  
}
