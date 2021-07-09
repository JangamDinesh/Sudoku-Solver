#include <iostream>
using namespace std;

#define N 9

// function to display grid
void Display(int A[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

// function to check if the number at that place is legal or not
bool isOk(int grid[N][N], int row, int col, int num)
{
    // checking whether the same number is present in same row
    for(int i=0; i<9; i++)
    {
        if(grid[row][i] == num) return false;
    }

    // checking whether the same number is present in same row
    for(int i=0; i<9; i++)
    {
        if(grid[i][col] == num) return false;
    }

    /* checking whether the same number is present in that
       particular 3*3 matrix */
    int a = row - row%3;
    int b = col - col%3;

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(grid[i+a][j+b] == num)
                return false;
        }
    }

    return true;
}

// function for solving sudoku...
bool solveSudoku (int grid[N][N], int row, int col)
{
    if(row == N-1 && col == N) return true;

    // if col becomes 9, move to next row
    if(col == N)
    {
        row++;
        col = 0;
    }

    if(grid[row][col] > 0) return solveSudoku(grid, row, col + 1);

    for(int num = 1; num <= N; num++)
    {
        if(isOk(grid, row, col, num))
        {
            grid[row][col] = num;
            if(solveSudoku(grid, row, col+1)) return true;
        }

        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    int grid[N][N];
    cout << "SUDOKU SOLVER" << endl;

    cout << "\nEnter the known values of Sudoku (row by row)\n";
    cout << "Enter zero(0) in place of empty spaces\n";

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cin>>grid[i][j];
    }

    /* (OR)
    int grid[N][N] = { { 0, 0, 0, 2, 6, 0, 7, 0, 1 },
                       { 6, 8, 0, 0, 7, 0, 0, 9, 0 },
                       { 1, 9, 0, 0, 0, 4, 5, 0, 0 },
                       { 8, 2, 0, 1, 0, 0, 0, 4, 0 },
                       { 0, 0, 4, 6, 0, 2, 9, 0, 0 },
                       { 0, 5, 0, 0, 0, 3, 0, 2, 8 },
                       { 0, 0, 9, 3, 0, 0, 0, 7, 4 },
                       { 0, 4, 0, 0, 5, 0, 0, 3, 6 },
                       { 7, 0, 3, 0, 1, 8, 0, 0, 0 } }; */


    cout<<"The given sudoku is: \n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout<<grid[i][j]<<" ";

        cout<<endl;
    }

    cout<<endl<<endl;

    if(solveSudoku(grid, 0, 0))
    {
        cout<<"The answer of given sudoku is: "<<endl;
        Display(grid);
    }
    else cout<<"No solution found!!!\n";

    return 0;
}
