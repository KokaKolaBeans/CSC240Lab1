// Ivan Temesvari (updated by Kazim Zaidi)
// CSC 240-0C1
// Summer 2011
// May 23, 2011 (updated 10/6/26)
// This is the header file for the ticTacToe game described on p. 58
// of Lab Exercises in Data Structures with C++ by Malik 2010
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

enum status
{
    WIN,
    DRAW,
    CONTINUE
};

class ticTacToe
{
public:
    void play();
    // Function: Runs the game logic from start to finish
    // Precondition: The TicTacToe object has been initialized
    // Postcondition: A complete game of ticTacToe has been played resulting in a WIN/DRAW condition and
    //      an appropriate message displayed to the screen; noOfMoves reflects the total number of valid
    //      moves played

    void displayBoard() const;
    // Function: displayBoard()
    // Precondition: The TicTacToe object has been initialized and the .play() method has been called
    // Postcondition: The board, reflecting all valid moves executed so far, is drawn to the terminal.

    bool isValidMove(int x, int y) const;
    // Function: Determines if a valid move has been entered
    // Precondition: .play() has been called; a move is entered by player into the terminal
    // Postcondition: If the move is invalid (chooses an occupied position on the board or falls outside the board's 3x3 matrix),
    // isValidMove returns false and an appropriate error message is displayed. Else, the move is valid and isValidMove returns
    //      true.

    bool getXOMove(char moveSymbol);
    // Function: Prompts the player and places his move (if valid) on the board
    // Precondition: .play() bas been called ; current board is displayed in terminal
    // Postcondition: if player input isValidMove, places playerSymbol at board[r][c] and returns true;
    //      else board remains unchanged and returns false

    status gameStatus();
    // Function: Returns current status of the game
    // Precondition: .play() has been called and a move has been entered by player
    // Precondition: Returns WIN, CONTINUE, or DRAW

    void reStart();
    // Function: Restarts the game
    // Precondition: gameStatus returns WIN, or DRAW, indicating end of game
    // Postcondition: Board is cleared and noOfMoves = 0

    ticTacToe();
    // Function: Default constructor.
    // Postcondition: Initializes the board to an empty state.

    char switchPlayer(char current);
    // Function: Switches player from 'X' to 'O' or vice versa
    // Precondition: method .play() has initiated; playerSymbols have been chosen; gameStatus == CONTINUE or WIN;
    // Postcondition: Current player is switched

private:
    char board[3][3];
    int noOfMoves;
};

#endif
