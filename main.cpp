#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
================================================================================
                       PROJECT AKHIR DASAR PEMROGRAMAN
         LAUNDREAM: SISTEM KASIR & REKAPITULASI BIAYA LAUNDRY
                    FAKULTAS MIPA - UNIVERSITAS NEGERI SEMARANG
================================================================================
Petunjuk Teknis untuk Seluruh Anggota Kelompok:
1. Program dirancang MODULAR berbasis Function (Fungsi) dan Vector C++ STL
   sesuai materi kuliah Pertemuan 11 (Vector) & Fungsi.
2. Setiap anggota bertanggung jawab mengimplementasikan fungsinya masing-masing
   pada blok komentar // TODO yang telah disediakan.
3. Jangan mengubah nama fungsi, tipe data return, atau parameter agar kode tim
   dapat terhubung dan berjalan dengan lancar saat digabungkan.
================================================================================
*/


// ============================================================================
// 1. MODUL KATALOG & DAFTAR HARGA
// Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
// Konsep C++      : Vector 1D, Looping Traversal, void Function
// ============================================================================
// TODO [Aulia]:
// 1. Buat perulangan for dari i = 0 sampai layanan.size() untuk mencetak
//    nama paket layanan dan tarifnya per kg.
// 2. Buat perulangan for kedua untuk menampilkan daftar parfum dan tarif tambahannya.
// 3. Tampilkan catatan promo diskon 10% untuk berat minimal 5 kg.
void tampilkanKatalogTarif(const vector<string> &layanan, 
                           const vector<int> &tarif, 
                           const vector<string> &parfum, 
                           const vector<int> &tarifParfum) {
    cout << "\n========================================================\n";
    cout << "            DAFTAR TARIF & KATALOG LAUNDRY              \n";
    cout << "========================================================\n";

    // --- [TULIS KODE FUNGSI AULIA DI BAWAH INI] ---
    cout << "\nDAFTAR PAKET LAYANAN:\n";
    cout << "---------------------\n";

    for (size_t i = 0; i < layanan.size(); ++i) {
        cout << i + 1 << ". " << layanan[i] << " - Rp" << tarif[i] << "/kg\n";
    }

    cout << "\nDAFTAR PARFUM:\n";
    cout << "----------------\n";

    for (size_t i = 0; i < parfum.size(); ++i) {
        cout << i + 1 << ". " << parfum[i] << " - Rp" << tarifParfum[i] << "/kg\n";
    }

    cout << "\nCATATAN PROMO:\n";
    cout << "----------------\n";
    cout << "Diskon 10% untuk berat cucian minimal 5 kg.\n";
    // --- [SELESAI FUNGSI AULIA] ---

    cout << "========================================================\n";
}


// ============================================================================
// 2. MODUL INPUT DATA TRANSAKSI
// Penanggung Jawab: MUHAMMAD DIENAN AKBAR (2604130112)
// Konsep C++      : Parameter Reference (&), I/O Stream (getline, cin)
// ============================================================================
// TODO [Dienan]:
// 1. Minta input nama pelanggan menggunakan cin.ignore() dan getline(cin, nama).
// 2. Tampilkan pilihan paket layanan (1 sampai layanan.size()) dan minta input pilihLayanan.
//    Lengkapi validasi while agar pilihan tidak di luar jangkauan 1 - layanan.size().
// 3. Tampilkan pilihan parfum (1 sampai parfum.size()) dan minta input pilihParfum.
// 4. Minta input berat pakaian (kg) dengan validasi while agar berat > 0.
void inputDataTransaksi(string &nama, int &pilihLayanan, int &pilihParfum, double &berat,
                        const vector<string> &layanan, const vector<int> &tarif,
                        const vector<string> &parfum) {
    cout << "\n========================================================\n";
    cout << "                TRANSAKSI LAUNDRY BARU                  \n";
    cout << "========================================================\n";

    // --- [TULIS KODE FUNGSI DIENAN DI BAWAH INI] ---
    cout << "[KOSONG] TODO: Implementasikan input nama, layanan, dan berat oleh Dienan.\n";
    nama = "Contoh Pelanggan";
    pilihLayanan = 1;
    pilihParfum = 1;
    berat = 1.0;
    (void)layanan; (void)tarif; (void)parfum;
    // --- [SELESAI FUNGSI DIENAN] ---
}


