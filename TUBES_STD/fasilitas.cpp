#include "fasilitas.h"

void createListFasilitas(ListFasilitas &L) {
    L.first = NULL;
}

bool isEmptyFasilitas(ListFasilitas L) {
    return L.first == NULL;
}

adrFasilitas alokasiFasilitas(infotypeFasilitas x) {
    adrFasilitas P = new elmFasilitas;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertFirstFasilitas(ListFasilitas &L, adrFasilitas P) {
    P->next = L.first;
    L.first = P;
}

adrFasilitas findFasilitas(ListFasilitas L, string id) {
    adrFasilitas P = L.first;
    while (P != NULL && P->info.idFasilitas != id) {
        P = P->next;
    }
    return P;
}

void printInfoFasilitas(adrFasilitas P) {
    cout << "[" << P->info.idFasilitas << "] " << P->info.nama
         << " (" << P->info.jenis << ") - " << P->info.lokasi
         << " - Kondisi: " << P->info.kondisi << endl;
}

void showAllFasilitas(ListFasilitas L) {
    if (isEmptyFasilitas(L)) {
        cout << "(Belum ada data fasilitas)" << endl;
    } else {
        int no = 1;
        adrFasilitas P = L.first;
        while (P != NULL) {
            cout << no << ". ";
            printInfoFasilitas(P);
            no++;
            P = P->next;
        }
    }
}
