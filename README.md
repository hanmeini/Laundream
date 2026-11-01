# Laundream: Sistem Penghitungan Biaya Laundry Berbasis C++

Program CLI (Command Line Interface) berbasis C++ yang dirancang untuk membantu proses penghitungan biaya pencucian pakaian pada usaha laundry sederhana secara otomatis, akurat, dan transparan.

Proyek ini disusun untuk memenuhi tugas akhir mata kuliah **Dasar Pemrograman**, Fakultas Matematika dan Ilmu Pengetahuan Alam, **Universitas Negeri Semarang (UNNES)**.

---

## 👥 Tim Pengembang & Pembagian Tugas

| No | Nama Lengkap | NIM | Peran Utama | Rincian Tanggung Jawab & Bagian Kode |
|---|---|---|---|---|
| 1 | **Ahmad Raihan Khomeini Saputra** | `2604130073` | **Ketua Tim & Arsitek Sistem** | Menyusun kerangka program, merancang alur utama (`main()`), menu navigasi, dan manajemen repositori Git. |
| 2 | **Muhammad Dienan Akbar** | `2604130112` | **Input & Handling Transaksi** | Membuat fungsi input data pelanggan (`cin` nama, pemilihan layanan, dan berat pakaian) dengan validasi data. |
| 3 | **Aulia Ari Fadhilah** | `2604130139` | **Katalog Tarif & Perhitungan Biaya** | Mengelola representasi Array tarif/layanan, menampilkan daftar tarif, dan menghitung biaya dasar (`berat × tarif`). |
| 4 | **Salwa Thalita Azahra** | `2604130033` | **Logika Diskon & Total Bayar** | Menerapkan percabangan `if-else` untuk diskon 10% (minimal berat 5 kg) dan menghitung total pembayaran bersih. |
| 5 | **Muhammad Fakhry Abyan** | `2604130074` | **Tampilan Output & Perulangan** | Mendesain struk/ringkasan transaksi yang rapi di terminal serta logika perulangan program (`do-while` menu). |
| 6 | **Athaufa Kindi Wiratama** | `2604130114` | **Integrator, QA & Dokumentasi** | Mengintegrasikan seluruh fungsi, menguji skenario edge cases/bug fixing, serta menyusun laporan akhir dan materi presentasi. |

---

## 💡 Fitur Utama

1. **Menu Utama Interaktif**: Navigasi mudah untuk transaksi baru, cek tarif layanan, atau keluar dari program.
2. **Dua Pilihan Layanan**:
   - **Reguler**: Rp7.000 / kg
   - **Ekspres**: Rp10.000 / kg
3. **Sistem Diskon Otomatis**: Diskon **10%** otomatis aktif apabila cucian mencapai berat minimal **5 kg**.
4. **Ringkasan Transaksi (Struk Terminal)**: Menampilkan rincian nama pelanggan, jenis layanan, berat, tarif, subtotal, potongan diskon, dan total bayar.
5. **Perulangan Transaksi**: Pengguna dapat melakukan transaksi berulang tanpa perlu me-restart program.

---

## 🛠️ Konsep Pemrograman C++ yang Digunakan

- **Input / Output**: `cin`, `cout`, `getline()`
- **Tipe Data & Variabel**: `string`, `int`, `double`, `bool`
- **Operator Aritmatika**: Perkalian, pengurangan, dan persentase diskon
- **Percabangan (`if-else` & `switch-case`)**: Pengkondisian diskon dan pemilihan menu
- **Perulangan (`do-while` / `while`)**: Menjaga program tetap aktif sampai user memilih keluar
- **Array**: Menyimpan data nama layanan dan daftar tarif per kilogram

---

## 🚀 Panduan Kompilasi & Menjalankan Program

Pastikan compiler C++ (seperti MinGW GCC / G++) sudah terpasang di komputer Anda.

### 1. Kompilasi
```bash
g++ -o laundream main.cpp
```

### 2. Jalankan Program
- **Windows**:
  ```powershell
  .\laundream.exe
  ```
- **Linux / macOS**:
  ```bash
  ./laundream
  ```

---

## 🌿 Panduan Kolaborasi Git untuk Anggota Tim

Agar pengerjaan tugas bersama tidak saling tumpang tindih (menghindari *merge conflict*), ikuti alur berikut:

1. **Clone repository**:
   ```bash
   git clone https://github.com/hanmeini/Laundream.git
   cd Laundream
   ```
2. **Buat branch fitur masing-masing**:
   ```bash
   git checkout -b fitur/nama-tugas
   # Contoh: git checkout -b fitur/input-dienan
   ```
3. **Simpan perubahan dan push**:
   ```bash
   git add .
   git commit -m "feat: implementasi fungsi input data pelanggan"
   git push origin fitur/nama-tugas
   ```
4. **Merge ke branch `main`**: Dilakukan atau ditinjau oleh Ketua (Raihan) / Integrator (Athaufa) melalui Pull Request.