// ============================================================================
// 3. MODUL PERHITUNGAN BIAYA, DISKON, DAN KASIR
// Penanggung Jawab: SALWA THALITA AZAHRA (2604130033)
// Konsep C++      : Function Return Value, Percabangan if-else & Operator Aritmatika
// ============================================================================ 
// Bagian A: Diskon 10% jika berat >= 5.0 kg, selain itu 0.0
double hitungDiskon(double berat, double subtotal) {
    if (berat >= 5.0) {
        return subtotal * 0.10;
    }
    return 0.0;
}

int bacaUang() {
    int nilai;
    while (!(cin >> nilai) || nilai < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[!] Input tidak valid. Masukkan angka : Rp ";
    }
    return nilai;
}

int prosesPembayaranKasir(int totalBayar, int &uangBayar, int &kembalian) {
    cout << "\nTotal Tagihan : Rp " << totalBayar << endl;
    cout << "Uang Bayar    : Rp ";
    uangBayar = bacaUang();

    while (uangBayar < totalBayar) {
        cout << "[!] Uang kurang Rp " << (totalBayar - uangBayar) << endl;
        cout << "Masukkan ulang uang bayar : Rp ";
        uangBayar = bacaUang();
    }

    kembalian = uangBayar - totalBayar;
    return kembalian;
}


// ============================================================================
// 4A. MODUL CETAK STRUK KASIR
// Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
// Konsep C++      : Function void, Manipulasi Output Terminal
// ============================================================================
// TODO [Fakhry - Bagian A]:
// Desain tampilan struk kasir resmi yang rapi dengan pembatas '=' dan '-'.
// Tampilkan Nama, Layanan, Parfum, Berat, Tarif/kg, Subtotal, Diskon,
// Total Bayar, Uang Diterima, dan Uang Kembalian.
void cetakStrukKasir(const string &nama, const string &layanan, const string &parfum,
                     double berat, int tarifPerKg, double subtotal, double diskon,
                     int totalBayar, int uangBayar, int kembalian) {
    cout << "\n========================================================\n";
    cout << "             STRUK RESMI TRANSAKSI LAUNDREAM            \n";
    cout << "========================================================\n";

    // --- [TULIS KODE DESAIN STRUK DI SINI] ---
    cout << "[KOSONG] TODO: Desain tampilan struk kasir oleh Fakhry.\n";
    (void)nama; (void)layanan; (void)parfum; (void)berat; (void)tarifPerKg;
    (void)subtotal; (void)diskon; (void)totalBayar; (void)uangBayar; (void)kembalian;
    // --- [SELESAI STRUK] ---

    cout << "========================================================\n";
}


// ============================================================================
// 4B. MODUL PENCARIAN TRANSAKSI (MENGGUNAKAN find() & distance() DARI <algorithm>)
// Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
// Konsep C++      : STL Algorithm find(), Iterator, dan distance() (Slide 7 Vector)
// ============================================================================
// TODO [Fakhry - Bagian B]:
// 1. Periksa apakah riwayatNama.empty() (Slide 5 Vector). Jika iya, beri pesan kosong.
// 2. Minta input nama yang dicari (cariNama) menggunakan getline.
// 3. Terapkan fungsi find():
//    auto it = find(riwayatNama.begin(), riwayatNama.end(), cariNama);
// 4. Periksa if (it != riwayatNama.end()):
//    - Ambil indeksnya: int idx = distance(riwayatNama.begin(), it);
//    - Cetak rincian cucian pada indeks [idx] tersebut.
// 5. Jika tidak cocok (else), tampilkan pesan bahwa pelanggan tidak ditemukan.
void cariTransaksiPelanggan(const vector<string> &riwayatNama,
                            const vector<string> &riwayatLayanan,
                            const vector<string> &riwayatParfum,
                            const vector<double> &riwayatBerat,
                            const vector<int> &riwayatTotalBayar,
                            const vector<int> &riwayatUangBayar,
                            const vector<int> &riwayatKembalian) {
    cout << "\n========================================================\n";
    cout << "          PENCARIAN RIWAYAT TRANSAKSI PELANGGAN         \n";
    cout << "========================================================\n";

    // --- [TULIS KODE PENCARIAN DENGAN find() DI SINI] ---
    cout << "[KOSONG] TODO: Implementasikan pencarian dengan find() oleh Fakhry.\n";
    (void)riwayatNama; (void)riwayatLayanan; (void)riwayatParfum; (void)riwayatBerat;
    (void)riwayatTotalBayar; (void)riwayatUangBayar; (void)riwayatKembalian;
    // --- [SELESAI PENCARIAN] ---
}


