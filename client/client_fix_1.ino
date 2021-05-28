#include <Wire.h>
#include <DS3231.h>

DS3231  rtc(A2, A3);
Time waktu;
long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ, id;
int trigPin = 8;    //Trig - green Jumper
int echoPin = 9;    //Echo - yellow Jumper
int dataJam ;
int dataMenit ;
int dataDetik ;
double duration, cm, inches;
float cm2, tinggi;
int led = 4;
//float id;


void setup() {
  Serial.begin(38400);
  Wire.begin();
  rtc.begin();
  setupMPU();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  id = 1;
}


void loop() {
  static unsigned long delai = millis();
  if (millis() - delai > 1000)
  {
    delai = millis();

    recordAccelRegisters();
    konfigultrasonik();
    // printData();
    // cm2=cm;
    float transmit[5] = {tinggi, gForceX, gForceY, gForceZ, id };

    //Serial.print ("char x = ");
  //  Serial.write((uint8_t*)transmit, 5 * sizeof(float));

    //ambil waktu
    waktu = rtc.getTime();
    dataJam = waktu.hour;
    dataMenit = waktu.min;
    dataDetik = waktu.sec;
    if (dataJam == 17 && dataMenit == 30) {
      while (dataMenit <= 34) {


        digitalWrite(led , HIGH);

      }
    } else {
      digitalWrite(led, LOW);
    }

    Serial.print(" Accel (g)");
      Serial.print(" X=");
      Serial.print(gForceX);
      Serial.print(" Y=");
      Serial.print(gForceY);
      Serial.print(" Z=");
      Serial.print(gForceZ);
      Serial.print("ultra =");
      Serial.print(tinggi);
      Serial.print("id =");
      Serial.println(id);

      Serial.print(dataJam);
      Serial.print(':');
      Serial.print(dataMenit);
      Serial.print(':');
      Serial.println(dataDetik); 
  }

}

