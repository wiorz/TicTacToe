//Ko, Ivan
//Mar 17th, 2017
//input: x
//output: x
//Purpose: tic tac toe against the pc. PC is programmed to be random.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Check all conditions on the board.
//return 0 if player 1 wins.
//return 1 if computer wins.
//return 2 if draw game.
int check_board(int x[][3]) {
	int i = 0, j = 0, sum = 0, count = 0;

	//Check each row. also check for draw here to see if all slots on board are taken.
	//The count is for check if a square is taken. If so, count + 1.
	//At the end, if count is greater than 8, and there's no win detected, then it's a draw.
	for (i = 0; i < 3; ++i) {
		sum = 0;
		for (j = 0; j < 3; ++j) {
			sum += x[i][j];
			//Add counts for draw condition here.
			if (x[i][j] != 5) {
				count += 1;
			}
		}
		if (sum == 0) {
			return 0;
		}
		else if (sum == 3) {
			return 1;
		}
	}

	//Check columns here.
	for (i = 0; i < 3; ++i) {
		sum = 0;
		for (j = 0; j < 3; ++j) {
			sum += x[j][i];
		}
		if (sum == 0) {
			return 0;
		}
		else if (sum == 3) {
			return 1;
		}
	}

	//Check diagonal here.
	sum = 0;
	for (i = 0; i < 3; ++i) {
		sum += x[i][i];
	}
	if (sum == 0) {
		return 0;
	}
	else if (sum == 3) {
		return 1;
	}

	//Check reverse diagonal here.
	sum = 0;
	for (i = 0; i < 3; ++i) {
		sum += x[i][2 - i];
	}
	if (sum == 0) {
		return 0;
	}
	else if (sum == 3) {
		return 1;
	}

	//Check draw here.
	if (count > 8) {
		return 2;
	}

	return 5;
}

void print_board(int x[][3]) {
	//Make char board here because the required int board from the spec file makes no sense.
	char y[3][3] = { " " };
	int i = 0, j = 0;

	//Determine what to assign to a square depending on the x board values.
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			if (x[i][j] == 0) {
				y[i][j] = 'X';
			}
			else if (x[i][j] == 1) {
				y[i][j] = 'O';
			}
			else {
				y[i][j] = ' ';
			}
		}
	}

	printf("  %c  |  %c  |  %c  \n", y[0][0], y[0][1], y[0][2]);
	printf(" _ _ | _ _ | _ _ \n");
	printf("  %c  |  %c  |  %c  \n", y[1][0], y[1][1], y[1][2]);
	printf(" _ _ | _ _ | _ _ \n");
	printf("  %c  |  %c  |  %c  \n", y[2][0], y[2][1], y[2][2]);
	return;
}

int main(){
	int x[3][3] = {5, 5, 5, 5, 5, 5, 5, 5, 5};
	int userPos1, userPos2;
	int randPos1, randPos2;
	int result = 5;
	char userName[50];

	printf("Player 1 enter your name: ");
	scanf("%s", userName);

	printf("%s, Let's play tic tac toe:\n", userName);

	print_board(x);

	//Keep looping as long as there's no conclusive result.
	while ((result != 0) && (result != 1) && (result != 2)) {
		printf("Player 1, enter an 'X' :");
		scanf("%d %d", &userPos1, &userPos2);
		while (x[userPos1][userPos2] != 5) {
			//Keep asking for input as long as square is already taken.
			printf("Position already entered, please choose another location.\n");
			scanf("%d %d", &userPos1, &userPos2);
		};
		x[userPos1][userPos2] = 0;

		print_board(x);
		result = check_board(x);

		printf("The computer entered an 'O' at position : ");

		randPos1 = rand() % 10 % 3; //generate random number between 0~2;
		randPos2 = rand() % 10 % 3;
		while (x[randPos1][randPos2] != 5){
			//Keep generating new numbers until a square isn't taken.
			randPos1 = rand() % 10 % 3; 
			randPos2 = rand() % 10 % 3;
		}

		///It may not look truly random, but that's due to inherent problem in C's rand().
		///test here to see it's random:
		///for (int p = 0; p < 10; p++) {printf("random %d\n", rand() % 10 % 3);}
		x[randPos1][randPos2] = 1;
		printf("%d %d\n", randPos1, randPos2);

		print_board(x);
		result = check_board(x);
	}

	if (result == 0) {
		printf("Player 1 wins!\n");
	}
	else if (result == 1) {
		printf("Computer wins!\n");
	}
	else if (result == 2) {
		printf("Draw game!\n");
	}
	
	

	return 0;
}