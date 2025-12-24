#include <iostream>
#include <string>
using namespace std;

// --- 1. TYPE BENTUKAN (STRUCT & ADT) ---
struct Kamar {
    int nomor;      // Contoh: 101
    string tipe;    // Standard/Deluxe
    long harga;     // Harga per malam
    int status;     // 0 = Kosong, 1 = Terisi
    string namaTamu;// Nama pemesan
};

// --- 2. PROTOTYPE FUNCTION & PROCEDURE ---

// Utilitas: Mengisi data awal (Hardcode)
void inisialisasiData(Kamar arr[], int jumlah);

// Fitur 1: Menampilkan Data & Sorting
// Parameter 'ascending': true buat termurah, false buat termahal
void tampilkanDaftar(Kamar arr[], int jumlah);
void bubbleSortKamar(Kamar arr[], int jumlah, bool ascending); 

// Fitur 2: Check-In (PAKE POINTER)
// Menerima ALAMAT memori kamar (*ptrKamar) biar perubahan nempel permanen
void prosesBooking(Kamar *ptrKamar);

// Fitur 3: Check-Out & Hitung Biaya (REKURSIF)
// Mengembalikan nilai total harga (long)
long hitungTotalRekursif(long hargaPerMalam, int durasi);
void prosesCheckOut(Kamar arr[], int jumlah);


// --- 3. MAIN PROGRAM ---
int main() {
    // ARRAY 1 DIMENSI (ADT)
    const int JUMLAH_KAMAR = 5; // Kecil aja biar gampang ngetesnya
    Kamar hotel[JUMLAH_KAMAR]; 

    // Panggil Inisialisasi dulu sebelum masuk menu
    inisialisasiData(hotel, JUMLAH_KAMAR);

    int pilihan;
    
    // LOOPING MENU UTAMA (DO-WHILE)
    do {
        // TAMPILKAN MENU DISINI (Cout biasa)
        // 1. Daftar Kamar, 2. Check In, 3. Check Out, 4. Exit
        cout << "\n=== SISTEM HOTEL ===" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // LOGIKANYA:
                // 1. Tanya user mau sort Termurah (1) atau Termahal (2)
                // 2. Panggil bubbleSortKamar(...) sesuai pilihan
                // 3. Panggil tampilkanDaftar(...)
                break;

            case 2:
                // LOGIKANYA:
                // 1. User input nomor kamar yang mau dibooking
                // 2. Lakukan SEARCHING (Pakai WHILE) buat cari indexnya
                // 3. Kalau ketemu, panggil: prosesBooking( &hotel[i] ); 
                //    (Ingat pakai tanda '&' karena parameternya pointer)
                break;

            case 3:
                // LOGIKANYA:
                // 1. Panggil prosesCheckOut(hotel, JUMLAH_KAMAR);
                //    (Searching dan hitung rekursif lakukan di dalam sana)
                break;

            case 4:
                cout << "Terima kasih!" << endl;
                break;

            default:
                cout << "Input salah!" << endl;
        }

    } while (pilihan != 4); // Loop berhenti kalau pilih 4

    return 0;
}


// --- 4. DEFINISI FUNCTION (ISI LOGIKA DISINI) ---

void inisialisasiData(Kamar arr[], int jumlah) {
    // LOGIKA:
    // Isi arr[0] sampai arr[jumlah-1] secara manual
    // Contoh: arr[0].nomor = 101; arr[0].harga = 300000; arr[0].status = 0;
    // ... dst ...
}

void bubbleSortKamar(Kamar arr[], int jumlah, bool ascending) {
    // LOGIKA:
    // Gunakan NESTED WHILE (While di dalam While)
    // Cek 'ascending'. Jika true, tukar kalau kiri > kanan.
    // Jika false, tukar kalau kiri < kanan.
    // Hati-hati jangan pakai FOR loop sesuai request.
}

void tampilkanDaftar(Kamar arr[], int jumlah) {
    // LOGIKA:
    // Pakai WHILE loop untuk cout semua isi array satu per satu
}

void prosesBooking(Kamar *ptrKamar) {
    // LOGIKA POINTER:
    // Cek status pakai panah: if (ptrKamar->status == 0) { ... }
    // Kalau kosong:
    //    Input ptrKamar->namaTamu
    //    Ubah ptrKamar->status = 1
    // Kalau tidak kosong (else):
    //    Tampilkan pesan error "Kamar penuh"
}

long hitungTotalRekursif(long hargaPerMalam, int durasi) {
    // LOGIKA REKURSIF:
    // Base Case: Jika durasi == 1, return hargaPerMalam.
    // Recursive Case: return hargaPerMalam + hitungTotalRekursif(..., durasi-1);
    return 0; // (Hapus ini ganti kodemu)
}

void prosesCheckOut(Kamar arr[], int jumlah) {
    // LOGIKA KOMBINE:
    // 1. Input nomor kamar
    // 2. Search pakai WHILE
    // 3. Kalau ketemu & statusnya 1 (terisi):
    //    - Input berapa malam menginap
    //    - Panggil: long total = hitungTotalRekursif(...);
    //    - Tampilkan total bayar
    //    - RESET DATA: status = 0, namaTamu = "-"
    // 4. Kalau status 0, bilang "Kamar ini memang kosong!"
}