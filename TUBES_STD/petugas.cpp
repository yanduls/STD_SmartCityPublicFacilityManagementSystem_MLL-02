#include "petugas.h"

void createListPetugas(ListPetugas &L) {
    L.first = NULL;
    L.last = NULL;
}

bool isEmptyPetugas(ListPetugas L) {
    return L.first == NULL;
}

adrPetugas alokasiPetugas(infotypePetugas x) {
    adrPetugas P = new elmPetugas;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLastPetugas(ListPetugas &L, adrPetugas P) {
    if (isEmptyPetugas(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

adrPetugas findPetugas(ListPetugas L, string id) {
    adrPetugas P = L.first;
    while (P != NULL && P->info.idPetugas != id) {
        P = P->next;
    }
    return P;
}

void printInfoPetugas(adrPetugas P) {
    cout << "[" << P->info.idPetugas << "] " << P->info.nama
         << " - Divisi " << P->info.divisi << endl;
}

void showAllPetugas(ListPetugas L) {
    if (isEmptyPetugas(L)) {
        cout << "(Belum ada data petugas)" << endl;
    } else {
        int no = 1;
        adrPetugas P = L.first;
        while (P != NULL) {
            cout << no << ". ";
            printInfoPetugas(P);
            no++;
            P = P->next;
        }
    }
}
