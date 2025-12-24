// JUDUL: Sistem Reservasi Hotel (Versi Hybrid)
// TUGAS UAS KELOMPOK 7
// Nama: Andhika Hisyam Muhammad Rafi (A11.2025.16251)
// Nama: Ayudhya Naja Adinda (A11.2025.16249)
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// KAMUS: 
struct Kamar {
    int nomor;      // Contoh: 101
    string tipe;    // Standard/Deluxe/Suite
    long harga;     // Harga per malam
    int status;     // 0 = Kosong, 1 = Terisi
    string namaPemesan;// Nama pemesan
};

const int MAX_KAMAR = 40;      // Kapasitas Gudang (Maksimal)
Kamar hotel[MAX_KAMAR];         // Array Besar
int jumlahData = 5;             // Data aktif saat ini (Mulai dari 5 karena hardcode)
int pilihan;

// --- 2. PROTOTYPE FUNCTION & PROCEDURE ---
// [TUGAS BAYIK] - Mengisi 5 data awal (Hardcode)
void dataKamar(Kamar arr[]);

// [TUGAS BAYIK] - Fitur Input Manual (Nambah kamar baru)
// PENTING: Pakai int &jumlahData (pass by reference) biar jumlahData di main ikut berubah
void inputKamar(Kamar arr[], int &jumlahData, int maxKapasitas);

// [TUGAS BAYIK] - Sorting & Perhitungan
// Parameter 'ascending': true buat termurah, false buat termahal
void bubbleSortKamar(Kamar arr[], int jumlahData, bool ascending);
long hitungTotalRekursif(long hargaPerMalam, int durasi);

// [TUGAS MAS] - Tampil & Proses Transaksi
void tampilkanDaftar(Kamar arr[], int jumlahData);
// Menerima ALAMAT memori kamar (*ptrKamar) biar perubahan nempel permanen
void prosesBooking(Kamar *ptrKamar);
void prosesCheckOut(Kamar arr[], int jumlahData);


// DISKRIPSI: 

