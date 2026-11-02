#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

bool move_left(int board[][5], int& scoreGained, int numrows = 5)
{
	bool changed = false;
	scoreGained = 0;

	// go through each row of the board
	for (int r = 0; r < rumrows; r++)
		{
			int temp[5] = { 0 };
			int count = 0;

			// move all nonzero tiles left
			for(int c = 0; c < 5; c++)
				{
					if(board[r][c] != 0)
					{
						temp[count] = board[r][c];
						count++;
					}
				}

			// merge adgacent equal tiles
			int merged[5] = { 0 };
			int pos = 0;

			for(int c = 0; c < count; c++)
				{
					if(c+1 < count && temp[c] == temp[c + 1])
					{
						merged[pos] = temp[c] * 2;

						scoreGained += merged[pos];

						c++; // skip the second tile in the pair
					}
					else
					{
						merged[pos] = temp[c];
					}

					pos++;
				{

					// copy the final row back to the board

					for(int c = 0; c < 5; c++)
						{
							if(board[r][c] != merged[c])
							{
								changed = true;
							}

							board[r][c] = merged[c];
						}
					
		}
					return changed;
	
	// moves the tiles toward the left

	// matching adjacent tiles merge once per move

	// returns information about the board change
}

void move_right(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_up(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_down(int board[][5], int numrows = 5)
{
	//CODE HERE
}


void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}
