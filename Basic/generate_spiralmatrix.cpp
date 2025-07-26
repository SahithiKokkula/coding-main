#include<iostream>
#include<vector>
using namespace std;
void s_matrix(vector<vector<int>>&matrix){
    int left=0;
    int right=matrix[0].size()-1;
    int top =0;
    int bottom = matrix.size()-1;
    int direction=0;
    int c=1;
    while(top<=bottom&&left<=right){
        // left to right=0
        if (direction==0){
            for(int i=left;i<=right;i++){
                matrix[top][i]=c;
                c++;
            }
            top++;
        }
        // top to bottom=1
        else if (direction==1){
            for(int i=top;i<=bottom;i++){
                matrix[i][right]=c;
                c++;
            }
            right--;
        }
        // right to left=2
        else if (direction==2){
            for(int i=right;i>=left;i--){
                matrix[bottom][i]=c;
                c++;
            }
            bottom--;
        }
        // bottom to top=3
        else  {
            for(int i=bottom;i>=top;i--){
                matrix[i][left]=c;
                c++;
            }
            left++;
        }
        direction=(direction+1)%4;
    }
}
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    vector<vector<int>>spiral_matrix(n,vector<int>(n));
    s_matrix(spiral_matrix);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<spiral_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

