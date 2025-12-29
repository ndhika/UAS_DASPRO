// JUDUL: Sistem Reservasi Hotel 
// TUGAS UAS KELOMPOK 7
// Nama: Andhika Hisyam Muhammad Rafi (A11.2025.16251)
// Nama: Ayudhya Naja Adinda (A11.2025.16249)
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// KAMUS: 

struct Kamar {
    int nomor;      
    string tipe;    // Standard/Deluxe/Suite
    long harga;     
    int status;     
    string namaPemesan;
};
struct Tanggal
{
    string hari;
    int tgl;
    string bulan;
    int tahun;
};
struct Reservasi
{
    Kamar kamar;
    Tanggal tanggalCheckIn;
    int lamaMenginap;
    long totalBiaya;
};

const int MAX_KAMAR = 40;      // Kapasitas kamar (Maksimal)
Kamar hotel[MAX_KAMAR];         // Array of Struct
int jumlahData = 5;             
int pilihan;

void dataKamar(Kamar arr[]);
void inputKamar(Kamar arr[], int &jumlah, int maxKapasitas);
void bubbleSortKamar(Kamar arr[], int jumlah, bool ascending);
long hitungTotalRekursif(long hargaPerMalam, int durasi);
void tampilkanDaftar(Kamar arr[], int jumlah);
void prosesBooking(Kamar *ptrKamar);
void prosesCheckOut(Kamar arr[], int jumlah);

// DISKRIPSI: 

// ------------------------------------------------------------
// JUDUL     : main
// KAMUS     : pilihan (global), hotel (global)
// DISKRIPSI : Program utama yang berisi menu navigasi (Switch-Case)
//             untuk mengatur alur program (CRUD & Transaksi).
// ------------------------------------------------------------
int main() {
    dataKamar(hotel);

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
                {   
                    int nomorCari;
                    bool ketemu = false;

                    cout << "\n--- RESERVASI KAMAR ---" << endl;
                    cout << "Masukkan Nomor Kamar yang dicari: ";
                    cin >> nomorCari;

                    int i = 0;
                    do{
                        if (hotel[i].nomor == nomorCari)
                        {
                            ketemu = true;
                            prosesBooking(&hotel[i]);
                            break;
                        }
                        i++;
                    } while (i < jumlahData);

                    if (!ketemu) {
                        cout << ">> Error: Nomor kamar " << nomorCari << " tidak ditemukan." << endl;
                    }
                }  
            break;
            case 3:
                prosesCheckOut(hotel, jumlahData);
                break;
            case 4:
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

// ------------------------------------------------------------
// JUDUL     : hargaKamar
// KAMUS     : tipe (string)
// DISKRIPSI : Mengembalikan nilai harga (long) berdasarkan 
//             string tipe kamar yang diinputkan.
// ------------------------------------------------------------
long hargaKamar (string tipe) 
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
        return 0; 
    }
}

// ------------------------------------------------------------
// JUDUL     : dataKamar
// KAMUS     : arr[] (parameter output), dataDummy (lokal array), i
// DISKRIPSI : Mengisi array utama dengan 5 data dummy awal
//             agar program tidak kosong saat dijalankan.
// ------------------------------------------------------------
void dataKamar(Kamar arr[]) {
    // Format: {Nomor, Tipe, Harga, Status, Nama}
    Kamar dataDummy[5] = {
        {101, "Standard", hargaKamar("Standard"), 0, "-"},
        {105, "Deluxe", hargaKamar("Deluxe"), 0, "-"},
        {110, "Suite", hargaKamar("Suite"), 0, "-"},
        {115, "Standard", hargaKamar("Standard"), 0, "-"},
        {120, "Deluxe", hargaKamar("Deluxe"), 0, "-"}
    };

    int jumlahData = 0;
    do {
        arr[jumlahData] = dataDummy[jumlahData];
        jumlahData++;
    } while (jumlahData < 5);
}

// ------------------------------------------------------------
// JUDUL     : inputKamar
// KAMUS     : arr[], jumlah (pass by ref), maxKapasitas, i
// DISKRIPSI : Menambah data kamar baru ke dalam array. 
//             Melakukan validasi kapasitas penuh & nomor unik.
// ------------------------------------------------------------
void inputKamar(Kamar arr[], int &jumlah, int maxKapasitas) {
    if (jumlah >= maxKapasitas) {
        cout << ">> Peringatan: Kapasitas penyimpanan penuh! Tidak bisa tambah data." << endl;
        return; 
    }

    cout << "\n===== Input Data Kamar Baru (Index ke-" << jumlah << ") =====" << endl;
    cout << "Nomor Kamar : ";
    cin >> arr[jumlah].nomor;
    int i = 0;
    while (i < jumlah) {
        if (arr[i].nomor == arr[jumlah].nomor) {
            cout << ">> Peringatan: Nomor kamar sudah ada! Tidak bisa tambah data." << endl;
            return;
        }
        i++;
    }
    cin.ignore();
    do {
        cout << "Tipe Kamar (Standard/Deluxe/Suite) : ";
        getline(cin, arr[jumlah].tipe); 
        arr[jumlah].harga = hargaKamar(arr[jumlah].tipe); 

        if (arr[jumlah].harga == 0) {
            cout << "WARNING: Tipe salah/typo! Silakan ketik ulang.\n";
        }
    } while (arr[jumlah].harga == 0);

    cout << "Harga per Malam : Rp " << arr[jumlah].harga << endl;
    arr[jumlah].status = false; 
    arr[jumlah].namaPemesan = "-";
    cout << "Status : Kosong" << endl;
    jumlah++; 
    cout << "\n===== Sukses! Data kamar berhasil disimpan. =====" << endl;
}

