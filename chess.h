#pragma once


#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stddef.h>
#include <stdlib.h>
// Defines the board length/height. 
// This is the only supported board currently.
#define bool unsigned char
#define HEADER 53 // 51/53
#define BODY 26 // could change to 27 to have extra spacing at bottom

#define false 0
#define true 1

extern bool POSSIBLE_ENPASSANT;
extern char ENPASSANT_LOC[3]; 


// IMPLEMENTED FUNCTIONS
void print_board(wchar_t table[][HEADER]);

int position(char a); // helper function to cleanup code

int column(char a); // helper function to cleanup code


void create_board(wchar_t table[][HEADER]); // indentation is shown to show helper functions
    void create_header(wchar_t table[][HEADER]);
    void create_body(wchar_t table[][HEADER]);
    wchar_t get_code(char side, char piece); // gets unicode for a specific peice
// Pieces can move
// TODO: Implement checks, pieces being blocked
// TODO: Implement castling
// TODO: Implement Taking Pieces
void move_piece(wchar_t table[][HEADER], bool turn); // going to validate user input and check if piece is on square.




// FUTURE IMPLEMENTATIONS
// TODO: add validation to see if piece can move
// TODO: mark spaces that are currently free with an X to indicate possible square
//          could make a new function to print the possible moves?
// TODO: Implement a game log to output file? could be cool


//void print_moves(wchar_t table[][HEADER]); // kind of tricky, not sure ab implementation yet. may not implement bc im lazy
// TODO: could use some ds or array to hold the possible amount of moves, temporarily modify array, then set it back

// TODO: Add a output file denoting the moves of the game in a certain format, possibly for evalutation?