#include <SoftwareSerial.h>


// Sensor Api
int sensorPin = 8;
int sensorValue = 0;

//LED & Buzzer untuk Indikator Kebakaran 
int ledMerah = 2;
int buzzer = 5;


//LED LAMPU CONTROL
int ledPutih = 3;
int ledBening = 4;

void setup() {
  Serial.begin(9600);

  pinMode(sensorPin, INPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPutih, OUTPUT);
  pinMode(ledBening, OUTPUT);

}

void loop(){
// DETEKSI SENSOR API
  sensorValue = digitalRead(sensorPin);

  if(sensorValue == LOW);{
    digitalWrite (ledMerah, HIGH);
    digitalWrite (buzzer, HIGH);
    if (millis() - waktuLama >= 500){
      Serial.Println("⚠️ BAHAYA! Kebakaran Terdeteksi!");
      waktuLama = millis();
    }
  } else{
    digitalWrite(ledMerah, LOW);
    digitalWrite(buzzer, LOW);
    if (millis() - waktuLama >= 2000){
      Serial.Println("🟢 Status: Suhu & Lingkungan Aman.");
      waktuLama = millis();
    }
  }

//LED LAMPU CONTROL
//Ketik 2 :nyalakan lampu LED putih
else if(hasil == '2'){
  Serial.println("Perintah: LED Putih MENYALA");
  digitalWrite(ledPutih, HIGH);
}
//Ketik 3: nyalakan lampu LED Bening
else if (hasil == '3'){
  Serial.println("Perintah: LED Bening MENYALA");
  digitalWrite(ledBening, HIGH);
}
else if (hasil == '5'){
  Serial.println("Perintah: semua lampu DIMATIKAN");
  digitalWrite(ledPutih, LOW);
  digitalWrite(ledBening, LOW);
}

}
