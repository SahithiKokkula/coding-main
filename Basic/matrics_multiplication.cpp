#include<iostream>
using namespace std;
int main(){
    int n1 ;
    int m1 ;
    cout<<"For matrix 1"<<endl;
    cout<<"Enter number of rows and colums:";
    cin>>n1>>m1;
    int mat1[n1][m1];
    for (int i=0;i<n1;i++){
        for (int j=0;j<m1;j++){
            cout<<"Enter element for row "<<i+1<<" and column "<<j+1<<":";
            cin>>mat1[i][j];
        }
    }
    int n2 =m1;
    int m2 ;
    cout<<"For matrix 2"<<endl;
    cout<<"Number of rows ="<<n2<<endl<<"Enter no of columns: ";
    cin>>m2;   
    int mat2[n2][m2];
    for (int i=0;i<n2;i++){
        for (int j=0;j<m2;j++){
            cout<<"Enter element for row "<<i+1<<" and column "<<j+1<<":";
            cin>>mat2[i][j];
        }
    }
    int mul[n1][m2];
    for (int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            int ans=0;
            for (int k=0;k<m1;k++){
                ans+=mat1[i][k]*mat2[k][j];
            }
            mul[i][j]=ans;
        }
    }
    cout<<endl;
    for (int i=0;i<n1;i++){
        for (int j=0;j<m2;j++){
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}