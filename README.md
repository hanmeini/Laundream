# Laundream: Sistem Kasir & Rekapitulasi Penghitungan Biaya Laundry (C++)

Program terminal berbasis C++ untuk otomatisasi transaksi kasir laundry, penghitungan tarif dan diskon bertingkat, pencarian riwayat transaksi (*STL find*), serta penyusunan rekapitulasi laporan penjualan dan statistik harian secara terpadu.

Proyek ini disusun untuk memenuhi tugas akhir mata kuliah **Dasar Pemrograman**, Fakultas Matematika dan Ilmu Pengetahuan Alam, **Universitas Negeri Semarang (UNNES)** tahun 2026.

---

## 👥 Tim Pengembang & Pembagian Tugas (Berbasis Function & Vector)

Program dirancang modular dengan pemisahan fungsi dan struktur data dinamis `std::vector` sesuai materi kuliah Pertemuan 11 (Vector STL) & Fungsi:

| No | Nama Lengkap | NIM | Tanggung Jawab & Modul Fungsi | Materi C++ yang Digunakan |
|---|---|---|---|---|
| 1 | **Ahmad Raihan Khomeini Saputra** | `2604130073` *(Ketua)* | Fungsi `tampilkanMenuUtama()`, fungsi `int main()`, perulangan `do-while`, pemanggilan fungsi, dan manajemen Git. | *Function void, Looping & Switch-Case* |
| 2 | **Muhammad Dienan Akbar** | `2604130112` | Fungsi `inputDataTransaksi(...)`: input nama (`getline`), pemilihan paket layanan, opsi parfum, dan validasi berat cucian. | *Function Reference (`&`), I/O Stream & Looping* |
| 3 | **Salwa Thalita Azahra** | `2604130033` | Fungsi `hitungDiskon(...)` & `prosesPembayaranKasir(...)`: kalkulasi tarif, diskon 10% ($\ge 5\text{ kg}$), input uang tunai, dan kembalian. | *Function Return Value, If-Else & Aritmatika* |
| 4 | **Aulia Ari Fadhilah** | `2604130139` | Fungsi `tampilkanKatalogTarif(...)`: menampilkan katalog harga paket layanan dan parfum dari vector. | *Vector 1D, Size & For Loop* |
| 5 | **Muhammad Fakhry Abyan** | `2604130074` | Fungsi `cetakStrukKasir(...)` & `cariTransaksiPelanggan(...)`: format struk kasir rapi dan pencarian transaksi berbasis algoritma `find()` & `distance()`. | *STL Algorithm `find()`, `distance()`, & Output* |
| 6 | **Athaufa Kindi Wiratama** | `2604130114` | Fungsi `tampilkanRekapPenjualan(...)`: rekapitulasi penjualan (vector `.empty()`, `.size()`, omzet) & algoritma mencari transaksi terbesar (*nilai maksimum*). | *Vector Operations, Nilai Maksimum & QA* |

---

## 💡 Fitur Utama Program

1. **Transaksi Laundry Baru (Menu 1)**:
   - Input nama pelanggan (mendukung nama lengkap berspasi).
   - Memilih 4 varian paket layanan:
     - Cuci Kering Lipat (Rp6.000/kg)
     - Cuci Kering Setrika (Rp8.000/kg)
     - Setrika Saja (Rp5.000/kg)
     - Paket Ekspres 1 Hari (Rp12.000/kg)
   - Opsi tambahan parfum: Standar (Rp0/kg) atau Premium (+Rp2.000/kg).
   - Diskon otomatis **10%** apabila berat cucian $\ge 5\text{ kg}$.
   - Pembayaran kasir dengan validasi uang tunai dan penghitungan uang kembalian.
   - Pencetakan struk transaksi resmi dan otomatis tersimpan ke Vector riwayat transaksi menggunakan `.push_back()`.
2. **Pencarian Riwayat Transaksi Pelanggan (Menu 2)**:
   - Pencarian berbasis nama menggunakan fungsi **`find()`** dan **`distance()`** dari library `<algorithm>` pada Vector riwayat.
   - Menampilkan detail cucian, berat, total biaya, dan status lunas pembayaran.
3. **Rekap Laporan Penjualan & Statistik Kasir (Menu 3)**:
   - Menampilkan tabel riwayat seluruh transaksi yang terjadi hari ini menggunakan `.empty()` dan `.size()`.
   - Menghitung total transaksi, total kilogram cucian, rata-rata berat cucian, dan total omzet uang kas masuk.
   - **Statistik Kasir**: Menentukan transaksi cucian terbesar (*Nilai Maksimum*) hari ini beserta nama pelanggannya.
4. **Lihat Daftar Tarif & Katalog Layanan (Menu 4)**:
   - Menampilkan daftar harga katalog resmi laundry secara transparan.
5. **Keluar (Menu 5)**:
   - Menutup program dengan pesan terima kasih.

---

## 🛠️ Konsep Pemrograman C++ yang Digunakan (100% Sesuai Silabus)

- **Vector C++ (STL)**: `#include <vector>`, `push_back()`, `.size()`, `.empty()`, inisialisasi list `{...}`
- **Fungsi (Function)**: Fungsi `void`, fungsi dengan nilai balik (*return value*), dan *pass-by-reference* (`&`)
- **Algoritma STL**: `#include <algorithm>`, `find()`, `distance()`
- **Input / Output Stream**: `#include <iostream>`, `cin`, `cout`, `getline()`
- **Tipe Data & Variabel**: `int`, `double`, `string`, `char`, `size_t`
- **Operator Aritmatika & Logika**: `*`, `-`, `+`, `/`, `>`, `>=`, `==`
- **Percabangan**: `if-else` (diskon & validasi) dan `switch-case` (menu utama)
- **Perulangan**: `do-while` (menu berulang), `while` (validasi input), dan `for` (rekap & katalog)

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

---

## 📚 Panduan Kolaborasi Tim & Penggunaan Git

Bagi seluruh anggota kelompok yang ingin mulai mengerjakan tugas fungsinya dan mengunggah kode ke GitHub, silakan baca panduan lengkap dan ramah pemula di file:  
👉 **[PANDUAN_GIT.md](PANDUAN_GIT.md)** (Berisi cara clone, buat branch, commit, push, hingga pull request tanpa bentrok).

