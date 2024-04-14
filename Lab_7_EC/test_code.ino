/*#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// Initialize the MPU6050 and LCD
Adafruit_MPU6050 mpu;
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// Variables to hold step count and previous filtered acceleration
int stepCount = 0;
float lastFilteredAccel = 0;
float stepThreshold = 2.0; // Adjust this threshold based on your testing

// Moving average filter parameters
const int numReadings = 10;
float readings[numReadings]; // the readings from the analog input
int readIndex = 0; // the index of the current reading
float total = 0; // the running total
float average = 0; // the average

void setup() {
  Serial.begin(115200);

  // Initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Steps: ");

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  // Set up MPU6050
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate the magnitude of the accelerometer vector
  float accelMagnitude = sqrt(a.acceleration.x * a.acceleration.x + 
                              a.acceleration.y * a.acceleration.y + 
                              a.acceleration.z * a.acceleration.z);

  // Subtract the last reading:
  total = total - readings[readIndex];
  // Read from the sensor:
  readings[readIndex] = accelMagnitude;
  // Add the reading to the total:
  total = total + readings[readIndex];
  // Advance to the next position in the array:
  readIndex = (readIndex + 1) % numReadings;
  // Calculate the average:
  average = total / numReadings;

  // Check if the filtered acceleration exceeds the threshold and there's a significant change
  if (average > stepThreshold && abs(average - lastFilteredAccel) > 0.3) {
    stepCount++;
    lcd.setCursor(7, 0);
    lcd.print(stepCount);
    delay(250); // Delay to avoid counting the same step multiple times
  }

  lastFilteredAccel = average; // Update the last filtered acceleration magnitude

  // Optional: Add a delay for debouncing
  delay(50); 
} */

//Not sensitive enough


