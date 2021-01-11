#include <iostream>
#include <stack>
using namespace std;

#define empty 0
#define N 9

bool isEmpty(int grid[N][N], int &row, int &col);
bool inRow(int grid[N][N], int row, int num);
bool inCol(int grid[N][N], int col, int num);
bool inBox(int grid[N][N], int firstRow, int firstCol, int num);
bool isValid(int grid[N][N], int row, int col, int num);
void display(int grid[N][N]);
bool Solve(int grid[N][N]);

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
    if (Solve(grid))
    {
        display(grid);
    }
    else
    {
        cout << "No solution";
    }
}

bool isEmpty(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == empty)
            {
                return true;
            }
        }
    }
    return false;
}

bool inRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool inCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (grid[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool inBox(int grid[N][N], int firstRow, int firstCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + firstRow][col + firstCol] == num)
            {
                return true;
            }
        }
    }
    return false;
}

bool isValid(int grid[N][N], int row, int col, int num)
{
    return !inRow(grid, row, num) && !inCol(grid, col, num) && !inBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == empty;
}

void display(int grid[N][N])
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            cout << grid[row][col];
        }
        cout << endl;
    }
}

bool Solve(int grid[N][N])
{
    int row, col;
    stack<pair<int, int>> s;
    s.push({row, col});

    if (!isEmpty(grid, row, col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(grid, row, col, num))
        {
            grid[row][col] = num;

            if (Solve(grid))
            {
                return true;
            }

            grid[row][col] = empty;
        }
    }
    return false;
}
