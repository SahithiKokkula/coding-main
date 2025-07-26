#include<iostream>
#include<vector>
using namespace std;
void spiralOrder(vector<vector<int>>&matrix,int n,int m){
    int left=0;
    int right=m-1;
    int top =0;
    int bottom = n-1;
    int direction=0;
    while(top<=bottom&&left<=right){
        // left to right=0
        if (direction==0){
            for(int i=left;i<=right;i++){
                cout<<matrix[top][i]<<" ";
            }
            top++;
        }
        // top to bottom=1
        else if (direction==1){
            for(int i=top;i<=bottom;i++){
                cout<<matrix[i][right]<<" ";
            }
            right--;
        }
        // right to left=2
        else if (direction==2){
            for(int i=right;i>=left;i--){
                cout<<matrix[bottom][i]<<" ";
            }
            bottom--;
        }
        // bottom to top=3
        else  {
            for(int i=bottom;i>=top;i--){
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }
        direction=(direction+1)%4;
    }
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
    spiralOrder(matrix,n,m);
    return 0;
}