#ifndef MOVES_H
#define MOVES_H
#include "chess.h"

#define WKING 0x265A


extern PLAYER white;
extern PLAYER black;

void move_piece(bool current_move);

bool pawn_move();
bool rook_move();
bool knight_move();
bool bishop_move();
bool queen_move();
bool king_move();


#endif
