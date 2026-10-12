//===========================================================================================================
// Name        : Lab 1 – Tic Tac Toe
// Author      : Kazim Zaidi
// Version     : 10/06/2026 - change: simple restart logic; pre- and postconditions added
// Description : This program runs a simple tic tac toe game;
//               simple restart logic included
//===========================================================================================================

//===========================================================================================================
/*                             Question 1 – Design and Documentation

Each location on the board is filled with one of three characters: a space, an 'X', or an 'O';
each location on the board changes state a maximum of one time (state machine representation:
space --> token = 0 or = 1); the noOfMoves counter is an integer between 0 and 9 that indicates
a 'draw' condition upon overflow. Player input and token positions are restricted to the 3x3 matrix */
//===========================================================================================================

#include <iostream>
#include "ticTacToe.h"

using namespace std;

int main()
{

  char playAgain;

  do
  {
    ticTacToe game;
    game.play();
    cout << "Would you like to play again? Type Y for 'yes' or any other letter for 'no'." << endl;
    if (cin >> playAgain)
    {
      playAgain = ((playAgain >= 'a' && playAgain <= 'z') ? playAgain - 32 : playAgain);
    }

  } while (playAgain == 'Y');

  return 0;
}

//===========================================================================================================
/*                                        AI Disclosure

I used Gemini to check my code at the end. It helped me pinpoint a few rogue semicolons and a few small bugs
(e.g. write player = switchPlayer() instead of switchPlayer() alone in the implementation file) and suggested
I create a Coordinate struct and winLine matrix to hold board position coordinates and detect win- conditions,
respectively. */
//===========================================================================================================

//===========================================================================================================
/*                                           Note

I rewrote the game logic in game.play() because I couldn't quite make sense of it. My version, however, appears
to work fine. */
//===========================================================================================================

// g++ -std=c++17 ticTacToeDriver.cpp ticTacToe.cpp -o ticTacToe && ./ticTacToe
