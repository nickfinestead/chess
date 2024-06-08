#include "moves.h"

#define h_delta	((destination[0] - 65) - (location[0] - 65))
#define v_delta (((destination[1] - 48) - (location[1] - 48)))



bool pawn_move(char location[3], char destination[3])
{
	// TODO: Implement two move at the start
	// TODO: Implement regular move
	// TODO: Implement En Passant
	// TODO: Implement capture logic
}



bool rook_move(char location[3], char destination[3])
{
	// TODO: Implement horizontal movement
	// TODO: Implement vertical movement
	
}


bool knight_move(char location[3], char destination[3])
{
	int dest_row = row(destination[1]);
	int dest_col = column(destination[0]);
	int curr_row = row(location[1]);
	int curr_col = column(location[0]);
	printf("hi\n");
	printf("Delta total %d\th: %d\tv:%d\n",abs(h_delta) + abs(v_delta),abs(h_delta), abs(v_delta));
	if(abs(h_delta) + abs(v_delta) != 3)
		return false;
	if(!board.table[dest_row][dest_col])
		return true;
	if(board.table[curr_row][curr_col]->color != board.table[dest_row][dest_col]->color)
		return true;
	return false;
}


bool bishop_move(char location[3], char destination[3])
{
	
	
	
}



bool queen_move(char location[3], char destination[3])
{
	
	
	
}


bool king_move(char location[3], char destination[3])
{
	
	
	
	
}