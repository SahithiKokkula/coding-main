/*The problem is to count all the possible paths on an m x n grid from top left
(grid[0][0]) to bottom right (grid[m-1][n-1]).

Having constraints that from each cell you can either move only to right or
down.*/
#include<iostream>
#include<math.h>
#include <vector>
using namespace std;
int fac(int n){
    if (n==0) return 1;
    return n*fac(n-1);
}
// Method-1
int f1(int n, int m){
    return fac(m+n-2)/(fac(n-1)*fac(m-1));
}
// Method-2
int c=0;
void f2(int m,int n,int i=0,int j=0){
    if(i==0&&j==0) c=0;
    if(i==m||j==n) return;
    if(i==m-1&&j==n-1){
        c+=1;
    }
    f2(m,n,i+1,j);
    f2(m,n,i,j+1);
}
// Method-3
int f3(int n, int m,int i=0,int j=0){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m ||j>=n) return 0;
    return f3(n,m,i+1,j) + f3(n,m,i,j+1);
}
int main(){
    int n=5;
    int m=4;
    cout<<f1(n,m)<<" ";
    f2(n,m);
    cout<<c<<" ";
    cout<<f3(n,m);
    return 0;
}