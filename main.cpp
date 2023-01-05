#include "tubes.h"

using namespace std;

int main()
{
    listP pst;
    listL lmb;
    createListLomba(lmb);
    createListPeserta(pst);
    int Menu = select_lomba();
    while(Menu != 0){
        if (Menu == 1){
            int n;
            int i = 0;
            infotypeP p;
            cout << "Jumlah Peserta Yang Ingin Daftar: ";
            cin >> n;
            cout << endl;
            while (i < n){
                getline(cin, p.nama);
                cout << "Nama Peserta: ";
                getline(cin, p.nama) ;
                cout << "Asal Universitas: ";
                getline(cin, p.univ);
                cout << "NIM Peserta: ";
                cin >>p.nim ;
                cout << "Angkatan Peserta: ";
                cin >>p.angkatan ;
                p.skor = 0 ;
                p.peringkat = 0 ;
                adrP peserta = createElementPeserta(p);
                insertPeserta(pst, peserta);
                cout << endl;
                i++;
            }
        } else if (Menu == 2){
            infotypeL l;
            int i = 0;
            int n;
            cout << "Jumlah Lomba Yang Ingin Diinput: ";
            cin >> n;
            cout << endl;
            while (i < n){
                getline(cin, l.lomba);
                cout << "Nama Lomba: ";
                getline(cin, l.lomba) ;
                cout << "Level Lomba: ";
                getline(cin, l.level);
                cout << "Lomba Untuk Angkatan: ";
                cin >> l.angk;
                cout << "Kuota Lomba: ";
                cin >> l.kuota ;
                adrL lomba = createElementLomba(l);
                insertLomba(lmb, lomba);
                cout << endl;
                i++;
            }
        }else if (Menu == 3){
            string nama,lomba;
            getline(cin, nama);
            cout << "Nama Peserta: ";
            getline(cin, nama);
            cout << "Lomba Yang Ingin Diikuti: ";
            getline(cin, lomba);
            daftarLomba(pst,lmb,nama,lomba);
        }else if(Menu == 4){
            string lomba,nama;
            getline(cin, nama);
            cout << "Nama Peserta: ";
            getline(cin, nama);
            cout << "Lomba Baru Yang Ingin Diikuti: ";
            getline(cin, lomba);
            pindahLomba(pst,lmb,lomba,nama);
        }else if(Menu == 5){
            adrL p;
            string nama,lomba;
            getline(cin, lomba);
            cout << "Lomba Yang Ingin Dihapus: ";
            getline(cin, lomba);
            hapusLomba(lmb,pst,p,lomba);
            adrP q = first(pst);
            while(q != NULL){
                if(lombaP(q) == NULL){
                    cout << "Nama Peserta: " << infoP(q).nama << endl;
                    cout << "Lomba Baru Yang Ingin Diikuti: ";
                    getline(cin, lomba);
                    daftarLomba(pst,lmb,infoP(q).nama,lomba);
                }
                q = nextP(q);
            }
        }else if (Menu == 6){
            adrP p;
            string nama;
            getline(cin, nama);
            cout << "Nama Peserta Yang Ingin Dihapus: ";
            getline(cin, nama);
            hapusPeserta(pst,lmb,p,nama);
        }else if (Menu == 7){
            showAllLomba(lmb);
        }else if (Menu == 8){
            showAllPeserta(pst);
        }else if(Menu == 9){
            showAll(lmb,pst);
        }else if (Menu == 10){
            string nama;
            getline(cin, nama);
            cout << "Nama Mahasiswa: ";
            getline(cin, nama);
            showLombaMahasiswa(lmb, pst, nama);
        }else if (Menu == 11){
            string lomba;
            getline(cin, lomba);
            cout << "Nama Lomba Yang Ingin Ditunjukkan Pesertanya: ";
            getline(cin, lomba);
            showPesertaLomba(lmb,pst,lomba);
        } else  if (Menu == 12){
            showTotalPeserta(pst);
        } else {
            cout << "Inputan Invalid" << endl;
        }
        char x;
        cout << "Kembali Ke Menu Awal (Y/N)? ";
        cin >> x;
        if (x == 'Y'){
            Menu = select_lomba();
        } else {
            break;
        }
    }
}
