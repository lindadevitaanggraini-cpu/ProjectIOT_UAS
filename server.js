const { SerialPort } = require("serialport");
const { ReadlineParser } = require("@serialport/parser-readline");
const { Server } = require("socket.io");
const http = require("http");
const express = require("express");

const app = express();
const server = http.createServer(app);
const io = new Server(server);

app.use(express.json());

app.get("/", (req, res) => {
    res.sendFile(__dirname + "/views/index.html");
});

io.on("connection", (socket) => {
    console.log("Client connected to Dashboard...");
    socket.on("disconnect", () => {
        console.log("Client disconnected from Dashboard");
    });
});

server.listen(5000, () => {
    console.log("Server Smart Home running on port 5000!");
});

// Konektifitas Serial Arduino
const port = new SerialPort({
    path: "COM7", // Sesuaikan dengan port Arduino Anda (COM3, COM4, COM5, dst)
    baudRate: 9600, // PERBAIKAN: Diubah ke 9600 mengikuti spesifikasi sketch Smart Home baru
});

const parser = port.pipe(new ReadlineParser({ delimiter: "\r\n" }));

// 1. TERIMA DATA SERIAL DARI ARDUINO (STATUS SUHU / ALARM API) KE WEB DASHBOARD
parser.on("data", (result) => {
    // Bersihkan data dari spasi atau karakter enter tak terlihat
    const cleanData = result.toString().trim();
    
    console.log("Data dari Arduino -> ", cleanData);

    // Cek jika data mengandung indikator bahaya kebakaran/api
    if (cleanData.includes("⚠️ BAHAYA") || cleanData.includes("Kebakaran")) {
        // Kirim sinyal alert darurat kebakaran ke frontend web
        io.emit("kebakaranAlert", { message: cleanData });
    } 
    // Cek jika data berupa status suhu aman reguler
    else if (cleanData.includes("🟢 Status") || cleanData.includes("Aman")) {
        // Kirim status kondisi aman ke frontend web
        io.emit("statusAman", { message: cleanData });
    }
});

// 2. KONTROL UTAMA: API Endpoint Menerima Klik Tombol Web (1, 2, 3, 4, 5) untuk Dikirim ke Arduino
app.post("/arduinoApi", (req, res) => {
    const data = req.body.data; // Menerima angka string (misal: "1", "2", dst)

    // Tulis data ke kabel USB Arduino
    port.write(data, (err) => {
        if (err) {
            console.log('Error saat mengontrol alat via Serial: ', err);
            return res.status(500).json({ error: "Gagal mengirim perintah ke alat!" });
        }
        console.log("Web Dashboard mengirim perintah -> Karakter [" + data + "] sukses diteruskan ke Arduino.");
        res.json({ status: "success", message: "Perintah " + data + " berhasil dikirim." });
    });
});