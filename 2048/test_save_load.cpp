
#include <iostream>
#include <fstream>
#include "save_load.h"
using namespace std;

int main()
{
    int board[5][5] = {
        {0, 4, 2, 4, 0},
        {0, 0, 0, 0, 0},
        {2, 0, 2, 0, 2},
        {0, 0, 2, 0, 0},
        {2, 2, 2, 2, 2}
    };

    int score = 100;

    // TEST 1: Save and load
    if (!save_game(board, score, "test_save.txt"))
    {
        cout << "SAVE FAILED!" << endl;
        return 1;
    }

    board[0][0] = 128;
    score = 999;

    if (!load_game(board, score, "test_save.txt"))
    {
        cout << "LOAD FAILED!" << endl;
        return 1;
    }

    if (board[0][0] == 0 && score == 100)
        cout << "TEST PASSED!" << endl;
    else
    {
        cout << "TEST FAILED!" << endl;
        return 1;
    }

    // TEST 2: Missing save file
    int oldScore = score;
    int oldTile = board[0][0];

    if (!load_game(board, score, "missing_file.txt")
        && score == oldScore
        && board[0][0] == oldTile)
    {
        cout << "MISSING FILE TEST PASSED!" << endl;
    }
    else
    {
        cout << "MISSING FILE TEST FAILED!" << endl;
        return 1;
    }

    // TEST 3: Corrupted save file
    {
        ofstream badFile("corrupt_save.txt");
        badFile << "this is not valid game data";
    }

    int previousScore = score;
    int previousBoard[5][5];

    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++)
            previousBoard[r][c] = board[r][c];

    bool loaded = load_game(board, score, "corrupt_save.txt");
    bool unchanged = (score == previousScore);

    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++)
            if (board[r][c] != previousBoard[r][c])
                unchanged = false;

    if (!loaded && unchanged)
        cout << "CORRUPT FILE TEST PASSED!" << endl;
    else
    {
        cout << "CORRUPT FILE TEST FAILED!" << endl;
        return 1;
    }

    return 0;
}
