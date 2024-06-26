#include <stdio.h>
#include "chess.h"
#include <locale.h>
#include <stdlib.h>


int main()
{
    setlocale(LC_CTYPE, "");
    int turn_count = 0; // even is white's turn, odd is black
    wchar_t table[BODY][HEADER] = {65};
    create_board(table);

    while ( 1 )
    {
        turn_count = turn_count % 2;
        print_board(table, turn_count != 0);
        // TODO: check for check
        move_piece(table, turn_count); 
        turn_count++; // Commented out occasionally to test move features for pieces other than pawns
    }
    return 0;
}

