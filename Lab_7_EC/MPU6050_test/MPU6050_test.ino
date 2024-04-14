// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect
  Serial.println("Initializing MPU6050...");
  Wire.begin();
  
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed. Check your connections.");
  } else {
    Serial.println("MPU6050 connection successful.");
  }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  Serial.print("Accel X: "); Serial.print(ax);
  Serial.print(" | Accel Y: "); Serial.print(ay);
  Serial.print(" | Accel Z: "); Serial.print(az);
  Serial.print(" | Gyro X: "); Serial.print(gx);
  Serial.print(" | Gyro Y: "); Serial.print(gy);
  Serial.print(" | Gyro Z: "); Serial.println(gz);

  delay(1000); // Update at 1Hz
}
