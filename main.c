#include <stdio.h>
#include "chess.h"
#include <locale.h>
#include <stdlib.h>


int main()
{
    setlocale(LC_CTYPE, "");
    int turn_count = 0; // even is white's turn, odd is black
	BOARD chess_table;
	
    create_board(chess_table);

    while ( 1 )
    {
        turn_count = turn_count % 2;
        print_board();
        // TODO: check for check
        move_piece(turn_count); 
        turn_count++; // Commented out occasionally to test move features for pieces other than pawns
	}
    return 0;
}

