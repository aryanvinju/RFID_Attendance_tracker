#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

// 20 columns, 4 rows
LiquidCrystal_I2C lcd(0x27, 20, 4);

String student1 = "3C E9 FA 03";   // Replace with your UID
String student2 = "D5 CD FE 03";
String student3 = "91 99 FB 03";
String student4 = "CC EF FF 03";

bool marked1 = false;
bool marked2 = false;
bool marked3 = false;
bool marked4 = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("RFID Attendance");
  lcd.setCursor(0, 1);
  lcd.print("Scan your card");
}

void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String content = "";

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    content += String(mfrc522.uid.uidByte[i], HEX);
  }

  content.toUpperCase();

  Serial.println(content.substring(1));

  lcd.clear();

  if (content.substring(1) == student1) {
    lcd.setCursor(0, 0);
    lcd.print("Aryan");
    lcd.setCursor(0, 1);
    lcd.print(marked1 ? "Already Marked" : "Attendance Done");
    marked1 = true;
  }

  else if (content.substring(1) == student2) {
    lcd.setCursor(0, 0);
    lcd.print("Shetty");
    lcd.setCursor(0, 1);
    lcd.print(marked2 ? "Already Marked" : "Attendance Done");
    marked2 = true;
  }

  else if (content.substring(1) == student3) {
    lcd.setCursor(0, 0);
    lcd.print("Vinju");
    lcd.setCursor(0, 1);
    lcd.print(marked3 ? "Already Marked" : "Attendance Done");
    marked3 = true;
  }

  else if (content.substring(1) == student4) {
    lcd.setCursor(0, 0);
    lcd.print("Aditya");
    lcd.setCursor(0, 1);
    lcd.print(marked4 ? "Already Marked" : "Attendance Done");
    marked4 = true;
  }

  else {
    lcd.setCursor(0, 0);
    lcd.print("Unknown Card");
  }

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");
}