// ============================================================================
// 5. MODUL REKAPITULASI PENJUALAN & STATISTIK KASIR
// Penanggung Jawab: ATHAUFA KINDI WIRATAMA (2604130114)
// Konsep C++      : Vector .empty(), .size(), Traversal & Algoritma Nilai Maksimum
// ============================================================================
// TODO [Athaufa]:
// 1. Cek if (riwayatNama.empty()), jika kosong tampilkan pesan belum ada data.
// 2. Jika ada data:
//    - Gunakan loop for (size_t i = 0; i < riwayatNama.size(); i++) untuk
//      mencetak tabel seluruh transaksi.
//    - Tampilkan ringkasan: Total Transaksi, Total Berat (kg), Rata-rata Berat,
//      dan Total Omzet Uang Masuk.
// 3. Algoritma Nilai Maksimum (Mencari Transaksi Terbesar):
//    - Inisialisasi: int bayarTerbesar = riwayatTotalBayar[0]; size_t idxTerbesar = 0;
//    - Gunakan loop for dari 1 sampai riwayatTotalBayar.size():
//      if (riwayatTotalBayar[i] > bayarTerbesar) { bayarTerbesar = riwayatTotalBayar[i]; idxTerbesar = i; }
//    - Tampilkan nama pelanggan dan nominal transaksi terbesar tersebut.
void tampilkanRekapPenjualan(const vector<string> &riwayatNama,
                             const vector<string> &riwayatLayanan,
                             const vector<string> &riwayatParfum,
                             const vector<double> &riwayatBerat,
                             const vector<int> &riwayatTotalBayar,
                             int totalOmzet, double totalKg) {
    cout << "\n======================================================================\n";
    cout << "               REKAP LAPORAN PENJUALAN LAUNDREAM                      \n";
    cout << "======================================================================\n";

    // --- [TULIS KODE REKAP LAPORAN & NILAI MAKSIMUM DI SINI] ---
    cout << "[KOSONG] TODO: Implementasikan rekap penjualan & nilai maksimum oleh Athaufa.\n";
    (void)riwayatNama; (void)riwayatLayanan; (void)riwayatParfum; (void)riwayatBerat;
    (void)riwayatTotalBayar; (void)totalOmzet; (void)totalKg;
    // --- [SELESAI REKAP] ---

    cout << "======================================================================\n";
}


// ============================================================================
// 6. MODUL MENU UTAMA & INTEGRASI PROGRAM
// Penanggung Jawab: AHMAD RAIHAN KHOMEINI SAPUTRA (2604130073) - Ketua
// Konsep C++      : void Function, do-while Loop, switch-case & Pemanggilan Fungsi
// ============================================================================
void tampilkanMenuUtama() {
    cout << "\n========================================================\n";
    cout << "                 LAUNDREAM - MENU UTAMA                 \n";
    cout << "========================================================\n";
    cout << "1. Transaksi Laundry Baru (Kasir & Kembalian)\n";
    cout << "2. Cari Riwayat Transaksi Pelanggan (find() Vector)\n";
    cout << "3. Rekap Laporan Penjualan & Statistik Kasir\n";
    cout << "4. Lihat Daftar Tarif & Layanan\n";
    cout << "5. Keluar\n";
    cout << "========================================================\n";
    cout << "Pilih menu (1-5): ";
}

