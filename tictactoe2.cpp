#include <iostream>
using namespace std;

//membuat array 2D
char space[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

//memanggil tipe data dan nama data
int row;
int col;
bool draw;
char input = 'X';


//untuk menampilkan UI atau interface
void table() {

	cout << "===PERMAINAN TIC TAC TOE===" << endl;
	cout << "player yang bisa mendapat baris maka akan menang" << endl;
	cout << endl;
    cout << " _________________ " << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  |" << endl;
	cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << endl;

}


//untuk mengisi input user ke dalam table
void inv() {
    int digit;
    
    // Memeriksa apakah giliran saat ini adalah pemain 1 atau pemain 2 dan meminta input sesuai
    if (input == 'X') {
        cout << " Player 1(X) masukkan nomer :";
        cin >> digit;
        cout << endl;  // Menambahkan baris kosong setelah pemain memasukkan angka
        
    } else if (input == 'O') {
        cout << " Player 2(O) masukkan nomer :";
        cin >> digit;
        cout << endl;  // Menambahkan baris kosong setelah pemain memasukkan angka
    }

    // Memvalidasi input pemain, yaitu harus dalam rentang 1 hingga 9
    if (digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;  // Menghitung baris berdasarkan input pemain
        col = (digit - 1) % 3;  // Menghitung kolom berdasarkan input pemain

        // Memeriksa apakah sel di papan tersebut belum diisi
        if (space[row][col] != 'X' && space[row][col] != 'O') {
            space[row][col] = input;  // Menetapkan simbol (X atau O) ke sel papan yang sesuai
            input = (input == 'X') ? 'O' : 'X';  // Mengganti giliran pemain
        } else {
            cout << "Kotak telah diisi!" << endl;  // Jika sel sudah diisi, tampilkan pesan kesalahan
            inv();  // Panggil kembali fungsi inv untuk meminta input lagi
        }
    } else {
        cout << "input INVALID" << endl;  // Jika input tidak valid (tidak dalam rentang 1-9), tampilkan pesan kesalahan
        inv();  // Panggil kembali fungsi inv untuk meminta input lagi
    }
    
    table();  // Setelah memperbarui papan, tampilkan papan terbaru ke layar
}


//untuk mengecek keberlangsungan game dan untuk menentukan draw
bool cek() {
	
	//membuat kondisi untuk mengecek kemenangan
	
	//untuk elemen lurus
	
    for (int i = 0; i < 3; i++) {
    	
	// image screenshot
	// jika elemen 0,0 sama dengan 0,1   dan elemen 0,0 sama dengan 0,2
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || //<<- horizontal
            space[0][i] == space[1][i] && space[0][i] == space[2][i]) { // <<- vertikal
            return true;
        }
    }
    // untuk elemen diagonal
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || //line1
        space[0][2] == space[1][1] && space[1][1] == space[2][0]) { //line2
        return true;
    }
    
    //----------
    
	//untuk mengecek keberlangsungan game
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
        	// semua kondisi di cek di dalam syntax if
			// jika posisi kolom atau baris tidak ada X atau 0 maka permainan belum selesai
			// karena semua kolom atau baris harus di iisi semuanya
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }
    
	// jika kondisi tidak terpenuhi maka game seri atau draw
    draw = true;
    return true;
}


// memanggil 3 void atau functions
int main() {
	
	//loop untuk mengulang fungsi tf sampai return false
	//dan fungsi tf tetap berulang sampai player 1 atau player 2 menang
    while (!cek()) {
        table();
        inv();
        system("cls");//untuk me refresh UI
    }

	// jika yang menang adalah x dan jika draw == false maka player 1 menang
    if (input == 'O' && !draw) {
    	table();
        cout << "Hooray! Player 1(X) Menang! " << endl;
	    }
    
		// jika yang menang adalah 0 dan jika draw == false maka player 2 menang	
		else if (input == 'X' && !draw) {
			table();
	        cout << "Hooray! Player 2(O) Menang! " << endl;
		    }
    
			// jika kedua kondisi tidak terpenuhi makan game adalah draw atau seri	
			else {
				table();
 		        cout << "Game SERI!" << endl;
			    }
    
    return 0;
}

