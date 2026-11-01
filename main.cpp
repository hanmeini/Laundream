#include <iostream>
#include <string>

using namespace std;

int main() {
    // ========================================================================
    // BLOK 1: DEKLARASI ARRAY TARIF & RIWAYAT TRANSAKSI
    // Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
    // Konsep C++: Array 1 Dimensi & Variabel
    // ========================================================================
    const int JUMLAH_LAYANAN = 2;
    string namaLayanan[JUMLAH_LAYANAN] = {"Reguler", "Ekspres"};
    int tarifLayanan[JUMLAH_LAYANAN] = {7000, 10000};

    // Array untuk menyimpan riwayat transaksi harian (Kapasitas maks 50 transaksi)
    const int MAX_TRANSAKSI = 50;
    string riwayatNama[MAX_TRANSAKSI];
    string riwayatLayanan[MAX_TRANSAKSI];
    double riwayatBerat[MAX_TRANSAKSI];
    int riwayatTotal[MAX_TRANSAKSI];

    // Variabel akumulasi rekap
    int jumlahTransaksi = 0;
    int totalPendapatan = 0;
    double totalKgLaundry = 0.0;

    // Variabel umum navigasi
    int pilihanMenu = 0;
    char lanjutMenu = 'y';

    cout << "==================================================\n";
    cout << "     SELAMAT DATANG DI APLIKASI LAUNDREAM         \n";
    cout << "  Sistem Penghitungan Biaya Laundry Berbasis C++  \n";
    cout << "==================================================\n";

    // ========================================================================
    // BLOK 2: PERULANGAN PROGRAM UTAMA & MENU UTAMA
    // Penanggung Jawab: AHMAD RAIHAN KHOMEINI SAPUTRA (2604130073) - Ketua
    // Konsep C++: Perulangan do-while & Percabangan switch-case
    // ========================================================================
    do {
        cout << "\n====================================\n";
        cout << "       LAUNDREAM - MENU UTAMA       \n";
        cout << "====================================\n";
        cout << "1. Transaksi Laundry Baru\n";
        cout << "2. Rekap Laporan Penjualan\n";
        cout << "3. Lihat Tarif Layanan\n";
        cout << "4. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                // ============================================================
                // BLOK 3: INPUT DATA TRANSAKSI
                // Penanggung Jawab: MUHAMMAD DIENAN AKBAR (2604130112)
                // Konsep C++: Input/Output (cin, getline)
                // ============================================================
                string namaPelanggan;
                int pilihanLayanan = 0;
                double beratPakaian = 0.0;

                cout << "\n====================================\n";
                cout << "       LAUNDREAM - TRANSAKSI        \n";
                cout << "====================================\n";

                // Input Nama
                cout << "Masukkan nama pelanggan : ";
                cin.ignore();
                getline(cin, namaPelanggan);

                // Input Layanan
                cout << "\nPilih jenis layanan:\n";
                for (int i = 0; i < JUMLAH_LAYANAN; i++) {
                    cout << (i + 1) << ". " << namaLayanan[i] 
                         << " - Rp" << tarifLayanan[i] << "/kg\n";
                }
                cout << "Pilih layanan (1-2) : ";
                cin >> pilihanLayanan;

                // Validasi pilihan layanan sederhana
                while (pilihanLayanan < 1 || pilihanLayanan > JUMLAH_LAYANAN) {
                    cout << "[!] Pilihan salah. Masukkan nomor layanan (1-2): ";
                    cin >> pilihanLayanan;
                }

                // Input Berat
                cout << "Masukkan berat pakaian (kg) : ";
                cin >> beratPakaian;

                while (beratPakaian <= 0) {
                    cout << "[!] Berat tidak valid. Masukkan berat positif (kg): ";
                    cin >> beratPakaian;
                }

                // ============================================================
                // BLOK 4: PERHITUNGAN BIAYA & LOGIKA DISKON
                // Penanggung Jawab: SALWA THALITA AZAHRA (2604130033)
                // Konsep C++: Operator Aritmatika & Percabangan if-else
                // ============================================================
                int indeksLayanan = pilihanLayanan - 1;
                string jenisTerpilih = namaLayanan[indeksLayanan];
                int tarifPerKg = tarifLayanan[indeksLayanan];

                // Hitung biaya laundry
                double subtotal = beratPakaian * tarifPerKg;
                double diskon = 0.0;

                // Ketentuan: diskon 10% jika berat >= 5 kg
                if (beratPakaian >= 5.0) {
                    diskon = subtotal * 0.10;
                } else {
                    diskon = 0.0;
                }

                double totalBayar = subtotal - diskon;

                // Simpan transaksi ke Array Riwayat (Jika belum penuh)
                if (jumlahTransaksi < MAX_TRANSAKSI) {
                    riwayatNama[jumlahTransaksi] = namaPelanggan;
                    riwayatLayanan[jumlahTransaksi] = jenisTerpilih;
                    riwayatBerat[jumlahTransaksi] = beratPakaian;
                    riwayatTotal[jumlahTransaksi] = totalBayar;

                    jumlahTransaksi++;
                    totalPendapatan = totalPendapatan + totalBayar;
                    totalKgLaundry = totalKgLaundry + beratPakaian;
                }

                // ============================================================
                // BLOK 5: STRUK TRANSAKSI & KONFIRMASI KEMBALI
                // Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
                // Konsep C++: Manipulasi Output & Tampilan Struk Rapi
                // ============================================================
                cout << "\n====================================\n";
                cout << "        RINGKASAN TRANSAKSI         \n";
                cout << "====================================\n";
                cout << "Nama pelanggan : " << namaPelanggan << "\n";
                cout << "Jenis layanan  : " << jenisTerpilih << "\n";
                cout << "Berat pakaian  : " << beratPakaian << " kg\n";
                cout << "Tarif per kg   : Rp" << tarifPerKg << "\n";
                cout << "Biaya laundry  : Rp" << (int)subtotal << "\n";
                cout << "Diskon         : Rp" << (int)diskon;
                if (diskon > 0) {
                    cout << " (10%)";
                }
                cout << "\n";
                cout << "------------------------------------\n";
                cout << "Total bayar    : Rp" << (int)totalBayar << "\n";
                cout << "====================================\n";

                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 2: {
                // ============================================================
                // BLOK 6A: REKAP LAPORAN PENJUALAN KASIR
                // Penanggung Jawab: ATHAUFA KINDI WIRATAMA (2604130114)
                // Konsep C++: Pembacaan Array dengan Perulangan for
                // ============================================================
                cout << "\n======================================================\n";
                cout << "             REKAP LAPORAN PENJUALAN LAUNDRY          \n";
                cout << "======================================================\n";

                if (jumlahTransaksi == 0) {
                    cout << "Belum ada transaksi yang tercatat hari ini.\n";
                } else {
                    cout << "No. | Nama Pelanggan   | Layanan  | Berat  | Total Bayar\n";
                    cout << "------------------------------------------------------\n";
                    for (int i = 0; i < jumlahTransaksi; i++) {
                        cout << (i + 1) << "   | " 
                             << riwayatNama[i] << "\t\t| " 
                             << riwayatLayanan[i] << "\t | " 
                             << riwayatBerat[i] << " kg | Rp" 
                             << riwayatTotal[i] << "\n";
                    }
                    cout << "------------------------------------------------------\n";
                    cout << "Total Transaksi   : " << jumlahTransaksi << " transaksi\n";
                    cout << "Total Berat Cucian: " << totalKgLaundry << " kg\n";
                    cout << "Total Pemasukan   : Rp" << totalPendapatan << "\n";
                }
                cout << "======================================================\n";

                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 3: {
                // ============================================================
                // BLOK 6B: TAMPILAN TARIF LAYANAN
                // Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
                // Konsep C++: Perulangan for & Array
                // ============================================================
                cout << "\n====================================\n";
                cout << "       DAFTAR TARIF LAYANAN         \n";
                cout << "====================================\n";
                for (int i = 0; i < JUMLAH_LAYANAN; i++) {
                    cout << (i + 1) << ". Layanan " << namaLayanan[i] 
                         << " : Rp" << tarifLayanan[i] << " / kg\n";
                }
                cout << "------------------------------------\n";
                cout << "* Diskon 10% untuk cucian minimal 5 kg!\n";
                cout << "====================================\n";

                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 4: {
                cout << "\n==================================================\n";
                cout << " Terima kasih telah menggunakan aplikasi Laundream!\n";
                cout << "               Sampai jumpa kembali!              \n";
                cout << "==================================================\n";
                lanjutMenu = 'n';
                break;
            }

            default: {
                cout << "\n[!] Menu tidak valid. Silakan pilih nomor 1 sampai 4.\n";
                cout << "Tekan tombol apa saja lalu enter untuk kembali...";
                char sembarang;
                cin >> sembarang;
                lanjutMenu = 'y';
                break;
            }
        }

    } while (lanjutMenu == 'y' || lanjutMenu == 'Y');

    return 0;
}
