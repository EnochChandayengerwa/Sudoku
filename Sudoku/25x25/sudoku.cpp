#include <iostream>
#include <stack>
using namespace std;

#define empty 0
#define N 25

bool isValid(int grid[N][N], int row, int col, int num);
void display(int grid[N][N]);
bool solve(int grid[N][N]);

int main()
{
    int grid[N][N];
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
            else if (num == "H")
            {
                num = "17";
                grid[row][col] = stoi(num);
            }
            else if (num == "I")
            {
                num = "18";
                grid[row][col] = stoi(num);
            }
            else if (num == "J")
            {
                num = "19";
                grid[row][col] = stoi(num);
            }
            else if (num == "K")
            {
                num = "20";
                grid[row][col] = stoi(num);
            }
            else if (num == "L")
            {
                num = "21";
                grid[row][col] = stoi(num);
            }
            else if (num == "M")
            {
                num = "22";
                grid[row][col] = stoi(num);
            }
            else if (num == "N")
            {
                num = "23";
                grid[row][col] = stoi(num);
            }
            else if (num == "O")
            {
                num = "24";
                grid[row][col] = stoi(num);
            }
            else if (num == "P")
            {
                num = "25";
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
    for (int row = 0; row < 5; row++)
        for (int col = 0; col < 5; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}

bool isValid(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 5, col - col % 5, num) && grid[row][col] == empty;
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
            else if (grid[row][col] == 17)
            {
                cout << "H ";
            }
            else if (grid[row][col] == 18)
            {
                cout << "I ";
            }
            else if (grid[row][col] == 19)
            {
                cout << "J ";
            }
            else if (grid[row][col] == 20)
            {
                cout << "K ";
            }
            else if (grid[row][col] == 21)
            {
                cout << "L ";
            }
            else if (grid[row][col] == 22)
            {
                cout << "M ";
            }
            else if (grid[row][col] == 23)
            {
                cout << "N ";
            }
            else if (grid[row][col] == 24)
            {
                cout << "O ";
            }
            else if (grid[row][col] == 25)
            {
                cout << "P ";
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