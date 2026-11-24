#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "relasi.h"

string inputTeks(string label);
/* I.S. -
   F.S. Menampilkan label, lalu mengembalikan satu baris input yang TIDAK kosong
        (user diminta mengulang selama input masih kosong) */

int inputAngka(string label);
/* I.S. -
   F.S. Mengembalikan bilangan bulat dari input user, atau -1 jika input bukan angka */

string inputKondisi();
/* I.S. -
   F.S. Mengembalikan "Baik", "Rusak Ringan", atau "Rusak Berat" sesuai pilihan user
        (user diminta mengulang selama pilihan tidak valid) */

void tampilMenu();
/* I.S. -
   F.S. Menu utama tampil di layar */

void menuTambahData(ListPetugas &LP, ListFasilitas &LF);
/* I.S. LP dan LF terdefinisi
   F.S. Satu petugas baru ditambahkan ke LP (insert last) atau satu fasilitas baru
        ditambahkan ke LF (insert first), jika ID belum pernah dipakai */

void menuPenugasan(ListPetugas LP, ListFasilitas LF, ListRelasi &LR);
/* I.S. LP, LF, dan LR terdefinisi
   F.S. Relasi baru antara petugas dan fasilitas ditambahkan ke LR (insert first)
        jika petugas dan fasilitas ditemukan dan belum pernah direlasikan */

void menuTampilPenugasan(ListPetugas LP, ListRelasi LR);
/* I.S. LP dan LR terdefinisi
   F.S. Tampil seluruh petugas beserta fasilitas yang ditangani masing-masing */

void prosesMenu(int pilihan, ListPetugas &LP, ListFasilitas &LF, ListRelasi &LR);
/* I.S. pilihan berisi nomor menu yang dipilih user
   F.S. Prosedur yang sesuai dengan pilihan dijalankan */

#endif // MENU_H_INCLUDED
