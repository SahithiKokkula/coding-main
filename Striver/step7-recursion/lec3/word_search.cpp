#include<bits/stdc++.h>
using namespace std;
bool searching(vector<vector<char>>&matrix, int index, string target,int i, int j,int n, int m){
    if (index == target.length()){
        return true;
    }
    if(i <0 || j < 0 || i >= n || j >= m || matrix[i][j] != target[index] || matrix[i][j] == '!'){
        return false;
    }
    char c = matrix[i][j];
    matrix[i][j] = '!';

    bool top = searching(matrix,index+1,target,i-1,j,n,m);
    bool bottom = searching(matrix,index+1,target,i+1,j,n,m);
    bool right = searching(matrix,index+1,target,i,j+1,n,m);
    bool left = searching(matrix,index+1,target,i,j-1,n,m);
    matrix[i][j] = c;
    return top || bottom || right || left;
}
bool word_search(vector<vector<char>> matrix, string target){
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (target[0] == matrix[i][j]){
                if (searching(matrix,0,target,i,j,n,m)){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    vector<vector<char>> matrix = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string target = 'ASADEESE';
    cout<<word_search(matrix,target);
}