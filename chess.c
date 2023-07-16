#include "chess.h"
#include "moves.h"

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
                    table[j][i-1] = 'b';
                else if(j/3 >=7 && j/3 <= 8)
                    table[j][i-1] = 'w';
            }
            else
                table[j][i] = ' ';
        }
        
    }
}

void move_piece(char table[][HEADER], char piece[3], bool turn)
{
    char move[3] = {};

    // while(strlen(piece) != 2 || piece[0] < 'A' || piece[0] > 'H' || piece[1] < '1' || piece[1] > '8')
    // {
    //     printf("ERROR: Invalid Piece\nPlease reenter your piece: ");
    //     scanf(" %s",piece);
    // }
    int pos = ((piece[0] - 65) * 6) + 5; // mult by 6, offset of 5 for first letter
    int col = ((piece[1] - 48) * 3); // mult by 3

    // while(table[col][pos] == ' ')
    // {
    //     printf("ERROR: No piece is at that location\nPlease reenter your piece: ")
    //     scanf(" %s",piece)
    // }
    // while(table[col][pos-1] == 'b' && turn == 0 || table[col][pos-1] == 'w' && turn == 1 )
    // {
    //     printf("ERROR: That is the wrong color's turn to move\nPlease reenter your piece: ");
    //     scanf(" %s", piece);
    // }

    printf("Please enter the space you want to move to: ");
    scanf(" %s", move);
    int pos_tomove = ((move[0] - 65) * 6) + 5; // mult by 6, offset of 5 for first letter
    int col_tomove = ((move[1] - 48) * 3); // mult by 3

    if(!isFree(table, col_tomove, pos_tomove))
    {
        // TODO: Reprompt
    }

    char piece_name = table[col][pos];

    switch(piece_name) // will execute validation/actual move
    {
        case('P'):
            break;
        case('R'):
            break;
        case('H'):
            break;
        case('B'):
            break;
        case('Q'):
            break;
        case('K'):
            break;
    }
    table[col_tomove][pos_tomove-1] = table[col][pos-1]; // lets user move whereever they want, simple swap
    table[col_tomove][pos_tomove] = table[col][pos];
    table[col][pos-1] = ' ';
    table[col][pos] = ' ';

    
}
