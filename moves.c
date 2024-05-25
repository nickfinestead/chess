#include "moves.h"


// TODO: Add blocks for pieces in the way
        //  maybe add validation to see if a piece can move?

bool isFree(wchar_t a[][HEADER], int col, int pos)
{
    return a[col][pos] == ' ';
}

// TODO: Fix column() and position() functions
// TODO: Do more testing for edge cases, seems to have basic functionality so far
// Color is 0 for white, 1 for black
bool pawn_move(wchar_t table[][HEADER], char location[3], char destination[3], bool color )
{
    if(location[1] > '1' && color == 0 ) // Diagonal Capture for White Pawn
    {
        if(location[0] - 1 >= 'A' && destination[0] == location[0] - 1 && table[column(destination[1])][position(destination[0])] < WKING)
            return true;
        if(location[0] - 1 <= 'H' && destination[0] == location[0] + 1 && table[column(destination[1])][position(destination[0])] < WKING)
            return true;
        // TODO: Will add White en passant here.
    }
    if(location[1] < '8' && color == 1 ) // Diagonal Capture for Black Pawn
    {
        if(location[0] - 1 >= 'A' && destination[0] == location[0] - 1 && table[column(destination[1])][position(destination[0])] > WKING)
            return true;
        if(location[0] - 1 <= 'H' && destination[0] == location[0] + 1 && table[column(destination[1])][position(destination[0])] > WKING)
            return true;
        // TODO: Will add Black en passant here.
    }
    if(destination[1] < '7' && location[0] == destination[0] &&  color == 0) // White Pawn Normal Moves
    {
        if(location[1] - destination[1] < 2)
            return isFree(table, column(location[1]-1), position(location[0]));
        else if(location[1] == '7' && location[1] - destination[1] == 2)
            return isFree(table, column(location[1]-2), position(location[0])) && isFree(table, column(location[1]-1), position(location[0]));
    }
    if( destination[1] > '2' && location[0] == destination[0] && color == 1) // Black Pawn Normal Moves
    {
        if(destination[1] - location[1] < 2)
            return isFree(table, column(location[1]+1), position(location[0]));
        else if(location[1] == '2' && destination[1] - location[1] == 2)
            return isFree(table, column(location[1]+2), position(location[0])) && isFree(table, column(location[1]+1), position(location[0]));

    }


    // TODO: Test Promotion
    if (color == 0 && destination[1] == '1' && location[1] - destination[1] < 2 && isFree(table, column(destination[1]), position(destination[0]))) // Promotion Logic WP
        table[column(destination[1])][position(destination[0])] = get_code('w','Q'); // Colors are inverted I think, further testing required
    if (color == 1 && destination[1] == '8' && destination[1]-location[1] < 2 && isFree(table, column(destination[1]), position(destination[0]))) // Promotion Logic BP
        table[column(destination[1])][position(destination[0])] = get_code('b','Q'); // Colors are inverted I think, further testing required
    

    // Done: Add move two at beginning
    // Done: Add directional move based on color
    // Done: Add check if peice is blocked
    // Done: Add diagonal capture
    // TODO: Add En Passant
    // Testing: Add Promotion?
    // Done: Decide how to do reprompt
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