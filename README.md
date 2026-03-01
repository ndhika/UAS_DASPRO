# 🏨 Sistem Reservasi Hotel - UAS Dasar Pemrograman

Repositori ini berisi *source code* untuk program **Sistem Reservasi Hotel** yang dibangun menggunakan bahasa pemrograman **C++**. Proyek ini dikembangkan sebagai pemenuhan tugas Ujian Akhir Semester (UAS) mata kuliah Dasar Pemrograman (Daspro) pada program studi Teknik Informatika.

## 📋 Deskripsi Proyek
Program ini adalah aplikasi berbasis CLI (*Command Line Interface*) yang dirancang untuk mensimulasikan proses pemesanan kamar hotel secara digital. Aplikasi ini memudahkan pencatatan data tamu, pemilihan kamar, hingga kalkulasi total pembayaran.

Dalam pengembangannya, file utama `sistem_reservasi_hotel.cpp` disusun dengan mengimplementasikan beberapa konsep fundamental C++, antara lain:
* **Struct**: Digunakan untuk mengelompokkan entitas data yang berkaitan, seperti informasi identitas tamu dan detail spesifikasi kamar (nomor, tipe, harga).
* **Array**: Berfungsi untuk menyimpan sekumpulan data kamar yang tersedia serta riwayat reservasi pelanggan agar pengelolaan data lebih terstruktur.
* **Fungsi Rekursif**: Diterapkan dalam alur logika program, baik untuk proses pencarian data kamar, menu iterasi, maupun perhitungan kalkulasi biaya secara dinamis.

## 🚀 Fitur Utama
1.  **Daftar Kamar**: Menampilkan katalog kamar yang tersedia beserta tipe dan tarif per malam.
2.  **Proses Pemesanan**: Memungkinkan pengguna untuk menginput data diri dan durasi menginap.
3.  **Kalkulasi Biaya Otomatis**: Menghitung total tagihan berdasarkan tipe kamar yang dipilih dan lama waktu menginap.
4.  **Cetak Struk Reservasi**: Menampilkan ringkasan (invoice) dari pesanan yang telah berhasil dibuat.

## 🛠️ Cara Menjalankan Program
Pastikan komputer kamu sudah terinstal *compiler* C++ (seperti MinGW, GCC, atau *built-in compiler* dari IDE seperti Dev-C++/Code::Blocks).

1. **Clone Repositori**
   Buka terminal/CMD dan jalankan perintah berikut:
   ```bash
   git clone [https://github.com/ndhika/UAS_DASPRO.git](https://github.com/ndhika/UAS_DASPRO.git)
   cd UAS_DASPRO
Kompilasi Kode
Compile file program menggunakan g++:

Bash
g++ sistem_reservasi_hotel.cpp -o reservasi_hotel
Jalankan Aplikasi
Setelah proses kompilasi berhasil, jalankan executable file dengan perintah:

Bash
# Pengguna Windows:
reservasi_hotel.exe

# Pengguna Linux / Mac:
./reservasi_hotel
📂 Struktur Repositori
sistem_reservasi_hotel.cpp: File source code utama yang berisi seluruh logika program aplikasi.

.gitignore: File konfigurasi untuk mengabaikan file yang tidak perlu masuk ke dalam version control (seperti file hasil compile / .exe).

Dibuat untuk keperluan akademik - Ujian Akhir Semester (UAS) Dasar Pemrograman.


***

**Tips Tambahan:** Jika aplikasi tersebut memiliki tambahan fitur spesifik lain yan
