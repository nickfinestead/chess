#include "moves.h"

#define h_delta	(((destination[0] - 65) - ((PIECE*)(self))->location[0] - 65))
#define v_delta (((destination[1] - 48) - (((PIECE*)(self))->location[1] - 48)))


// c is column
// r is row
bool isFree(char c, char r)
{
	return (board.table[row(r)][column(c)] == 0);
}

bool isOpponent(char c, char r, char color)
{
	if(isFree(c, r))
		return false;
	return (board.table[row(r)][column(c)]->color != color);
}


bool pawn_move(char destination[3], void *self)
{
	//printf("Delta total %d\th: %d\tv:%d\n",abs(h_delta) + abs(v_delta),abs(h_delta), abs(v_delta));
	if(h_delta > 1)
		return false;
	if(v_delta > 2 || v_delta <= 0)
		return false;
	if(((((PIECE*)self)->hasMoved == false && v_delta == 2) || v_delta == 1) && isFree(destination[0],destination[1])) 
		return true;
	if(isOpponent(destination[0],destination[1], ((PIECE*)self)->color) && abs(h_delta) == 1 && abs(v_delta) == 1)
		return true;
	
	
	// TODO: Implement En Passant
}



bool rook_move(char destination[3], void *self)
{
	// TODO: Implement horizontal movement
	// TODO: Implement vertical movement
	
}


bool knight_move(char destination[3], void *self)
{
	if(abs(h_delta) + abs(v_delta) != 3)
		return false;
	if(isOpponent(destination[0],destination[1], ((PIECE*)self)->color) || isFree(destination[0],destination[1]))
		return true;
	return false;
}


bool bishop_move(char destination[3], void *self)
{

	
	
}



bool queen_move(char destination[3], void *self)
{
	
	
	
}


bool king_move(char destination[3], void *self)
{
	
	
	
	
}