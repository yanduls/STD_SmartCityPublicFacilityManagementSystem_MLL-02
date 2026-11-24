#include "relasi.h"

void createListRelasi(ListRelasi &L) {
    L.first = NULL;
}

bool isEmptyRelasi(ListRelasi L) {
    return L.first == NULL;
}

adrRelasi alokasiRelasi(adrPetugas P, adrFasilitas F) {
    adrRelasi R = new elmRelasi;
    R->petugas = P;
    R->fasilitas = F;
    R->next = NULL;
    return R;
}

void insertFirstRelasi(ListRelasi &L, adrRelasi R) {
    R->next = L.first;
    L.first = R;
}

adrRelasi findRelasi(ListRelasi L, adrPetugas P, adrFasilitas F) {
    adrRelasi R = L.first;
    while (R != NULL && !(R->petugas == P && R->fasilitas == F)) {
        R = R->next;
    }
    return R;
}

int countFasilitasDariPetugas(ListRelasi L, adrPetugas P) {
    int jumlah = 0;
    adrRelasi R = L.first;
    while (R != NULL) {
        if (R->petugas == P) {
            jumlah++;
        }
        R = R->next;
    }
    return jumlah;
}

void showFasilitasDariPetugas(ListRelasi L, adrPetugas P) {
    int no = 1;
    adrRelasi R = L.first;
    while (R != NULL) {
        if (R->petugas == P) {
            cout << "     " << no << ") ";
            printInfoFasilitas(R->fasilitas);
            no++;
        }
        R = R->next;
    }
    if (no == 1) {
        cout << "     (Belum ditugaskan ke fasilitas manapun)" << endl;
    }
}

void showPetugasBesertaFasilitas(ListPetugas LP, ListRelasi LR) {
    if (isEmptyPetugas(LP)) {
        cout << "(Belum ada data petugas)" << endl;
    } else {
        adrPetugas P = LP.first;
        while (P != NULL) {
            cout << "- ";
            printInfoPetugas(P);
            cout << "  Menangani " << countFasilitasDariPetugas(LR, P) << " fasilitas:" << endl;
            showFasilitasDariPetugas(LR, P);
            P = P->next;
        }
    }
}
