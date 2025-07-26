#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isValid(vector < vector < char >> & board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
            return false;

            if (board[row][i] == c)
            return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
        }
        return true;
    }
private:
    bool sol(vector<vector<char>>&board){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9;j++){
                if(board[i][j] == '.'){
                    for(char p = '1' ; p <= '9'; p++){
                        if(isValid(board,i,j,p)){
                            board[i][j] = p;
                            if(sol(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        bool solved = sol(board);
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<char>>board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solution.solveSudoku(board);
    for(int i = 0 ; i < 9;i++){
        for(int j = 0 ; j < 9 ;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}