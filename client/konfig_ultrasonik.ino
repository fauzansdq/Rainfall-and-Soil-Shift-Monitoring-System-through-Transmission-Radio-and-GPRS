void konfigultrasonik(){
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
   cm = ((duration/2) / 29.1)*10;
  //Serial.println(duration);
  inches = (duration/2) / 74; 
  tinggi = 310 - cm;
  if (tinggi > 200){
 
  digitalWrite(led,HIGH);
  while (tinggi > 5){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
// Calculating the cm
cm= ((duration/2) / 29.1)*10;
tinggi = 310 - cm;
digitalWrite(led,HIGH);
 /* Serial.println("solenoid nyala");
  delay(500);*/
  }
}else{
  digitalWrite(led,LOW);
}
}

