#include <iostream>
#include <string>
using namespace  std;

int main() {
    string username, password;
    string correctUser = "Alfath";  
    string correctPass = "026";        
    int kesempatan = 0;

    #//Login
    while (kesempatan < 3) {
        cout << "LOGIN" << endl;
        cout << "Masukkan Nama     : ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == correctUser && password == correctPass) {
            cout << "\nLogin berhasil!\n" << endl;
            break;
        } else {
            kesempatan++;
            cout << "Login salah! Kesempatan tersisa: " 
                 << 3 - kesempatan << endl << endl;
        }
    }

    if (kesempatan == 3) {
        cout << "Anda telah salah login 3 kali. Program berhenti." << endl;
        return 0;
    }

    #//Menu Utama
    int pilihan;
    double nilai;

    do {
        cout << "MENU KONVERSI" << endl;
        cout << "1. Meter -> Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer -> Meter dan Centimeter" << endl;
        cout << "3. Centimeter -> Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai dalam Meter: ";
                cin >> nilai;
                cout << "Hasil: " << nilai/1000 << " km dan "
                     << nilai*100 << " cm" << endl;
                break;

            case 2:
                cout << "Masukkan nilai dalam Kilometer: ";
                cin >> nilai;
                cout << "Hasil: " << nilai*1000 << " m dan "
                     << nilai*100000 << " cm" << endl;
                break;

            case 3:
                cout << "Masukkan nilai dalam Centimeter: ";
                cin >> nilai;
                cout << "Hasil: " << nilai/100 << " m dan "
                     << nilai/100000 << " km" << endl;
                break;

            case 4:
                cout << "Program selesai. Terima kasih!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}
