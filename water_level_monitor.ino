#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// If your LCD stays blank, its I2C address may be 0x3F instead of 0x27.
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Water Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}

void loop() {
  int value = analogRead(sensorPin);

  lcd.setCursor(0, 0);
  lcd.print("Value: ");
  lcd.print(value);
  lcd.print("     ");

  lcd.setCursor(0, 1);
  lcd.print("W Level: ");

  // Example thresholds: calibrate these for your sensor.
  if (value == 0) {
    lcd.print("Empty  ");
  } else if (value < 350) {
    lcd.print("LOW    ");
  } else if (value < 510) {
    lcd.print("Medium ");
  } else {
    lcd.print("HIGH   ");
  }

  Serial.print("Sensor Value: ");
  Serial.println(value);
  delay(500);
}
