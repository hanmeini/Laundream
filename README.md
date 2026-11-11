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

## 📖 PANDUAN PENGGUNAAN GIT UNTUK ANGGOTA TIM

Panduan praktis langkah-demi-langkah bagi teman-teman kelompok untuk mengambil proyek, mengerjakan fungsi C++, dan mengunggah kode ke GitHub tanpa takut bentrok (*merge conflict*):

### 1. Persiapan Awal di Laptop (Hanya Sekali)
Pastikan Git sudah terpasang di laptopmu. Cek di terminal/CMD:
```bash
git --version
```
*(Jika belum ada, download di: [https://git-scm.com/downloads](https://git-scm.com/downloads) dan install seperti biasa).*

Atur nama dan emailmu di Git:
```bash
git config --global user.name "Nama Kamu"
git config --global user.email "emailkamu@gmail.com"
```

Download proyek ke laptopmu:
```bash
git clone https://github.com/hanmeini/Laundream.git
cd Laundream
```

---

### 2. Buat Branch Baru Sebelum Ngoding (PENTING!)
> ⚠️ **JANGAN LANGSUNG NGODING DI BRANCH `main`!**  
> Buatlah cabang (*branch*) sendiri agar kodinganmu terpisah dan aman:

Ketik perintah ini sesuai dengan nama tugasmu:
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

### 3. Cara Mengerjakan Kode di `main.cpp`
1. Buka folder `Laundream` di **VS Code**.
2. Buka file **`main.cpp`**, lalu cari nama kamu di bagian komentar **`// TODO [Nama Kamu]`**.
3. Ketik kodingan fungsimu di area:
   ```cpp
   // --- [TULIS KODE FUNGSI DI SINI] ---
   
   // ... kodinganmu ...
   
   // --- [SELESAI FUNGSI] ---
   ```
4. **Perhatian:** Jangan ubah nama fungsi, tipe data parameter, atau fungsi milik teman lain ya!

---

### 4. Uji Coba Kodinganmu di Terminal
Sebelum disimpan ke GitHub, pastikan program bisa dicompile dan tidak ada error:
```bash
g++ -static -o laundream main.cpp
.\laundream.exe
```
Coba jalankan menu yang kamu buat untuk memastikan logikanya sudah berjalan benar.

---

### 5. Simpan & Kirim Kodingan ke GitHub (Setelah Selesai Ngoding)
Setelah kodinganmu selesai dan berjalan lancar, ikuti **4 perintah ini secara berurutan** di terminal:

```bash
# Langkah 5.1: Cek file yang berubah
git status

# Langkah 5.2: Masukkan perubahan ke antrean
git add .

# Langkah 5.3: Simpan perubahan dengan pesan catatan
git commit -m "feat: selesaikan tugas fungsi oleh [Nama Kamu]"

# Langkah 5.4: Kirim (Push) ke GitHub online
git push origin [nama-branch-kamu]
```
*Contoh untuk Dienan:*  
`git push origin fitur/input-dienan`

*(Catatan: Jika baru pertama kali push, biasanya akan muncul jendela browser kecil untuk login/authorize ke akun GitHub-mu, cukup klik tombol hijau Setujui).*

---

### 6. Beri Tahu Ketua (Pull Request)
1. Buka browser: **https://github.com/hanmeini/Laundream**
2. Nanti akan ada tombol hijau bertuliskan **"Compare & pull request"**. Klik tombol itu, lalu klik **"Create pull request"**.
3. Chat di grup WA:  
   > *"Raihan, tugasku di branch `[nama-branch]` sudah ku-push ke GitHub ya, tolong di-review dan digabungkan!"*

---

### 7. Cara Mengambil Update Terbaru dari Teman
Jika teman-teman lain sudah selesai dan kodingannya sudah digabung oleh Raihan ke branch `main`, kamu bisa mengambil kodingan terbaru ke laptopmu:
```bash
git checkout main
git pull origin main
```

---

### 🆘 Solusi Darurat (Kalau Laptop Error Git atau Malas Pakai Terminal)
Kalau ada kendala teknis dengan instalasi Git di laptop, jangan khawatir:
1. Buka web: **https://github.com/hanmeini/Laundream**
2. Klik tombol hijau **`<> Code`** $\to$ pilih **`Download ZIP`**.
3. Ekstrak di laptop, buka `main.cpp`, dan kerjakan fungsimu.
4. Kalau sudah beres dan jalan, cukup **copy teks fungsimu saja** lalu kirimkan lewat WhatsApp ke Raihan / Athaufa biar dibantu di-push ke GitHub!
