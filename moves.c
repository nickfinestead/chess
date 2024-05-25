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
    POSSIBLE_ENPASSANT = 1;
    strcpy(ENPASSANT_LOC, "D4"); // TODO: Actually set En passant values without hard coding for testing.
    // printf("test1 %d %d %d\n", location[1] > '1', color == 1, (table[column(destination[1])][position(destination[0])] > WKING || isFree(table, column(destination[1]), position(destination[0])))); // if a space is just ' ' then it is less then WKING constant
    if(location[1] > '1' && color == 1 && (table[column(destination[1])][position(destination[0])] > WKING || isFree(table, column(destination[1]), position(destination[0])))) // Diagonal Capture for Black Pawn
    {
        if((location[0] - 1 >= 'A' && destination[0] == location[0] - 1)
        || (location[0] + 1 <= 'H' && destination[0] == location[0] + 1))
        {
            if(POSSIBLE_ENPASSANT == 1 && destination[0] == ENPASSANT_LOC[0] && destination[1] == ENPASSANT_LOC[1] - 1) // Logic seems to work, needs more testing. Works when going from A -> B column and etc
            {
                if(isFree(table, column(destination[1]), position(destination[0]))) // Since capture needs to be handled here simplier to use return value in if statement to indicate capture
                {
                    table[column(ENPASSANT_LOC[1])][position(ENPASSANT_LOC[0])] = ' '; // Handles capture functionality for EN PASSANT CASE
                    return true; 
                }
            }
            return !isFree(table, column(destination[1]), position(destination[0]));
        }
        if(location[0] == destination[0]) // Black Pawn Normal Moves
        {
            // printf("if %d\n", location[1] - destination[1] < 2);
            // printf("elif %d %d\n", location[1] == '7' ,location[1] - destination[1] == 2);
            if(location[1] - destination[1] < 2)
                return isFree(table, column(location[1]-1), position(location[0]));
            else if(location[1] == '7' && location[1] - destination[1] == 2) // TODO: strcpy destination into ENPASSANT_LOC and set bool = 1
                return isFree(table, column(location[1]-2), position(location[0])) && isFree(table, column(location[1]-1), position(location[0]));
        }
    }

    if(location[1] < '8' && color == 0 && table[column(destination[1])][position(destination[0])] < WKING) // White Pawn Normal Moves
    {
        if((location[0] - 1 >= 'A' && destination[0] == location[0] - 1)
        || (location[0] + 1 <= 'H' && destination[0] == location[0] + 1))
        {
           if(POSSIBLE_ENPASSANT == 1 && destination[0] == ENPASSANT_LOC[0] && destination[1] == ENPASSANT_LOC[1] + 1) // Logic seems to work, needs more testing. Works when going from A -> B column and etc
            {
                if(isFree(table, column(destination[1]), position(destination[0]))) // Since capture needs to be handled here simplier to use return value in if statement to indicate capture
                {
                    table[column(ENPASSANT_LOC[1])][position(ENPASSANT_LOC[0])] = ' '; // Handles capture functionality for EN PASSANT CASE
                    return true; 
                }
            }
            return !isFree(table, column(destination[1]), position(destination[0]));
        }
        if(location[0] == destination[0])
        {
            if(destination[1] - location[1] < 2)
                return isFree(table, column(location[1]+1), position(location[0]));
            else if(location[1] == '2' && destination[1] - location[1] == 2)
                return isFree(table, column(location[1]+2), position(location[0])) && isFree(table, column(location[1]+1), position(location[0]));
        }
    }
    
    // IN PROGRESS: Test Promotion
    if (color == 1 && destination[1] == '1' && location[1] - destination[1] < 2 && isFree(table, column(destination[1]), position(destination[0]))) // Promotion Logic BP
        table[column(destination[1])][position(destination[0])] = get_code('w','Q'); // Colors are inverted I think, further testing required
    if (color == 0 && destination[1] == '8' && destination[1]-location[1] < 2 && isFree(table, column(destination[1]), position(destination[0]))) // Promotion Logic WP
        table[column(destination[1])][position(destination[0])] = get_code('b','Q'); // Colors are inverted I think, further testing required
    

    // Done: Add move two at beginning
    // Done: Add directional move based on color
    // Done: Add check if peice is blocked
    // Done: Add diagonal capture
    // IN PROGRESS: Add En Passant
    //          Considering adding global variable containing location of last double move to check if En passant is legal. 
    // IN PROGRESS: Add Promotion?
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