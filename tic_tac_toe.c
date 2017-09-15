/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 6 /////////////////////////////////////////////
////////////////////////////////////////////// MULTI-DIMENSIONAL ARRAYS /////////////////////////////////////////////
//////////////////////////////////////////////////// "Tic Tac Toe" //////////////////////////////////////////////////
////////////////////////////////////////////////////// Stub Code ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Replicate a tic tac toe grid using a two-dimensional char array of global scope (for ease of use)
// Define the following prototype functions in main(void) according to their specifications:
//     int printTheGrid(void);
//     int any_plays_left(void);
//     char did_someone_win(void);
//     int what_is_your_play(char currentPlayer, int gridLocation);
// Loop through those functions, in the order listed above and below, taking input until:
//     Someone wins *or*
//     There are no more selections (stalemate)
// Check for bad input (e.g., Selection 99) and reported errors (e.g., what_is_your_play() should return -1 on
//     an invalid selection)
// Direct reference to array elements (e.g., myArray[0][1]) is authorized.  In other words, pointer arithmetic
//     is not mandatory.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

/*
 * FUNCTION:   int print_the_grid(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, 1
 *             On failure, 0
 *
 * NOTES:      This function should first print out a tic tac toe legend:
 *              1 | 2 | 3
 *             -----------
 *              4 | 5 | 6
 *             -----------
 *              7 | 8 | 9
 *
 *             Then, this function should print out the current state of the 2D char array in a similar format:
 *                |   | X
 *             -----------
 *              X | O |  
 *             -----------
 *                |   |  
 */
int print_the_grid(void);

/*
 * FUNCTION:   int any_plays_left(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the number of available choices
 *             On failure, 0
 *
 * NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
 */
int any_plays_left(void);

/*
 * FUNCTION:   char did_someone_win(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
 *             On failure, 0
 *
 * NOTES:      There are 8 possible win conditions:
 *                 Top row, middle row, bottom row
 *                 Left column, middle column, right column
 *                 Backslash, "Frontslash" (TM pending)
 */
char did_someone_win(void);

/*
 * FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
 *
 * ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
 *             int gridLocation should indicate the position on the grid to place "currentPlayer" as
 *                 defined by whomever defined print_the_grid().
 *
 * RETURNS:	   On a successful choice, 1
 *             If the user chooses a location that has already been taken, 0
 *             On failure, -1
 *
 * NOTES:      Verify that gridLocation has not already been chosed before accepting the play
 *             If the play is valid, record the selection within the 2D tic tac toe array
 */
int what_is_your_play(char currentPlayer, int gridLocation);

/* TIC TAC TOE char array */
char ticTacToeGrid[3][3];

char player = 88;

int main(void)
{
	puts("Good luck to you. \n");

	for (int i = 0; i < 9; i++)
	{
		print_the_grid();
		printf("Please enter a number 1 - 9 to select a grid location.\n Player 'X' will go first.");
		what_is_your_play(player, _getch() - 48);
		system("cls");
				
		if (did_someone_win())
		{
			printf("\n");
			print_the_grid();
			break;
		}
		if (i != 8) system("cls");
		
	}
	 // Remove this

	/* PRINT THE LEGEND AND CURRENT STATUS OF THE GAME */
	//print_the_grid();

	/* DETERMINE IF THERE ARE NO MORE MOVES LEFT */
	//any_plays_left();

	/* DID SOMEONE WIN?  INFORM THE PLAYERS AND END THE GAME */
	

	/* OTHERWISE, ALLOW THE NEXT PLAYER TO MAKE A MOVE */
	//what_is_your_play();
	
	

	// NOTE:  Don't forget error checking and input validation along the way.
	getchar(); getchar();
	return 0;
}

/*
 * FUNCTION:   int printTheGrid(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, 1
 *             On failure, 0
 *
 * NOTES:      This function should first print out a tic tac toe legend:
 *              1 | 2 | 3
 *             -----------
 *              4 | 5 | 6
 *             -----------
 *              7 | 8 | 9
 *
 *             Then, this function should print out the current state of the 2D char array in a similar format:
 *                |   | X
 *             -----------
 *              X | O |
 *             -----------
 *                |   |
 */
