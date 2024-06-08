#include "chess.h"
#include "moves.h"
//#define SPACE 3
//#define spacing (for(int i = 0; i < SPACE; printf(" "), i++);)

//#define COL(a) (72 - a)
//#define ROW(b) (56 - b)

//bool POSSIBLE_ENPASSANT;
//char ENPASSANT_LOC[3];

PLAYER white;
PLAYER black;
BOARD board;


void print_board()
{
	print_header();
	for (int j = 0; j < 8; j++)
	{
		printf("%d ", 8 - j);
		for (int i = 0; i < 8; i++)
		{	
			if(((i+1)+j)%2 == 0)
				printf("\033[1;40m");
			if (board.table[j][i])
				printf(" %lc ",board.table[j][i]->value);
			else
				printf("   ");
			printf("\e[m");
			printf("|");
		}
		printf("\n");
	}

}
void create_board()
{
    //print_header();
    create_body();
}

void print_header()
{
     // This loop prints the header
	printf("   ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c   ",i+65);
    }
	printf("\n");
}

wchar_t get_code(char side, char piece)
{
    wchar_t value = 0x2654;
    if(side == 'w')
        value+=6;

    switch(piece)
    {
        case('P'):
            value++;
        case('H'):
            value++;
        case('B'):
            value++;
        case('R'):
            value++;
        case('Q'):
            value++;
    }
    return value;
}

PIECE create_piece(char *name, char loc[3], char color, wchar_t value)
{
	PIECE temp_piece;
	temp_piece.name = malloc(sizeof(char)*strlen(name) +1);
	temp_piece.name[strlen(name) +1] = '\0';
	strcpy(temp_piece.name, name);
	strcpy(temp_piece.location, loc);
	temp_piece.color = color;
	temp_piece.value = value;
	temp_piece.hasMoved = false;
	
	switch(name[0])
	{
		case 'P':
			temp_piece.move = &pawn_move;
			break;
		case 'R':
			temp_piece.move = &rook_move;
			break;
		case 'H':
			temp_piece.move = &knight_move;
			break;
		case 'B':
			temp_piece.move = &bishop_move;
			break;
		case 'Q':
			temp_piece.move = &queen_move;
			break;
		case 'K':
			temp_piece.move = &king_move;
			break;
		
	}
	
	return temp_piece;
}

void create_body()
{
	char row[][8] = {"ROOK", "HORSE", "BISHOP", "QUEEN", "KING", "BISHOP", "HORSE", "ROOK"};
	
	
	
	// Black piece setup
	for ( int j = 0; j < 2; j++)
	{	
		for ( int i = 0; i < 8; i++)
		{
			char location[3];
			location[0] = 65 + i; // column ex. A
			location[1] = 56-j; // row ex. 8
			if (j == 0)
				black.pieces[i] = create_piece(row[i], location, 'b', get_code('b',row[i][0]));
			else
				black.pieces[i+(j*8)] = create_piece("PAWN", location, 'b', get_code('b','P'));
			
			board.table[j][i] = &black.pieces[i+(j*8)];
		}
	}
	
	
	for ( int j = 0; j < 2; j++)
	{	
		for ( int i = 0; i < 8; i++)
		{
			char location[3];
			location[0] = 65 + i; // column ex. A
			location[1] = 49 + j; // row ex. 1
			if (j == 0)
				white.pieces[i] = create_piece(row[i], location, 'w', get_code('w',row[i][0]));
			else
				white.pieces[i+(j*8)] = create_piece("PAWN", location, 'w', get_code('w','P'));
			
			board.table[7-j][i] = &white.pieces[i+(j*8)];
		}
	}
}

char *handle_input(char *label, bool turn)
{
	char *input;
	input = malloc(sizeof(char) * 3); // Two characters + null byte
	char buffer[1024];
	do
	{
		printf("Please enter the %s piece's %s: ", (turn == 0) ? "white" : "black", label);
		scanf(" %s",buffer); 
		
		
	}while( buffer[0] > 'H' || buffer[0] < 'A' || buffer[1] > '8' || buffer[1] < '1' || (board.table[row(buffer[1])][column(buffer[0])] == 0 && label != "destination"));
	
	strncpy(input,buffer,2);
	input[2] = '\0';
	
	return input;
}

void move_piece(bool turn)
{
	char location[3];
	strcpy(location,handle_input("location",turn));
	char destination[3];
	strcpy(destination,handle_input("destination",turn));
	
	int dest_row = row(destination[1]), dest_col= column(destination[0]), curr_row = row(location[1]), curr_col = column(location[0]);
	
	PIECE* temp_piece = (board.table[curr_row][curr_col]);
	bool result = temp_piece->move(destination, temp_piece);

	if(result)
	{
		// Implement checking algorithm, ensure that move doesn't put opposing king in check
		board.table[dest_row][dest_col] = board.table[curr_row][curr_col];
		board.table[curr_row][curr_col] = 0x0;
		strcpy(temp_piece->location, destination);
		if(!temp_piece->hasMoved)
			temp_piece->hasMoved = true;
	}
}