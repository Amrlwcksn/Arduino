
int trig = 4;
int echo = 2;
long durasi, jarak;
int merah = 26;
int kuning =27;
int hijau = 14;
int buzzer = 25;

#include <Wire.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 lcd( 128, 32, &Wire, 4);

void setup() {
  lcd.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  lcd.clearDisplay();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(merah,OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  durasi = pulseIn(echo, HIGH);
  jarak = (durasi / 2 ) / 29.1;
  if(jarak >= 10){
    digitalWrite(hijau, HIGH);
    digitalWrite(merah, LOW);
    digitalWrite(kuning, LOW);
    digitalWrite(buzzer, LOW);
  }else if ((jarak > 5) && (jarak <=10 )){
    digitalWrite(hijau, LOW);
    digitalWrite(merah, LOW);
    digitalWrite(kuning, HIGH);
    digitalWrite(buzzer, LOW);
    delay(400);
    digitalWrite(buzzer, HIGH);
    delay(400);
  }
  else if ((jarak >2 )&& (jarak <=5)) {
    digitalWrite(hijau, LOW);
    digitalWrite(merah, HIGH);
    digitalWrite(kuning, LOW);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(200);
  }

   lcd.clearDisplay();

  //jarak
  lcd.setTextSize(1);
  lcd.setCursor(0,0);
  lcd.setTextColor(WHITE);
  lcd.print("Distance: ");
  //Parameter jarak
  lcd.setTextSize(1);
  lcd.setCursor(55,0);
  lcd.print(jarak);
  
  lcd.display(); 
  // Serial.print("Jarak benda : ");
  // Serial.print(jarak);
  // Serial.print(" cm");

}