// --- 3. MAIN PROGRAM ---
int main() {
    // 1. ISI DATA AWAL (Hardcode)
    dataKamar(hotel);

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
            // 1. Tanya user: 1. Termurah (Ascending), 2. Termahal (Descending)
            // 2. if (pilih == 1) bubbleSortKamar(hotel, jumlahData, true);
            // 3. else bubbleSortKamar(hotel, jumlahData, false);
            // 4. tampilkanDaftar(hotel, jumlahData);
            // [LOGIKA MAS]
            cout << "\n--- Mau cari kamar yang ---" << endl;
            cout << "1. Termurah" << endl;
            cout << "2. Termahal" << endl;
            cin >> pilihan;
            if (pilihan == 1) {
                cout << "tes" << endl;
                //     bubbleSortKamar(hotel, jumlahData, true);
            } else {
                //    bubbleSortKamar(hotel, jumlahData, false);
                cout << "tes" << endl;

            }
            tampilkanDaftar(hotel, jumlahData);

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
                inputKamar(hotel, jumlahData, MAX_KAMAR);
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
long hargaKamar (string tipe) // Harga otomatis berdasarkan tipe kamar agar data konsisten
{
    if (tipe == "Standard" || tipe == "standard") {
        return 300000;
    } 
    else if (tipe == "Deluxe" || tipe == "deluxe") {
        return 500000;
    } 
    else if (tipe == "Suite" || tipe == "suite" ) {
        return 1000000;
    } 
    else {
        return 0; // Jika tipe salah ketik, harga 0
    }
}
// [AREA KERJA BAYIK]
void dataKamar(Kamar arr[]) {
    // HARDCODE DATA (Index 0 sampai 4)
    // Format: {Nomor, Tipe, Harga, Status, Nama}

    Kamar hotel[5] = {
        {101, "Standard", hargaKamar("Standard"), 0, "-"},
        {105, "Deluxe", hargaKamar("Deluxe"), 1, "Andhika"},
        {110, "Suite", hargaKamar("Suite"), 0, "-"},
        {115, "Standard", hargaKamar("Standard"), 1, "Ayudhya"},
        {120, "Deluxe", hargaKamar("Deluxe"), 0, "-"}
    };

    int jumlahData = 0;
    do {
        arr[jumlahData] = hotel[jumlahData];
        jumlahData++;
    } while (jumlahData < 5);
}

// [AREA KERJA BAYIK]
void inputKamar(Kamar arr[], int &jumlahData, int maxKapasitas) {
    // LOGIKA:
    // 1. Cek apakah (jumlahData >= maxKapasitas)? Jika ya, cout "Penuh" & return.
    
    // 2. Input data ke dalam array index ke-[jumlahData] (karena index mulai dari 0)
    //    Contoh: cin >> arr[jumlahData].nomor;
    
    // 3. Set default: arr[jumlahData].status = 0; arr[jumlahData].namaTamu = "-";
    
    // 4. JANGAN LUPA: jumlahData++; (Menambah counter data)
    if (jumlahData >= maxKapasitas) {
        cout << "Peringatan: Kapasitas penyimpanan penuh! Tidak bisa tambah data." << endl;
        return; 
    }

    cout << "\n--- Input Data Kamar Baru (Index ke-" << jumlahData << ") ---" << endl;

    cout << "Nomor Kamar                            : ";
    cin >> arr[jumlahData].nomor;

    cin.ignore(); 
    do {
        cout << "Tipe Kamar (Standard/Deluxe/Suite) : ";
        // Input string dengan spasi
        getline(cin, arr[jumlahData].tipe); 

        // Hitung harga otomatis
        arr[jumlahData].harga = hargaKamar(arr[jumlahData].tipe); 

        // Cek jika salah ketik (harga jadi 0)
        if (arr[jumlahData].harga == 0) {
            cout << ">> WARNING: Tipe salah/typo! Silakan ketik ulang.\n" << endl;
        }
    // Syarat mengulang: Jika harga masih 0, kembali ke atas (do)
    } while (arr[jumlahData].harga == 0);

    cout << "Harga per Malam                        : ";
    arr[jumlahData].harga = hargaKamar(arr[jumlahData].tipe); // Set Harga Otomatis

    if (arr[jumlahData].harga == 0) {
        cout << "WARNING: Tipe kamar salah ketik! Harga diset 0." << endl;
    } else {
        cout << arr[jumlahData].harga << endl;
    }

    int pilStatus;
    cout << "Status Kamar saat ini                  :" << endl;
    cout << "  1. Kosong" << endl;
    cout << "  2. Dipesan" << endl;
    cout << "Pilih (1 / 2): ";
    cin >> pilStatus;

    if (pilStatus == 1) {
        arr[jumlah].status = true;
    } else {
        arr[jumlah].status = false;
    }

    jumlahData++; // Menambah jumlahData data agar input berikutnya masuk ke index baru
    
    cout << "===== Sukses! Data kamar berhasil disimpan. =====" << endl;
}

// [AREA KERJA BAYIK]
void bubbleSortKamar(Kamar arr[], int jumlahData, bool ascending, int opsi) {
    // LOGIKA SORTING:
    // Gunakan Nested Loop (While dalam While)
    // Jika ascending = true, tukar jika (kiri.harga > kanan.harga)
    // Jika ascending = false, tukar jika (kiri.harga < kanan.harga)

    // Prosedur Sort
    // opsi 1 = Berdasarkan Harga
    // opsi 2 = Berdasarkan Nomor Kamar
    // for (int i = 0; i < jumlah - 1; i++) {
    //     for (int j = 0; j < jumlah - i - 1; j++) {
            
    //         bool tukar = false;
            
    //         // --- LOGIKA PEMBANDING ---
    //         long nilaiKiri, nilaiKanan;

            // --- LOGIKA PEMBANDING (Sama Persis) ---
            if (opsi == 1) { // Berdasarkan Harga
                nilaiKiri = arr[j].harga;
                nilaiKanan = arr[j+1].harga;
            } else { // Berdasarkan Nomor
                nilaiKiri = arr[j].nomor;
                nilaiKanan = arr[j+1].nomor;
            }

            if (ascending) {
                if (nilaiKiri > nilaiKanan) tukar = true;
            } else {
                if (nilaiKiri < nilaiKanan) tukar = true;
            }

            if (tukar) {
                Kamar temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }   
}

// [AREA KERJA BAYIK]
long hitungTotalRekursif(long hargaPerMalam, int durasi) {
    // LOGIKA REKURSIF:
    // Base Case: Jika durasi == 1, return hargaPerMalam.
    // Recursive Case: return hargaPerMalam + hitungTotalRekursif(..., durasi-1);
    return 0; 
}

// [AREA KERJA MAS]
void tampilkanDaftar(Kamar arr[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Belum ada data kamar." << endl;
        return;
    }

    cout << "\n--- Daftar Kamar Hotel ---" << endl;
    
    cout << left << setw(8)  << "No" 
        << setw(12) << "Tipe" 
        << setw(15) << "Harga" 
        << setw(12) << "Status" 
        << "Nama Pemesan" << endl;
    cout << string(65, '-') << endl; 
    int i = 0;
    do {
        cout << left << setw(8)  << arr[i].nomor 
            << setw(12) << arr[i].tipe 
            << setw(15) << arr[i].harga 
            << setw(12) << (arr[i].status == 1 ? "Dipesan" : "Kosong") 
            << arr[i].namaPemesan << endl;
        i++;
    } while (i < jumlahData);
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
void prosesCheckOut(Kamar arr[], int jumlahData) {
    // LOGIKA:
    // 1. Input Nomor Kamar
    // 2. Cari Kamarnya (Looping Search)
    // 3. Jika ketemu & Status == 1 (Ada tamu):
    //    - Input Durasi Menginap
    //    - Panggil: total = hitungTotalRekursif(hotel[i].harga, durasi);
    //    - Tampilkan Tagihan
    //    - Reset Kamar (Status=0, Nama="-")
}