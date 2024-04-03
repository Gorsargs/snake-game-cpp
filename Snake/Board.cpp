#include "Board.h"
#include <iostream>
Board::Board()
{	
    // Accessing elements of the 2D array
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            board[i][j] = 0;
        }
    }
}
