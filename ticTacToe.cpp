// Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip>
#include <random>
#include <limits>
#include "ticTacToe.h"

const int MIN = 0;
const int MAX = 2;

using namespace std;

void ticTacToe::play()
{
    srand(time(0)); // seed the generator from the clock
    char player;

    if (rand() % 2 == 0)
    {
        player = 'X';
    }

    else
    {
        player = 'O';
    }

    displayBoard();

    while (gameStatus() == CONTINUE) // game loop
    {

        if (getXOMove(player))
        {
            noOfMoves++;

            player = switchPlayer(player);

            displayBoard();
        }
    }

    if (gameStatus() == WIN)
    {
        player = switchPlayer(player);

        cout << "Player " << player << " wins!" << endl;
    }

    else if (gameStatus() == DRAW)
    {
        cout << "The game is a draw.";
    }
}

void ticTacToe::displayBoard() const
{
    cout << "    1   2   3"
         << endl;

    cout << setw(15) << "+---+---+---+" << endl; // representation is 13 ch

    cout << setw(3) << "1 | "
         << board[0][0] << " | "
         << board[0][1] << " | "
         << board[0][2] << " | " << endl;

    cout << setw(15) << "+---+---+---+" << endl;

    cout << setw(3) << "2 | "
         << board[1][0] << " | "
         << board[1][1] << " | "
         << board[1][2] << " | " << endl;

    cout << setw(15) << "+---+---+---+" << endl;

    cout << setw(3) << "3 | "
         << board[2][0] << " | "
         << board[2][1] << " | "
         << board[2][2] << " | " << endl;

    cout << setw(15) << "+---+---+---+" << endl;
}

bool ticTacToe::isValidMove(int row, int col) const
{
    if (col < MIN || col > MAX || row < MIN || row > MAX) // error checking for range
    {
        cout << "Move " << row + 1 << " " << col + 1 << " outside range of board" << endl;
        return false;
    }

    else if (board[row][col] != ' ') // error checking; position is already occupied
    {
        cout << "That square is already taken. Try again." << endl;
        return false;
    }
    else // square is unoccupied; move falls within range of board
    {
        return true;
    }
}

bool ticTacToe::getXOMove(char playerSymbol)
{
    int r;
    int c;
    cout << "Player " << playerSymbol << " enter move: ";
    cin >> r >> c;

    if (cin.fail()) // if cin receives more than two characters in the input, it fails
    {
        cin.clear(); // resets cin error flag so that it can be used for further operation

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore every input buffer character after the second one provided up to the newline character
        return false;                                        // end getXOMove function call; return false to the caller
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (isValidMove(r - 1, c - 1))
    {
        board[r - 1][c - 1] = playerSymbol;
        return true;
    }

    else
    {
        return false;
    }
}

status ticTacToe::gameStatus()
{
    enum status currentStatus;

    struct Coordinate // holds coordinate points to represent board positions
    {
        int row;
        int col;
    };

    /*

    The following array tracks all 8 possible win-conditions; static constexpr keywords
    used so this array does not have to be recalculated each time gameStatus() is called.

    */

    static constexpr Coordinate winLine[8][3] =
        {
            {{0, 0}, {0, 1}, {0, 2}}, // win top row
            {{1, 0}, {1, 1}, {1, 2}}, // win middle row
            {{2, 0}, {2, 1}, {2, 2}}, //  win bottom row
            {{0, 0}, {1, 0}, {2, 0}}, //  win left column
            {{0, 1}, {1, 1}, {2, 1}}, // win middle column
            {{0, 2}, {1, 2}, {2, 2}}, // win right column
            {{0, 0}, {1, 1}, {2, 2}}, // win diagonal left to right
            {{0, 2}, {1, 1}, {2, 0}}, // win diagonal right to left
    };

    for (int line = 0; line < 8; line++)
    {
        Coordinate spot1 = winLine[line][0];
        Coordinate spot2 = winLine[line][1];
        Coordinate spot3 = winLine[line][2];

        if (board[spot1.row][spot1.col] != ' ')
        {
            if ((board[spot1.row][spot1.col] == board[spot2.row][spot2.col]) && (board[spot1.row][spot1.col] == board[spot3.row][spot3.col])) // if win condition met
            {
                return WIN;
            }
        }
    }

    if (noOfMoves == 9) // board is full; previous win condition not met; no winner

    {
        return DRAW;
    }

    else // neither win nor draw condition met; continue play
    {
        return CONTINUE;
    }
}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

char ticTacToe::switchPlayer(char current)

{
    if (current == 'X')
    {
        return 'O';
    }

    else

    {
        return 'X';
    }
}