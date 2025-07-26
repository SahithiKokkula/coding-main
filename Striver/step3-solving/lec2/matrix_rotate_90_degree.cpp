#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> rotate_matrix(vector<vector<int>>&matrix,int n, int m){
    vector<vector<int>>rotated_matrix(m,vector<int>(n));
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            rotated_matrix[j][n-1-i]=matrix[i][j];
        }
    }
    return rotated_matrix;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    int num;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>num;
            matrix[i][j]=num;
        }
    }
    vector<vector<int>>rotated_matrix = rotate_matrix(matrix,n,m);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<rotated_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}