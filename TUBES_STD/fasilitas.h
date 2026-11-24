#ifndef FASILITAS_H_INCLUDED
#define FASILITAS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
    LIST CHILD  : FASILITAS PUBLIK
    Jenis List  : Singly Linked List (first saja)
    Penambahan  : INSERT FIRST
*/

typedef struct elmFasilitas *adrFasilitas;

struct infotypeFasilitas {
    string idFasilitas;
    string nama;
    string jenis;       // contoh: Taman, Halte, Toilet Umum, Lampu Jalan
    string lokasi;
    string kondisi;     // Baik / Rusak Ringan / Rusak Berat
};

struct elmFasilitas {
    infotypeFasilitas info;
    adrFasilitas next;
};

struct ListFasilitas {
    adrFasilitas first;
};

void createListFasilitas(ListFasilitas &L);
/* I.S. -
   F.S. Terbentuk list fasilitas kosong (first = NULL) */

bool isEmptyFasilitas(ListFasilitas L);
/* I.S. List L terdefinisi
   F.S. Mengembalikan true jika list fasilitas kosong, false jika tidak */

adrFasilitas alokasiFasilitas(infotypeFasilitas x);
/* I.S. x berisi data fasilitas
   F.S. Mengembalikan alamat elemen baru berisi x, dengan next = NULL */

void insertFirstFasilitas(ListFasilitas &L, adrFasilitas P);
/* I.S. List L terdefinisi (boleh kosong), P sudah dialokasi
   F.S. P menjadi elemen pertama list L */

adrFasilitas findFasilitas(ListFasilitas L, string id);
/* I.S. List L terdefinisi
   F.S. Mengembalikan alamat fasilitas dengan idFasilitas = id, NULL jika tidak ditemukan */

void printInfoFasilitas(adrFasilitas P);
/* I.S. P tidak NULL
   F.S. Data fasilitas P tampil di layar dalam satu baris */

void showAllFasilitas(ListFasilitas L);
/* I.S. List L terdefinisi
   F.S. Seluruh data fasilitas tampil di layar dari first sampai elemen terakhir */

#endif // FASILITAS_H_INCLUDED
