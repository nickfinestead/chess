# chess.c
Hi, This is a little project I decided to do because I was bored
This project started on 7/15/2023

5/24/2024
  - Added unicode chess pieces, general unicode support
  - Reworked isFree function
  - Reworked other misc error checking
  - Changed output of the board
  - Added logic to pawn movement function
  - Tested basic pawn movements
  - Added reprompt for illegal moves
  - Added extra spacing for board
  
  5/25/2024
  - Fixed Output of Board
  - Fixing Pawn movement function
  - Pawns were able to move diagonally without capturing
  - Slight logic error with pawn captures on H file which would likely cause undefined behavior
  - Consolidated conditions for pawn movement
  - Added En Passant Support
  - Added Rook logic
  - Added Knight logic
  - Added Bishop logic
  - By proxy, Added Queen logic
  - Added more input verification


Current Bugs
- King unable to move

Current Features
- (Most) Pieces move
- Captures

Untested Features
- Promotion
- Most movement functions

Future Features/tasks, TBD
- Checking mechanism
- Checkmate mechanism
- Castle'ing
- Add letter input at bottom of the board
- Add possible coloring to board
- Print Board view, based on current player.
- Refactor spaghetti code
- Possibly comment on functions IO in .c files
