#pragma once
#include "chess.h"

bool isFree(wchar_t a[][HEADER], int col, int pos); // helper function

bool pawn_move(wchar_t table[][HEADER], char location[3],  char destination[3]);
bool rook_move (wchar_t table[][HEADER], char location[3],  char destination[3]);
bool bishop_move(wchar_t table[][HEADER], char location[3],  char destination[3]);
bool horse_move(wchar_t table[][HEADER], char location[3],  char destination[3]);
bool queen_move(wchar_t table[][HEADER], char location[3],  char destination[3]);
bool king_move(wchar_t table[][HEADER], char location[3],  char destination[3]);


