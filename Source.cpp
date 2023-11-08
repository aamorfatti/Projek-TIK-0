#include <iostream>
#include <string>

using namespace std;

void header() {
    system("cls");
    cout << "===========================================================\n";
    cout << "== \t SELAMAT DATANG DIPENGINAPAN TENGKAWANG \t == \n";
    cout << "== \t Silahkan memilih opsi yang disedikana \t\t == \n";
    cout << "===========================================================\n";
}

void sistem_kamar(short kamar[2][6]) {
    for (short i = 1; i <= 2; i++) {
        cout << "\nruangan yang tersedia pada lantai " << i << ": \n" << endl;
        for (short j = 0; j < 6; j++) {
            if (kamar[i - 1][j] == 0) {
                cout << "kamar " << i << "0" << j << " \t: kosong" << endl;
            }
            else if (kamar[i - 1][j] == 1) {
                cout << "kamar " << i << "0" << j << " \t: terisi" << endl;
            }
            else {
                cout << "kamar " << i << "0" << j << " \t: belum siap" << endl;
            }
        }

    }
}

void check_in(string data[2][6][3], short kamarr[2][6], unsigned short input, unsigned short lantaii, unsigned short ruangann) {
   
    while (true) {                             //memilih kamar
        system("cls");
        cout << "=========================================\n=\t\t\t\t\t=\n=\t\tcheck-in\t\t=\n=\t\t\t\t\t=\n=========================================" << endl;
        sistem_kamar(kamarr);
        cout << "\nketik 0 untuk batal\npilih kamar: "; 
        
        if (!(cin >> input)) {
            // Input tidak valid
            cin.clear(); // Menghapus keadaan kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer
            cout << "\n|!!|\t masukan angka yang valid\t|!!|\n" << endl;
            system("pause");
            continue;
        }
        else if (input == 0) {
            cout << "untuk kembali, ";
            system("pause");
            break;
        }

        lantaii = input / 100;
        ruangann = input % 100;

        if (lantaii > 2 ||ruangann > 5 || lantaii == 0 ) {
            cout << "Masukan nomor kamar yang valid." << endl;
            system("pause");
            continue;
        }
        
        if (kamarr[lantaii - 1][ruangann] == 0) {       //mengecek ketersediaan kamar
            char yn;
            cout << "\nkonfirmasi kamar?\ninput(y/n): "; cin >> yn;
            if (yn == 'y') {                            //mengkonfirmasi kamar yang dipilih
                system("cls");
                cout << "\nkamar " << lantaii << "0" << ruangann << " berhasil terisi." << endl;
                kamarr[lantaii - 1][ruangann] = 1;
                //sistem_kamar(kamarr);
            }
            else if (yn == 'n') {
                cout << "untuk kembali, ";
                system("pause");
                continue;
            }
            else {
                cout << "masukan hanya huruf y dan n saja\n" << endl;
                system("pause");
                continue;
            }
        }
        else if (kamarr[lantaii - 1][ruangann] == 1) {
            cout << "\nkamar " << lantaii << "0" << ruangann << " sudah terisi. silahkan pilih kamar lain." << endl;
            system("pause");
            continue;
        }
        else {
            cout << "\nkamar " << lantaii << "0" << ruangann << " unavailable. silahkan pilih kamar lain." << endl;
            system("pause");
            continue;
        }
        
        //mengisi biodata
        unsigned short tf = 1;
        while (tf != 0) {
            cout << "\nmasukan biodata anda:" << endl;
            cin.ignore();
            cout << "nama lengkap\t: ";  getline(cin, data[lantaii - 1][ruangann][0]);
            cout << "umur Anda\t: ";  getline(cin, data[lantaii - 1][ruangann][1]);
            cout << "NIK Anda\t: ";  getline(cin, data[lantaii - 1][ruangann][2]);

            system("cls");
            cout << "konfirmasi data anda: " << endl;               // mengkonfirmasi biodata
            cout << "\nnama lengkap\t: " << data[lantaii - 1][ruangann][0] << endl;
            cout << "umur Anda\t: " << data[lantaii - 1][ruangann][1] << endl;
            cout << "NIK Anda\t: " << data[lantaii - 1][ruangann][2] << endl;
            cout << "No. kamar\t: " << lantaii << "0" << ruangann << endl;

            while (true) {
                char yn;
                cout << "\napakah data diatas sudah benar?\ninput(y/n): "; cin >> yn;
                if (yn == 'y') {
                    tf = 0;
                    system("cls");
                    cout << "data Anda:\n";
                    cout << "nama lengkap\t: " << data[lantaii - 1][ruangann][0] << endl;
                    cout << "umur Anda\t: " << data[lantaii - 1][ruangann][1] << endl;
                    cout << "NIK Anda\t: " << data[lantaii - 1][ruangann][2] << endl;
                    cout << "No. kamar\t: " << lantaii << "0" << ruangann << endl;
                    cout << "check-in berhasil dilakukan. selamat beristirahat." << endl;
                    system("pause");
                    tf = 0;
                    break;
                }
                else if (yn == 'n') {
                    system("cls");
                    break;
                }
                else {
                    cout << "masukan hanya huruf y dan n saja" << endl;
                }
            }
        }
        break;
    }

}

