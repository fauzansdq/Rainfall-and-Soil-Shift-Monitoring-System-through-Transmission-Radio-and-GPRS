void SubmitHttpRequest()
{

  SIM800.println("AT+CSQ");
  delay(5);
  ShowSerialData();
  SIM800.println("AT+CGATT?");
  delay(5);
  ShowSerialData();
  SIM800.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(5);
  ShowSerialData();
  SIM800.println("AT+SAPBR=3,1,\"APN\",\"internet\"");
  delay(5);
  ShowSerialData();
  SIM800.println("AT+SAPBR=1,1");
  delay(5);
  ShowSerialData();
  SIM800.println("AT+HTTPINIT");
  delay(5);
  ShowSerialData();
  /*   waktu = rtc.getTime();
    int dataJam = waktu.hour;
    int dataMenit = waktu.min;
    int dataDetik = waktu.sec; */
  /* if (dataJam = 14 and dataMenit <55){
    Serial.print("kirim ke statistik");
    }else{ */
  SIM800.print("AT+HTTPPARA=\"URL\",\"monitoringcurahhujan.000webhostapp.com/aksi_input_data.php?tinggi=");
  //}
  SIM800.print(received[0]); SIM800.print("&x="); SIM800.print(received[1]);
  SIM800.print("&id="); SIM800.print(received[2]);
  SIM800.println("\"");
  delay(5);
  ShowSerialData();
  SIM800.println("AT+HTTPACTION=0");
  delay(5);
  ShowSerialData();
  SIM800.println("AT+HTTPTERM");
  delay(5);
  ShowSerialData();

  /* Serial.println(""); Serial.print( " Tinggi = "); Serial.print(received[0]);
    Serial.print( " x = "); Serial.print(received[1]);
    Serial.print( " y = "); Serial.print(received[2]);
    Serial.print( " z = "); Serial.print(received[3]);
    Serial.print( " id = "); Serial.println(received[4]);
    Serial.print( " tanggal = "); Serial.print(rtc.getDateStr());
    Serial.print( " Jam = "); Serial.println(rtc.getTimeStr()); */
  lcd.setCursor(2, 1);
  lcd.print(received[0], 2);
  lcd.setCursor(12, 1);
  lcd.print(received[1]);
  lcd.setCursor(3, 3);
  lcd.print(received[2], 0);
}

void ShowSerialData()
{
  while (SIM800.available() != 0)
    Serial.write(char (SIM800.read()));
}
