// JUDUL: Sistem Reservasi Hotel (Versi Hybrid)
// TUGAS UAS KELOMPOK 7
// Nama: Andhika Hisyam Muhammad Rafi (A11.2025.16251)
// Nama: Ayudhya Naja Adinda (A11.2025.16249)
#include <iostream>
#include <string>
using namespace std;

// KAMUS: 
struct Kamar {
    int nomor;      // Contoh: 101
    string tipe;    // Standard/Deluxe/Suite
    long harga;     // Harga per malam
    int status;     // 0 = Kosong, 1 = Terisi
    string namaTamu;// Nama pemesan
};

const int MAX_KAMAR = 40;      // Kapasitas Gudang (Maksimal)
Kamar hotel[MAX_KAMAR];         // Array Besar
int jumlahData = 5;             // Data aktif saat ini (Mulai dari 5 karena hardcode)
int pilihan;

// --- 2. PROTOTYPE FUNCTION & PROCEDURE ---
// [TUGAS BAYIK] - Mengisi 5 data awal (Hardcode)
void inisialisasiData(Kamar arr[]);

// [TUGAS BAYIK] - Fitur Input Manual (Nambah kamar baru)
// PENTING: Pakai int &jumlah (pass by reference) biar jumlah di main ikut berubah
void tambahKamar(Kamar arr[], int &jumlah, int maxKapasitas);

// [TUGAS BAYIK] - Sorting & Perhitungan
// Parameter 'ascending': true buat termurah, false buat termahal
void bubbleSortKamar(Kamar arr[], int jumlah, bool ascending);
long hitungTotalRekursif(long hargaPerMalam, int durasi);

// [TUGAS MAS] - Tampil & Proses Transaksi
void tampilkanDaftar(Kamar arr[], int jumlah);
// Menerima ALAMAT memori kamar (*ptrKamar) biar perubahan nempel permanen
void prosesBooking(Kamar *ptrKamar);
void prosesCheckOut(Kamar arr[], int jumlah);


// DISKRIPSI: 

// --- 3. MAIN PROGRAM ---
int main() {
    // 1. ISI DATA AWAL (Hardcode)
    inisialisasiData(hotel);

    // 2. LOOPING MENU UTAMA
    do {
        cout << "\n=== SISTEM HOTEL (Data: " << jumlahData << "/" << MAX_KAMAR << ") ===" << endl;
        cout << "1. Daftar Kamar (Sorting)" << endl;
        cout << "2. Check-In (Booking)" << endl;
        cout << "3. Check-Out (Bayar)" << endl;
        cout << "4. Tambah Kamar Baru" << endl; // <--- MENU BARU
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // [LOGIKA MAS]
                // 1. Tanya user: 1. Termurah (Ascending), 2. Termahal (Descending)
                // 2. if (pilih == 1) bubbleSortKamar(hotel, jumlahData, true);
                // 3. else bubbleSortKamar(hotel, jumlahData, false);
                // 4. tampilkanDaftar(hotel, jumlahData);
                break;

            case 2:
                // [LOGIKA MAS]
                // 1. Input nomor kamar dicari
                // 2. Searching Index (Looping cari hotel[i].nomor == input)
                // 3. Jika ketemu: prosesBooking(&hotel[index_ketemu]);
                break;

            case 3:
                // [LOGIKA MAS]
                // 1. Panggil prosesCheckOut(hotel, jumlahData);
                break;

            case 4:
                // [LOGIKA BAYIK - FITUR BARU]
                // Kirim alamat variable jumlahData biar bisa ditambah di dalam fungsi
                tambahKamar(hotel, jumlahData, MAX_KAMAR);
                break;

            case 5:
                cout << "Terima kasih!" << endl;
                break;

            default:
                cout << "Input salah!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}


// --- 4. DEFINISI FUNCTION (AREA KODING) ---

// [AREA KERJA BAYIK]
void inisialisasiData(Kamar arr[]) {
    // HARDCODE DATA (Index 0 sampai 4)
    // Format: {Nomor, Tipe, Harga, Status, Nama}
    
    
    cout << ">> Sistem siap! 5 Data kamar berhasil dimuat." << endl;
}

// [AREA KERJA BAYIK]
void tambahKamar(Kamar arr[], int &jumlah, int maxKapasitas) {
    // LOGIKA:
    // 1. Cek apakah (jumlah >= maxKapasitas)? Jika ya, cout "Penuh" & return.
    
    // 2. Input data ke dalam array index ke-[jumlah] (karena index mulai dari 0)
    //    Contoh: cin >> arr[jumlah].nomor;
    
    // 3. Set default: arr[jumlah].status = 0; arr[jumlah].namaTamu = "-";
    
    // 4. JANGAN LUPA: jumlah++; (Menambah counter data)
}

// [AREA KERJA BAYIK]
void bubbleSortKamar(Kamar arr[], int jumlah, bool ascending) {
    // LOGIKA SORTING:
    // Gunakan Nested Loop (boleh While dalam While, atau For dalam For)
    // Jika ascending = true, tukar jika (kiri.harga > kanan.harga)
    // Jika ascending = false, tukar jika (kiri.harga < kanan.harga)
}

// [AREA KERJA BAYIK]
long hitungTotalRekursif(long hargaPerMalam, int durasi) {
    // LOGIKA REKURSIF:
    // Base Case: Jika durasi == 1, return hargaPerMalam.
    // Recursive Case: return hargaPerMalam + hitungTotalRekursif(..., durasi-1);
    return 0; 
}

// [AREA KERJA MAS]
void tampilkanDaftar(Kamar arr[], int jumlah) {
    // LOGIKA:
    // Loop dari i = 0 sampai i < jumlah
    // Cout data kamar dalam bentuk tabel/list rapi
}

// [AREA KERJA MAS]
void prosesBooking(Kamar *ptrKamar) {
    // LOGIKA POINTER:
    // Akses pakai tanda panah (->)
    // if (ptrKamar->status == 0) -> Masih kosong
    //      Input nama, Ubah status jadi 1
    // Else -> "Maaf kamar penuh"
}

// [AREA KERJA MAS]
void prosesCheckOut(Kamar arr[], int jumlah) {
    // LOGIKA:
    // 1. Input Nomor Kamar
    // 2. Cari Kamarnya (Looping Search)
    // 3. Jika ketemu & Status == 1 (Ada tamu):
    //    - Input Durasi Menginap
    //    - Panggil: total = hitungTotalRekursif(hotel[i].harga, durasi);
    //    - Tampilkan Tagihan
    //    - Reset Kamar (Status=0, Nama="-")
}