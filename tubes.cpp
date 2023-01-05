#include "tubes.h"

void createListPeserta(listP &pst){
    first(pst) = NULL;
    last(pst) = NULL;
}

adrP createElementPeserta(infotypeP x){
    adrP p = new elemP;
    infoP(p) = x;
    nextP(p) = NULL;
    prevP(p) = NULL;
    lombaP(p) = NULL;
    return p;
}

void insertPeserta(listP &pst, adrP p){
    if(first(pst) == NULL){
        first(pst) = p;
        last(pst) = p;
        cout << "Penginputan Peserta Telah Berhasil" << endl;
    } else {
        nextP(p) = first(pst);
        prevP(first(pst)) = p;
        first(pst) = p;
        cout << "Penginputan Peserta Telah Berhasil" << endl;
    }
}

void daftarLomba(listP &pst, listL lmb, string nama, string lomba){
    adrP x = findPeserta(pst,nama);
    adrL y = findLomba(lmb,lomba);
    if (x != NULL && y != NULL){
        if(lombaP(x) == NULL && infoP(x).angkatan == infoL(y).angk && infoL(y).kuota > 0){
            lombaP(x) = y;
            infoL(y).kuota--;
            cout << "Pendaftaran Lomba Berhasil" << endl;
        } else if (lombaP(x) != NULL){
            cout << "Tidak Bisa Mendaftar Lebih Dari 1 Lomba" << endl;
        } else {
            cout << "Pendaftaran Lomba Gagal, Silahkan Pilih Lomba Lain" << endl;
        }
    }else {
        if (x == NULL){
            cout << "Peserta Tidak Ada" << endl;
        } else if (y == NULL){
            cout << "Lomba Tidak Ada" << endl;
        }
    }
}

adrP findPeserta(listP pst, string nama){
    adrP x = first(pst);
    while (x != NULL){
        if (infoP(x).nama == nama){
            return x;
        }
        x = nextP(x);
    }
    return NULL;
}

void hapusPeserta(listP &pst, listL &lmb, adrP &p, string nama){
    adrP x = findPeserta(pst, nama);
    if (x == NULL){
        cout << "Peserta Tidak Ada" << endl;
    } else {
        if(x == NULL){
            cout << "Tidak Ada Peserta" << endl;
        } else if(nextP(x) == NULL && prevP(x) == NULL){
            p = x;
            nextP(p) = NULL;
            prevP(p) = NULL;
        } else if (prevP(x) == NULL) {
            p = x;
            first(pst) = nextP(first(pst));
            prevP(first(pst)) = NULL;
            nextP(p) = NULL;
        } else if (nextP(x) == NULL) {
            p = x;
            last(pst) = prevP(p);
            nextP(last(pst)) = NULL;
            prevP(p) = NULL;
        } else {
            adrP prec = prevP(p);
            p = x;
            nextP(prec) = nextP(p);
            prevP(nextP(p)) = prec;
            nextP(p) = NULL;
            prevP(p) = NULL;
        }
        adrL y;
        y = lombaP(p);
        infoL(y).kuota++;
        lombaP(p) = NULL;
        cout << "Penghapusan Peserta Berhasil" << endl;
    }
}

void showAllPeserta(listP pst){
    adrP x = first(pst);
    if (x == NULL){
        cout << "Belum Ada Peserta" << endl;
    } else {
        cout << "Daftar Semua Peserta" << endl;
        cout << endl;
        while (x != NULL){
            cout << "Nama: " << infoP(x).nama << endl;
            cout << "Universitas: " << infoP(x).univ << endl;
            cout << "NIM: " << infoP(x).nim << endl;
            cout << "Angkatan: " << infoP(x).angkatan << endl;
            cout << "Skor: " << infoP(x).skor << endl;
            cout << "Peringkat: " << infoP(x).peringkat << endl;
            cout << endl;
            x = nextP(x);
        }
    }
}

