#include <iostream>
#include <string>

using namespace std;

/*
================================================================================
                       PROJECT AKHIR DASAR PEMROGRAMAN
         LAUNDREAM: SISTEM KASIR & REKAPITULASI BIAYA LAUNDRY
                    FAKULTAS MIPA - UNIVERSITAS NEGERI SEMARANG
================================================================================
Petunjuk untuk Seluruh Anggota Kelompok:
1. Seluruh kode ditulis murni di dalam fungsi int main() sesuai silabus perkuliahan.
2. Setiap anggota bertanggung jawab mengimplementasikan bagian kodenya masing-masing
   pada blok komentar // TODO yang telah disediakan.
3. Jangan mengubah nama variabel yang sudah disepakati bersama agar kode dapat terhubung
   dengan lancar.
================================================================================
*/

int main() {
    // ========================================================================
    // BLOK 1: DEKLARASI DATA KATALOG & ARRAY RIWAYAT TRANSAKSI
    // Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
    // Konsep C++      : Array 1 Dimensi & Variabel Dasar
    // ========================================================================
    // TODO [Aulia]:
    // 1. Deklarasikan array untuk nama paket layanan (4 paket):
    //    - "Cuci Kering Lipat", "Cuci Kering Setrika", "Setrika Saja", "Paket Ekspres (1 Hari)"
    // 2. Deklarasikan array untuk tarif masing-masing paket layanan:
    //    - 6000, 8000, 5000, 12000
    // 3. Deklarasikan array untuk opsi parfum/pewangi (2 opsi) beserta tarif tambahannya:
    //    - "Parfum Standar" (Rp0) dan "Parfum Premium" (Rp2000/kg)
    // 4. Deklarasikan array penampung riwayat transaksi (kapasitas 50):
    //    - string riwayatNama[50];
    //    - string riwayatLayanan[50];
    //    - string riwayatParfum[50];
    //    - double riwayatBerat[50];
    //    - int riwayatTotalBayar[50];
    //    - int riwayatUangBayar[50];
    //    - int riwayatKembalian[50];
    // 5. Deklarasikan variabel akumulasi rekap:
    //    - int jumlahTransaksi = 0;
    //    - int totalPendapatan = 0;
    //    - double totalKgLaundry = 0.0;
    
    // --- [MULAI KODING BLOK 1 DI SINI] ---
    const int JUMLAH_LAYANAN = 4;
    string namaLayanan[JUMLAH_LAYANAN] = {
        "Cuci Kering Lipat",
        "Cuci Kering Setrika",
        "Setrika Saja",
        "Paket Ekspres (1 Hari)"
    };
    int tarifLayanan[JUMLAH_LAYANAN] = {6000, 8000, 5000, 12000};

    const int JUMLAH_PARFUM = 2;
    string namaParfum[JUMLAH_PARFUM] = {"Parfum Standar", "Parfum Premium (+Rp2.000/kg)"};
    int tarifParfum[JUMLAH_PARFUM] = {0, 2000};

    const int MAX_TRANSAKSI = 50;
    string riwayatNama[MAX_TRANSAKSI];
    string riwayatLayanan[MAX_TRANSAKSI];
    string riwayatParfum[MAX_TRANSAKSI];
    double riwayatBerat[MAX_TRANSAKSI];
    int riwayatTotalBayar[MAX_TRANSAKSI];
    int riwayatUangBayar[MAX_TRANSAKSI];
    int riwayatKembalian[MAX_TRANSAKSI];

    int jumlahTransaksi = 0;
    int totalPendapatan = 0;
    double totalKgLaundry = 0.0;
    // --- [SELESAI BLOK 1] ---


    // ========================================================================
    // BLOK 2: MENU UTAMA & PERULANGAN PROGRAM UTAMA
    // Penanggung Jawab: AHMAD RAIHAN KHOMEINI SAPUTRA (2604130073) - Ketua
    // Konsep C++      : Perulangan do-while & Percabangan switch-case
    // ========================================================================
    int pilihanMenu = 0;
    char lanjutMenu = 'y';

    cout << "========================================================\n";
    cout << "        SELAMAT DATANG DI APLIKASI LAUNDREAM            \n";
    cout << "  Sistem Kasir & Rekapitulasi Laundry Berbasis C++     \n";
    cout << "========================================================\n";

    // TODO [Raihan]:
    // 1. Buat perulangan do-while agar menu dapat terus berjalan berulang kali.
    // 2. Tampilkan teks Menu Utama (1 sampai 5).
    // 3. Minta input pilihanMenu dari user.
    // 4. Buat struktur percabangan switch (pilihanMenu) untuk memanggil case 1 - 5.

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
                // Konsep C++      : Input/Output (cin, getline) & Validasi Looping
                // ============================================================
                cout << "\n========================================================\n";
                cout << "                TRANSAKSI LAUNDRY BARU                  \n";
                cout << "========================================================\n";

                string namaPelanggan;
                int pilihanLayanan = 0;
                int pilihanParfum = 0;
                double beratPakaian = 0.0;

                // TODO [Dienan]:
                // 1. Minta input nama pelanggan menggunakan cin.ignore() dan getline(cin, namaPelanggan).
                // 2. Tampilkan daftar 4 jenis paket layanan menggunakan perulangan for.
                // 3. Minta input pilihanLayanan (1-4), lengkapi dengan while jika input < 1 atau > 4.
                // 4. Tampilkan opsi parfum (1-2) dan minta input pilihanParfum.
                // 5. Minta input beratPakaian (kg), lengkapi dengan while agar berat harus > 0.
                
                // --- [TULIS KODE BLOK 3 DI BAWAH INI] ---
                cout << "[KOSONG] TODO: Kerjakan input nama, layanan, parfum, dan berat oleh Dienan.\n";
                // --- [SELESAI BLOK 3] ---


                // ============================================================
                // BLOK 4: PERHITUNGAN BIAYA, DISKON 10% & UANG KEMBALIAN
                // Penanggung Jawab: SALWA THALITA AZAHRA (2604130033)
                // Konsep C++      : Operator Aritmatika & Percabangan if-else
                // ============================================================
                // TODO [Salwa]:
                // 1. Tentukan indeks layanan dan tarif efektif:
                //    - totalTarifPerKg = tarifLayanan[idxLayanan] + tarifParfum[idxParfum]
                // 2. Hitung biayaKotor = beratPakaian * totalTarifPerKg
                // 3. Buat percabangan if-else untuk diskon 10%:
                //    - if (beratPakaian >= 5.0) diskon = biayaKotor * 0.10; else diskon = 0.0;
                // 4. Hitung totalBayar = biayaKotor - diskon
                // 5. Minta input uang tunai kasir (uangBayar) dan buat perulangan while jika uang kurang.
                // 6. Hitung kembalian = uangBayar - totalBayar
                // 7. Simpan data transaksi ini ke dalam Array riwayat pada indeks [jumlahTransaksi],
                //    kemudian lakukan increment jumlahTransaksi++, tambahkan ke totalPendapatan,
                //    dan tambahkan ke totalKgLaundry.
                
                // --- [TULIS KODE BLOK 4 DI BAWAH INI] ---
                int totalBayar = 0;
                int uangBayar = 0;
                int kembalian = 0;
                cout << "[KOSONG] TODO: Kerjakan logika hitung biaya, if-else diskon, dan kembalian oleh Salwa.\n";
                // --- [SELESAI BLOK 4] ---


                // ============================================================
                // BLOK 5A: FORMAT TAMPILAN STRUK RESMI KASIR
                // Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
                // Konsep C++      : Manipulasi Tampilan Output (cout)
                // ============================================================
                // TODO [Fakhry]:
                // 1. Cetak struk rincian kasir resmi yang rapi dengan pembatas tanda '=' dan '-'.
                // 2. Tampilkan Nama, Layanan, Parfum, Berat, Tarif/kg, Subtotal, Diskon,
                //    Total Bayar, Uang Diterima, dan Uang Kembalian.
                // 3. Tanyakan konfirmasi kepada kasir: "Kembali ke menu utama? (y/n): "
                //    lalu simpan ke variabel lanjutMenu.
                
                // --- [TULIS KODE BLOK 5A DI BAWAH INI] ---
                cout << "[KOSONG] TODO: Desain tampilan struk kasir oleh Fakhry.\n";
                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                // --- [SELESAI BLOK 5A] ---

                break;
            }

            case 2: {
                // ============================================================
                // BLOK 5B: FITUR PENCARIAN TRANSAKSI (LINEAR SEARCH PADA ARRAY)
                // Penanggung Jawab: MUHAMMAD FAKHRY ABYAN (2604130074)
                // Konsep C++      : Algoritma Pencarian Sekuensial (Linear Search)
                // ============================================================
                cout << "\n========================================================\n";
                cout << "          PENCARIAN RIWAYAT TRANSAKSI PELANGGAN         \n";
                cout << "========================================================\n";

                // TODO [Fakhry]:
                // 1. Cek apakah jumlahTransaksi == 0. Jika iya, tampilkan bahwa belum ada transaksi.
                // 2. Jika ada, minta input cariNama menggunakan cin.ignore() dan getline(cin, cariNama).
                // 3. Buat variabel boolean: bool ditemukan = false;
                // 4. Gunakan perulangan for (int i = 0; i < jumlahTransaksi; i++):
                //    - Periksa: if (riwayatNama[i] == cariNama)
                //    - Jika cocok, ubah ditemukan = true dan cetak rincian cucian pelanggan tersebut.
                // 5. Jika setelah loop ditemukan == false, beri pesan data tidak ditemukan.
                // 6. Minta input lanjutMenu ('y' atau 'n').

                // --- [TULIS KODE BLOK 5B DI BAWAH INI] ---
                cout << "[KOSONG] TODO: Kerjakan pencarian linear search pada array oleh Fakhry.\n";
                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                // --- [SELESAI BLOK 5B] ---

                break;
            }

            case 3: {
                // ============================================================
                // BLOK 6: REKAP LAPORAN PENJUALAN & STATISTIK TRANSAKSI TERBESAR
                // Penanggung Jawab: ATHAUFA KINDI WIRATAMA (2604130114)
                // Konsep C++      : Pembacaan Array & Algoritma Nilai Maksimum
                // ============================================================
                cout << "\n======================================================================\n";
                cout << "               REKAP LAPORAN PENJUALAN LAUNDREAM                      \n";
                cout << "======================================================================\n";

                // TODO [Athaufa]:
                // 1. Cek apakah jumlahTransaksi == 0. Jika iya, tampilkan belum ada transaksi.
                // 2. Jika ada data:
                //    - Gunakan perulangan for untuk mencetak tabel seluruh transaksi dari array:
                //      riwayatNama[i], riwayatLayanan[i], riwayatBerat[i], riwayatTotalBayar[i].
                //    - Tampilkan ringkasan: Total Transaksi, Total Berat (kg), Rata-rata Berat,
                //      dan Total Omzet Pemasukan (totalPendapatan).
                // 3. Algoritma Mencari Transaksi Terbesar (Nilai Maksimum):
                //    - Inisialisasi: int bayarTerbesar = riwayatTotalBayar[0]; int idxTerbesar = 0;
                //    - Gunakan loop for (int i = 1; i < jumlahTransaksi; i++):
                //      if (riwayatTotalBayar[i] > bayarTerbesar) {
                //          bayarTerbesar = riwayatTotalBayar[i];
                //          idxTerbesar = i;
                //      }
                //    - Cetak statistik transaksi terbesar dan nama pelanggannya.
                // 4. Minta input lanjutMenu ('y' atau 'n').

                // --- [TULIS KODE BLOK 6 DI BAWAH INI] ---
                cout << "[KOSONG] TODO: Kerjakan rekap laporan, omzet, dan nilai maksimum oleh Athaufa.\n";
                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                // --- [SELESAI BLOK 6] ---

                break;
            }

            case 4: {
                // ============================================================
                // BLOK 7: TAMPILAN DAFTAR TARIF & KATALOG LAYANAN
                // Penanggung Jawab: AULIA ARI FADHILAH (2604130139)
                // Konsep C++      : Pembacaan Array dengan Perulangan for
                // ============================================================
                cout << "\n========================================================\n";
                cout << "            DAFTAR TARIF & KATALOG LAUNDRY              \n";
                cout << "========================================================\n";

                // TODO [Aulia]:
                // 1. Gunakan perulangan for untuk menampilkan isi array namaLayanan dan tarifLayanan.
                // 2. Tampilkan pula opsi pewangi dari array namaParfum dan tarifParfum.
                // 3. Beri catatan promo diskon 10% untuk berat cucian minimal 5 kg.
                // 4. Minta input lanjutMenu ('y' atau 'n').

                // --- [TULIS KODE BLOK 7 DI BAWAH INI] ---
                cout << "[KOSONG] TODO: Tampilkan katalog harga dari array oleh Aulia.\n";
                cout << "\nKembali ke menu utama? (y/n): ";
                cin >> lanjutMenu;
                // --- [SELESAI BLOK 7] ---

                break;
            }

            case 5: {
                // Keluar dari program
                cout << "\n========================================================\n";
                cout << "   Terima kasih telah menggunakan aplikasi Laundream!   \n";
                cout << "                 Sampai jumpa kembali!                  \n";
                cout << "========================================================\n";
                lanjutMenu = 'n';
                break;
            }

            default: {
                cout << "\n[!] Pilihan tidak valid. Silakan pilih nomor 1 sampai 5.\n";
                cout << "Tekan tombol karakter apa saja lalu enter untuk kembali...";
                char temp;
                cin >> temp;
                lanjutMenu = 'y';
                break;
            }
        }

    } while (lanjutMenu == 'y' || lanjutMenu == 'Y');

    return 0;
}
