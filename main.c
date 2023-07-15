#include <stdio.h>
#include "chess.h"


int main()
{
    char table[BODY][HEADER] = {};
    create_board(table);
    for(int j = 0; j < BODY; j++)
    {
        for(int i = 0; i < HEADER; i++)
            printf("%c", table[j][i]);
        printf("\n");
    }
    return 0;
}

