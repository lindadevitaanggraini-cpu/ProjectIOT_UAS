#include <SoftwareSerial.h>






//LED LAMPU CONTROL
int ledPutih = 3;
int ledBening = 4;

void setup() {


pinMode(ledPutih, OUTPUT);
pinMode(ledBening, OUTPUT);

}

void loop() {

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
