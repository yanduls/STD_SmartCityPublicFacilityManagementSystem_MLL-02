#ifndef PETUGAS_H_INCLUDED
#define PETUGAS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
    LIST PARENT : PETUGAS
    Jenis List  : Doubly Linked List (first dan last)
    Penambahan  : INSERT LAST
*/

typedef struct elmPetugas *adrPetugas;

struct infotypePetugas {
    string idPetugas;
    string nama;
    string divisi;
};

struct elmPetugas {
    infotypePetugas info;
    adrPetugas next;
    adrPetugas prev;
};

struct ListPetugas {
    adrPetugas first;
    adrPetugas last;
};

void createListPetugas(ListPetugas &L);
/* I.S. -
   F.S. Terbentuk list petugas kosong (first = NULL dan last = NULL) */

bool isEmptyPetugas(ListPetugas L);
/* I.S. List L terdefinisi
   F.S. Mengembalikan true jika list petugas kosong, false jika tidak */

adrPetugas alokasiPetugas(infotypePetugas x);
/* I.S. x berisi data petugas
   F.S. Mengembalikan alamat elemen baru berisi x, dengan next dan prev = NULL */

void insertLastPetugas(ListPetugas &L, adrPetugas P);
/* I.S. List L terdefinisi (boleh kosong), P sudah dialokasi
   F.S. P menjadi elemen terakhir list L */

adrPetugas findPetugas(ListPetugas L, string id);
/* I.S. List L terdefinisi
   F.S. Mengembalikan alamat petugas dengan idPetugas = id, NULL jika tidak ditemukan */

void printInfoPetugas(adrPetugas P);
/* I.S. P tidak NULL
   F.S. Data petugas P tampil di layar dalam satu baris */

void showAllPetugas(ListPetugas L);
/* I.S. List L terdefinisi
   F.S. Seluruh data petugas tampil di layar dari first sampai last */

#endif // PETUGAS_H_INCLUDED
