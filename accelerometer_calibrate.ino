
const int xPin = A0;
const int yPin = A2;
const int zPin = A4;
const int buttonPin = 2;

int xMin = 512; // xRaw at -1.0g
int xMax = 512; // xRaw at +1.0g 
int yMin = 512;
int yMax = 512;   
int zMin = 512;
int zMax = 512;
     
const int numSamples = 10;
     
void setup() {
   analogReference(EXTERNAL);
   Serial.begin(9600);
}
     
void loop() {
   int xRaw = getAverageReading(xPin);
   int yRaw = getAverageReading(yPin);
   int zRaw = getAverageReading(zPin);
   
   if (digitalRead(buttonPin) == LOW) {
      calibrateSensor(xRaw, yRaw, zRaw);
   }

   Serial.print("X axis: raw=");
   Serial.print(xRaw);
   Serial.print(" min=");
   Serial.print(xMin);
   Serial.print(" max=");
   Serial.print(xMax);   
   Serial.print(" g's=");
   Serial.println(convertToGravitationalForce(xRaw, xMin, xMax));

   Serial.print("Y axis: raw=");
   Serial.print(yRaw);
   Serial.print(" min=");
   Serial.print(yMin);
   Serial.print(" max=");
   Serial.print(yMax);   
   Serial.print(" g's=");
   Serial.println(convertToGravitationalForce(yRaw, yMin, yMax));

   Serial.print("Z axis: raw=");
   Serial.print(zRaw);
   Serial.print(" min=");
   Serial.print(zMin);
   Serial.print(" max=");
   Serial.print(zMax);   
   Serial.print(" g's=");
   Serial.println(convertToGravitationalForce(zRaw, zMin, zMax));

   delay(500);
}
     
int getAverageReading(int pin) {
   long sum = 0;
   for (int i=0; i < numSamples; i++) {
      sum = sum + analogRead(pin);
      delay(1);
   }
   return sum/numSamples;
}

void calibrateSensor(int xRaw, int yRaw, int zRaw) {
   Serial.println("Calibrating sensor...");
   if (xRaw < xMin) 
      xMin = xRaw;
   
   if (xRaw > xMax)
      xMax = xRaw;

   if (yRaw < yMin)
      yMin = yRaw;
      
   if (yRaw > yMax)
      yMax = yRaw;
     
   if (zRaw < zMin)
      zMin = zRaw;

   if (zRaw > zMax)
      zMax = zRaw;
}

float convertToGravitationalForce(int reading, int minValue, int maxValue) {
   // The map function simply rescales the reading based on our reference 
   // measurements at -1.0 g and +1.0g on the given axis. We convert the 
   // reading from the raw input to thousandths of the gravitational force, 
   // then divide by 1000 to get the g value.
   int milliGs = map(reading, minValue, maxValue, -1000, 1000);
   return milliGs / 1000.0;
}
