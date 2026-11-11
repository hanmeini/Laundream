# 📖 Panduan Lengkap Git untuk Tim Laundream

Panduan praktis langkah-demi-langkah bagi anggota kelompok untuk mengunduh, mengerjakan tugas fungsi C++, dan mengunggah kode ke GitHub tanpa takut bentrok (*merge conflict*).

---

## 🔰 Istilah Sederhana yang Perlu Dipahami

- **Repository (Repo)**: Folder proyek kita yang tersimpan di GitHub.
- **Clone**: Mendownload seluruh file proyek dari GitHub ke laptop kamu.
- **Branch (Cabang)**: Ruang kerja terpisah khusus untuk kamu, agar kodinganmu tidak menimpa kodingan teman lain sebelum selesai diuji.
- **Commit**: Menyimpan catatan perubahan kode yang sudah kamu ketik.
- **Push**: Mengirimkan hasil commit dari laptopmu kembali ke GitHub online.
- **Pull Request (PR)**: Permintaan izin untuk menggabungkan cabangmu ke cabang utama (`main`) yang akan disetujui oleh Ketua (Raihan).

---

## 🛠️ Langkah 1: Persiapan di Laptop (Hanya Sekali di Awal)

### 1.1 Cek Apakah Git Sudah Terpasang
Buka **Command Prompt (CMD)** atau **PowerShell**, lalu ketik:
```bash
git --version
```
- Jika muncul tulisan seperti `git version 2.x.x`, berarti Git sudah ada di laptopmu! Langsung lanjut ke langkah 1.3.
- Jika error / command not found, download dulu Git di: 👉 **[https://git-scm.com/downloads](https://git-scm.com/downloads)** (Pilih Windows, install, dan klik *Next* sampai selesai).

### 1.2 Atur Identitas Nama & Email Kamu di Git
Ketik dua baris ini di terminal (ganti dengan nama dan email aslimu):
```bash
git config --global user.name "Nama Lengkap Kamu"
git config --global user.email "emailkamu@gmail.com"
```

### 1.3 Download (Clone) Proyek ke Laptop
Pilih folder di laptop tempat kamu biasa menyimpan tugas kuliah (misal: di folder `Documents` atau `Kuliah`), lalu ketik:
```bash
git clone https://github.com/hanmeini/Laundream.git
cd Laundream
```
Sekarang folder proyek `Laundream` sudah ada di laptopmu!

---

## 🌿 Langkah 2: Buat Branch Pribadi Sebelum Mulai Ngoding

> ⚠️ **ATURAN EMAS KELOMPOK**:  
> Jangan pernah langsung mengetik di branch `main`! Selalu buat branch sesuai nama fitur/tugasmu agar aman.

Ketik perintah berikut sesuai bagian tugasmu:

```bash
# 1. Untuk Dienan (Input Transaksi):
git checkout -b fitur/input-dienan

# 2. Untuk Salwa (Diskon & Pembayaran Kasir):
git checkout -b fitur/diskon-salwa

# 3. Untuk Fakhry (Struk & Cari Pelanggan):
git checkout -b fitur/struk-search-fakhry

# 4. Untuk Aulia (Katalog Tarif):
git checkout -b fitur/tarif-aulia

# 5. Untuk Athaufa (Rekap Penjualan & Statistik):
git checkout -b fitur/rekap-athaufa
```
*Tanda bahwa kamu sudah di branch baru: di terminal akan muncul tulisan `Switched to a new branch 'fitur/...'`.*

---

## 💻 Langkah 3: Kerjakan Tugas di File `main.cpp`

1. Buka folder `Laundream` di **VS Code** (atau text editor pilihanmu).
2. Buka file **`main.cpp`**.
3. Cari nama kamu pada bagian komentar **`// TODO [Nama Kamu]`**.
4. Ketik kodingan logikamu tepat di antara tanda:
   ```cpp
   // --- [TULIS KODE FUNGSI DI SINI] ---
   
   // ... ketik kodinganmu di sini ...
   
   // --- [SELESAI FUNGSI] ---
   ```
5. **Jangan mengubah nama fungsi, tipe data, atau bagian punya teman lain** agar kode tim tetap cocok saat disatukan!

---

## 🧪 Langkah 4: Uji Coba Program di Terminal

Sebelum dikirim ke GitHub, pastikan kodinganmu tidak error saat dijalankan:

1. Buka terminal di VS Code (**Ctrl + ~**).
2. Ketik perintah kompilasi:
   ```bash
   g++ -static -o laundream main.cpp
   ```
3. Jalankan programnya:
   ```powershell
   .\laundream.exe
   ```
4. Coba jalankan menu yang menjadi tugasmu dan pastikan hasilnya sudah sesuai harapan.

---

## 🚀 Langkah 5: Simpan & Kirim Kodingan ke GitHub

Jika kodinganmu sudah dites dan berjalan lancar, ikuti **4 langkah berurutan** ini untuk mengirimnya ke GitHub:

### 5.1 Cek File yang Berubah
```bash
git status
```
*(Akan terlihat file `main.cpp` berwarna merah/hijau yang menandakan ada perubahan).*

### 5.2 Masukkan Perubahan ke Antrean Simpan
```bash
git add .
```

### 5.3 Simpan Perubahan dengan Pesan Keterangan
```bash
git commit -m "feat: menyelesaikan fungsi [nama tugas] oleh [nama kamu]"
```
*Contoh:*
```bash
git commit -m "feat: menyelesaikan fungsi input data transaksi oleh Dienan"
```

### 5.4 Kirim (Push) ke GitHub Online
Kirim branch kamu ke GitHub:
```bash
git push origin [nama-branch-kamu]
```
*Contoh untuk Dienan:*
```bash
git push origin fitur/input-dienan
```
*(Jika baru pertama kali push, Windows mungkin akan memunculkan jendela kecil browser untuk login akun GitHub kamu. Cukup klik tombol hijau Authorize).*

---

## 🔀 Langkah 6: Kabari Ketua Kelompok (Pull Request)

Setelah selesai push:
1. Buka link repositori kita di browser: **[https://github.com/hanmeini/Laundream](https://github.com/hanmeini/Laundream)**
2. Di bagian atas web, biasanya akan muncul tombol hijau bertuliskan **"Compare & pull request"**. Klik tombol tersebut, lalu klik **"Create pull request"**.
3. Kirim pesan ke grup WA kelompok:
   > *"Raihan, tugasku di branch `[nama-branch]` sudah ku-push ke GitHub dan sudah buat Pull Request ya, tolong di-review dan di-merge!"*

Selesai! Tugas kodinganmu resmi tercatat di riwayat kontribusi kelompok di GitHub. 🎉

---

## 🔄 Tips Tambahan: Cara Mengambil Update Kode Terbaru dari Teman

Jika teman lain sudah selesai dan kodingannya sudah digabung oleh Raihan ke branch `main`, kamu bisa mengambil kodingan terbaru tersebut ke laptopmu dengan cara:

```bash
git checkout main
git pull origin main
```

---

## 🆘 Solusi Darurat (Jika Laptop Error Git atau Terlalu Ribet)

Jika ada kendala instalasi Git di laptopmu, jangan panik! Kamu tetap bisa berkontribusi dengan cara mudah ini:
1. Buka **https://github.com/hanmeini/Laundream** di browser.
2. Klik tombol hijau **`<> Code`** $\to$ pilih **`Download ZIP`**.
3. Ekstrak di laptop, buka `main.cpp`, dan kerjakan tugasmu.
4. Setelah selesai dan dites jalan, **copy teks fungsi bagianmu saja** lalu kirimkan lewat chat WhatsApp ke Raihan / Athaufa agar dimasukkan ke repositori utama!
