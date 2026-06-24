#include <SoftwareSerial.h>
#include <Servo.h>

// Sensor Api
int sensorPin = 8;
int sensorValue = 0;

//LED & Buzzer untuk Indikator Kebakaran 
int ledMerah = 2;
int buzzer = 5;

//LED LAMPU CONTROL
int ledPutih = 3;
int ledBening = 4;

// Servo Motor untuk Garasi
Servo myServo;
int servoPin = 6;

// Perbaikan Variabel untuk menyimpan posisi sudut terakhir servo garasi
int posisiGarasi = 0; // Mulai dari 0 (tertutup)

//Variabel pembantu pembatas waktu cetak di terminal
unsigned long waktuLama = 0;

void setup() {
  Serial.begin(9600);

  pinMode(sensorPin, INPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPutih, OUTPUT);
  pinMode(ledBening, OUTPUT);

  //Setting awal servo garasi
  myServo.attach(servoPin);
  myServo.attach(posisiGarasi); // Set awal halus (0 derajat)

  Serial.println("--- SISTEM SMART HOME GERAKAN HALUS AKTIF");
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

  // ---SUB-SISTEM 2: KONTROL SERIAL (DENGAN EFEK SMOOTH SERVO)---
  if(Serial.available() > 0) {
    char hasil = Serial.read();

//Ketik 1: Buka Garasi secara perlahan
if(hasil == '1') {
  if (posisiGarasi!= 90) {//Hanya bergerak jika posisi saat ini belum terbuka
    Serial.println("Perintah: Membuka Pintu Garasi secara perlahan...");

    // Loop menaikkan sudut dari posisi terakhir menuju 90 derajat
    for (int i = posisisGarasi;  <= 90; i++) {
      myServo.write(i);
      delay(15); 
    }
    posisiGarasi = 90; // Simpan status bahwa garasi sekarang terbuka
    Serial.println("Pintu Garasi Selesai DIBUKA.");
   }
}

// Ketik 4: Tutup Garasi secara perlahan
else if (hasil == '4') {
  if (posisiGarasi != 0) {
    Serial.println("Perintah: Menutup Pintu Garasi secara perlahan...");

    //Loop menurunkan sudut dari posisi terakhir kembali ke 0 derajat
    for (int i = posisiGarasi; i >=0; i--) {
      myServo.write(i);
      delay(15); // Beri jeda yang sama agar kecepatan tutup sewajarnya
    }
    posisiGarasi = 0; // Simpan status bahwa garasi sekarang tertutup
    Serial.println("Pintu Garasi Selesai Ditutup.");
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

delay(20);
}
