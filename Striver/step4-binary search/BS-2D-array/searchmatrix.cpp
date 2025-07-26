// matrix is sorted both rows and col

#include<bits/stdc++.h>
using namespace std;
bool searchmatrix(vector<vector<int>>matrix,int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int right = m-1;
    int top = 0;
    while(right >= 0  && top <= n-1){
        if (matrix[top][right]==target){
            return true;
        }
        else if (matrix[top][right]<target){
            top++;
        }
        else{
            right--;
        }
    }
    return false;
}
int main(){
    int n;
    int m;
    int num;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>num;
            matrix[i][j]=num;
        }
    }
    int target;
    cin>>target;
    cout<<searchmatrix(matrix,target);
    return 0;
}