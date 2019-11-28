#include <RTClib.h>
#include <dht11.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#define DHT11_PIN 10
#define RTC_PIN 6
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht11 DHT;
RTC_DS1307 RTC;
char buffer1[20];
char buffer2[20];
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk=DHT.read(DHT11_PIN);
  lcd.setCursor(0, 0);
  lcd.print("Umid: ");
  lcd.print(DHT.humidity,1);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature,1);
  lcd.print(" gradi");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  RTC_DS1307 RTC;
  DateTime now = RTC.now();
  lcd.setCursor(0,0);
  lcd.print("Data: ");
  sprintf(buffer1, "%d/%d/%d",now.day(),now.month(),now.year());
  lcd.print(buffer1);
  lcd.setCursor(0,1);
  lcd.print("Ora: ");
  sprintf(buffer2, "%d:%d:%d", now.hour(), now.minute(), now.second());
  lcd.print(buffer2);
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}
