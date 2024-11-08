#include <iostream>
using namespace std;

char board[3][3]; 
char current_marker;
int current_player;


void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}


void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}


bool placeMarker(int row, int col) {
    if (board[row][col] != ' ') {
        return false;
    }
    board[row][col] = current_marker;
    return true;
}


int checkWinner() {
   
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return current_player;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return current_player;
    }
    return 0; 
}


void switchPlayer() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }
    current_player = (current_player == 1) ? 2 : 1;
}


void game() {
    initializeBoard(); 
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_marker = marker_p1;
    current_player = 1;

    drawBoard();
    int player_won = 0;

    for (int i = 0; i < 9; ++i) {
        cout << "Player " << current_player << "'s turn. Enter row and column (1-3): ";
        int row, col;
        cin >> row >> col;
        --row; --col; 
        if (row < 0 || row > 2 || col < 0 || col > 2 || !placeMarker(row, col)) {
            cout << "Invalid move! Try again.\n";
            --i; 
            continue;
        }

        drawBoard();
        player_won = checkWinner();

        if (player_won == 1) {
            cout << "Player 1 wins! Congratulations!\n";
            break;
        } else if (player_won == 2) {
            cout << "Player 2 wins! Congratulations!\n";
            break;
        }

        switchPlayer();
    }
    if (player_won == 0) {
        cout << "It's a draw!\n";
    }
}

int main() {
    game();
    return 0;
}
