#include <stdio.h>
#include "chess.h"
#include <locale.h>
#include <stdlib.h>


int main()
{
    setlocale(LC_CTYPE, "");
    //wchar_t star = 0x265A;    
    //printf("%lc\n", star);
    int turn_count = 0; // even is white's turn, odd is black
    char piece[3] = {};
    wchar_t table[BODY][HEADER] = {};
    create_board(table);

    while ( 1 )
    {
        print_board(table);
        printf("\n\n%s please enter the position of the piece you would like to move: ", (turn_count % 2 == 0) ? "White" : "Black" );
        scanf(" %s", piece);
        move_piece(table, piece, turn_count % 2); // validates that there is a piece there
        turn_count++;
    }

   
    
    // print_moves(table, "G8", 0);
    return 0;
}

