# Smart Home Monitoring & Automation System (Project Akhir) 🏠🤖

Repositori ini berisi kode sumber untuk proyek **Smart Home Monitoring & Automation System**. Pengembangan proyek ini dibagi menjadi dua komponen utama yang dikelola melalui percabangan (*branching*) Git secara terpisah untuk menjaga kerapian struktur kode.

---

## 📌 Penting: Struktur Percabangan (Branching)
Repositori ini memiliki dua branch utama dengan peran dan fungsi yang sepenuhnya terpisah:

### 1. 🌐 Branch: master (KHUSUS WEB DASHBOARD) 
* **Fungsi:** Menyimpan seluruh kodingan aplikasi web berbasis **Node.js & Express**. 
* **Tujuan:** Menampilkan dashboard monitoring dan kontrol otomatisasi rumah secara realtime. 
* **Pengelola:** **Linda Devita Anggraini** (Master/Owner).
* *Catatan: Di branch `master` ini Anda hanya akan menemukan berkas-berkas yang berkaitan dengan kebutuhan website dashboard.*

### 2. 🔌 Branch: main (KHUSUS HARDWARE & ARDUINO)
* **Fungsi:** Menyimpan seluruh kodingan sketsa (*sketch*), pustaka, dan konfigurasi perangkat keras IoT berbasis mikrokontroler Arduino/ESP.
* **Tujuan:** Memproses data sensor (seperti sensor api) dan mengendalikan modul otomatisasi rumah.
* **Pengelola:** **Firda Dwi Agustina** dan **Elsa Melania Putri**.
* *Catatan: Jika Anda mencari kodingan hardware/Arduino lengkap, Anda wajib berpindah ke branch main.*

---

## 📂 Struktur Berkas Branch 'master' (Web Dashboard)

Berikut adalah struktur file penyusun web dashboard yang berada di dalam branch `master` sesuai dengan repositori saat ini:

* **`server.js`** — Berkas utama backend Node.js / Express server untuk menangani logika web, websocket, atau komunikasi data sensor.
* **`views/`** — Folder tempat menyimpan file antarmuka (frontend) dashboard web (seperti `index.html`).
* **`projectIoT_UAS.ino`** — File sketsa awal program Arduino (initial commit: penambahan sensor api pada smart home sebagai pengujian awal).
* **`package.json` & `package-lock.json`** — File konfigurasi dependensi, versi library, dan manifes proyek Node.js.
* **`node_modules/`** — Folder otomatis tempat menyimpan library pihak ketiga yang diinstal via npm.

---

## 📥 Cara Mengambil Kodingan (Clone & Switch Branch)

Gunakan perintah di bawah ini pada terminal Git Bash untuk mengunduh proyek dan beralih ke branch yang diinginkan:

### A. Proses Clone dan Sinkronisasi
```bash
$ git clone [https://github.com/febrypradana/Smart-tongkat-tunanetra_Berbasis-web.git](https://github.com/febrypradana/Smart-tongkat-tunanetra_Berbasis-web.git)
$ cd Smart-tongkat-tunanetra_Berbasis-web
B. Sinkronisasi Branch
Bash
$ git fetch origin
C. Berpindah ke Komponen Web Dashboard (Branch ini)
Bash
$ git checkout master
D. Berpindah ke Komponen Hardware / Arduino (Branch Main)
Bash
$ git checkout main
🚀 Tahapan Menjalankan Aplikasi Web Dashboard (Pada Branch 'master')
Pastikan Anda telah berada di dalam branch master sebelum mengeksekusi langkah-langkah berikut:

Langkah 1: Pastikan posisi branch sudah benar (master)
Bash
$ git checkout master
Langkah 2: Instalasi seluruh library/dependensi proyek website
Bash
$ npm install
Langkah 3: Jalankan local server Node.js
Bash
$ node server.js
Langkah 4: Buka web browser, lalu akses sistem melalui URL berikut
Plaintext
http://localhost:5000
