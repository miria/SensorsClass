
const int sensorPin = A0;
const float maxVoltage = 5.0;

void setup() {  
   Serial.begin(9600); 
}

void loop() {
   int reading = analogRead(sensorPin);
   float voltage = (reading / 1024.0) * maxVoltage;
  
   // According to the datasheet, this sensor returns 0 volts at -50 degrees
   // Celsius and 1.75 volts at 125 degrees Celsius. It has a scale of 
   // 10 millivolts per degree Celsius (or, 1/100 volt = 1 degree C). To get the raw voltage reading, 
   // we take our reading value, divide it by 1024 (to get the percentage 
   // of the full voltage) and then multiply that by the max voltage. 
   // To scale the voltage to the range, we can simply multiply the voltage
   // by 100 (since 1/100 volt is 1 degree Celsius)  and then subtract 
   // 50 (since zero volts is -50 degrees Celsius).  
   float tempC = (voltage * 100.0) - 50.0;
   Serial.println("Temperature in Celsius: "); 
   Serial.println(tempC); 
  
   float tempF = (tempC * 9.0 / 5.0) + 32.0;
   Serial.print("Temperature in Fahrenheit: ");
   Serial.println(tempF); 
  
   delay(1000); 
}
