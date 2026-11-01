# Laundream: Sistem Kasir & Rekapitulasi Penghitungan Biaya Laundry (C++)

Program terminal berbasis C++ untuk otomatisasi transaksi kasir laundry, penghitungan tarif dan diskon bertingkat, pencarian riwayat transaksi (*linear search*), serta penyusunan rekapitulasi laporan penjualan dan statistik harian secara terpadu.

Proyek ini disusun untuk memenuhi tugas akhir mata kuliah **Dasar Pemrograman**, Fakultas Matematika dan Ilmu Pengetahuan Alam, **Universitas Negeri Semarang (UNNES)** tahun 2026.

---

## 👥 Tim Pengembang & Pembagian Tugas (Murni di dalam `int main()`)

Seluruh kode dirancang terstruktur secara sekuensial di dalam `int main()` menggunakan konsep dasar C++ yang telah diajarkan di kelas:

| No | Nama Lengkap | NIM | Tanggung Jawab & Blok Kode | Materi C++ yang Digunakan |
|---|---|---|---|---|
| 1 | **Ahmad Raihan Khomeini Saputra** | `2604130073` *(Ketua)* | Inisialisasi program, navigasi menu utama (5 fitur), struktur perulangan `do-while`, dan percabangan `switch-case`. | *Looping & Switch-Case* |
| 2 | **Muhammad Dienan Akbar** | `2604130112` | Blok input transaksi: nama pelanggan (`getline`), pilihan 4 paket layanan, opsi parfum, dan validasi berat cucian. | *I/O Stream & Looping Validasi* |
| 3 | **Salwa Thalita Azahra** | `2604130033` | Blok perhitungan biaya laundry, percabangan `if-else` diskon 10% ($\ge 5\text{ kg}$), input uang pembayaran kasir, dan hitung uang kembalian. | *Operator Aritmatika & If-Else* |
| 4 | **Aulia Ari Fadhilah** | `2604130139` | Deklarasi data katalog tarif & parfum dalam Array 1D, serta menu lihat daftar tarif layanan menggunakan perulangan `for`. | *Array 1D & For-Loop* |
| 5 | **Muhammad Fakhry Abyan** | `2604130074` | Format tampilan struk kasir resmi dan **fitur pencarian riwayat transaksi pelanggan (*linear search*)** berdasarkan nama. | *Linear Search di Array & Output Formatter* |
| 6 | **Athaufa Kindi Wiratama** | `2604130114` | Blok menu rekapitulasi penjualan harian (omzet, total kg cucian) & **algoritma mencari transaksi terbesar (*nilai maksimum*)**. Serta penyusunan laporan & PPT. | *Array 1D, Algoritma Nilai Maksimum, & QA/Testing* |

---

## 💡 Fitur Utama Program

1. **Transaksi Laundry Baru (Menu 1)**:
   - Input nama pelanggan (mendukung nama lengkap berspasi).
   - Memilih 4 varian layanan:
     - Cuci Kering Lipat (Rp6.000/kg)
     - Cuci Kering Setrika (Rp8.000/kg)
     - Setrika Saja (Rp5.000/kg)
     - Paket Ekspres 1 Hari (Rp12.000/kg)
   - Opsi tambahan parfum: Standar (Rp0/kg) atau Premium (+Rp2.000/kg).
   - Diskon otomatis **10%** apabila berat cucian $\ge 5\text{ kg}$.
   - Pembayaran kasir dengan validasi uang tunai dan penghitungan uang kembalian.
   - Pencetakan struk transaksi resmi dan otomatis tersimpan ke Array riwayat transaksi.
2. **Pencarian Riwayat Transaksi Pelanggan (Menu 2)**:
   - Pencarian berbasis nama menggunakan algoritma *Linear Search* pada Array riwayat.
   - Menampilkan detail cucian, berat, total biaya, dan status lunas pembayaran.
3. **Rekap Laporan Penjualan & Statistik Kasir (Menu 3)**:
   - Menampilkan tabel riwayat seluruh transaksi yang terjadi hari ini.
   - Menghitung total transaksi, total kilogram cucian, rata-rata berat cucian, dan total omzet uang kas masuk.
   - **Statistik Kasir**: Menentukan transaksi cucian terbesar (*Nilai Maksimum*) hari ini beserta nama pelanggannya.
4. **Lihat Daftar Tarif & Katalog Layanan (Menu 4)**:
   - Menampilkan daftar harga katalog resmi laundry secara transparan.
5. **Keluar (Menu 5)**:
   - Menutup program dengan pesan terima kasih.

---

## 🛠️ Konsep Pemrograman C++ yang Digunakan (100% Sesuai Silabus)

- **Input / Output Stream**: `#include <iostream>`, `cin`, `cout`, `getline()`
- **Tipe Data & Variabel**: `int`, `double`, `string`, `char`
- **Operator Aritmatika & Logika**: `*`, `-`, `+`, `/`, `>`, `>=`, `==`
- **Percabangan**: `if-else` (diskon & validasi) dan `switch-case` (menu utama)
- **Perulangan**: `do-while` (menu berulang), `while` (validasi input), dan `for` (rekap & searching)
- **Array 1 Dimensi**: Menyimpan katalog tarif, nama layanan, riwayat transaksi, berat, total bayar, uang diterima, dan kembalian.
- **Algoritma Dasar Array**:
  - *Linear Search* (pencarian data pelanggan).
  - *Pencarian Nilai Maksimum* (mencari transaksi terbesar).

---

## 🚀 Panduan Kompilasi & Menjalankan

### Kompilasi (Gunakan flag `-static` agar mandiri tanpa butuh file DLL eksternal)
```bash
g++ -static -o laundream main.cpp
```

### Menjalankan Program
- **Windows**:
  ```powershell
  .\laundream.exe
  ```
- **Linux / macOS**:
  ```bash
  ./laundream
  ```
