#include <iostream>
#include <string>
using namespace std;

// struct data motor
struct Motor {
    string nama;
    int harga;
};

// fungsi login
bool cekLogin(string user, string pass) {
    if (user == "Alfath" && pass == "026") {
        return true;
    } else {
        return false;
    }
}

// prosedur menu
void menu() {
    cout << "== RENTAL MOTOR PRAMUKA ==" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Tampil Data" << endl;
    cout << "3. Hapus Data" << endl;
    cout << "4. Cari Nama" << endl;
    cout << "5. Cari Harga" << endl;
    cout << "6. Hitung Mundur" << endl;
    cout << "0. Keluar" << endl;
}

// tambah data
void tambah(Motor m[], int &jml) {
    cout << "Nama motor : ";
    cin >> m[jml].nama;
    cout << "Harga      : ";
    cin >> m[jml].harga;
    jml++;
}

// tampil data
void tampil(Motor m[], int jml) {
    cout << "\nData Motor:\n";
    for (int i = 0; i < jml; i++) {
        cout << i+1 << ". " << m[i].nama << " - " << m[i].harga << endl;
    }
}

// hapus data
void hapus(Motor m[], int &jml) {
    int x;
    cout << "Hapus nomor : ";
    cin >> x;

    if (x > 0 && x <= jml) {
        for (int i = x-1; i < jml-1; i++) {
            m[i] = m[i+1];
        }
        jml--;
        cout << "Data dihapus";
    } else {
        cout << "Salah input";
    }
}

// overloading cari
void cari(Motor m[], int jml, string nama) {
    bool ketemu = false;
    for (int i = 0; i < jml; i++) {
        if (m[i].nama == nama) {
            cout << "Ketemu: " << m[i].nama << " - " << m[i].harga << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Tidak ada";
}

void cari(Motor m[], int jml, int harga) {
    bool ketemu = false;
    for (int i = 0; i < jml; i++) {
        if (m[i].harga == harga) {
            cout << "Ketemu: " << m[i].nama << " - " << m[i].harga << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Tidak ada";
}

// rekursif
void mundur(int n) {
    if (n == 0) return;
    cout << n << " ";
    mundur(n-1);
}

// main
int main() {
    string user, pass;
    int coba = 0;

    while (coba < 3) {
        cout << "LOGIN\n";
        cout << "Username : ";
        cin >> user;
        cout << "Password : ";
        cin >> pass;

        if (cekLogin(user, pass)) {
            cout << "Berhasil login";
            break;
        } else {
            cout << "Salah!";
            coba++;
        }
    }

    if (coba == 3) {
        cout << "Gagal 3x, keluar.";
        return 0;
    }

    Motor data[100];
    int jml = 0;
    int pilih;

    do {
        menu();
        cout << "Pilih : ";
        cin >> pilih;

        if (pilih == 1) {
            tambah(data, jml);
        } 
        else if (pilih == 2) {
            tampil(data, jml);
        } 
        else if (pilih == 3) {
            hapus(data, jml);
        } 
        else if (pilih == 4) {
            string n;
            cout << "Nama : ";
            cin >> n;
            cari(data, jml, n);
        } 
        else if (pilih == 5) {
            int h;
            cout << "Harga : ";
            cin >> h;
            cari(data, jml, h);
        } 
        else if (pilih == 6) {
            int x;
            cout << "Angka : ";
            cin >> x;
            mundur(x);
            cout << endl;
        }

    } while (pilih != 0);

    return 0;
}