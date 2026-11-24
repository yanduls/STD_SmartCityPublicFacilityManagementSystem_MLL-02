#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "petugas.h"
#include "fasilitas.h"

/*
    LIST RELASI : PENUGASAN (Petugas <-> Fasilitas Publik), relasi N to M  [MLL-02]
    Jenis List  : Singly Linked List (first saja)
    Penambahan  : INSERT FIRST
    Setiap elemen relasi menyimpan pointer ke elemen Petugas (parent)
    dan pointer ke elemen Fasilitas (child).
*/

typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    adrPetugas petugas;
    adrFasilitas fasilitas;
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

void createListRelasi(ListRelasi &L);
/* I.S. -
   F.S. Terbentuk list relasi kosong (first = NULL) */

bool isEmptyRelasi(ListRelasi L);
/* I.S. List L terdefinisi
   F.S. Mengembalikan true jika list relasi kosong, false jika tidak */

adrRelasi alokasiRelasi(adrPetugas P, adrFasilitas F);
/* I.S. P dan F tidak NULL
   F.S. Mengembalikan alamat elemen relasi baru yang menunjuk P dan F, next = NULL */

void insertFirstRelasi(ListRelasi &L, adrRelasi R);
/* I.S. List L terdefinisi (boleh kosong), R sudah dialokasi
   F.S. R menjadi elemen pertama list relasi */

adrRelasi findRelasi(ListRelasi L, adrPetugas P, adrFasilitas F);
/* I.S. List L terdefinisi
   F.S. Mengembalikan alamat relasi yang menghubungkan P dan F, NULL jika tidak ada */

int countFasilitasDariPetugas(ListRelasi L, adrPetugas P);
/* I.S. List L terdefinisi, P tidak NULL
   F.S. Mengembalikan jumlah fasilitas yang ditangani petugas P */

void showFasilitasDariPetugas(ListRelasi L, adrPetugas P);
/* I.S. List L terdefinisi, P tidak NULL
   F.S. Tampil semua fasilitas yang ditangani oleh petugas P */

void showPetugasBesertaFasilitas(ListPetugas LP, ListRelasi LR);
/* I.S. LP dan LR terdefinisi
   F.S. Tampil setiap petugas beserta jumlah dan daftar fasilitas yang ditanganinya */

#endif // RELASI_H_INCLUDED
