#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define empty 0
#define N 16

bool isUnassigned(int grid[N][N], int &row, int &col);
bool UsedInRow(int grid[N][N], int row, int num);
bool UsedInCol(int grid[N][N], int col, int num);
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
bool isValid(int grid[N][N], int row, int col, int num);
vector<int> possibleValues(int grid[N][N], int row, int col, int num);
void display(int grid[N][N]);
bool solve(int grid[N][N]);

int main()
{
    int grid[N][N];
    vector<int> pv;
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
    if (solve(grid))
    {
        cout << "-------------------------------" << endl;
        display(grid);
    }
    else
    {
        cout << "No solution";
    }
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
    for (int row = 0; row < 4; row++)
        for (int col = 0; col < 4; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}

bool isValid(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 4, col - col % 4, num) && grid[row][col] == empty;
}

vector<int> possibleValues(int grid[N][N], int row, int col, int num)
{
    vector<int> pv;
    for (int i = num; i <= N; i++)
    {
        if (isValid(grid, row, col, i))
        {
            pv.push_back(i);
        }
    }
    return pv;
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

bool solve(int grid[N][N])
{
    int row, col, count = 0;
    vector<int> pv;
    stack<pair<int, int>> history;
    while (isUnassigned(grid, row, col))
    {
        pv = possibleValues(grid, row, col, grid[row][col]);
        if (pv.size() == empty)
        {
            if (history.size() == empty)
            {
                return false;
            }
            else
            {
                grid[row][col] = 0;
                vector<int> opv = possibleValues(grid, history.top().first, history.top().second, grid[history.top().first][history.top().second]);
                if (opv.size() != empty)
                {
                    cout << "Found next possible value" << endl;
                    grid[history.top().first][history.top().second] = opv.at(1);
                }
                else
                {
                    grid[history.top().first][history.top().second] = empty;
                    cout << "The value at: " << history.top().first << " and " << history.top().second << " - Should be 0" << endl;
                    history.pop();
                    if (solve(grid))
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            grid[row][col] = pv.front();
            history.push(make_pair(row, col));
        }
        display(grid);
        cout << "--------------------------------" << endl;
        count++;
    }
    return true;
}