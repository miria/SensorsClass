
const int xPin = A0;
const int yPin = A2;
const int zPin = A4;

// Values from the calibration script
const int xMin = 404;
const int xMax = 613;
const int yMin = 400;
const int yMax = 603;
const int zMin = 405;
const int zMax = 617;

void setup () {  
   analogReference(EXTERNAL);
   Serial.begin(9600);
}

void loop() {
   int xRaw = analogRead(xPin);
   int yRaw = analogRead(yPin);
   int zRaw = analogRead(zPin);
  
   Serial.print("X axis: reading=");
   Serial.println(convertToGs(xRaw, xMin, xMax));

   Serial.print("Y axis: reading=");
   Serial.println(convertToGs(yRaw, yMin, yMax));

   Serial.print("Z axis: reading=");
   Serial.println(convertToGs(zRaw, zMin, zMax));
   
   delay(500); 
}

float convertToGs(int reading, int minValue, int maxValue) {
   int milliGs = map(reading, minValue, maxValue, -1000, 1000);
   return milliGs / 1000.0;
}
