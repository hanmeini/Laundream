#include <iostream>
#include <string>

using namespace std;

int main() {
    // ========================================================================
    // BLOK 1: KATALOG DATA MASTER & ARRAY PENYIMPANAN RIWAYAT
    // Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
    // Konsep C++: Array 1 Dimensi, Konstanta, dan Inisialisasi Variabel
    // ========================================================================
    const int JUMLAH_LAYANAN = 4;
    string namaLayanan[JUMLAH_LAYANAN] = {
        "Cuci Kering Lipat",
        "Cuci Kering Setrika",
        "Setrika Saja",
        "Paket Ekspres (1 Hari)"
    };
    int tarifLayanan[JUMLAH_LAYANAN] = {6000, 8000, 5000, 12000};

    const int JUMLAH_PARFUM = 2;
    string namaParfum[JUMLAH_PARFUM] = {
        "Parfum Standar",
        "Parfum Premium (+Rp2.000/kg)"
    };
    int tarifParfum[JUMLAH_PARFUM] = {0, 2000};

    // Array Penyimpanan Riwayat Transaksi Kasir (Kapasitas maks 50 transaksi)
    const int MAX_TRANSAKSI = 50;
    string riwayatNama[MAX_TRANSAKSI];
    string riwayatLayanan[MAX_TRANSAKSI];
    string riwayatParfum[MAX_TRANSAKSI];
    double riwayatBerat[MAX_TRANSAKSI];
    int riwayatTotalBayar[MAX_TRANSAKSI];
    int riwayatUangBayar[MAX_TRANSAKSI];
    int riwayatKembalian[MAX_TRANSAKSI];

    // Variabel Rekapitulasi Akumulasi
    int jumlahTransaksi = 0;
    int totalPendapatan = 0;
    double totalKgLaundry = 0.0;

    int pilihanMenu = 0;
    char lanjutMenu = 'y';

    cout << "========================================================\n";
    cout << "        SELAMAT DATANG DI APLIKASI LAUNDREAM            \n";
    cout << "  Sistem Kasir & Rekapitulasi Laundry Berbasis C++     \n";
    cout << "========================================================\n";

    // ========================================================================
    // BLOK 2: MENU UTAMA & PERULANGAN PROGRAM (do-while)
    // Penanggung Jawab: AHMAD RAIHAN KHOMEINI SAPUTRA (2604130073) - Ketua
    // Konsep C++: Perulangan do-while & Percabangan switch-case
    // ========================================================================
    do {
        cout << "\n========================================================\n";
        cout << "                 LAUNDREAM - MENU UTAMA                 \n";
        cout << "========================================================\n";
        cout << "1. Transaksi Laundry Baru (Kasir & Kembalian)\n";
        cout << "2. Cari Riwayat Transaksi Pelanggan (Linear Search)\n";
        cout << "3. Rekap Laporan Penjualan & Statistik Kasir\n";
        cout << "4. Lihat Daftar Tarif & Layanan\n";
        cout << "5. Keluar\n";
        cout << "========================================================\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                // ============================================================
                // BLOK 3: INPUT DATA TRANSAKSI & PILIHAN LAYANAN
                // Penanggung Jawab: MUHAMMAD DIENAN AKBAR (2604130112)
                // Konsep C++: Input/Output (cin, getline) & Validasi Looping
                // ============================================================
                string namaPelanggan;
                int pilihanLayanan = 0;
                int pilihanParfum = 0;
                double beratPakaian = 0.0;

                cout << "\n========================================================\n";
                cout << "                TRANSAKSI LAUNDRY BARU                  \n";
                cout << "========================================================\n";

                // Input Nama Pelanggan (Mendukung nama dengan spasi)
                cout << "Masukkan nama pelanggan : ";
                cin.ignore();
                getline(cin, namaPelanggan);

                // Pilih Paket Layanan
                cout << "\nPilihan Jenis Layanan:\n";
                for (int i = 0; i < JUMLAH_LAYANAN; i++) {
                    cout << (i + 1) << ". " << namaLayanan[i] 
                         << " (Rp" << tarifLayanan[i] << "/kg)\n";
                }
                cout << "Pilih layanan (1-" << JUMLAH_LAYANAN << ") : ";
                cin >> pilihanLayanan;

                while (pilihanLayanan < 1 || pilihanLayanan > JUMLAH_LAYANAN) {
                    cout << "[!] Pilihan tidak valid. Masukkan angka (1-" << JUMLAH_LAYANAN << "): ";
                    cin >> pilihanLayanan;
                }

                // Pilih Opsi Tambahan Parfum
                cout << "\nPilihan Opsi Parfum / Pewangi:\n";
                for (int i = 0; i < JUMLAH_PARFUM; i++) {
                    cout << (i + 1) << ". " << namaParfum[i] << "\n";
                }
                cout << "Pilih opsi parfum (1-" << JUMLAH_PARFUM << ") : ";
                cin >> pilihanParfum;

                while (pilihanParfum < 1 || pilihanParfum > JUMLAH_PARFUM) {
                    cout << "[!] Pilihan tidak valid. Masukkan angka (1-" << JUMLAH_PARFUM << "): ";
                    cin >> pilihanParfum;
                }

                // Input Berat Pakaian
                cout << "Masukkan berat pakaian (kg) : ";
                cin >> beratPakaian;

                while (beratPakaian <= 0) {
                    cout << "[!] Berat harus berupa angka positif. Coba lagi (kg): ";
                    cin >> beratPakaian;
                }

                // ============================================================
                // BLOK 4: PERHITUNGAN BIAYA, DISKON & UANG KEMBALIAN
                // Penanggung Jawab: SALWA THALITA AZAHRA (2604130033)
                // Konsep C++: Operator Aritmatika & Percabangan if-else
                // ============================================================
                int idxLayanan = pilihanLayanan - 1;
                int idxParfum = pilihanParfum - 1;

                string layananTerpilih = namaLayanan[idxLayanan];
                string parfumTerpilih = (idxParfum == 0) ? "Standar" : "Premium";

                int tarifDasar = tarifLayanan[idxLayanan];
                int tarifTambahanParfum = tarifParfum[idxParfum];
                int totalTarifPerKg = tarifDasar + tarifTambahanParfum;

                // Hitung biaya kotor
                double biayaKotor = beratPakaian * totalTarifPerKg;
                double diskon = 0.0;

                // Ketentuan: diskon 10% jika berat cucian minimal 5 kg
                if (beratPakaian >= 5.0) {
                    diskon = biayaKotor * 0.10;
                } else {
                    diskon = 0.0;
                }

                int totalBayar = (int)(biayaKotor - diskon);

                // Tampilkan struk sementara & minta uang bayar tunai
                cout << "\n--------------------------------------------------------\n";
                cout << "Total Biaya yang Harus Dibayar : Rp" << totalBayar << "\n";
                cout << "--------------------------------------------------------\n";

                int uangBayar = 0;
                cout << "Masukkan nominal uang tunai kasir : Rp";
                cin >> uangBayar;

                while (uangBayar < totalBayar) {
                    cout << "[!] Uang pembayaran kurang! Kurang Rp" << (totalBayar - uangBayar) << "\n";
                    cout << "Masukkan uang tunai yang mencukupi: Rp";
                    cin >> uangBayar;
                }

                int kembalian = uangBayar - totalBayar;

                // Simpan transaksi ke Array Riwayat
                if (jumlahTransaksi < MAX_TRANSAKSI) {
                    riwayatNama[jumlahTransaksi] = namaPelanggan;
                    riwayatLayanan[jumlahTransaksi] = layananTerpilih;
                    riwayatParfum[jumlahTransaksi] = parfumTerpilih;
                    riwayatBerat[jumlahTransaksi] = beratPakaian;
                    riwayatTotalBayar[jumlahTransaksi] = totalBayar;
                    riwayatUangBayar[jumlahTransaksi] = uangBayar;
                    riwayatKembalian[jumlahTransaksi] = kembalian;

                    jumlahTransaksi++;
                    totalPendapatan = totalPendapatan + totalBayar;
                    totalKgLaundry = totalKgLaundry + beratPakaian;
                }

                // ============================================================
                // BLOK 5: STRUK RESMI KASIR
                // Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
                // Konsep C++: Manipulasi Output Struk Rapi
                // ============================================================
                cout << "\n========================================================\n";
                cout << "             STRUK RESMI TRANSAKSI LAUNDREAM            \n";
                cout << "========================================================\n";
                cout << "Nama Pelanggan  : " << namaPelanggan << "\n";
                cout << "Jenis Layanan   : " << layananTerpilih << "\n";
                cout << "Pilihan Parfum  : " << parfumTerpilih << "\n";
                cout << "Berat Cucian    : " << beratPakaian << " kg\n";
                cout << "Tarif per kg    : Rp" << totalTarifPerKg << "\n";
                cout << "Biaya Subtotal  : Rp" << (int)biayaKotor << "\n";
                cout << "Potongan Diskon : Rp" << (int)diskon;
                if (diskon > 0) {
                    cout << " (10% - Promo Cucian >= 5 kg)";
                }
                cout << "\n";
                cout << "--------------------------------------------------------\n";
                cout << "TOTAL BAYAR     : Rp" << totalBayar << "\n";
                cout << "UANG DITERIMA   : Rp" << uangBayar << "\n";
                cout << "UANG KEMBALIAN  : Rp" << kembalian << "\n";
                cout << "========================================================\n";
                cout << "   Terima kasih telah mempercayakan pakaian Anda!       \n";
                cout << "========================================================\n";

                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 2: {
                // ============================================================
                // BLOK 6: FITUR PENCARIAN TRANSAKSI (LINEAR SEARCH)
                // Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
                // Konsep C++: Pencarian Linear Search pada Array 1 Dimensi
                // ============================================================
                cout << "\n========================================================\n";
                cout << "          PENCARIAN RIWAYAT TRANSAKSI PELANGGAN         \n";
                cout << "========================================================\n";

                if (jumlahTransaksi == 0) {
                    cout << "[!] Belum ada transaksi yang tersimpan hari ini.\n";
                } else {
                    string cariNama;
                    cout << "Masukkan nama pelanggan yang dicari: ";
                    cin.ignore();
                    getline(cin, cariNama);

                    bool ditemukan = false;
                    cout << "\nHasil Pencarian untuk \"" << cariNama << "\":\n";
                    cout << "--------------------------------------------------------\n";

                    for (int i = 0; i < jumlahTransaksi; i++) {
                        // Memeriksa kesamaan nama (Case-sensitive sederhana)
                        if (riwayatNama[i] == cariNama) {
                            ditemukan = true;
                            cout << "• Transaksi ID  : #" << (i + 1) << "\n";
                            cout << "  Layanan       : " << riwayatLayanan[i] << "\n";
                            cout << "  Parfum        : " << riwayatParfum[i] << "\n";
                            cout << "  Berat Pakaian : " << riwayatBerat[i] << " kg\n";
                            cout << "  Total Bayar   : Rp" << riwayatTotalBayar[i] << "\n";
                            cout << "  Status        : Lunas (Bayar: Rp" << riwayatUangBayar[i] 
                                 << ", Kembali: Rp" << riwayatKembalian[i] << ")\n";
                            cout << "--------------------------------------------------------\n";
                        }
                    }

                    if (!ditemukan) {
                        cout << "[!] Data pelanggan dengan nama \"" << cariNama << "\" tidak ditemukan.\n";
                    }
                }

                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 3: {
                // ============================================================
                // BLOK 7: REKAP LAPORAN PENJUALAN & STATISTIK KASIR
                // Penanggung Jawab: ATHAUFA KINDI WIRATAMA (2604130114)
                // Konsep C++: Traversal Array & Algoritma Nilai Maksimum (Maks)
                // ============================================================
                cout << "\n======================================================================\n";
                cout << "               REKAP LAPORAN PENJUALAN LAUNDREAM                      \n";
                cout << "======================================================================\n";

                if (jumlahTransaksi == 0) {
                    cout << "Belum ada transaksi yang tercatat hari ini.\n";
                } else {
                    cout << "No | Nama Pelanggan   | Layanan             | Berat  | Total Bayar\n";
                    cout << "----------------------------------------------------------------------\n";
                    for (int i = 0; i < jumlahTransaksi; i++) {
                        cout << (i + 1) << "  | "
                             << riwayatNama[i] << "\t| "
                             << riwayatLayanan[i] << " (" << riwayatParfum[i] << ") | "
                             << riwayatBerat[i] << " kg | Rp"
                             << riwayatTotalBayar[i] << "\n";
                    }
                    cout << "----------------------------------------------------------------------\n";
                    cout << "Total Transaksi      : " << jumlahTransaksi << " transaksi\n";
                    cout << "Total Berat Cucian   : " << totalKgLaundry << " kg\n";
                    cout << "Rata-rata Berat      : " << (totalKgLaundry / jumlahTransaksi) << " kg/pelanggan\n";
                    cout << "Total Omzet Uang Masuk : Rp" << totalPendapatan << "\n";

                    // Algoritma Mencari Transaksi Terbesar (Nilai Maksimum dalam Array)
                    int idxTerbesar = 0;
                    int bayarTerbesar = riwayatTotalBayar[0];

                    for (int i = 1; i < jumlahTransaksi; i++) {
                        if (riwayatTotalBayar[i] > bayarTerbesar) {
                            bayarTerbesar = riwayatTotalBayar[i];
                            idxTerbesar = i;
                        }
                    }

                    cout << "----------------------------------------------------------------------\n";
                    cout << "* STATISTIK REKAP KASIR:\n";
                    cout << "  Transaksi Terbesar : Rp" << bayarTerbesar 
                         << " (Pelanggan: " << riwayatNama[idxTerbesar] 
                         << ", " << riwayatBerat[idxTerbesar] << " kg)\n";
                }
                cout << "======================================================================\n";

                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                break;
            }

            case 4: {
                // ============================================================
                // BLOK 8: KATALOG DAFTAR TARIF & LAYANAN
                // Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
                // Konsep C++: Pembacaan Array dengan Perulangan for
                // ============================================================
                cout << "\n========================================================\n";
                cout << "            DAFTAR TARIF & KATALOG LAUNDRY              \n";
                cout << "========================================================\n";
                cout << "[1] Paket Layanan Utama:\n";
                for (int i = 0; i < JUMLAH_LAYANAN; i++) {
                    cout << "    " << (i + 1) << ". " << namaLayanan[i] 
                         << " : Rp" << tarifLayanan[i] << " / kg\n";
                }
                cout << "\n[2] Pilihan Parfum / Pewangi Tambahan:\n";
                for (int i = 0; i < JUMLAH_PARFUM; i++) {
                    cout << "    " << (i + 1) << ". " << namaParfum[i] 
                         << " : Rp" << tarifParfum[i] << " / kg\n";
                }
                cout << "--------------------------------------------------------\n";
                cout << "* PROMO DISKON: Potongan 10% untuk cucian minimal 5 kg!\n";
                cout << "========================================================\n";

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
                cout << "\n[!] Pilihan tidak valid. Silakan pilih menu nomor 1 sampai 5.\n";
                cout << "Tekan karakter apa saja lalu enter untuk kembali...";
                char temp;
                cin >> temp;
                lanjutMenu = 'y';
                break;
            }
        }

    } while (lanjutMenu == 'y' || lanjutMenu == 'Y');

    return 0;
}
