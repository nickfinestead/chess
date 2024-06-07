#ifndef MOVES_H
#define MOVES_H
#include "chess.h"

#define WKING 0x265A


extern PLAYER white;
extern PLAYER black;
extern BOARD board;

void move_piece(bool current_move);

bool pawn_move(char location[3], char destination[3]);
bool rook_move(char location[3], char destination[3]);
bool knight_move(char location[3], char destination[3]);
bool bishop_move(char location[3], char destination[3]);
bool queen_move(char location[3], char destination[3]);
bool king_move(char location[3], char destination[3]);


#endif
