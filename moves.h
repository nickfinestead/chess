#pragma once
#include "chess.h"

bool isFree(char a[][HEADER], int col, int pos); // helper function

void pawn_move(char table[][HEADER], char location[3],  char destionation[3], char color);
void rook_move (char table[][HEADER], char location[3],  char destionation[3]);
void bishop_move(char table[][HEADER], char location[3],  char destionation[3]);
void horse_move(char table[][HEADER], char location[3],  char destionation[3]);
void queen_move(char table[][HEADER], char location[3],  char destionation[3]);
void king_move(char table[][HEADER], char location[3],  char destionation[3]);


