#pragma once
#include "chess.h"

#define WKING 0x265A

bool POSSIBLE_ENPASSANT;
char ENPASSANT_LOC[3]; 


bool isFree(wchar_t a[][HEADER], int col, int pos); // helper function

bool pawn_move(wchar_t table[][HEADER], char location[3],  char destination[3], bool color);
bool rook_move (wchar_t table[][HEADER], char location[3],  char destination[3]);
bool bishop_move(wchar_t table[][HEADER], char location[3],  char destination[3]);
bool horse_move(wchar_t table[][HEADER], char location[3],  char destination[3]);
bool queen_move(wchar_t table[][HEADER], char location[3],  char destination[3]);
bool king_move(wchar_t table[][HEADER], char location[3],  char destination[3]);


