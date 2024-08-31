#include <iostream>
using namespace std;

char board[3][3];  // Game board
char currentPlayer;  // Current player ('X' or 'O')

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + 3 * i + j;  // Fill the board with numbers 1 to 9
        }
    }
    currentPlayer = 'X';  // X always starts first
}

// Function to display the current game board
void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
        cout << "-------------\n";
    }
}

// Function to make a move on the board
bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;  // Position already taken
    }
}

// Function to check for a win
bool checkWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // Empty space still exists, not a draw
            }
        }
    }
    return true;
}

// Function to switch the current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main function
int main() {
    int position;
    bool gameWon = false, gameDraw = false;
    char playAgain;

    do {
        initializeBoard();
        gameWon = false;
        gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> position;

            if (position < 1 || position > 9 || !makeMove(position)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            gameWon = checkWin();
            if (!gameWon) {
                gameDraw = checkDraw();
                if (!gameDraw) {
                    switchPlayer();
                }
            }
        }

        displayBoard();

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (gameDraw) {
            cout << "The game is a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
