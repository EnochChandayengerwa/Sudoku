#include <iostream>
#include <stack>
using namespace std;

#define empty 0
#define N 9

bool isValid(int grid[N][N], int row, int col, int num);
void display(int grid[N][N]);
bool solve(int grid[N][N]);

int main()
{
    int grid[N][N];
    int num;
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            cin >> num;
            grid[row][col] = num;
        }
    }
    if (solve(grid))
    {
        //cout << "------------------------------------" << endl;
        display(grid);
    }
    else
    {
        cout << "No solution";
    }
}

bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}

bool isValid(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == empty;
}

void display(int grid[N][N])
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {

            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool solve(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int num = 1; num <= N; num++)
                {
                    if (isValid(grid, i, j, num))
                    {
                        grid[i][j] = num;
                        if (solve(grid))
                        {
                            return true;
                        }
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}