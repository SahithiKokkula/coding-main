#include<iostream>
#include <vector>
using namespace std;
// dual row traversing 
void method1(vector<vector<int>>matrix,int l1, int r1,int l2, int r2){
    cout<<"method1"<<endl;
    int sum=0;
    for (int row=l1;row<=l2;row++){
        for (int col=r1;col<=r2;col++){
            sum+=matrix[row][col];
        }
    }
    cout<<"Required sum: "<<sum<<endl;
}
// horizontal row prefix sum method
void method2(vector<vector<int>>matrix,int l1, int r1,int l2, int r2){
    cout<<"method2"<<endl;
    for (int i=0;i<matrix.size();i++){
        for (int j=0;j<matrix[0].size();j++){
            matrix[i][j]+=matrix[i][j-1];
        }
    }
    int sum=0;
    for (int row=l1;row<=l2;row++){
        sum+=matrix[row][r2]-matrix[row][r1-1];
    }
    cout<<"Required sum: "<<sum<<endl;
}
// prefixx sum row wise and column wise both
void method3(vector<vector<int>>matrix,int l1, int r1,int l2, int r2){
    cout<<"method3"<<endl;
    // cout<<"method3";
    for (int i=0;i<matrix.size();i++){
        for (int j=1;j<matrix[0].size();j++){
            matrix[i][j]+=matrix[i][j-1];
        }
    }
    for (int i=0;i<matrix[0].size();i++){
        for (int j=1;j<matrix.size();j++){
            matrix[j][i]+=matrix[j-1][i];
        } 
    }
    int sum;
    if(l1!=0 && r1!=0){
        sum=matrix[l2][r2]-matrix[l1-1][r2]-matrix[l2][r1-1]+matrix[l1-1][r1-1];
    }
    if(l1!=0 && r1==0){
        sum=matrix[l2][r2]-matrix[l1-1][r2];
    }
    if(l1==0 && r1!=0){
        sum=matrix[l2][r2]-matrix[l2][r1-1];
    }
    if(l1==0 && r1==0){
        sum=matrix[l2][r2];
    }
    cout<<"Required sum: "<<sum<<endl;
}
int main(){
    int n ;
    int m ;
    cout<<"Enter number of rows and colums:";
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<"Enter element for row "<<i+1<<" and column "<<j+1<<":"<<endl;
            cin>>matrix[i][j];
        }
    }
    int l1;
    int r1;
    int l2;
    int r2;
    cout<<"Enter coordinates of point 1: ";
    cin>>l1>>r1;
    cout<<"Enter coordinates of point 2: ";
    cin>>l2>>r2;
    method1(matrix,l1,r1,l2,r2);
    method2(matrix,l1,r1,l2,r2);
    method3(matrix,l1,r1,l2,r2);
    return 0; 
}