// Program: Connect 4 game
// Author: Mariam Mohamed Ibrahim Mohamed Abdelsalam ID: 20230567
// Version: version 4.0
// Date: 03/01/2024

#include <iostream>


using namespace std;

void displayBoard(char board[6][7]);
bool insertInBoard(char board[6][7], char choice, char currentPlayer);
char checkForWinner(char board[6][7]);
bool checkIfEqual(char c1, char c2, char c3, char c4);
void displayWinner(char c);

int main(){

    char board[6][7] = {
        {'-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-'},
    };


    bool turn = false;
    char currentPlayer = 'X'; 

    displayBoard(board);

    while(true){
        if(turn){
            currentPlayer = 'O';
        }else{
            currentPlayer = 'X';
        }

        while(true){
            char choice;
            cin >> choice;
            
            

            bool isInserted = insertInBoard(board, choice, currentPlayer);

            if(isInserted) break;

            displayBoard(board);
        }
        
        char c = checkForWinner(board);
        displayWinner(c);
        if(c != '-') break;

        displayBoard(board);
        turn = !turn;
    }
}


void displayBoard(char board[6][7]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            cout << board[i][j];
            
            if(j != 6) cout << '|';
        }
        cout << '\n';
    }

    cout << "Please enter the number of column to play in: ";
}

bool insertInBoard(char board[6][7], char choice, char currentPlayer){
    if(choice < '1' || choice > '7') return false;

    int column = choice - '0';
    --column;

    for(int i = 5; i >= 0; --i){
        if(board[i][column] == '-'){
            board[i][column] = currentPlayer;
            return true;
        }
    }

    return false;
}

char checkForWinner(char board[6][7]){
    // check horizontally
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 4; ++j){
            char c1 = board[i][j];
            char c2 = board[i][j + 1];
            char c3 = board[i][j + 2];
            char c4 = board[i][j + 3];

            if(checkIfEqual(c1, c2, c3, c4) && c1 != '-'){
                return c1;
            }
        }
    }

    // check vertically
    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < 3; ++j){
            char c1 = board[j][i];
            char c2 = board[j + 1][i];
            char c3 = board[j + 2][i];
            char c4 = board[j + 3][i];

            if(checkIfEqual(c1, c2, c3, c4) && c1 != '-'){
                return c1;
            }
        }
    }

    // check diagonally
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 7; ++j){
            // left-to-right diagonal
            if(i + 3 <= 5 && j + 3 <= 6){
                char c1 = board[i][j];
                char c2 = board[i + 1][j + 1];
                char c3 = board[i + 2][j + 2];
                char c4 = board[i + 3][j + 3];

                if(checkIfEqual(c1, c2, c3, c4) && c1 != '-'){
                    return c1;
                }
            }

            // right-to-left diagonal
            if(i + 3 <= 5 && j - 3 >= 0){
                char c1 = board[i][j];
                char c2 = board[i + 1][j - 1];
                char c3 = board[i + 2][j - 2];
                char c4 = board[i + 3][j - 3];

                if(checkIfEqual(c1, c2, c3, c4) && c1 != '-'){
                    return c1;
                }
            }
        }
    }

    bool isDraw = true;
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 7; ++j){
            if(board[i][j] == '-'){
                isDraw = false;
            }
        }
    }

    if(isDraw){
        return 'D';
    }else{
        return '-';
    }
}

bool checkIfEqual(char c1, char c2, char c3, char c4){
    if(c1 == c2 && c1 == c3 && c1 == c4){
        return true;
    }
    return false;
}

void displayWinner(char c){
    if(c == 'X' || c == 'O'){
        cout << "Congratulations! you have won, player " << c << '\n';
    }else if(c == 'D'){
        cout << "There is a Draw!\n";
    }
}