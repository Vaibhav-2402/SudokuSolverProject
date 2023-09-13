#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int val, vector<vector<int> > &boards) {
    //row check
    for(int i = 0; i < 9; i++) {
        
        //row check
        if(boards[row][i] == val)
            return false;

        //column check
        if(boards[i][col] == val)
            return false;

        //3x3 grid check
        if(boards[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int> > &sudoku) {
    int n = sudoku[0].size();

    for(int row = 0; row < n; row++) {

        for(int col = 0; col < n; col++) {

            if(sudoku[row][col] == 0) {

                for(int val = 1; val <= 9; val++) {

                    if(isSafe(row, col, val, sudoku)) {

                        sudoku[row][col] = val;
                        bool fillOther = solve(sudoku);

                        if(fillOther) {
                            return true;
                        }
                        else {
                            //backtrack
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {

    //creating sudoku
    vector<vector<int> > sudoku 
    {
    {0, 8, 0, 1, 0, 0, 0, 0, 5},
    {0, 1, 3, 0, 2, 0, 7, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 9},
    {0, 0, 1, 0, 0, 3, 0, 9, 0},
    {0, 0, 8, 0, 0, 0, 4, 0, 0},
    {0, 9, 0, 7, 0, 0, 2, 0, 0},
    {1, 4, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2 ,0, 6, 0, 9, 5, 0},
    {6, 0, 0, 0, 0, 8, 0, 7, 0}
    };

    bool check = solve(sudoku);

    //displaying sudoku
    if(check) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << "  ";
            }
            cout << endl;
        }
    }
    else {
        cout << " the given sudoku cannot be solved !!! " << endl;
    }

    return 0;
}