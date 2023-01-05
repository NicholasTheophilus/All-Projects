#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#define infoP(P) P->infoP
#define nextP(P) P->nextP
#define lombaP(P) P->lombaP
#define prevP(P) P->prevP
#define infoL(P) P->infoL
#define nextL(P) P->nextL
#define first(L) (L).first
#define last(L) (L).last

using namespace std;

struct peserta{
    string nama,univ;
    int nim,angkatan,skor,peringkat;
};

struct Lomba{
    string lomba, level;
    int angk, kuota;
};

typedef struct elemL *adrL;
typedef struct elemP *adrP;
typedef peserta infotypeP;
typedef Lomba infotypeL;

struct elemP{
    infotypeP infoP;
    adrP nextP;
    adrP prevP;
    adrL lombaP;
};

struct listP{
    adrP first,last;
};

struct elemL{
    infotypeL infoL;
    adrL nextL;
};

struct listL{
    adrL first;
};

void createListPeserta(listP &pst);

adrP createElementPeserta(infotypeP x);

void insertPeserta(listP &pst, adrP p);

void daftarLomba(listP &pst, listL lmb, string nama, string lomba);

adrP findPeserta(listP pst, string nama);

void hapusPeserta(listP &pst, listL &lmb, adrP &p, string nama);

void showAllPeserta(listP pst);

void showPesertaLomba(listL lmb, listP pst, string lomba);

void showTotalPeserta(listP pst);

void createListLomba(listL &lmb);

adrL createElementLomba(infotypeL x);

void insertLomba(listL &lmb, adrL P);

adrL findLomba(listL lmb, string lomba);

void pindahLomba(listP &pst, listL lmb, string lomba, string nama);

void hapusLomba (listL &lmb, listP &pst, adrL &p, string lomba);

void showAllLomba(listL lmb);

void showAll(listL lmb, listP pst);

void showLombaMahasiswa(listL lmb, listP pst, string nama);

int select_lomba();
#endif // TUBES_H_INCLUDED
