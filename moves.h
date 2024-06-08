#ifndef MOVES_H
#define MOVES_H
#include "chess.h"

#define WKING 0x265A


void move_piece(bool current_move);

bool pawn_move(char[3],void*);
bool rook_move(char[3],void*);
bool knight_move(char[3],void*);
bool bishop_move(char[3],void*);
bool queen_move(char[3],void*);
bool king_move(char[3],void*);


#endif
