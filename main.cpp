#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ============================================================================
// KONSTANTA & DATA GLOBAL (Array & Variabel Dasar)
// Penanggung Jawab: Tim Laundream
// ============================================================================
const int JUMLAH_LAYANAN = 2;
const string NAMA_LAYANAN[JUMLAH_LAYANAN] = {"Reguler", "Ekspres"};
const int TARIF_LAYANAN[JUMLAH_LAYANAN] = {7000, 10000};

// ============================================================================
// MODUL 1: MENU UTAMA & NAVIGASI
// Penanggung Jawab: AHMAD RAIHAN KHOMEINI SAPUTRA (2604130073) - Ketua
// Deskripsi: Menampilkan header program, opsi menu, dan mengarahkan navigasi.
// ============================================================================
void tampilkanMenuUtama() {
    cout << "\n====================================\n";
    cout << "       LAUNDREAM - MENU UTAMA       \n";
    cout << "====================================\n";
    cout << "1. Transaksi Laundry\n";
    cout << "2. Lihat Tarif Layanan\n";
    cout << "3. Keluar\n";
    cout << "====================================\n";
    cout << "Pilih menu: ";
}

// ============================================================================
// MODUL 3A: KATALOG TARIF LAYANAN
// Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
// Deskripsi: Menampilkan informasi jenis layanan dan tarif dari Array.
// ============================================================================
void tampilkanDaftarTarif() {
    cout << "\n====================================\n";
    cout << "       DAFTAR TARIF LAYANAN         \n";
    cout << "====================================\n";
    for (int i = 0; i < JUMLAH_LAYANAN; i++) {
        cout << (i + 1) << ". Layanan " << NAMA_LAYANAN[i] 
             << " : Rp" << TARIF_LAYANAN[i] << " / kg\n";
    }
    cout << "------------------------------------\n";
    cout << "* Diskon 10% untuk cucian minimal 5 kg!\n";
    cout << "====================================\n";
}

// ============================================================================
// MODUL 2: INPUT DATA PELANGGAN & PILIHAN LAYANAN
// Penanggung Jawab: MUHAMMAD DIENAN AKBAR (2604130112)
// Deskripsi: Menerima input nama pelanggan, pilihan jenis layanan, dan berat.
// ============================================================================
void inputDataPelanggan(string &nama, int &pilihanLayanan, double &berat) {
    cout << "\n====================================\n";
    cout << "       LAUNDREAM - TRANSAKSI        \n";
    cout << "====================================\n";
    
    // Input Nama Pelanggan
    cout << "Masukkan nama pelanggan : ";
    getline(cin >> ws, nama);

    // Pilihan Layanan
    cout << "\nPilih jenis layanan:\n";
    for (int i = 0; i < JUMLAH_LAYANAN; i++) {
        cout << (i + 1) << ". " << NAMA_LAYANAN[i] << " - Rp" << TARIF_LAYANAN[i] << "/kg\n";
    }
    
    // Loop validasi pilihan layanan
    do {
        cout << "Pilih layanan (1-" << JUMLAH_LAYANAN << ") : ";
        if (!(cin >> pilihanLayanan) || pilihanLayanan < 1 || pilihanLayanan > JUMLAH_LAYANAN) {
            cout << "[!] Pilihan tidak valid. Silakan coba lagi.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihanLayanan = 0;
        }
    } while (pilihanLayanan < 1 || pilihanLayanan > JUMLAH_LAYANAN);

    // Input Berat Pakaian
    do {
        cout << "Masukkan berat pakaian (kg) : ";
        if (!(cin >> berat) || berat <= 0) {
            cout << "[!] Berat pakaian harus berupa angka positif. Silakan ulangi.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            berat = 0;
        }
    } while (berat <= 0);
}

// ============================================================================
// MODUL 3B: PERHITUNGAN BIAYA DASAR LAUNDRY
// Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
// Deskripsi: Menghitung biaya laundry sebelum diskon (berat * tarif).
// ============================================================================
double hitungBiayaLaundry(double berat, int tarifPerKg) {
    return berat * tarifPerKg;
}

// ============================================================================
// MODUL 4: LOGIKA DISKON & TOTAL PEMBAYARAN
// Penanggung Jawab: SALWA THALITA AZAHRA (2604130033)
// Deskripsi: Menerapkan percabangan if-else untuk menghitung potongan diskon 10%
//            dan menghitung total akhir yang harus dibayarkan.
// ============================================================================
double hitungDiskon(double berat, double biayaLaundry) {
    // Ketentuan: Diskon 10% jika berat pakaian >= 5 kg
    if (berat >= 5.0) {
        return biayaLaundry * 0.10;
    } else {
        return 0.0;
    }
}