bool semuaKamarKosong(short kamar[2][6]) {
    for (short i = 0; i < 2; i++) {
        for (short j = 0; j < 6; j++) {
            if (kamar[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void check_out(string data[2][6][3], short kamarr[2][6], unsigned short input, unsigned short lantaii, unsigned short ruangann) {
    while (true) {          //memilih kamar
        // mengeluarkan header untuk fungsi check-out
        system("cls"); 
        cout << "=========================================\n=\t\t\t\t\t=\n=\t\tcheck-out\t\t=\n=\t\t\t\t\t=\n=========================================" << endl;
        sistem_kamar(kamarr);

        cout << "\nketik 0 untuk batal\npilih kamar : ";
        
        // mencegah input huruf
        if (!(cin >> input)) {
            cin.clear(); // Menghapus keadaan kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer
            cout << "\n|!!|\t masukan angka yang valid\t|!!|\n" << endl;
            system("pause");
            continue;
        }
        // keluar dari fungsi check-out
        else if (input == 0) {
            cout << "untuk kembali, ";
            system("pause");
            break;
        }

        lantaii = input / 100;
        ruangann = input % 100;

        // mengatasi input yang tidak ada di list
        if (lantaii > 2 || ruangann > 5 || lantaii == 0) {
            cout << "Masukan nomor kamar yang valid." << endl;
            system("pause");
            continue;
        }

        // mengecek ketersediaan kamar
        if (kamarr[lantaii - 1][ruangann] == 0) { //kamar yang kosong
            cout << "kamar " << lantaii << "0" << ruangann << " masih kosong. silahkan pilih kamar lain." << endl;
            system("pause");
            continue;
        }
        else if (kamarr[lantaii - 1][ruangann] == 1) {  // kamar yang terisi    
            char yn;

            //mengkonfirmasi kamar yang dipilih
            cout << "\nkonfirmasi kamar?\ninput(y/n): "; cin >> yn;
            
            // mengcheck-out kamar yg dipilih
            if (yn == 'y') {                            
                system("cls");
                cout << "kamar " << lantaii << "0" << ruangann << " berhasil dipilih.\n" << endl;
                kamarr[lantaii - 1][ruangann] = 0;
            }
            // membatalkan kamar yang dipilih
            else if (yn == 'n') {   
                kamarr[lantaii - 1][ruangann] = 1;
                system("pause");
                continue;
            }
            // mengatasi input yang salah
            else {
                cout << "masukan hanya huruf y dan n saja" << endl;
                continue;
            }
        }
        else { // kamar yang rusak atau dalam maintenance
            cout << "kamar " << lantaii << "0" << ruangann << " unavailable. silahkan pilih kamar lain." << endl;
            continue;
        }

        

        unsigned short tf = 1;
        while (tf != 0) {
            // mengkonfirmasi biodata
            system("cls");
            cout << "konfirmasi data anda: " << endl;
            cout << "\nnama lengkap\t: " << data[lantaii - 1][ruangann][0] << endl;
            cout << "umur Anda\t: " << data[lantaii - 1][ruangann][1] << endl;
            cout << "NIK Anda\t: " << data[lantaii - 1][ruangann][2] << endl;
            cout << "No. kamar\t: " << lantaii << "0" << ruangann << endl;

            char yn;
            cout << "\napakah data diatas sudah benar?\ninput(y/n): "; cin >> yn;

            if (yn == 'y') {
                cout << "kamar berhasil dicheck-out. terima kasih sudah menggunakan jasa kami." << endl;
                system("pause");
                break;
            }
            else if (yn == 'n') {
                kamarr[lantaii - 1][ruangann] = 1;
                tf = 0;
                continue;
            }
            else {
                cout << "masukan hanya huruf y dan n saja" << endl;
                system("pause");
                continue;
            }
        }
        break;
    }

}

// menampilkan home screen.
void menu_utama(unsigned short indikator, string data[2][6][3], short kamarr[2][6], unsigned short input, unsigned short lantaii, unsigned short ruangann) {
    unsigned short tf = 1;
    while (tf != 0){
        char mc;
        header();
        cout << "\nMENU:\n1. List kamar\n2. Check-in\n3. Check-out" << endl;
        cout << "masukan angka 1 sampai 3 untuk memilih opsi diatas. \nmasukan angka 9 untuk menutup program." << endl;
        cout << "\ninput: "; cin >> indikator;
        
        switch (indikator) {
        case 1:
            system("cls");
            cout << "=========================================\n=\t\t\t\t\t=\n=\t\t\List kamar\t\t=\n=\t\t\t\t\t=\n=========================================" << endl;
            sistem_kamar(kamarr);
            cout << "untuk kembali, ";
            system("pause");
            continue;
            
        case 2:
            check_in(data, kamarr, input, lantaii, ruangann);
            continue;

        case 3:
            if (semuaKamarKosong(kamarr)) {
                cout << "gawian lagi sepi wal, semua kamar kosong." << endl;
                system("pause");
                continue;
            }
            else {
                check_out(data, kamarr, input, lantaii, ruangann);
                continue;
            }

        case 9:
            break;

        default:
            // Input tidak valid
            cin.clear(); // Menghapus keadaan kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer
            cout << "\n|!!|\t masukan angka yang valid\t|!!|\n" << endl;
            system("pause");
            continue;
        }

        cout << "akhir dari program" << endl;
        tf = 0;    
    }
}

int main(){ 
    unsigned short lantai = 0, ruangan = 0, input_kamar = 0, indikator_menu = 0;
    short kamar[2][6] = { {0,0,0,0,0,0}, {0,0,0,0,0,0} };
    string biodata[2][6][3] = 
    {
        {
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}}
        },
        {
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}},
            {{0, 0, 0}}
        }
    };

   //sistem_kamar(kamar);
   menu_utama(indikator_menu, biodata, kamar, input_kamar, lantai, ruangan);
   // check_in(biodata, kamar, input_kamar, lantai, ruangan);
   // check_out(biodata, kamar, input_kamar, lantai, ruangan);

   return 0;
}