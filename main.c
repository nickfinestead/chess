#include <stdio.h>
#include "chess.h"


int main()
{
    char table[BODY][HEADER] = {};
    create_board(table);
    print_board(table);
    return 0;
}

