/*
    TUGAS BESAR STRUKTUR DATA
    Judul  : Smart City Public Facility Management System
    Tipe   : MLL-02 (Multi Linked List dengan List Relasi, N to M)
    Relasi : Petugas <-> Fasilitas Publik

    Anggota:
    1. Faizul 'Afiat              - 103012400356
    2. Muhammad Alfian Nurhakim   - 103012400377

    Struktur:
    - List Parent  (Petugas)   : Doubly Linked List -> insert LAST
    - List Child   (Fasilitas) : Singly Linked List -> insert FIRST
    - List Relasi  (Penugasan) : Singly Linked List -> insert FIRST
*/

#include "menu.h"

int main() {
    ListPetugas LP;
    ListFasilitas LF;
    ListRelasi LR;

    createListPetugas(LP);
    createListFasilitas(LF);
    createListRelasi(LR);

    int pilihan;
    do {
        tampilMenu();
        pilihan = inputAngka("Pilih menu: ");
        prosesMenu(pilihan, LP, LF, LR);
    } while (pilihan != 0);

    return 0;
}
