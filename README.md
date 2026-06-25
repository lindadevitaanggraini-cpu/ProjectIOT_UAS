# 🏠 Smart Home IoT Project — Garasi Mobil & Sistem Proteksi Kebakaran (Branch: main)

Selamat datang di repositori komponen hardware dan kode mikrokontroler proyek **Smart Home IoT**. Dokumentasi ini dibuat khusus untuk memandu tim penguji atau divisi hardware dalam memasang, mengonfigurasi, dan mengunggah kode program langsung ke sirkuit fisik menggunakan **Arduino IDE**.

---

## 🛠️ Ringkasan Fitur Sistem
Kode program pada branch ini mengimplementasikan sistem rumah pintar terintegrasi yang memiliki 2 sub-sistem utama:
1. **Sistem Deteksi Dini Kebakaran:** Memanfaatkan *Sensor Api (Flame Sensor)* yang secara *real-time* memicu alarm berupa **Buzzer** dan **LED Merah** saat terindikasi ada api.
2. **Kontrol Garasi & Lampu via Serial:** Fitur otomatisasi pergerakan pintu garasi secara halus (*smooth servo movement*) dan manajemen saklar lampu (LED Putih & Bening) yang dikendalikan melalui input teks serial perintah (karakter '1' sampai '5').

---

## 🔌 Daftar Komponen & Pemetaan Pin (Pinout)

Silakan rakit komponen hardware Anda dengan mengikuti konfigurasi pin Arduino berikut:

| Nama Komponen | Pin Arduino | Deskripsi / Fungsi |
| :--- | :---: | :--- |
| **Sensor Api (Digital Out)** | **Pin 8** | Sensor pendeteksi radiasi panjang gelombang api |
| **Servo Motor** | **Pin 6** | Motor penggerak mekanik pintu garasi |
| **LED Merah** | **Pin 2** | Indikator visual ketika terjadi bahaya kebakaran |
| **Buzzer** | **Pin 5** | Alarm suara peringatan kebakaran |
| **LED Putih** | **Pin 3** | Lampu penerangan interior ruangan 1 |
| **LED Bening** | **Pin 4** | Lampu penerangan interior ruangan 2 |

---

## 🚀 Panduan Instalasi & Upload Kode

### Langkah 1: Kloning Repositori & Berpindah Jalur (Git Bash)
Buka terminal Git Bash pada komputer Anda, kemudian jalankan baris perintah berikut untuk mengunduh proyek dan masuk ke jalur branch `main`:

```bash
# 1. Download repositori ke lokal laptop
$ git clone [https://github.com/febrypradana/Smart-tongkat-tunanetra_Berbasis-web.git](https://github.com/febrypradana/Smart-tongkat-tunanetra_Berbasis-web.git)

# 2. Masuk ke direktori folder proyek
$ cd Smart-tongkat-tunanetra_Berbasis-web

# 3. Sinkronisasi seluruh indeks data dari server github
$ git fetch origin

# 4. Berpindah jalur secara khusus ke kode hardware utama
$ git checkout main
Setelah perintah di atas sukses, folder lokal Anda otomatis akan berisi dokumen kode utama bernama projectIOT_UAS.ino.

Langkah 2: Konfigurasi di Arduino IDE
Hubungkan papan mikrokontroler (Arduino Uno / sejenisnya) ke laptop menggunakan kabel USB data.

Buka aplikasi Arduino IDE, lalu muat/buka berkas kode projectIOT_UAS.ino.

Lakukan pengaturan perangkat pada bilah menu atas:

Pilih Board: Tools -> Board -> Pilih Arduino Uno (atau sesuaikan dengan jenis sirkuit Anda).

Pilih Port: Tools -> Port -> Pilih port yang aktif (misalnya COM3 / COM4).

Langkah 3: Verifikasi & Injeksi Program
Klik ikon Verify (Simbol Centang ✔️) untuk memastikan proses kompilasi kode berhasil tanpa adanya syntax error.

Klik ikon Upload (Simbol Panah Kanan ➡️) untuk langsung menginjeksikan kodingan program ke dalam sirkuit mikrokontroler.

Pastikan muncul status "Done uploading" pada bar bagian bawah aplikasi Arduino IDE.

🧪 Lembar Panduan Pengujian Sistem (Serial Monitor)
Setelah kode berhasil tertanam, buka fitur Serial Monitor pada Arduino IDE (atur tipe kecepatan data ke 9600 baud). Kirimkan karakter-karakter perintah berikut pada kolom input teks untuk menguji fungsionalitas alat:

Ketik 1 : Membuka Pintu Garasi secara perlahan (Smooth 0° ke 90°).

Ketik 4 : Menutup Pintu Garasi secara perlahan (Smooth 90° ke 0°).

Ketik 2 : Menyalakan Lampu Interior (LED Putih).

Ketik 3 : Menyalakan Lampu Teras (LED Bening).

Ketik 5 : Mematikan seluruh lampu rumah secara serentak (LED Putih & Bening padam).

⚠️ Simulasi Kebakaran: Dekatkan pemantik api ke Sensor Api. Secara otomatis, sistem akan langsung memotong antrean proses, menyalakan alarm buzzer, menyalakan LED Merah, serta memunculkan pesan peringatan mendesak ⚠️ BAHAYA! Kebakaran Terdeteksi! pada layar Serial Monitor Anda.
