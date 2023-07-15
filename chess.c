#include "chess.h"

void print_board(char table[][HEADER])
{
    for(int j = 0; j < BODY; j++)
    {
        for(int i = 0; i < HEADER; i++)
            printf("%c", table[j][i]);
        printf("\n");
    }
}
void create_board(char table[][HEADER])
{
       create_header(table);
       create_body(table);
}

void create_header(char table[BODY][HEADER])
{
     // This loop creates the header
        for(int i = 0; i < HEADER; i++)
        {
            
            if((i + 1) % 3 == 0 && (i+1) % 6 != 0)
                table[0][i] = '|';
            else if((i+1) % 6 == 0)
                table[0][i] = (i/6) + 65;
            else
                table[0][i] = ' ';
        }
}

void create_body(char table[BODY][HEADER])
{
    char row[] = {'R' ,'H' ,'B' ,'K' ,'Q' , 'B', 'H', 'R'};
    
    for(int j = 1; j < BODY; j++)
    {
        for(int i = 0; i < HEADER; i++)
        {
            if((i+4) % 6 == 0)
                table[j][i] =  '|';
            else if((j-1) % 3 == 0)
                table[j][i] =  '_';
            else if(j % 3 == 0 && i == 0)
                table[j][i] = 48 + j/3;
            else if(j % 3 == 0 && (i+1) % 6 == 0 && ( j/3 <= 2 || j/3 >= 7))
            {
                if(j/3 == 1 || j/3 == 8)
                    table[j][i] = row[i/6];
                else if(j/3 == 2 || j/3 == 7)
                    table[j][i] = 'P';
                if(j/3 >= 1 && j/3 <= 2)
                    table[j][i-1] = 'w';
                else if(j/3 >=7 && j/3 <= 8)
                    table[j][i-1] = 'b';
            }
            else
                table[j][i] = ' ';
        }
        
    }
}