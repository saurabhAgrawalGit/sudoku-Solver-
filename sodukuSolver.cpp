#include <iostream>
#define n 9
using namespace std;
bool isSafe(int grid[n][n], int row, int col, int val)
{
    for (int x = 0; x < n; x++)
    {
        if (grid[x][col] == val)
        {
            return false;
        }
         if (grid[row][x] == val)
        {
            return false;
        }
    }
    int sr = 3 * (row / 3);
    int sc = 3 * (col / 3);
    for (int i = sr; i < sr + 3; i++)
    {
        for (int j = sc; j < sc + 3; j++)
        {
            if (grid[i][j] == val)
            {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int grid[n][n])
{
  
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(grid, row, col, val))
                    {
                        grid[row][col] = val;
                        if (solveSudoku(grid))
                        {
                            return true;
                        }
                        else
                        {
                            grid[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void displayBoard(int grid[n][n])
{
 for (int i = 0; i < n - 1; i++)
    {
        cout << "-----";
    }
    cout << "--";

    for (int i = 0; i < n; i++)
    {
        if (i == 3 || i == 6)
        {
            cout << "\n ======================================== ";
        }

        for (int j = 0; j < n; j++)
        {

            if (j == 0)
            {
                cout << "\n|";
            }

            cout << " " << grid[i][j] << "  ";

            if (j == 2 || j == 5)
            {
                cout << "||";
            }

            if (j == 8 && i != 8)
            {
                cout << " |\n|\t\t\t\t\t  |";
            }
        }
    }
    cout << " |\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "-----";
    }
    cout << "--";
}


int main()
{

    int grid[9][9] =
        {
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    displayBoard(grid);
    cout << solveSudoku(grid) << endl;
    cout << "\nafter solve sudoku" << endl;
    displayBoard(grid);
    
}
ALGORITHM
