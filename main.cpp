#include <iostream>

using namespace std;

/* 
   0 | 1 | 2
   ----------
   3 | 4 | 5
   ----------
   6 | 7 | 8
*/

void updateBoard(int board[])
{
    cout << endl;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 1) {
            cout << "X";
        }
        else if (board[i] == 2) {
            cout << "O";
        }
        else {
            cout << " ";
        }

        if (i == 2 || i == 5) {
            cout << endl;
            cout << "---------" << endl;
        }

        if (i != 2 && i != 5 && i != 8) {
            cout << " | ";
        }
    }
    cout << endl;
} // updateBoard()

bool checkWin(int board[], int player) {
    if (board[0] == player) {
        if (board[1] == player && board[2] == player) {
            // P1 wins horiz
            cout << "Player " << player << " Wins!" << endl;
            return true;
        }
        if (board[3] == player && board[6] == player) {
            // P1 wins vert 
            cout << "Player " << player << " Wins!" << endl;
            return true;
        }
        if (board[4] == player && board[8] == player) {
            // P1 wins diag
            cout << "Player " << player << " Wins!" << endl;
            return true;
        }
    }

    if (board[1] == player) {
        if (board[4] == player && board[7] == player) {
            // P1 wins vert
            cout << "Player " << player << " Wins!" << endl;
            return true;
        }
    }

    if (board[2] == player) {
        if (board[5] == player && board[8] == player) {
            // P1 wins vert
            cout << "Player " << player << " Wins!" << endl;
            return true;
        }
        if (board[4] == player && board[6] == player) {
            // P1 wins diag
            cout << "Player " << player << " Wins!" << endl;
            return true;
        }
    }

    if (board[3] == player && board[4] == player && board[5] == player) {
        // P1 wins horiz
        cout << "Player " << player << " Wins!" << endl;  
        return true;
    }

    if (board[6] == player && board[7] == player && board[8] == player) {
        // P1 wins horiz
        cout << "Player " << player << " Wins!" << endl;
        return true;
    }
    return false;
} // checkWin()

bool checkForTie(int board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            return false;
        }
    }
    return true;
} // checkForTie()

void playTurn(int playerNum, int board[]) {
    // Player 1 go
    cout << endl;
    cout << "Player " << playerNum << ": Where you wanna go?" << endl;

    int pos;
    cin >> pos;

    // Check if spot is empty or not
    while (board[pos] != 0) {
        cout << "That space is already taken, pick another one" << endl;
        cin >> pos;
    }

    board[pos] = playerNum;

    // Draw on Board
    updateBoard(board);
} // playTurn()

void clearInput() {
    cin.clear(); // clears error flag
    cin.ignore(10000, '\n'); 
} // clearInput()

int main()
{ 
    while (1) {
        cout << endl;
        cout << "Welcome to Tic Tac Toe!" << endl;

        cout << endl;
        cout << " 0 | 1 | 2 " << endl;
        cout << "-----------" << endl;
        cout << " 3 | 4 | 5 " << endl;
        cout << "-----------" << endl;
        cout << " 6 | 7 | 8 " << endl;

        // Create Empty Game Board
        int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

        // Game 
        while (1) {
            // Player 1 turn
            playTurn(1, board);

            // Check For Win
            if (checkWin(board, 1)) {
                break;
            }

            // Check for tie (can only happen with player 1)
            if (checkForTie(board)) { 
                cout << "Wow! You tied!" << endl;
                break;
            }

            // Clear input stream
            clearInput(); 

            // Player 2 turn
            playTurn(2, board);

            // Check For Win
            if (checkWin(board, 2)) {
                break;
            }

            // Clear input stream
            clearInput(); 
        }
        //Test
        // Play again?
        cout << "Wanna play again?? ('y' or 'n')" << endl;

        char playAgain;
        cin >> playAgain;

        while (playAgain != 'y' && playAgain != 'n') {
            cout << "Type 'y' or 'n'" << endl;
            cin >> playAgain;
        }

        if (playAgain == 'n') {
            break;
        }
    }
    cout << "Thanks for playing!" << endl;

    return 0;
}
