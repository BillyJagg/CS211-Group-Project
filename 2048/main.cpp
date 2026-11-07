#include <iostream>
#include "2048_helper.h"
#include "save_load.h"
using namespace std;

int main()
{
	int size = 5;
	int score = 0;
	int board[5][5] = {
		{0, 4, 2, 4, 0},
		{0, 0, 0, 0, 0},
		{2, 0, 2, 0, 2},
		{0, 0, 2, 0, 0},
		{2, 2, 2, 2, 2},
	};
	//while getch == x loop for up down left right

	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	int scoreGained = 0;
	bool changed = false;

	char choice = 'u';	//initialized
	while (choice != 'e')
	{

		cout << "Please enter choice:{u,d,l,r,s,o,e}"
			<< " for UP, DOWN, LEFT, RIGHT, Save, Open, Exit: "
			<< endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 'u')
		{
			changed = move_up(board, scoreGained, size);
		}
		else if (choice == 'd')
		{
			changed = move_down(board, scoreGained, size);
		}
		else if (choice == 'l')
		{
			changed = move_left(board, scoreGained, size);
		}	
		else if (choice == 'r')
		{
			changed = move_right(board, scoreGained, size);
		}
		else if (choice == 's')
		{
			if (save_game(board, score))
				cout << "Game saved successfully!" << endl;
			else
				cout << "Error saving game." << endl;
		}
		else if (choice == 'o')
		{
			if (load_game(board, score))
				cout << "Game loaded successfully!" << endl;
			else
				cout << "Error loading game." << endl;
		}

		// update score after a movement
		score += scoreGained;

		if (changed)
		{
			insert_random(board, size);
		}

		if (choice != 'e')
		{
			print_board(board);
			cout << "Score: " << score << endl;
		}

	}


	return 0;
}
