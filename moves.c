#include "moves.h"

// TODO: Add blocks for pieces in the way
        //  maybe add validation to see if a piece can move?

bool isFree(char a[][HEADER], int col, int pos)
{
    return a[col][pos] == ' ';
}
void pawn_move(char table[][HEADER], char location[3], char destionation[3], char color)
{
    
    if(location[1] == '2' || location[1] == '7')
    {

    }
    // TODO: Add move two at beginning
    // TODO: Add directional move based on color
}

void rook_move(char table[][HEADER], char location[3],  char destionation[3])
{
    // TODO: Add movement vertically
    // TODO: Add movement horizontally
}

void bishop_move(char table[][HEADER], char location[3],  char destionation[3])
{
    // TODO: Add movement diagonally
}

void horse_move(char table[][HEADER], char location[3],  char destionation[3])
{
    // TODO: Add movement in L shape, may just hardcode
}

void queen_move(char table[][HEADER], char location[3],  char destionation[3])
{
    // TODO: Add movement horizontally
    // TODO: Add movement vertically
    // TODO: Add movement diagonally
}

void king_move(char table[][HEADER], char location[3],  char destionation[3])
{
    // TODO: Add movement
}