#include <SoftwareSerial.h>
#include <SD.h>
#include <SPI.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
File myFile;
int pinCS = 10;

SoftwareSerial SIM800(4, 5); //rx tx
float received[3];    
int i;

DS3231  rtc(SDA, SCL);
Time waktu;

void setup() {
   lcd.init();                      // initialize the lcd
  lcd.backlight();
 lcd.setCursor(0,1);
 lcd.print("t=");
 lcd.setCursor(10,1);
 lcd.print("x=");
 lcd.setCursor(0,2);
 lcd.print("y=");
 lcd.setCursor(10,2);
 lcd.print("z=");
 lcd.setCursor(0,3);
 lcd.print("id=");
 lcd.setCursor(10,3);
 lcd.print("SD=");
  SIM800.begin(38400);
  Serial.begin(38400);
 // Serial.println("BISMILLAH");
  pinMode(pinCS, OUTPUT);
   rtc.begin();
 // rtc.setTime(20, 21, 00);      // Set waktu JJ:MM:DD (24hr format)
 // rtc.setDate(19, 7, 2018);

  if (SD.begin())
  {
   lcd.setCursor(13,3);
   lcd.print("ON");
  } else
  {
  //  Serial.println("inisialisasi SD card gagal.");
  lcd.setCursor(13,3);
  lcd.print("error");
    return;
  }

 
  
 
}


void loop() {
  static unsigned long cetak = millis();
  if (millis() - cetak > 1000)
  {
  cetak = millis(); 
//  Serial.println("  Menerima data dari client....");
 // Serial.println("Proses pengiriman data melalui SIM800L...." );
  //Serial.println("");

  if (SIM800.available() > 0 * sizeof(float)) {
    uint8_t *recv_bytes = (uint8_t*)received;
    for (i = 0; i < 3 * sizeof(float); i++)
    {
      recv_bytes[i] = SIM800.read();
    }
    SubmitHttpRequest();
   // Serial.println(F(""));
   
  }
  
  
//lcd.setCursor(

 
 
 
  else {
  //  Serial.println("error opening test.txt");
  }

 // Serial.println("proses transfer data selesai" );
 // Serial.println("");
 // fauzan;
 // delay(2000);
  }
  waktu2();
  sdcard();
}

void waktu2(){
  static unsigned long waktu1 = millis();
  if (millis() - waktu1 > 1000)
  {
  waktu1 = millis();
   lcd.setCursor(0,0);
   lcd.print(rtc.getTimeStr());
   lcd.setCursor(10,0);
   lcd.print(rtc.getDateStr());
}
}

void sdcard(){
 static unsigned long waktu1 = millis();
  if (millis() - waktu1 > 10000)
  {
  waktu1 = millis();
  
  myFile = SD.open("test3.txt", FILE_WRITE);
  if (myFile) {
    myFile.print(rtc.getDateStr());
    myFile.print(",");
    myFile.print(rtc.getTimeStr());
    myFile.print(",");
    myFile.print(received[0]);
    myFile.print(",");
    myFile.print(received[1]);
    myFile.print(",");
    myFile.print(received[2]);
    myFile.close();
  }
  
  }
}

