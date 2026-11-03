
#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <fstream>
#include <string>
using namespace std;

// Save the current board and score
bool save_game(const int board[][5], int score,
               const string& filename = "save.txt")
{
    ofstream file(filename);

    if (!file)
        return false;

    file << score << '\n';

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            file << board[r][c] << ' ';
        }
        file << '\n';
    }

    file.close();
    return file.good();
}

// Load a previously saved board and score
bool load_game(int board[][5], int& score,
               const string& filename = "save.txt")
{
    ifstream file(filename);

    if (!file)
        return false;

    int tempBoard[5][5];
    int tempScore;

    if (!(file >> tempScore) || tempScore < 0)
        return false;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (!(file >> tempBoard[r][c]))
                return false;

            int value = tempBoard[r][c];

            if (value < 0 || (value != 0 &&
                (value & (value - 1)) != 0))
                return false;
        }
    }

    string extra;
    if (file >> extra)
        return false;

    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++)
            board[r][c] = tempBoard[r][c];

    score = tempScore;
    return true;
}

#endif
