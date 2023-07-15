#pragma once


#include <stdio.h>
// Defines the board length/height. 
// This is the only supported board currently.
#define HEADER 51
#define BODY 26



void print_board(char table[][HEADER]);



void create_board(char table[][HEADER]); // indentation is shown to show helper functions
    void create_header(char table[][HEADER]);
    void create_body(char table[][HEADER]);



// TODO: add validation to see if piece can move
// TODO: mark spaces that are currently free with an X to indicate possible square
//          could make a new function to print the possible moves?
// TODO: check if right user is choosing right pieces
void move_piece(char table[][HEADER], char piece[3]); // going to validate user input and check if piece is on square.
void print_moves(char table[][HEADER], char piece[3]); // kind of tricky, not sure ab implementation yet