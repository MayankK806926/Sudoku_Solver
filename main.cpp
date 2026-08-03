#include<iostream>
#include<vector>

using namespace std;

const int N = 9;
const int BOX = 3;

//This is to print the final solved sudoku grid.
void print_final_grid(const vector<vector<int>>& sudoku_grid){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<sudoku_grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Checks whether placing 'n' at (row, col) breaks row/column/box rules.
//Only inspects the row, column and box containing the cell (O(N) instead
//of re-validating the whole grid on every candidate).
bool can_place(const vector<vector<int>>& sudoku_grid, int row, int col, int n){
    for(int i=0;i<N;++i){
        if(sudoku_grid[row][i]==n) return false;
        if(sudoku_grid[i][col]==n) return false;
    }

    int boxRow=(row/BOX)*BOX, boxCol=(col/BOX)*BOX;
    for(int i=0;i<BOX;++i){
        for(int j=0;j<BOX;++j){
            if(sudoku_grid[boxRow+i][boxCol+j]==n) return false;
        }
    }
    return true;
}

//Finds the first empty cell (value 0) in row-major order.
bool find_the_place(const vector<vector<int>>& sudoku_grid,int& row,int& col){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(sudoku_grid[i][j]==0){
                row=i; col=j;
                return true;
            }
        }
    }
    return false;
}

//This function solves and checks whether the given grid can be solved or not.
bool solve_the_grid(vector<vector<int>>& sudoku_grid){
    int row,col;
    if(!find_the_place(sudoku_grid,row,col)) return true;

    for(int n=1;n<=N;++n){
        if(can_place(sudoku_grid,row,col,n)){
            sudoku_grid[row][col]=n;
            if(solve_the_grid(sudoku_grid)) return true;
            sudoku_grid[row][col]=0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> sudoku_grid(N,vector<int>(N,0));
    //Taking the input of the initial state of grid.
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            int num;
            cin>>num;
            //Checks whether the provided input is valid or not.
            if(num>=0 && num<=9) sudoku_grid[i][j]=num;
            else{
                cout<<"Invalid Input!!!"<<endl;
                return 0;
            }
        }
    }

    //Here we make ensure that the sudoku grid is solvable or not.
    if(solve_the_grid(sudoku_grid))
        print_final_grid(sudoku_grid);
    else
        cout<<"This grid cannot be solved!!! \nTry with other input grid."<<endl;
}
