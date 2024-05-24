#include "moves.h"

// TODO: Add blocks for pieces in the way
        //  maybe add validation to see if a piece can move?

bool isFree(wchar_t a[][HEADER], int col, int pos)
{
    return a[col][pos] == ' ';
}

// TODO: Fix column() and position() functions
bool pawn_move(wchar_t table[][HEADER], char location[3], char destination[3])
{
    if(location[1] == '7'  && destination[1] < '7' && table[column(location[1])][position(location[0])] > 0x265A)
    {
        if(location[1]-destination[1] <= 2)
            return true; // indicating valid move for white pawn
        // TODO: Add possible Diagonal take.
        // TODO: Add En Passant
        else
           return false;
    }
    if(location[1] == '2'  && destination[1] > '2' && table[column(location[1])][position(location[0])] < 0x265A)
    {
        printf("loololol\n");
        if(destination[1] - location[1] <= 2)
            return true; // indicating valid move for black pawn
        // TODO: Add possible Diagonal take.
        // TODO: Add En Passant
        else
           return false;
    }

    // TODO: Add move two at beginning
    // TODO: Add directional move based on color
    // TODO: Add check if peice is blocked
    // TODO: Add diagonal capture
    // TODO: Add En Passant
    // TODO: Add Promotion?
    // TODO: Decide how to do reprompt
    //      Possibly create function for whole prompt 
    printf("test1\n");
    return false;
}

bool rook_move(wchar_t table[][HEADER], char location[3],  char destination[3])
{
    // TODO: Add movement vertically
    //          Add support for checking if path is blocked
    // TODO: Add capture vertically
    // TODO: Add movement horizontally
    //          Add support for checking if path is blocked
    // TODO: Add capture horizontally
}

bool bishop_move(wchar_t table[][HEADER], char location[3],  char destination[3])
{
    // Use current location and loop till isFree is false() or at the edge of the table?
    //     Could save possible moves in a DS, but also could just do comparison to destination
    // Base Cases
    // A1                       H1
    // 
    // TODO: Add movement diagonally
    // TODO: Add capture diagonally
}

bool horse_move(wchar_t table[][HEADER], char location[3],  char destination[3])
{
    // TODO: Add movement in L shape,
}

bool queen_move(wchar_t table[][HEADER], char location[3],  char destination[3])
{
    // Likely use combo of bishop move and rook move for simplicity
    // TODO: Add all captures
    // TODO: Add movement horizontally
    // TODO: Add movement vertically
    // TODO: Add movement diagonally
}

bool king_move(wchar_t table[][HEADER], char location[3],  char destination[3])
{
    // TODO: Add movement
    // TODO: Implement Capture
    // TODO: Possibly Implement Castle Algorithm
    // TODO: Implement Check algorithm and blocking algorithm
}