#include <iostream>
using namespace std;

struct kamar
{
    string tipeKamar;
    int nomorKamar;
    float hargaPerMalam;
    bool status; // true = kosong , false = dipesan
};
struct reservasi
{
    string namaPemesan;
    int nomorKamar;
    int lamaMenginap;
    int totalbiaya;
};
// struct hotel
// {
//     struct kamar;
//     struct reservasi;
// };

//ADT Kamar
// Prosedur untuk input data kamar ke dalam array
void inputDataKamar(kamar hotel[], int &jumlahKamarSekarang, int kapasitasMaksimal) {
    int jumlahInput;
    
    cout << "--- Fitur Input Data Kamar ---" << endl;
    cout << "Berapa banyak kamar yang ingin didaftarkan? ";
    cin >> jumlahInput;

    // IF-ELSE untuk validasi kapasitas array
    if (jumlahKamarSekarang + jumlahInput > kapasitasMaksimal) {
        cout << "Gagal! Kapasitas hotel tidak mencukupi." << endl;
    } else {
        // LOOPING untuk mengisi data ke dalam array
        for (int i = 0; i < jumlahInput; i++) {
            cout << endl << "Data Kamar ke-" << (jumlahKamarSekarang + 1) << endl;
            cout << "Nomor Kamar : ";
            cin >> hotel[jumlahKamarSekarang].nomorKamar;
            
            cout << "Tipe Kamar (Standard/Deluxe/Suite): ";
            cin.ignore(); 
            getline(cin, hotel[jumlahKamarSekarang].tipeKamar);
            
            cout << "Harga per Malam: ";
            cin >> hotel[jumlahKamarSekarang].hargaPerMalam;
            
            int pilihanStatus;
            cout << "Status Kamar saat ini:" << endl;
            cout << "  1. Kosong" << endl;
            cout << "  2. Dipesan" << endl;
            cout << "Pilih (1 / 2): ";
            cin >> pilihanStatus;

            // Menggunakan If-Else untuk menentukan bool
            if (pilihanStatus == 1) {
                hotel[jumlahKamarSekarang].status = true;
            } else {
                hotel[jumlahKamarSekarang].status = false;
            }
            
            jumlahKamarSekarang++; 
        }
        cout << endl << "Berhasil menambahkan " << jumlahInput << " kamar ke sistem." << endl;
    }
}

void tampilDataKamar(kamar kamar[], int jumlahKamar)
{

}

void sortingKamar(kamar kamar[], int jumlahKamar)
{

}

//ADT Reservasi
void reservasiKamar(kamar kamar[], int jumlahKamar, reservasi &data)
{

}

void checkoutKamar(kamar kamar[], int jumlahKamar)
{

}

int hitungTotalBiaya(int hargaPerMalam, int lamaMenginap)
{

}

//Menu Utama
void menuUtama()
{

}

int main()
{
    const int MAX_KAMAR = 50; // Kapasitas Array
    kamar daftarKamar[MAX_KAMAR];
    int jumlahKamar = 0; // Counter kamar yang sudah terinput

    // Memanggil prosedur input
    inputDataKamar(daftarKamar, jumlahKamar, MAX_KAMAR);
    return 0;
}
