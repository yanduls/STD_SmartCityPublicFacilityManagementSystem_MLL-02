#include "menu.h"

string inputTeks(string label) {
    string s = "";
    while (s == "") {
        cout << label;
        getline(cin, s);
        if (s == "") {
            cout << "  Input tidak boleh kosong!" << endl;
        }
    }
    return s;
}

int inputAngka(string label) {
    string s;
    cout << label;
    getline(cin, s);

    int hasil = 0;
    int i = 0;
    bool valid = s.length() > 0;
    while (i < (int)s.length() && valid) {
        if (s[i] >= '0' && s[i] <= '9') {
            hasil = hasil * 10 + (s[i] - '0');
        } else {
            valid = false;
        }
        i++;
    }
    if (!valid) {
        hasil = -1;
    }
    return hasil;
}

string inputKondisi() {
    string kondisi = "";
    while (kondisi == "") {
        cout << "Kondisi (1. Baik  2. Rusak Ringan  3. Rusak Berat)" << endl;
        int k = inputAngka("Pilih kondisi : ");
        if (k == 1) {
            kondisi = "Baik";
        } else if (k == 2) {
            kondisi = "Rusak Ringan";
        } else if (k == 3) {
            kondisi = "Rusak Berat";
        } else {
            cout << "  Pilihan tidak valid!" << endl;
        }
    }
    return kondisi;
}

void tampilMenu() {
    cout << "\n=====================================================" << endl;
    cout << "  SMART CITY PUBLIC FACILITY MANAGEMENT SYSTEM" << endl;
    cout << "=====================================================" << endl;
    cout << "1. Tambah Data (Petugas / Fasilitas)" << endl;
    cout << "2. Tugaskan Petugas ke Fasilitas" << endl;
    cout << "3. Tampilkan Petugas beserta Fasilitasnya" << endl;
    cout << "0. Keluar" << endl;
    cout << "=====================================================" << endl;
}

void menuTambahData(ListPetugas &LP, ListFasilitas &LF) {
    cout << "\n--- TAMBAH DATA ---" << endl;
    cout << "1. Petugas" << endl;
    cout << "2. Fasilitas Publik" << endl;
    int jenis = inputAngka("Pilih jenis data: ");

    if (jenis == 1) {
        infotypePetugas x;
        x.idPetugas = inputTeks("ID Petugas    : ");
        if (findPetugas(LP, x.idPetugas) != NULL) {
            cout << "Gagal: ID petugas " << x.idPetugas << " sudah dipakai." << endl;
        } else {
            x.nama   = inputTeks("Nama          : ");
            x.divisi = inputTeks("Divisi        : ");
            insertLastPetugas(LP, alokasiPetugas(x));
            cout << "Petugas " << x.nama << " berhasil ditambahkan." << endl;
        }
    } else if (jenis == 2) {
        infotypeFasilitas x;
        x.idFasilitas = inputTeks("ID Fasilitas  : ");
        if (findFasilitas(LF, x.idFasilitas) != NULL) {
            cout << "Gagal: ID fasilitas " << x.idFasilitas << " sudah dipakai." << endl;
        } else {
            x.nama    = inputTeks("Nama          : ");
            x.jenis   = inputTeks("Jenis         : ");
            x.lokasi  = inputTeks("Lokasi        : ");
            x.kondisi = inputKondisi();
            insertFirstFasilitas(LF, alokasiFasilitas(x));
            cout << "Fasilitas " << x.nama << " berhasil ditambahkan." << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

void menuPenugasan(ListPetugas LP, ListFasilitas LF, ListRelasi &LR) {
    cout << "\n--- TUGASKAN PETUGAS KE FASILITAS ---" << endl;
    if (isEmptyPetugas(LP) || isEmptyFasilitas(LF)) {
        cout << "Data petugas dan fasilitas harus diisi terlebih dahulu (menu 1)." << endl;
    } else {
        cout << "Daftar Petugas:" << endl;
        showAllPetugas(LP);
        cout << "\nDaftar Fasilitas:" << endl;
        showAllFasilitas(LF);
        cout << endl;

        adrPetugas P = findPetugas(LP, inputTeks("ID Petugas    : "));
        adrFasilitas F = findFasilitas(LF, inputTeks("ID Fasilitas  : "));

        if (P == NULL) {
            cout << "Gagal: petugas tidak ditemukan." << endl;
        } else if (F == NULL) {
            cout << "Gagal: fasilitas tidak ditemukan." << endl;
        } else if (findRelasi(LR, P, F) != NULL) {
            cout << "Gagal: " << P->info.nama << " sudah ditugaskan ke "
                 << F->info.nama << "." << endl;
        } else {
            insertFirstRelasi(LR, alokasiRelasi(P, F));
            cout << "Berhasil: " << P->info.nama << " ditugaskan ke "
                 << F->info.nama << "." << endl;
        }
    }
}

void menuTampilPenugasan(ListPetugas LP, ListRelasi LR) {
    cout << "\n--- PETUGAS BESERTA FASILITAS YANG DITANGANI ---" << endl;
    showPetugasBesertaFasilitas(LP, LR);
}

void prosesMenu(int pilihan, ListPetugas &LP, ListFasilitas &LF, ListRelasi &LR) {
    if (pilihan == 1) {
        menuTambahData(LP, LF);
    } else if (pilihan == 2) {
        menuPenugasan(LP, LF, LR);
    } else if (pilihan == 3) {
        menuTampilPenugasan(LP, LR);
    } else if (pilihan == 0) {
        cout << "Terima kasih, program selesai." << endl;
    } else {
        cout << "Pilihan menu tidak valid." << endl;
    }
}
