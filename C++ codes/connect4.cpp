#include <iostream>
#include <vector>

using namespace std;


const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';


void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
}


bool isValidMove(const vector<vector<char>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}


void makeMove(vector<vector<char>>& board, int col, char player) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            break;
        }
    }
}


bool isBoardFull(const vector<vector<char>>& board) {
    for (int j = 0; j < COLS; ++j) {
        if (board[0][j] == EMPTY) {
            return false;
        }
    }
    return true;
}


bool checkWin(const vector<vector<char>>& board, char player) {
   
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col <= COLS - 4; ++col) {
            if (board[row][col] == player && board[row][col + 1] == player &&
                board[row][col + 2] == player && board[row][col + 3] == player) {
                return true;
            }
        }
    }

    
    for (int col = 0; col < COLS; ++col) {
        for (int row = 0; row <= ROWS - 4; ++row) {
            if (board[row][col] == player && board[row + 1][col] == player &&
                board[row + 2][col] == player && board[row + 3][col] == player) {
                return true;
            }
        }
    }

    
    for (int row = 0; row <= ROWS - 4; ++row) {
        for (int col = 0; col <= COLS - 4; ++col) {
            if (board[row][col] == player && board[row + 1][col + 1] == player &&
                board[row + 2][col + 2] == player && board[row + 3][col + 3] == player) {
                return true;
            }
        }
    }

    
    for (int row = 3; row < ROWS; ++row) {
        for (int col = 0; col <= COLS - 4; ++col) {
            if (board[row][col] == player && board[row - 1][col + 1] == player &&
                board[row - 2][col + 2] == player && board[row - 3][col + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY));
    bool player1Turn = true;

    cout << "Welcome to Connect 4!\n";

    while (true) {
        printBoard(board);

        char currentPlayer = (player1Turn) ? PLAYER1 : PLAYER2;
        cout << "Player " << currentPlayer << ", enter your move (1-7): ";
        
        int col;
        cin >> col;
        col--; 
        
        if (isValidMove(board, col)) {
            makeMove(board, col, currentPlayer);
            
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            
            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!\n";
                break;
            }
            
            player1Turn = !player1Turn; 
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}
