#include "iarduino_RTC.h"
#include <Servo.h> 

Servo servo1;

iarduino_RTC time(RTC_DS1302, 4, 2, 3);  // для модуля DS1302 - RST, CLK, DAT
// iarduino_RTC time(RTC_DS1307);       // для модуля DS1307 с i2C
// iarduino_RTC timeRTC_DS3231);        // для модуля DS3231 с i2C

#include "Wire.h"                   // библиотека для устройств I2C 
#include "LiquidCrystal_I2C.h"       // подк1ючаем библиотеку для дисплея



LiquidCrystal_I2C LCD(0x27,16,2);  // присваиваем имя дисплею  

void setup() {
   pinMode(13, OUTPUT); // объявляем пин 13 как выход
   pinMode(12, OUTPUT); // объявляем пин 13 как выход
   servo1.attach(11);
   delay(300);
   LCD.init();            // инициализация LCD дисплея
   LCD.backlight();  // включение подсветки дисплея
   Serial.begin(9600);
   time.begin();
   time.settime(45, 11, 20, 9, 3, 24, 6); // 0  сек, 30 мин, 18 часов, 12, июня, 2020, четверг
   digitalWrite(13, HIGH); // зажигаем светодиод
   servo1.write(100); 
}

void loop() {
   // Получаем текущее время каждую секунду
   if (millis() % 1000 == 0) {
      // Получаем текущее время в формате "H:i:s"
      String currentTime = time.gettime("H:i:s");
      
      int hour = currentTime.substring(0, 2).toInt();
      int minute = currentTime.substring(3, 5).toInt();
      int second = currentTime.substring(6, 8).toInt();


      int h1 = hour / 10;
      int h2 = hour % 10;

      int m1 = minute / 10;
      int m2 = minute % 10;

      int s1 = second / 10;
      int s2 = second % 10;

       LCD.setCursor(4, 0); 
       LCD.print(h1);  
       LCD.setCursor(5, 0); 
       LCD.print(h2); 
       LCD.setCursor(6, 0);  
       LCD.print(":"); 
       LCD.setCursor(7, 0); 
       LCD.print(m1);
       LCD.setCursor(8, 0); 
       LCD.print(m2); 
       LCD.setCursor(9, 0); 
       LCD.print(':'); 
       LCD.setCursor(10, 0); 
       LCD.print(s1); 
       LCD.setCursor(11, 0); 
       LCD.print(s2); 

       if(h1 == 2 && h2 == 0 && m1 == 1 && m2 == 2 && s1 == 0 && s2 == 0){
                  digitalWrite(13, LOW); // выключаем светодиод
                  servo1.write(0); // ставим угол поворота под 0
       }
       if(h1 == 2 && h2 == 0 && m1 == 1 && m2 == 2 && s1 == 1 && s2 == 0){
                  servo1.write(120); // ставим угол поворота под 0
                  digitalWrite(13, HIGH); // выключаем светодиод
                   
       }
      
      delay(1);
   }
}