int main() {
    // Inisialisasi Vector Katalog Layanan & Parfum
    vector<string> namaLayanan = {
        "Cuci Kering Lipat",
        "Cuci Kering Setrika",
        "Setrika Saja",
        "Paket Ekspres (1 Hari)"
    };
    vector<int> tarifLayanan = {6000, 8000, 5000, 12000};

    vector<string> namaParfum = {
        "Parfum Standar",
        "Parfum Premium (+Rp2.000/kg)"
    };
    vector<int> tarifParfum = {0, 2000};

    // Vector Dinamis Riwayat Transaksi (Bertambah otomatis via .push_back())
    vector<string> riwayatNama;
    vector<string> riwayatLayanan;
    vector<string> riwayatParfum;
    vector<double> riwayatBerat;
    vector<int> riwayatTotalBayar;
    vector<int> riwayatUangBayar;
    vector<int> riwayatKembalian;

    int totalOmzet = 0;
    double totalKgLaundry = 0.0;

    int pilihanMenu = 0;
    char lanjutMenu = 'y';

    cout << "========================================================\n";
    cout << "        SELAMAT DATANG DI APLIKASI LAUNDREAM            \n";
    cout << "  Sistem Kasir & Rekapitulasi Laundry Berbasis C++     \n";
    cout << "========================================================\n";

    do {
        tampilkanMenuUtama();
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                string namaPelanggan;
                int pilihLayanan = 0;
                int pilihParfum = 0;
                double beratPakaian = 0.0;

                // 1. Panggil Modul Input (Dienan)
                inputDataTransaksi(namaPelanggan, pilihLayanan, pilihParfum, beratPakaian,
                                   namaLayanan, tarifLayanan, namaParfum);

                int idxLayanan = pilihLayanan - 1;
                int idxParfum = pilihParfum - 1;

                string layananTerpilih = namaLayanan[idxLayanan];
                string parfumTerpilih = (idxParfum == 0) ? "Standar" : "Premium";

                int tarifDasar = tarifLayanan[idxLayanan];
                int tarifTambahan = tarifParfum[idxParfum];
                int totalTarifPerKg = tarifDasar + tarifTambahan;

                // 2. Panggil Modul Perhitungan & Kasir (Salwa)
                double subtotal = beratPakaian * totalTarifPerKg;
                double diskon = hitungDiskon(beratPakaian, subtotal);
                int totalBayar = static_cast<int>(subtotal - diskon);

                int uangBayar = 0;
                int kembalian = 0;
                prosesPembayaranKasir(totalBayar, uangBayar, kembalian);

                // 3. Simpan ke Vector Riwayat menggunakan .push_back()
                riwayatNama.push_back(namaPelanggan);
                riwayatLayanan.push_back(layananTerpilih);
                riwayatParfum.push_back(parfumTerpilih);
                riwayatBerat.push_back(beratPakaian);
                riwayatTotalBayar.push_back(totalBayar);
                riwayatUangBayar.push_back(uangBayar);
                riwayatKembalian.push_back(kembalian);

                totalOmzet += totalBayar;
                totalKgLaundry += beratPakaian;

                // 4. Cetak Struk Resmi (Fakhry)
                cetakStrukKasir(namaPelanggan, layananTerpilih, parfumTerpilih,
                                beratPakaian, totalTarifPerKg, subtotal, diskon,
                                totalBayar, uangBayar, kembalian);

                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 2: {
                // Panggil Modul Cari Pelanggan dengan find() (Fakhry)
                cariTransaksiPelanggan(riwayatNama, riwayatLayanan, riwayatParfum,
                                       riwayatBerat, riwayatTotalBayar,
                                       riwayatUangBayar, riwayatKembalian);
                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 3: {
                // Panggil Modul Rekap Penjualan & Statistik (Athaufa)
                tampilkanRekapPenjualan(riwayatNama, riwayatLayanan, riwayatParfum,
                                        riwayatBerat, riwayatTotalBayar,
                                        totalOmzet, totalKgLaundry);
                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 4: {
                // Panggil Modul Katalog Tarif (Aulia)
                tampilkanKatalogTarif(namaLayanan, tarifLayanan, namaParfum, tarifParfum);
                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 5: {
                cout << "\n========================================================\n";
                cout << "   Terima kasih telah menggunakan aplikasi Laundream!   \n";
                cout << "                 Sampai jumpa kembali!                  \n";
                cout << "========================================================\n";
                lanjutMenu = 'n';
                break;
            }

            default: {
                cout << "\n[!] Pilihan tidak valid. Silakan pilih nomor 1 sampai 5.\n";
                cout << "Tekan tombol karakter apa saja lalu enter...";
                char temp;
                cin >> temp;
                lanjutMenu = 'y';
                break;
            }
        }

    } while (lanjutMenu == 'y' || lanjutMenu == 'Y');

    return 0;
}
