#include "chess.h"
#include "moves.h"

extern bool POSSIBLE_ENPASSANT = 0;
// Actually Calculates column
// TODO: Fix that
// Array is possibly allocated backwards?
int position(char a)
{
    return ((a - 65) * 6) + 5;
}

// Actually calculates position in row
// TODO: Fix that
// DONE: Fix formula to correctly calulate row number
// IN PROGRESS: Needs more testing
int column(char a)
{
    //if(a < '5')
    return (((9-(a - 48))) * 3);
    // Original return statement below
    //return (((a) - 48) * 3);
}

void print_board(wchar_t table[][HEADER], bool color)
{

    // TODO:
    /*
        - Add logic to output board from other perspective using for loop as below with if condition
      for(int j = BODY-1; j >= 0; j--)
        - Possible problem with how whitespace is outputting?
    */
    if (color == 0)
    {
        for(int j = 0; j < BODY; j++)
        {
            for(int i = 0; i < HEADER; i++)
                printf("%lc", table[j][i]);
            printf("\n");
        }
    }
    else
    {
        for(int j = BODY-1; j >= 0; j--)
        {
            for(int i = HEADER-1; i >= 0; i--)
                printf("%lc", table[j][i]);
            printf("\n");
        }
    }

}
void create_board(wchar_t table[][HEADER])
{
    create_header(table);
    create_body(table);
}

void create_header(wchar_t table[BODY][HEADER])
{
     // This loop creates the header
    for(int i = 0; i < HEADER; i++)
    {
        
        if((i + 1) % 3 == 0 && (i+1) % 6 != 0)
            table[0][i] = '|';
        else if((i+1) % 6 == 0)
            table[0][i] = (i/6) + 65;
        else
            table[0][i] = ' ';
    }
}

wchar_t get_code(char side, char piece)
{
    wchar_t value = 0x2654; // Since terminal coloring is inverted W == B and B == W
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

void create_body(wchar_t table[BODY][HEADER])
{
    
    char row[] = {'R' ,'H' ,'B' ,'K' ,'Q' , 'B', 'H', 'R'};
    
    for(int j = 1; j < BODY; j++)
    {
        for(int i = 0; i < HEADER; i++)
        {
            if((i+4) % 6 == 0)
                table[j][i] =  '|';
            else if((j-1) % 3 == 0)
                table[j][i] =  '_';
            else if(j % 3 == 0 && i == 0)
                table[j][i] = 57 - j/3;
            else if(j % 3 == 0 && (i+1) % 6 == 0 && ( j/3 <= 2 || j/3 >= 7))
            {
                if(j/3 == 1 || j/3 == 8)
                    table[j][i] = row[i/6];
                else if(j/3 == 2 || j/3 == 7)
                    table[j][i] = 'P';
                if(j/3 >= 1 && j/3 <= 2)
                    table[j][i-1] = 'b';     
                else if(j/3 >=7 && j/3 <= 8)
                    table[j][i-1] = 'w';
            }
            else
                table[j][i] = ' ';
        }
        
    }

    for(int j = 0; j < HEADER ; j++)
    {   
        
        for(int i = 0; i < HEADER; i++)
        {
            if(table[j][i] == 'b' || table[j][i] == 'w')
            {
                //printf("%lc%lc ", table[j][i], table[j][i+1]); // check [4][21]
                 table[j][i+1] = get_code(table[j][i], table[j][i+1]);
                 table[j][i] =  ' ';
            }
        }
        printf("\n");
    }
}

void move_piece(wchar_t table[][HEADER],bool turn)
{
    //int test[8][1] = {65,66,67,68,69,0};

    //printf("\n\n\'%ls\'\n\n", *test);
    char piece[3] = {};
    char move[3] = {};
    rePrompt:
        do
        {
            printf("\n\n%s please enter the position of the piece you would like to move: ", (turn == 0) ? "White" : "Black" );
            scanf(" %s", piece);
        } while(strcmp(piece,"A1") < 0 || strcmp(piece, "H8") > 0);

        int pos = position(piece[0]); // mult by 6, offset of 5 for first letter
        int col = column(piece[1]); // mult by 3

        while(isFree(table, col, pos)) // Check to see if a piece is there
        {
            printf("ERROR: No piece is at that location\nPlease reenter the location of your piece: ");
            scanf(" %s",piece);
            pos = position(piece[0]); // mult by 6, offset of 5 for first letter
            col = column(piece[1]); // mult by 3

        }
        while(table[col][pos] < 0x265A && turn == 0 || table[col][pos] > 0x265A && turn == 1) // Check to see if it is the correct color
        {
            printf("ERROR: That is the wrong color's turn to move\nPlease reenter the location of your piece: ");
            scanf(" %s", piece);
            pos = position(piece[0]); // mult by 6, offset of 5 for first letter
            col = column(piece[1]); // mult by 3
        }
        


        printf("Please enter the space you want to move to: ");
        
        scanf(" %s", move);
        int pos_tomove = position(move[0]); // mult by 6, offset of 5 for first letter
        int col_tomove = column(move[1]); // mult by 3
        while(pos_tomove == pos && col_tomove == col)
        {
            printf("ERROR: Please re-enter the position to move to: ");
            scanf(" %s", move);
            pos_tomove = position(move[0]); // mult by 6, offset of 5 for first letter
            col_tomove = column(move[1]); // mult by 3
        }
    

    
    // TODO: Refactor to work with unicode
    wchar_t piece_val = 0;
    
    piece_val = (table[col][pos]%0x2654)%6; // 0x2654 is value for a king, 6 different values for chess peices as shown in switch below.
    //printf("piece_val:%d\n", piece_val);
    //printf("piece value %d\n",piece_val);

    bool result = false;
    switch(piece_val) // will execute validation/actual move
    {
        case(5): // Pawn
            result = pawn_move(table, piece, move, turn != 0);
            break;
        case(4): // Knight
            result = horse_move(table, piece, move, turn != 0);
            break;
        case(3): // Bishop
            result = bishop_move(table, piece, move, turn != 0);
            break;
        case(2): // Rook
            result = rook_move(table, piece, move, turn != 0);
            break;
        case(1): // Queen
            result = queen_move(table, piece, move, turn != 0);
            break;
        case(0): // King
            result = king_move(table, piece, move, turn != 0);
            break;
    }

    if(result)
    {
        // TODO: Implement check to see if king is in check and input print statement here indicating king is in check.

        table[col_tomove][pos_tomove] = table[col][pos];
        table[col][pos] = ' ';

    }
    else
    {
        printf("ERROR: INVALID MOVE");
        goto rePrompt;
    }
}