int print_the_grid(void)
{
	int numOfSpaces = 1;
	int rows = 0;
	int columns = 0;

	printf("\n");

	for (rows = 0; rows < 3; rows++)
	{
		for (columns = 0; columns < 3; columns++)
		{
			if (columns < 2)
			{
				printf(" %d |", numOfSpaces++);
			}
			else
			{
				printf(" %d", numOfSpaces++);
			}
		}
		if (rows < 2)
		{
			printf("\n-----------\n");
		}
	}
	printf("\n\n");
	for (rows = 0; rows < 3; rows++)
	{
		for (columns = 0; columns < 3; columns++)
		{
			if (columns < 2)
			{
				printf(" %c |", ticTacToeGrid[rows][columns]);
			}
			else
			{
				printf(" %c", ticTacToeGrid[rows][columns]);
			}
		}
		if (rows < 2)
		{
			printf("\n-----------\n");
		}		
	}
	printf("\n\n");
}

/*
 * FUNCTION:   int any_plays_left(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the number of available choices
 *             On failure, 0
 *
 * NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
 */
int any_plays_left(void)
{
	
}

/*
 * FUNCTION:   char did_someone_win(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
 *             On failure, 0
 *
 * NOTES:      There are 8 possible win conditions:
 *                 Top row, middle row, bottom row
 *                 Left column, middle column, right column
 *                 Backslash, "Frontslash" (TM pending)
 */
char did_someone_win(void)
{
	if ((ticTacToeGrid[0][0] == ticTacToeGrid[0][1] && ticTacToeGrid[0][0] == ticTacToeGrid[0][2]) && (ticTacToeGrid[0][0] == 'X'))
	{
		printf("X is your winner!");
		return -1;
	}
	else if ((ticTacToeGrid[0][0] == ticTacToeGrid[0][1] && ticTacToeGrid[0][0] == ticTacToeGrid[0][2]) && (ticTacToeGrid[0][0] == 'O'))
	{
		printf("O is your winner!");
		return -1;
	}
	// horizontal check row 0
	if ( (ticTacToeGrid[0][0] == ticTacToeGrid[0][1] && ticTacToeGrid[0][0] == ticTacToeGrid[0][2]) && (ticTacToeGrid[0][0] == 'X') )
	{
		printf("X is your winner!");
		return -1;
	}
	else if ( (ticTacToeGrid[0][0] == ticTacToeGrid[0][1] && ticTacToeGrid[0][0] == ticTacToeGrid[0][2]) && (ticTacToeGrid[0][0] == 'O') )
	{
		printf("O is your winner!");
		return -1;
	}
	// horizontal check row 1
	if ( (ticTacToeGrid[1][0] == ticTacToeGrid[1][1] && ticTacToeGrid[1][0] == ticTacToeGrid[1][2]) && (ticTacToeGrid[1][0] == 'X') )
	{
		printf("X is your winner!");
		return -1;
	}
	else if ( (ticTacToeGrid[1][0] == ticTacToeGrid[1][1] && ticTacToeGrid[1][0] == ticTacToeGrid[1][2]) && (ticTacToeGrid[1][0] == 'O') )
	{
		printf("O is your winner!");
		return -1;
	}
	// horizontal check row 2
	if ( (ticTacToeGrid[2][0] == ticTacToeGrid[2][1] && ticTacToeGrid[2][0] == ticTacToeGrid[2][2]) && (ticTacToeGrid[2][0] == 'X') )
	{
		printf("X is your winner!");
		return -1;
	}
	else if ( (ticTacToeGrid[2][0] == ticTacToeGrid[2][1] && ticTacToeGrid[2][0] == ticTacToeGrid[2][2]) && (ticTacToeGrid[2][0] == 'O') )
	{
		printf("O is your winner!");
		return -1;
	}
	//vertical check column 0
	if ( (ticTacToeGrid[0][0] == ticTacToeGrid[1][0] && ticTacToeGrid[0][0] == ticTacToeGrid[2][0]) && (ticTacToeGrid[0][0] == 'X') )
	{
		printf("X is your winner!");
		return -1;
	}
	else if ( (ticTacToeGrid[0][0] == ticTacToeGrid[1][0] && ticTacToeGrid[0][0] == ticTacToeGrid[2][0]) && (ticTacToeGrid[0][0] == 'O') )
	{
		printf("O is your winner!");
		return -1;
	}
	//vertical check column 1
	if ( (ticTacToeGrid[0][1] == ticTacToeGrid[1][1] &&ticTacToeGrid[0][1] == ticTacToeGrid[2][1]) && (ticTacToeGrid[0][1] == 'X') )
	{
		printf("X is your winner!");
		return -1;
	}
	else if ((ticTacToeGrid[0][1] == ticTacToeGrid[1][1] && ticTacToeGrid[0][1] == ticTacToeGrid[2][1]) && (ticTacToeGrid[0][1] == 'O'))
	{
		printf("O is your winner!");
		return -1;
	}
	// vertical check column 2
	if ( (ticTacToeGrid[0][2] == ticTacToeGrid[1][2] && ticTacToeGrid[0][2] == ticTacToeGrid[2][2]) && (ticTacToeGrid[0][2] == 'X') )
	{
		printf("X is your winner!");
		return -1;
	}
	else if ( (ticTacToeGrid[0][2] == ticTacToeGrid[1][2] && ticTacToeGrid[0][2] == ticTacToeGrid[2][2]) && (ticTacToeGrid[0][2] == 'O') )
	{
		printf("O is your winner!");
		return -1;
	}
	// back slack check
	if ((ticTacToeGrid[0][0] == ticTacToeGrid[1][1] && ticTacToeGrid[0][0] == ticTacToeGrid[2][2]) && (ticTacToeGrid[0][0] == 'X'))
	{
		{
			printf("X is your winner!");
			return -1;
		}
	}
	else if ((ticTacToeGrid[0][0] == ticTacToeGrid[1][1] && ticTacToeGrid[0][0] == ticTacToeGrid[2][2]) && (ticTacToeGrid[0][0] == 'O'))
	{
		{
			printf("O is your winner!");
			return -1;
		}
	}
	// forward slash check
	if ((ticTacToeGrid[0][2] == ticTacToeGrid[1][1] && ticTacToeGrid[0][2] == ticTacToeGrid[2][0]) && (ticTacToeGrid[0][2] == 'X'))
	{
		{
			printf("X is your winner!");
			return -1;
		}
	}
	else if ((ticTacToeGrid[0][2] == ticTacToeGrid[1][1] && ticTacToeGrid[0][2] == ticTacToeGrid[2][0]) && (ticTacToeGrid[0][2] == 'O'))
	{
		{
			printf("O is your winner!");
			return -1;
		}
	}
	else
	{
		printf("No one wins :(");
	}
	return 0;
}