void showPesertaLomba(listL lmb, listP pst, string lomba){
    adrL y = findLomba(lmb, lomba);
    if (y == NULL){
        cout << "Lomba Tidak Ditemukan" << endl;
    } else {
        adrP x = first(pst);
        if(x == NULL){
            cout <<  "Tidak Ada Peserta" << endl;
        }
        else{
            int check = -1;
            while (x != NULL){
                adrL y = lombaP(x);
                if (infoL(y).lomba == lomba){
                    if(check == -1){
                        cout << "Semua Peserta Yang Mengikuti Lomba " << lomba << " adalah:" << endl << endl;
                        check++;
                    }
                    cout << "Nama: " << infoP(x).nama << endl;
                    cout << "Universitas: " << infoP(x).univ << endl;
                    cout << "NIM: " << infoP(x).nim << endl;
                    cout << "Angkatan: " << infoP(x).angkatan << endl;
                    cout << "Skor: " << infoP(x).skor << endl;
                    cout << "Peringkat: " << infoP(x).peringkat << endl;
                    cout << endl;
                }
                x = nextP(x);
            }
            if(check == -1){
                cout << "Tidak Ada Peserta Yang Mengikuti Lomba Ini" << endl;
            }
        }
    }
}

void showTotalPeserta(listP pst){
    adrP x = first(pst);
    int total = 0;
    while(x != NULL){
        total++;
        x = nextP(x);
    }
    cout << "Total Peserta: " << total << endl;
}

void createListLomba(listL &lmb){
    first(lmb) = NULL;
}

adrL createElementLomba(infotypeL x){
    adrL p = new elemL;
    infoL(p) = x;
    nextL(p) = NULL;
    return p;
}

void insertLomba(listL &lmb, adrL P){
    if(first(lmb) == NULL){
        first(lmb) = P;
        nextL(P) = first(lmb);
        cout << "Penginputan Lomba Telah Berhasil" << endl;
    } else if (nextL(first(lmb) == first(lmb))){
        nextL(first(lmb)) = P;
        nextL(P) = first(lmb);
        cout << "Penginputan Lomba Telah Berhasil" << endl;
    } else{
        adrL x = first(lmb);
        x = nextL(x);
        while(nextL(x) != first(lmb)){
            x = nextL(x);
        }
        nextL(P) = first(lmb);
        nextL(x) = P;
        cout << "Penginputan Lomba Telah Berhasil" << endl;
    }
}

adrL findLomba(listL lmb, string lomba){
    adrL x = first(lmb);
    if (infoL(x).lomba == lomba){
        return x;
    } else {
        x = nextL(x);
    }
    while (x != first(lmb)){
        if (infoL(x).lomba == lomba){
            return x;
        } else {
            x = nextL(x);
        }
    }
    return NULL;
}

void pindahLomba(listP &pst, listL lmb, string lomba, string nama){
    adrP x = findPeserta(pst,nama);
    adrL y = findLomba(lmb,lomba);
    adrL z = lombaP(x);
    if (x != NULL && y != NULL){
        if(infoL(y).kuota > 0 && infoL(y).level == infoL(z).level){
            infoL(z).kuota++;
            lombaP(x) = y;
            cout << "Pindah Lomba Berhasil" << endl;
        } else {
            cout << "Tidak Bisa Pindah Lomba" << endl;
            cout << "Silahkan Pilih Lomba Lain" << endl;
        }
    } else {
        if(x == NULL){
            cout << "Peserta Tidak Ada" << endl;
        } else  if (y == NULL){
            cout << "Lomba Tidak Ada" << endl;
        }
    }

}

void hapusLomba (listL &lmb, listP &pst, adrL &p, string lomba){
    p = findLomba(lmb, lomba);
    if (p == NULL){
        cout << "Tidak Ada Lomba Tersebut" << endl;
    }
    else{
        if(p == first(lmb)){
            if(nextL(p) == p){
                first(lmb) = NULL;
                nextL(p) = NULL;
            }else {
                adrL x = nextL(first(lmb));
                while (nextL(x) != first(lmb)){
                    x = nextL(x);
                }
                first(lmb) = nextL(first(lmb));
                nextL(x) = first(lmb);
                nextL(p) = NULL;
                cout << "Penghapusan Lomba Telah Berhasil" << endl;
                cout << "Silahkan Daftar Lomba Baru" << endl;
            }

        } else if(nextL(p) == first(lmb)){
            adrL x = first(lmb);
            while (nextL(x) != p){
                x = nextL(x);
            }
            nextL(x) = first(lmb);
            nextL(p) = NULL;
            cout << "Penghapusan Lomba Telah Berhasil" << endl;
            cout << "Silahkan Daftar Lomba Baru" << endl;
        } else {
            adrL x = first(lmb);
            while (nextL(x) != p){
                x = nextL(x);
            }
            nextL(x) = nextL(p);
            nextL(p) = NULL;
            cout << "Penghapusan Lomba Telah Berhasil" << endl;
            cout << "Silahkan Daftar Lomba Baru" << endl;
        }
    }
    adrP y = first(pst);
    while (y != NULL){
        if (lombaP(y) == p){
            lombaP(y) = NULL;
        }
        y = nextP(y);
    }
}

