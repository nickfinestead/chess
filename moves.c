#include "moves.h"

#define h_delta	((destination[0] - 65) - (location[0] - 65))
#define v_delta (((destination[1] - 65) - (location[1] - 65)))

extern PLAYER white;
extern PLAYER black;
extern BOARD board;



bool pawn_move(char location[3], char destination[3])
{
//	char c;
	//PIECE current_piece = *board.table[][];
//	printf("Location: %s\tDestination: %s\tVertical Delta: %d\tHorizontal Delta: %d\n",location,destination,v_delta,h_delta);
//	scanf(" %c", &c);
	return true;
}



bool rook_move(char location[3], char destination[3])
{
	
	
	
}


bool knight_move(char location[3], char destination[3])
{
	
	
	
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