/*
 * FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
 *
 * ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
 *             int gridLocation should indicate the position on the grid to place "currentPlayer" as
 *                 defined by whomever defined print_the_grid().
 *
 * RETURNS:	   On a successful choice, 1
 *             If the user chooses a location that has already been taken, 0
 *             On failure, -1
 *
 * NOTES:      Verify that gridLocation has not already been chosed before accepting the play
 *             If the play is valid, record the selection within the 2D tic tac toe array
 */
int what_is_your_play(char currentPlayer, int gridLocation)
{
	int i = 0;
	int j = 0;

	if (gridLocation > 9 || gridLocation < 1)
	{
		return -1;
		printf("You broke it!");
		system("exit)");
	}
	switch (gridLocation) {

	case 1:
		i = 0;
		j = 0;
		printf("%c", currentPlayer);
		break;

	case 2:
		i = 0;
		j = 1;
		printf("%c", currentPlayer);
		break;

	case 3:
		i = 0;
		j = 2;
		printf("%c", currentPlayer);
		break;

	case 4:
		i = 1;
		j = 0;
		printf("%c", currentPlayer);
		break;

	case 5:
		i = 1;
		j = 1;
		printf("%c", currentPlayer);
		break;

	case 6:
		i = 1;
		j = 2;
		printf("%c", currentPlayer);
		break;

	case 7:
		i = 2;
		j = 0;
		printf("%c", currentPlayer);
		break;

	case 8:
		i = 2;
		j = 1;
		printf("%c", currentPlayer);
		break;

	case 9:
		i = 2;
		j = 2;
		printf("%c", currentPlayer);
		break;

	default: /* Optional */
		printf("Please enter a valid Grid Location. \n");
		break;
	}
	if (ticTacToeGrid[i][j] != 0)
	{
		printf("That space is already taken.");
		return -1;
	}
	else
	{
		if (currentPlayer == 'X' || currentPlayer == 'O')
		{
			ticTacToeGrid[i][j] = currentPlayer;
			if (player == 88)
			{
				player = 79;
			}
			else
			{
				player = 88;
			}
		}
	}
}
