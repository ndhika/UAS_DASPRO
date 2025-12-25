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
struct Tanggal
{
    string hari;
    int tgl;
    int bulan;
    int tahun;
};
struct Reservasi
{
    Kamar kamar;
    Tanggal tanggalCheckIn;
    int lamaMenginap;
    long totalBiaya;
};

const int MAX_KAMAR = 40;      // Kapasitas Gudang (Maksimal)
Kamar hotel[MAX_KAMAR];         // Array Besar
int jumlahData = 5;             // Data aktif saat ini (Mulai dari 5 karena hardcode)
int pilihan;

// --- 2. PROTOTYPE FUNCTION & PROCEDURE ---
// [TUGAS BAYIK] - Mengisi 5 data awal (Hardcode)
void dataKamar(Kamar arr[]);

// [TUGAS BAYIK] - Fitur Input Manual (Nambah kamar baru)
// PENTING: Pakai int &jumlah (pass by reference) biar jumlah di main ikut berubah
void inputKamar(Kamar arr[], int &jumlah, int maxKapasitas);

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
    dataKamar(hotel);

    // 2. LOOPING MENU UTAMA
    do {
        cout << "\n=== SISTEM HOTEL (Data: " << jumlahData << "/" << MAX_KAMAR << ") ===" << endl;
        cout << "1. Daftar Kamar (Sorting)" << endl;
        cout << "2. Check-In (Reservasi)" << endl;
        cout << "3. Check-Out (Batalkan)" << endl;
        cout << "4. Tambah Kamar Baru" << endl;
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
                bubbleSortKamar(hotel, jumlahData, true);
            } else {
                bubbleSortKamar(hotel, jumlahData, false);
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

void inputKamar(Kamar arr[], int &jumlah, int maxKapasitas) {
    // LOGIKA:
    // 1. Cek apakah (jumlah >= maxKapasitas)? Jika ya, cout "Penuh" & return.
    
    // 2. Input data ke dalam array index ke-[jumlah] (karena index mulai dari 0)
    //    Contoh: cin >> arr[jumlah].nomor;
    
    // 3. Set default: arr[jumlah].status = 0; arr[jumlah].namaTamu = "-";
    
    // 4. JANGAN LUPA: jumlah++; (Menambah counter data)
    // 1. Cek Kapasitas Array
    if (jumlah >= maxKapasitas) {
        cout << ">> Peringatan: Kapasitas penyimpanan penuh! Tidak bisa tambah data." << endl;
        return; 
    }

    cout << "\n===== Input Data Kamar Baru (Index ke-" << jumlah << ") =====" << endl;

    // 2. Input Nomor Kamar
    cout << "Nomor Kamar : ";
    cin >> arr[jumlah].nomor;

    // 3. Input Tipe Kamar (Validasi dengan Loop)
    cin.ignore(); // Membersihkan buffer sebelum getline
    do {
        cout << "Tipe Kamar (Standard/Deluxe/Suite) : ";
        getline(cin, arr[jumlah].tipe); 

        // Hitung harga otomatis
        arr[jumlah].harga = hargaKamar(arr[jumlah].tipe); 

        // Validasi: Jika harga 0, berarti tipe salah ketik
        if (arr[jumlah].harga == 0) {
            cout << "WARNING: Tipe salah/typo! Silakan ketik ulang.\n";
        }
    
    // Ulangi terus selama harga masih 0
    } while (arr[jumlah].harga == 0);

    // 4. Tampilkan Harga (Hasil dari perhitungan di atas)
    cout << "Harga per Malam : Rp " << arr[jumlah].harga << endl;

    // 5. Set Status Otomatis (Default: Kosong)
    arr[jumlah].status = false; 
    arr[jumlah].namaPemesan = "-";
    cout << "Status : Kosong" << endl;

    // 6. Update Counter Data
    jumlah++; 
    
    cout << "\n===== Sukses! Data kamar berhasil disimpan. =====" << endl;
}

void bubbleSortKamar(Kamar arr[], int jumlah, bool ascending) {
    // LOGIKA SORTING:
    // Gunakan Nested Loop (While dalam While)
    // Jika ascending = true, tukar jika (kiri.harga > kanan.harga)
    // Jika ascending = false, tukar jika (kiri.harga < kanan.harga)

    int i = 0; 
    while (i < jumlah - 1) {
        int j = 0;
        while (j < jumlah - i - 1) {           
            bool tukar = false;
            // LANGSUNG AMBIL HARGA (Tanpa cek opsi)
            long indexpertama = arr[j].harga;
            long indexkedua = arr[j+1].harga;

            // Logika Ascending/Descending
            if (ascending) {
                // Termurah (Ascending)
                if (indexpertama > indexkedua) tukar = true;
            } else {
                // Termahal (Descending)
                if (indexpertama < indexkedua) tukar = true;
            }

            // Tukar Posisi
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

void tampilkanDaftar(Kamar arr[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data kamar." << endl;
        return;
    }

    cout << "\n--- Daftar Kamar Hotel ---" << endl;
    
    cout << left << setw(8)  << "No" 
        << setw(12) << "Tipe" 
        << setw(20) << "Harga per Malam" 
        << setw(12) << "Status" 
        << "Nama Pemesan" << endl;
    cout << string(65, '-') << endl; 
    int i = 0;
    do {
        cout << left << setw(8)  << arr[i].nomor 
            << setw(12) << arr[i].tipe 
            << setw(20) << arr[i].harga 
            << setw(12) << (arr[i].status == 1 ? "Dipesan" : "Kosong") 
            << arr[i].namaPemesan << endl;
        i++;
    } while (i < jumlah);
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