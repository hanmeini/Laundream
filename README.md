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

## 📖 PANDUAN KOLABORASI GIT (METODE FORK & PULL REQUEST)

Agar seluruh anggota tim bisa mengunggah kodingan secara mandiri **tanpa terkena error izin (*Permission Denied 403*)**, kita menggunakan metode standar GitHub: **FORK & PULL REQUEST**.

---

### 1. Fork Repositori ke Akun Pribadi (WAJIB di Awal)
1. Buka repositori proyek kita di browser: **[https://github.com/hanmeini/Laundream](https://github.com/hanmeini/Laundream)**
2. Klik tombol **"Fork"** di pojok kanan atas halaman GitHub, lalu klik **"Create fork"**.
3. Sekarang kamu sudah memiliki salinan resmi repositori ini di akun GitHub-mu sendiri:  
   `https://github.com/[username-kamu]/Laundream`

---

### 2. Download (Clone) dari Repositori Fork Milikmu Sendiri
Buka terminal/CMD di laptopmu, lalu clone repositori **hasil fork kamu** (ganti `[username-kamu]` dengan username GitHub aslimu):

```bash
# Contoh jika Aulia yang clone:
git clone https://github.com/auliari/Laundream.git
cd Laundream
```
*(⚠️ Jangan clone langsung URL `hanmeini` ya, clone URL milik akunmu sendiri agar kamu punya hak akses penuh untuk push).*

---

### 3. Buat Branch Baru Sebelum Ngoding
Buat cabang (*branch*) baru sesuai bagian tugasmu:

```bash
# Untuk Dienan (Input Transaksi):
git checkout -b fitur/input-dienan

# Untuk Salwa (Diskon & Kasir):
git checkout -b fitur/diskon-salwa

# Untuk Fakhry (Struk & Cari Pelanggan):
git checkout -b fitur/struk-search-fakhry

# Untuk Aulia (Katalog Tarif):
git checkout -b fitur/tarif-aulia

# Untuk Athaufa (Rekap Penjualan & Statistik):
git checkout -b fitur/rekap-athaufa
```

---

### 4. Cara Mengerjakan Kode di `main.cpp`
1. Buka folder `Laundream` di **VS Code**.
2. Buka file **`main.cpp`**, cari nama kamu di komentar **`// TODO [Nama Kamu]`**.
3. Ketik kodingan fungsimu di area yang disediakan.
4. Jangan ubah nama fungsi atau fungsi milik teman lain agar tidak bentrok.

---

### 5. Uji Coba Kodingan di Terminal
Pastikan kodinganmu bisa dicompile dan tidak error sebelum diupload:
```bash
g++ -static -o laundream main.cpp
.\laundream.exe
```

---

### 6. Simpan & Push ke GitHub Fork Kamu
Setelah selesai ngoding dan program berjalan lancar:
```bash
git add .
git commit -m "feat: selesaikan tugas fungsi oleh [Nama Kamu]"
git push origin [nama-branch-kamu]
```
*Contoh untuk Aulia:*  
`git push origin fitur/tarif-aulia`  
*(Pasti langsung sukses 100% tanpa error 403, karena kamu push ke repo milik akunmu sendiri!)*

---

### 7. Kirim Kodingan ke Repo Utama (Buka Pull Request)
1. Buka repositori fork di akun GitHub-mu di browser (misal: `github.com/[username-kamu]/Laundream`).
2. Klik tombol **"Contribute"** $\to$ pilih **"Open pull request"**.
3. Klik tombol hijau **"Create pull request"**.
4. Beri tahu Raihan (Ketua) di WA:  
   > *"Raihan, tugasku sudah ku-pull request ya, tolong di-merge ke main!"*
5. Raihan tinggal klik tombol **"Merge pull request"** di GitHub utama untuk menyatukan kodinganmu.

---

### 💡 KHUSUS UNTUK YANG SUDAH TERLANJUR NGODING (Seperti Kasus Aulia)
Bagi yang kodenya sudah diketik dan sudah di-commit di branch lokal tapi gagal push karena error 403:
1. Buka **https://github.com/hanmeini/Laundream** di browser $\to$ klik **"Fork"**.
2. Kembali ke terminal VS Code kamu, ketik perintah ini untuk mengubah alamat upload ke repo fork kamu:
   ```bash
   # Ganti auliari dengan username GitHub kamu:
   git remote set-url origin https://github.com/[username-kamu]/Laundream.git
   ```
3. Langsung push lagi:
   ```bash
   git push origin [nama-branch-kamu]
   ```
4. Kodinganmu **tidak akan hilang sama sekali**, langsung ter-upload ke akunmu, dan tinggal ikuti **Langkah 7 (Pull Request)** di atas!

---

### 🆘 Solusi Darurat (Kalau Laptop Error Git)
1. Buka web GitHub $\to$ klik **`Code` > `Download ZIP`**.
2. Ekstrak, kerjakan fungsimu di VS Code.
3. Kirimkan potongan teks fungsimu lewat WhatsApp ke Raihan / Athaufa biar dibantu di-push ke GitHub!
