Design and Documentation Questions – Lab 1

1. State the invariant your board maintains during play, in one sentence — something that is true before the first move, after every move, and at the end. Write it as a comment above your play function. (This is the invariant graded under Design and Documentation.)

ANSWER: Each location on the board is filled with one of three characters: a space, an 'X', or an 'O';
each location on the board changes state a maximum of one time (state machine representation:
space --> token = 0 or = 1); the noOfMoves counter is an integer between 0 and 9 that indicates
a 'draw' condition upon overflow. Player input and token positions are restricted to the 3x3 matrix \*/

2. Run your program and enter a move on a square that is already taken. Show me what happened and point to the line in your code that produced that behavior.

ANSWER: When amove occurs on a square that's already taken, noOfMomves does not increment (not a valid move), board is not redrawn, and current player is not switched. Terminal outputs an exception response ("That square is already taken. Try again.") and prompts current player for another move. This serves to maintain the invariant that a board location never changes state more than once.

3. Enter a move outside the board, such as 4 4. What did your program do? If it did something you did not intend, say so — naming a defect you found is worth more here than claiming there are none.

ANSWER: When a move occurs outside the board, noOfMoves does not increment (not a valid move), board is not redrawn, and current player is not switched. Terminal outputs an exception response ("Move 4 4 outside range of board") and prompts current player for another move. This helps maintain the invariant that moves never occur outside of the 3x3 board matrix.

4. Your win check runs after every move. Explain why checking only the row, column, and diagonals through the square just played would also be correct, and roughly how much work it would save.

ANSWER: My current design checks every possible win condition to see if one of them is true. This requires checking 8 possible conditions (24 basic square-checking operations) after each move. Checking only the potential win lines that include the square just played would require checking 2 to 4 win conditions after each move (6-12 basiic square-checking operations). The number of square-checking operations can be brought even lower by holding the state and location of the most recently played square in memory and reading only the two additional squares that compose each win condition.
