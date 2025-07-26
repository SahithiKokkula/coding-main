#include<iostream>
using namespace std;
int main(){
    int n1 ;
    int m1 ;
    cout<<"Enter number of rows and colums:";
    cin>>n1>>m1;
    int mat1[n1][m1];
    int transpose[m1][n1];
    for (int i=0;i<n1;i++){
        for (int j=0;j<m1;j++){
            cout<<"Enter element for row "<<i+1<<" and column "<<j+1<<":"<<endl;
            cin>>mat1[i][j];
        }
    }
    for (int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            transpose[i][j]=mat1[j][i];
        }
    }
    cout<<endl;
    for (int i=0;i<m1;i++){
        for (int j=0;j<n1;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}