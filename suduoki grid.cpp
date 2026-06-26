#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to print Sudoku grid
void printGrid(int grid[SIZE][SIZE])
{
    cout << "\nSolved Sudoku:\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if number exists in row
bool usedInRow(int grid[SIZE][SIZE], int row, int num)
{
    for (int col = 0; col < SIZE; col++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// Check if number exists in column
bool usedInCol(int grid[SIZE][SIZE], int col, int num)
{
    for (int row = 0; row < SIZE; row++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// Check if number exists in 3x3 box
bool usedInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

// Check whether placing number is safe
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

// Find an empty cell
bool findEmptyLocation(int grid[SIZE][SIZE], int &row, int &col)
{
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

// Backtracking Sudoku Solver
bool solveSudoku(int grid[SIZE][SIZE])
{
    int row, col;

    if (!findEmptyLocation(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int grid[SIZE][SIZE] =
    {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    cout << "Sudoku Solver using Backtracking\n";

    if (solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout << "No Solution Exists!" << endl;
    }

    return 0;
}