// ------------------------------------------------------------
// JUDUL     : bubbleSortKamar
// KAMUS     : arr[], jumlah, ascending, i, j, tukar, temp
// DISKRIPSI : Mengurutkan array kamar berdasarkan harga.
//             Bisa Ascending (Murah->Mahal) atau Descending (Mahal->Murah).
// ------------------------------------------------------------
void bubbleSortKamar(Kamar arr[], int jumlah, bool ascending) {
    int i = 0; 
    while (i < jumlah - 1) {
        int j = 0;
        while (j < jumlah - i - 1) {           
            bool tukar = false;
            long indexpertama = arr[j].harga;
            long indexkedua = arr[j+1].harga;

            if (ascending) {
                if (indexpertama > indexkedua) tukar = true;
            } else {
                if (indexpertama < indexkedua) tukar = true;
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

// ------------------------------------------------------------
// JUDUL     : tampilkanDaftar
// KAMUS     : arr[], jumlah, i
// DISKRIPSI : Menampilkan tabel seluruh data kamar.
// ------------------------------------------------------------
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

// ------------------------------------------------------------
// JUDUL     : prosesBooking
// KAMUS     : ptrKamar (pointer), nota (struct lokal)
// DISKRIPSI : Mengubah status kamar menjadi dipesan (1),
//             mengisi data pemesan, dan menampilkan struk.
// ------------------------------------------------------------
void prosesBooking(Kamar *ptrKamar) {
    if (ptrKamar->status == 0) {
        Reservasi nota;
        cout << "\n>> STATUS: TERSEDIA. Silakan isi data reservasi.\n";
        cout << "   Nama Pemesan : ";
        cin.ignore();
        getline(cin, ptrKamar->namaPemesan);
        cout << "   Hari Check-in   : "; cin >> nota.tanggalCheckIn.hari;
        cout << "   Tanggal         : "; cin >> nota.tanggalCheckIn.tgl;
        cout << "   Bulan           : "; cin >> nota.tanggalCheckIn.bulan;
        cout << "   Tahun           : "; cin >> nota.tanggalCheckIn.tahun;
        cout << "   Lama Menginap   : "; 
        cin >> nota.lamaMenginap;
        
        nota.kamar = *ptrKamar; 
        nota.totalBiaya = hitungTotalRekursif(ptrKamar->harga, nota.lamaMenginap);
        ptrKamar->status = 1; 

        // --- STRUK ---
        cout << "\n================ STRUK CHECK-IN ================" << endl;
        cout << "Kamar      : " << nota.kamar.nomor << " (" << nota.kamar.tipe << ")" << endl;
        cout << "Pemesan    : " << ptrKamar->namaPemesan << endl;
        cout << "Check-in   : " << nota.tanggalCheckIn.hari << ", " 
            << nota.tanggalCheckIn.tgl << "/" << nota.tanggalCheckIn.bulan << "/" << nota.tanggalCheckIn.tahun << endl;
        cout << "Durasi     : " << nota.lamaMenginap << " Malam" << endl;
        cout << "TOTAL      : Rp " << nota.totalBiaya << endl;
        cout << "===================================================" << endl;
        cout << "\nTerimakasih sudah mereservasi di hotel kami!" << endl;
    } else {
        cout << "\n>> MAAF! Kamar " << ptrKamar->nomor << " sedang terisi oleh seseorang." << endl;
    }
}

// ------------------------------------------------------------
// JUDUL     : hitungTotalRekursif
// KAMUS     : hargaPerMalam, durasi
// DISKRIPSI : Fungsi REKURSIF untuk menghitung total biaya.
//             (Base case: durasi <= 1)
// ------------------------------------------------------------
long hitungTotalRekursif(long hargaPerMalam, int durasi) {
    if (durasi <= 1) return hargaPerMalam; 
    return hargaPerMalam + hitungTotalRekursif(hargaPerMalam, durasi - 1);
}

// ------------------------------------------------------------
// JUDUL     : prosesCheckOut
// KAMUS     : arr[], jumlah, nomorCari, ketemu, i
// DISKRIPSI : Mencari kamar yang dipesan, menghitung tagihan
//             akhir, dan mereset status kamar menjadi kosong.
// ------------------------------------------------------------
void prosesCheckOut(Kamar arr[], int jumlah) {
    int nomorCari;
    bool ketemu = false;
    int i = 0; 

    cout << "\n--- FORM CHECK-OUT & PEMBAYARAN ---" << endl;
    cout << "Masukkan Nomor Kamar : ";
    cin >> nomorCari;

    if (jumlah > 0) { 
        do {
            if (arr[i].nomor == nomorCari) {
                ketemu = true;
                break; 
            }
            i++; 
            
        } while (i < jumlah);
    }

    if (!ketemu) {
        cout << ">> ERROR: Nomor kamar " << nomorCari << " tidak ditemukan!" << endl;
        return; 
    }
    
    if (arr[i].status == 1) {
        
        int durasiRealisasi;
        long totalFinal;
        cout << ">> DATA PEMESAN DITEMUKAN : " << arr[i].namaPemesan << endl;
        cout << "   Lama Menginap : ";
        cin >> durasiRealisasi;
        totalFinal = hitungTotalRekursif(arr[i].harga, durasiRealisasi);

        cout << "\n================ STRUK CHECK-OUT ================" << endl;
        cout << "TOTAL BAYAR : Rp " << totalFinal << endl;
        cout << "===================================================" << endl;
        arr[i].status = 0;          
        arr[i].namaPemesan = "-";   
        cout << "\n>> Check-out BERHASIL! Kamar " << arr[i].nomor << " kini statusnya KOSONG." << endl;
    } else {
        cout << ">> ERROR: Kamar " << arr[i].nomor << " statusnya sudah KOSONG." << endl;
    }
}