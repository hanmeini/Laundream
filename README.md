# Laundream: Sistem Kasir & Rekap Penghitungan Biaya Laundry (C++)

Program terminal berbasis C++ untuk membantu proses transaksi kasir laundry, penghitungan tarif & diskon otomatis, serta penyusunan rekapitulasi laporan penjualan harian secara terpadu.

Proyek ini disusun untuk memenuhi tugas akhir mata kuliah **Dasar Pemrograman**, Program Studi Pendidikan Matematika / Matematika / Ilmu Komputer, FMIPA **Universitas Negeri Semarang (UNNES)** tahun 2026.

---

## 👥 Tim Pengembang & Pembagian Tugas (Murni di dalam `int main()`)

Seluruh kode dirancang terstruktur secara sekuensial di dalam `int main()` menggunakan konsep dasar C++ yang telah diajarkan di kelas:

| No | Nama Lengkap | NIM | Tanggung Jawab & Blok Kode | Materi C++ yang Digunakan |
|---|---|---|---|---|
| 1 | **Ahmad Raihan Khomeini Saputra** | `2604130073` *(Ketua)* | Inisialisasi program, navigasi menu utama, struktur perulangan `do-while`, dan percabangan `switch-case`. | *Looping & Switch-Case* |
| 2 | **Muhammad Dienan Akbar** | `2604130112` | Blok input transaksi: nama pelanggan (`cin.ignore` + `getline`), pilihan layanan, dan input berat pakaian. | *Input/Output Stream & String* |
| 3 | **Salwa Thalita Azahra** | `2604130033` | Blok perhitungan biaya laundry, percabangan `if-else` diskon 10% ($\ge 5\text{ kg}$), dan total pembayaran. | *Operator Aritmatika & If-Else* |
| 4 | **Aulia Ari Fadhilah** | `2604130139` | Deklarasi data katalog tarif & menu lihat tarif layanan menggunakan Array dan perulangan `for`. | *Array 1D & For-Loop* |
| 5 | **Muhammad Fakhry Abyan** | `2604130074` | Format tampilan struk/ringkasan transaksi kasir yang rapi dan penanganan konfirmasi kembali ke menu (`y/n`). | *Manipulasi Output & Char Logic* |
| 6 | **Athaufa Kindi Wiratama** | `2604130114` | Blok menu rekap laporan penjualan (menampilkan riwayat dari Array & akumulasi omzet harian) + Laporan & PPT. | *Array 1D, Looping, Testing & QA* |

---

## 💡 Fitur Utama Program

1. **Transaksi Laundry Baru (Menu 1)**:
   - Input nama pelanggan (mendukung nama lengkap berspasi).
   - Memilih layanan: **Reguler** (Rp7.000/kg) atau **Ekspres** (Rp10.000/kg).
   - Input berat cucian dalam kilogram.
   - Diskon otomatis **10%** apabila berat cucian $\ge 5\text{ kg}$.
   - Menampilkan struk transaksi per pelanggan dan langsung tersimpan ke riwayat kasir.
2. **Rekap Laporan Penjualan (Menu 2)**:
   - Menampilkan daftar semua transaksi yang terjadi hari itu (dari Array).
   - Menghitung total transaksi, total kilogram cucian, dan **total uang kas masuk (omzet harian)**.
3. **Lihat Tarif Layanan (Menu 3)**:
   - Menampilkan daftar harga katalog resmi laundry.
4. **Keluar (Menu 4)**:
   - Menutup program dengan pesan terima kasih.

---

## 🛠️ Konsep Pemrograman C++ yang Digunakan (Sesuai Silabus)

- **Input / Output Stream**: `#include <iostream>`, `cin`, `cout`, `getline()`
- **Tipe Data & Variabel**: `int`, `double`, `string`, `char`
- **Operator Aritmatika**: `*`, `-`, `+`, `%`
- **Percabangan**: `if-else` (diskon & validasi) dan `switch-case` (menu utama)
- **Perulangan**: `do-while` (menu berulang), `while` (validasi input), dan `for` (rekap & daftar tarif)
- **Array 1 Dimensi**: Menyimpan data layanan, tarif, serta riwayat transaksi (nama, layanan, berat, total bayar)

---

## 🚀 Panduan Kompilasi & Menjalankan

### Kompilasi
```bash
g++ -o laundream main.cpp
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
