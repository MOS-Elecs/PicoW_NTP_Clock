#include <Wire.h>

#define RTC_I2C_ADDR 0x68
#define I2C_SDA         0
#define I2C_SCL         1

#define BAUDRATE 115200

uint8_t dec2bcd(uint8_t datum) {
  return ((datum / 10) << 4) | (datum % 10);
}

void setup() {
  Wire.setSDA(I2C_SDA);
  Wire.setSCL(I2C_SCL);
  Wire.begin();

  Serial.begin(BAUDRATE);
  for(size_t i = 0; i < 100 & !Serial; i++) delay(10);

  Wire.beginTransmission(RTC_I2C_ADDR);
  Wire.write(0x07);  // start address
  Wire.write(0b00010000);  // 1Hz output
  Wire.endTransmission();
}

void loop() {
}
