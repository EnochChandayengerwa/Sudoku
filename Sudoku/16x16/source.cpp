#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define empty 0
#define N 16

bool isUnassigned(int grid[N][N], int &row, int &col);
bool inRow(int grid[N][N], int row, int num);
bool inCol(int grid[N][N], int col, int num);
bool inSubGrid(int grid[N][N], int firstRow, int firstCol, int num);
bool isValid(int grid[N][N], int row, int col, int num);
void display(int grid[N][N]);
bool Solve(int grid[N][N], stack<pair<int, int>> s);

int main()
{
    /*int grid[N][N];
    stack<pair<int, int>> s;
    string num;
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            cin >> num;
            if (num == "A")
            {
                num = "10";
                grid[row][col] = stoi(num);
            }
            else if (num == "B")
            {
                num = "11";
                grid[row][col] = stoi(num);
            }
            else if (num == "C")
            {
                num = "12";
                grid[row][col] = stoi(num);
            }
            else if (num == "D")
            {
                num = "13";
                grid[row][col] = stoi(num);
            }
            else if (num == "E")
            {
                num = "14";
                grid[row][col] = stoi(num);
            }
            else if (num == "F")
            {
                num = "15";
                grid[row][col] = stoi(num);
            }
            else if (num == "G")
            {
                num = "16";
                grid[row][col] = stoi(num);
            }
            else
            {
                grid[row][col] = stoi(num);
            }
        }
    }
    if (Solve(grid, s))
    {
        cout << "------------------------------------" << endl;
        display(grid);
    }
    else
    {
        cout << "No solution";
    }*/
    vector<int> num;
    for (int i = 1; i < 11; i++)
    {
        if (i % 2 == 0)
        {
            num.push_back(i);
        }
    }

    cout << num.front() << endl;
}

bool isUnassigned(int grid[N][N], int &row, int &col)
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

bool inSubGrid(int grid[N][N], int firstRow, int firstCol, int num)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
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
    return !inRow(grid, row, num) && !inCol(grid, col, num) && !inSubGrid(grid, row - row % 4, col - col % 4, num) && grid[row][col] == empty;
}

void display(int grid[N][N])
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            if (grid[row][col] == 10)
            {
                cout << "A ";
            }
            else if (grid[row][col] == 11)
            {
                cout << "B ";
            }
            else if (grid[row][col] == 12)
            {
                cout << "C ";
            }
            else if (grid[row][col] == 13)
            {
                cout << "D ";
            }
            else if (grid[row][col] == 14)
            {
                cout << "E ";
            }
            else if (grid[row][col] == 15)
            {
                cout << "F ";
            }
            else if (grid[row][col] == 16)
            {
                cout << "G ";
            }
            else
            {
                cout << grid[row][col] << " ";
            }
        }
        cout << endl;
    }
}

bool Solve(int grid[N][N], stack<pair<int, int>> s)
{
    int row, col;
    s;
    int count = 16;
    while (isUnassigned(grid, row, col))
    {
        for (int num = 1; num <= 9; num++)
        {
            // if looks promising
            if (isValid(grid, row, col, num))
            {
                // make tentative assignment
                grid[row][col] = num;

                // return, if success, yay!
                if (Solve(grid, s))
                    return true;

                // failure, unmake & try again
                grid[row][col] = empty;
            }
        }
        // this triggers backtracking
        // if (!isValid(grid, row, col, grid[row][col]))
        // {
        //     while (!isValid(grid, row, col, grid[row][col]))
        //     {
        //         s.pop();
        //         grid[row][col] == empty;
        //         col -= 1;
        //     }

        //     grid[row][col] += 1;
        // }
        // if (s.size() == 0)
        // {
        //     return false;
        // }
        //return true;
    }
    return false;
}