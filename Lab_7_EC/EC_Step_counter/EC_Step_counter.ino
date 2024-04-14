#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// Initialize the MPU6050 and LCD
Adafruit_MPU6050 mpu;
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// Variables to hold step count and acceleration magnitude
int stepCount = 0;
float lastAccel = 0;
float stepThreshold = 11.5; // Adjust this threshold based on your testing

void setup() {
  Serial.begin(115200);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Step Counter: ");
  lcd.setCursor(0, 1);
  lcd.print(stepCount); // Display initial step count as 0

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

  // Check if the acceleration exceeds the threshold and there's a significant change
  if (accelMagnitude > stepThreshold && abs(accelMagnitude - lastAccel) > 0.2) {
    stepCount++;
    lcd.setCursor(0, 1);
    lcd.print("              "); // Clear the previous step count
    lcd.setCursor(0, 1);
    lcd.print(stepCount); // Display updated step count
    delay(250); // Delay to avoid counting the same step multiple times
  }

  lastAccel = accelMagnitude; // Update the last acceleration magnitude

  // Optional: Add a delay for debouncing
  delay(50);
}
