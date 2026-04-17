#include <iostream>
#include <string>
using namespace std;

struct Motor {
    string nama;
    int harga;
};

bool cekLogin(string user, string pass) {
    if (user == "Alfath" && pass == "026")
        return true;
    else
        return false;
}

void menu() {
    cout << endl;
    cout << "== RENTAL MOTOR PRAMUKA ==" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Tampil Data" << endl;
    cout << "3. Hapus Data" << endl;
    cout << "4. Cari Nama" << endl;
    cout << "5. Cari Harga" << endl;
    cout << "6. Hitung Mundur" << endl;
    cout << "7. List Motor" << endl;
    cout << "8. List Harga" << endl;
    cout << "9. List Harga lainnya" << endl;
    cout << "0. Keluar" << endl;
}

void tambah(Motor *m, int *jml) {

    cout << "Nama motor : ";
    cin.ignore();
    getline(cin, m[*jml].nama);

    cout << "Harga      : ";
    cin >> m[*jml].harga;

    (*jml)++;
}
void tampil(Motor *m, int jml) {

    cout << endl;
    cout << "===== DATA MOTOR =====" << endl;
    if (jml == 0) {
        cout << "Data kosong" << endl;
        return;
    }

    for (int i = 0; i < jml; i++) {
        cout << i+1 << ". "
             << (m+i)->nama
             << " - "
             << (m+i)->harga
             << endl;
    }
}

void hapus(Motor *m, int *jml) {
    int x;

    cout << "Hapus nomor : ";
    cin >> x;
    if (x > 0 && x <= *jml) {

        for (int i = x-1; i < *jml-1; i++) {
            m[i] = m[i+1];
        }

        (*jml)--;

        cout << "Data dihapus" << endl;
    }
    else {
        cout << "Input salah" << endl;
    }
}

void cari(Motor *m, int jml, string nama) {
    bool ketemu = false;

    for (int i = 0; i < jml; i++) {

        if ((m+i)->nama == nama) {
            cout << "Ketemu: "
                 << (m+i)->nama
                 << " - "
                 << (m+i)->harga
                 << endl;

            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Tidak ada data" << endl;
}

void cari(Motor *m, int jml, int harga) {
    bool ketemu = false;

    for (int i = 0; i < jml; i++) {
        if ((m+i)->harga == harga) {
            cout << "Ketemu: "
                 << (m+i)->nama
                 << " - "
                 << (m+i)->harga
                 << endl;

            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Tidak ada data" << endl;
}

void mundur(int n) {
    if (n == 0)
        return;

    cout << n << " ";
    mundur(n-1);
}

void quickSortNama(Motor data[], int low, int high) {
    int i = low;
    int j = high;

    string pivot = data[(low+high)/2].nama;
    while (i <= j) {

        while (data[i].nama > pivot) i++;

        while (data[j].nama < pivot) j--;

        if (i <= j) {
            Motor temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            i++;
            j--;
        }
    }
    if (low < j)
        quickSortNama(data, low, j);

    if (i < high)
        quickSortNama(data, i, high);
}

void insertionSortHarga(Motor data[], int n) {
    for (int i = 1; i < n; i++) {
        Motor key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j].harga > key.harga) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}

void selectionSortHarga(Motor data[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (data[j].harga < data[min].harga)
                min = j;
        }
        Motor temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}
void pause(){
    cout << endl;
    cout << "Tekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}
int main() {
    string user, pass;
    int coba = 0;

    while (coba < 3) {
        cout << "LOGIN" << endl;
        cout << "Username : ";
        cin >> user;
        cout << "Password : ";
        cin >> pass;

        if (cekLogin(user, pass)) {
            cout << "Berhasil login" << endl;
            break;
        }

        else {
            cout << "Salah!" << endl;
            coba++;
        }
    }
    if (coba == 3) {
        cout << "Gagal 3x, keluar." << endl;
        return 0;
    }

    Motor data[100];
    data[0] = {"Honda Beat", 70000};
    data[1] = {"Honda Scoopy", 85000};
    data[2] = {"Honda Vario125", 90000};
    data[3] = {"Yamaha Mio", 75000};
    data[4] = {"Yamaha Gear", 95000};
    data[5] = {"Yamaha NMAX", 150000};
    data[6] = {"Honda PCX", 160000};

    int jml = 7;
    int pilih;

do {
    menu();

    cout << "Pilih : ";
    cin >> pilih;

    if (pilih == 1){
    tambah(data, &jml);

    cout << endl << "Tekan enter untuk kembali...";
    cin.ignore();
    cin.get();
}

    else if (pilih == 2){
        tampil(data, jml);
        pause();
    }

    else if (pilih == 3){
        hapus(data, &jml);
        pause();
    }

    else if (pilih == 4){
        string n;
        cout << "Nama : ";
        cin >> n;

        cari(data, jml, n);
        pause();
    }

    else if (pilih == 5){
        int h;
        cout << "Harga : ";
        cin >> h;

        cari(data, jml, h);
        pause();
    }

    else if (pilih == 6){
        int x;
        cout << "Angka : ";
        cin >> x;

        mundur(x);
        cout << endl;
        pause();
    }

else if (pilih == 7){

    quickSortNama(data,0,jml-1);

    cout << "Data diurutkan (Nama Descending)" << endl;

    tampil(data, jml);

    pause();
}

else if (pilih == 8){

    insertionSortHarga(data,jml);

    cout << "Data diurutkan (Harga Ascending)" << endl;

    tampil(data, jml);

    pause();
}

else if (pilih == 9){

    selectionSortHarga(data,jml);

    cout << "Data diurutkan (Selection Sort)" << endl;

    tampil(data, jml);

    pause();
}
} while (pilih != 0);
return 0;
}