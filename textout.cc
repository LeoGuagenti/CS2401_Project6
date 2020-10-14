#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int board[2][7];
    board[0][6] = 3;
    board[1][0] = 10;

    for(int i = 0; i < 6; i++){
        board[0][i] = 4;
    }

    for(int j = 1; j < 7; j++){
        board[1][j] = 4;
    }

        cout << "=-------------------------------------------------------------=" << endl;
    cout << left << "|      |   " << setw(2) << board[0][0] << "  |   " << setw(2) << board[0][1] << "  |   " << setw(2) << board[0][2] << "  |   " << setw(2) << board[0][3] << "  |   " << setw(2) << board[0][4] << "  |   " << setw(2) <<  board[0][5] << "  |      |" << endl;
    cout << "|      |       |       |       |       |       |       |      |" << endl;
    cout << left << setw(2) << "|  " << board[1][0] << "  |-----------------------------------------------|  " << setw(2) << board[0][6] << "  |" << endl;
    cout << left << "|      |   " << setw(2) << board[1][1] << "  |   " << setw(2) << board[1][2] << "  |   " << setw(2) << board[1][3] << "  |   " << setw(2) << board[1][4] << "  |   " << setw(2) << board[1][5] << "  |   " << setw(2) <<  board[1][6] << "  |      |" << endl;
    cout << "|      |   A   |   B   |   C   |   D   |   E   |   F   |      |" << endl;
    cout << "=-------------------------------------------------------------=" << endl;


    return 0;
}