double hitungTotalBayar(double biayaLaundry, double diskon) {
    return biayaLaundry - diskon;
}

// ============================================================================
// MODUL 5: TAMPILAN RINGKASAN TRANSAKSI (STRUK) & PERULANGAN
// Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
// Deskripsi: Menampilkan struk transaksi yang rapi dan mengelola konfirmasi ulang.
// ============================================================================
void tampilkanRingkasanTransaksi(const string &nama, const string &jenisLayanan, 
                                double berat, int tarif, double subtotal, 
                                double diskon, double total) {
    cout << "\n====================================\n";
    cout << "        RINGKASAN TRANSAKSI         \n";
    cout << "====================================\n";
    cout << left << setw(18) << "Nama pelanggan" << ": " << nama << "\n";
    cout << left << setw(18) << "Jenis layanan"  << ": " << jenisLayanan << "\n";
    cout << left << setw(18) << "Berat pakaian"  << ": " << berat << " kg\n";
    cout << left << setw(18) << "Tarif per kg"   << ": Rp" << tarif << "\n";
    cout << left << setw(18) << "Biaya laundry"  << ": Rp" << fixed << setprecision(0) << subtotal << "\n";
    cout << left << setw(18) << "Diskon"         << ": Rp" << diskon;
    if (diskon > 0) {
        cout << " (10%)";
    }
    cout << "\n";
    cout << "------------------------------------\n";
    cout << left << setw(18) << "Total bayar"    << ": Rp" << total << "\n";
    cout << "====================================\n";
}

bool konfirmasiKembali() {
    char pilihan;
    cout << "\nKembali ke menu utama? (y/n): ";
    cin >> pilihan;
    return (pilihan == 'y' || pilihan == 'Y');
}

// ============================================================================
// MODUL 6: INTEGRASI, QUALITY ASSURANCE & MAIN FUNCTION
// Penanggung Jawab: ATHAUFA KINDI WIRATAMA (2604130114) & AHMAD RAIHAN (Ketua)
// Deskripsi: Mengintegrasikan seluruh fungsi ke alur eksekusi utama program.
// ============================================================================
int main() {
    int pilihanMenu = 0;
    bool programBerjalan = true;

    cout << "==================================================\n";
    cout << "     SELAMAT DATANG DI APLIKASI LAUNDREAM         \n";
    cout << "  Sistem Penghitungan Biaya Laundry Berbasis C++  \n";
    cout << "==================================================\n";

    while (programBerjalan) {
        tampilkanMenuUtama();
        
        if (!(cin >> pilihanMenu)) {
            cout << "\n[!] Masukan tidak valid. Silakan masukkan angka menu!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (pilihanMenu) {
            case 1: {
                // Modul 2: Input Data
                string namaPelanggan;
                int pilihanLayanan = 0;
                double beratPakaian = 0.0;

                inputDataPelanggan(namaPelanggan, pilihanLayanan, beratPakaian);

                // Modul 3: Ambil tarif & hitung subtotal
                int indeksLayanan = pilihanLayanan - 1;
                string jenisLayananTerpilih = NAMA_LAYANAN[indeksLayanan];
                int tarifTerpilih = TARIF_LAYANAN[indeksLayanan];
                double subtotal = hitungBiayaLaundry(beratPakaian, tarifTerpilih);

                // Modul 4: Hitung diskon & total
                double diskon = hitungDiskon(beratPakaian, subtotal);
                double totalBayar = hitungTotalBayar(subtotal, diskon);

                // Modul 5: Tampilkan struk
                tampilkanRingkasanTransaksi(namaPelanggan, jenisLayananTerpilih, 
                                           beratPakaian, tarifTerpilih, 
                                           subtotal, diskon, totalBayar);

                // Konfirmasi kembali ke menu
                if (!konfirmasiKembali()) {
                    programBerjalan = false;
                    cout << "\nTerima kasih telah menggunakan aplikasi Laundream!\n";
                }
                break;
            }
            case 2: {
                // Modul 3A: Tampilkan Daftar Tarif
                tampilkanDaftarTarif();
                if (!konfirmasiKembali()) {
                    programBerjalan = false;
                    cout << "\nTerima kasih telah menggunakan aplikasi Laundream!\n";
                }
                break;
            }
            case 3: {
                // Keluar dari Program
                programBerjalan = false;
                cout << "\n==================================================\n";
                cout << " Terima kasih telah menggunakan aplikasi Laundream!\n";
                cout << "               Sampai jumpa kembali!              \n";
                cout << "==================================================\n";
                break;
            }
            default: {
                cout << "\n[!] Menu nomor " << pilihanMenu << " tidak tersedia. Silakan pilih 1 - 3.\n";
                break;
            }
        }
    }

    return 0;
}
