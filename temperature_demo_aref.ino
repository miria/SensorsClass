const int sensorPin = A0;
const float maxVoltage = 3.3;

void setup() { 
  analogReference(EXTERNAL); 
  Serial.begin(9600); 
}

void loop() {
   int reading = analogRead(sensorPin);
   float voltage = (reading / 1024.0) * maxVoltage;

   float tempC = (voltage * 100.0) - 50.0;
   Serial.println("Temperature in Celsius: "); 
   Serial.println(tempC); 
  
   float tempF = (tempC * 9.0 / 5.0) + 32.0;
   Serial.print("Temperature in Fahrenheit: ");
   Serial.println(tempF); 
  
   delay(1000); 
}

