#pragma once
#include "chess.h"

bool isFree(wchar_t a[][HEADER], int col, int pos); // helper function

void pawn_move(wchar_t table[][HEADER], char location[3],  char destionation[3], char color);
void rook_move (wchar_t table[][HEADER], char location[3],  char destionation[3]);
void bishop_move(wchar_t table[][HEADER], char location[3],  char destionation[3]);
void horse_move(wchar_t table[][HEADER], char location[3],  char destionation[3]);
void queen_move(wchar_t table[][HEADER], char location[3],  char destionation[3]);
void king_move(wchar_t table[][HEADER], char location[3],  char destionation[3]);