void showAllLomba(listL lmb){
    adrL x = first(lmb);
    if (x == NULL){
        cout << "Belum Ada Lomba" << endl;
    } else {
        cout << "Daftar Semua Lomba" << endl;
        cout << endl;
        cout << "Lomba: " << infoL(x).lomba << endl;
        cout << "Level: " << infoL(x).level << endl;
        cout << "Angkatan: " << infoL(x).angk << endl;
        cout << "Kuota: " << infoL(x).kuota << endl;
        cout << endl;
        x = nextL(x);
        while (x != first(lmb)){
            cout << "Lomba: " << infoL(x).lomba << endl;
            cout << "Level: " << infoL(x).level << endl;
            cout << "Angkatan: " << infoL(x).angk << endl;
            cout << "Kuota: " << infoL(x).kuota << endl;
            cout << endl;
            x = nextL(x);
        }
    }
}

void showAll(listL lmb, listP pst){
    adrL x = first(lmb);
    bool filled;
    if(x == NULL){
        cout << "Belum Ada Lomba" << endl;
    } else {
        cout << "Daftar Semua Lomba Beserta Pesertanya" << endl;
        do{
            filled = false;
            cout << "Lomba: " << infoL(x).lomba << endl;
            cout << "Level: " << infoL(x).level << endl;
            cout << "Angkatan: " << infoL(x).angk << endl;
            cout << "Kuota: " << infoL(x).kuota << endl;
            cout << endl;
            cout << "Diikuti Oleh: " << endl;
            adrP y = first(pst);
            while (y != NULL){
                if(lombaP(y) == x){
                    filled = true;
                    cout << "Nama: " << infoP(y).nama << endl;
                    cout << "Universitas: " << infoP(y).univ << endl;
                    cout << "NIM: " << infoP(y).nim << endl;
                    cout << "Angkatan: " << infoP(y).angkatan << endl;
                    cout << "Skor: " << infoP(y).skor << endl;
                    cout << "Peringkat: " << infoP(y).peringkat << endl << endl;
                    }
                y = nextP(y);
            }
            if(!filled){
                cout << "Tidak Ada Peserta Yang Mengikuti Lomba Ini" << endl << endl;
            }
            x = nextL(x);
        } while(x != first(lmb));
    }
}

void showLombaMahasiswa(listL lmb, listP pst, string nama){
    adrP x = findPeserta(pst, nama);
    if (x == NULL){
        cout << "Peserta Tidak Ada" << endl;
    } else {
        adrL y = lombaP(x);
        if (lombaP(x) != NULL){
            cout << nama << " Mengikuti" << endl;
            cout << "Lomba: " << infoL(y).lomba << endl;
            cout << "Level: " << infoL(y).level << endl;
            cout << "Angkatan: " << infoL(y).angk << endl;
            cout << "Kuota: " << infoL(y).kuota << endl;
        } else {
            cout << nama << " Tidak Mengikuti Lomba Apapun" << endl;
        }
    }
}

int select_lomba(){
    cout << "===========================MENU============================" << endl;
    cout << " 1.Tambah Peserta " << endl;
    cout << " 2.Tambah Lomba " << endl;
    cout << " 3.Daftar Lomba " << endl;
    cout << " 4.Pindah Lomba " << endl;
    cout << " 5.Hapus Lomba " << endl;
    cout << " 6.Hapus Peserta " << endl;
    cout << " 7.Daftar Semua Lomba " << endl;
    cout << " 8.Daftar Semua Peserta " << endl;
    cout << " 9.Daftar Lomba Beserta Pesertanya " << endl;
    cout << " 10.Tampil Peserta Tertentu Beserta Lombanya " << endl;
    cout << " 11.Daftar Peserta Yang Mengikuti Lomba Tertentu " << endl;
    cout << " 12.Total Mahasiswa Yang Mengikuti Olimpiade " << endl;
    cout << " 0.Exit " << endl;
    cout << "===========================================================" << endl;
    int input;
    cout << "Pilih Menu: ";
    cin >> input;
    return input;
}
