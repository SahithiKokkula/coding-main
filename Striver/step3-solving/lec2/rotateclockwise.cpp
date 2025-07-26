#include<bits/stdc++.h>
using namespace std;
// void rotate_matrix(vector<vector<int>>&matrix,int n, int m){
//     int left = 0;
//     int right = m-1;
//     int top = 0;
//     int bottom = n-1;
//     int direction =0;
//     while(left<right && top < bottom){
//         int buffer = matrix[top][left];
//         // top to bottom
//         for(int i=top+1;i<=bottom;i++){
//             matrix[i-1][left]=matrix[top][left];
//         }
//         left++;
//         // left to right
//         for (int i=left;i<=right;i++){
//             matrix[bottom][i-1]=matrix[bottom][left];
//         }
//         bottom--;
//         // bottom to top 
//         for (int i=bottom;i>=top;i--){
//             matrix[i+1][right]=matrix[i][right];
//         }
//         right--;
//         // right to left 
//         for (int i=right;i>=left;i--){
//             matrix[top][i+1]=matrix[top][i];
//         }
//         matrix[top][left]=buffer;
//         top++;
        
//     }
//     return;
// }
void rotate_matrix(vector<vector<int>>& matrix, int n, int m) {
    int left = 0;
    int right = m - 1;
    int top = 0;
    int bottom = n - 1;

    // Rotate layer by layer
    while (left < right && top < bottom) {
        // Save the top-left element in a buffer
        int buffer = matrix[top][left];

        // Top to bottom
        for (int i = top; i < bottom; i++) {
            matrix[i][left] = matrix[i + 1][left];
        }

        // Left to right
        for (int i = left; i < right; i++) {
            matrix[bottom][i] = matrix[bottom][i + 1];
        }

        // Bottom to top
        for (int i = bottom; i > top; i--) {
            matrix[i][right] = matrix[i - 1][right];
        }

        // Right to left
        for (int i = right; i > left + 1; i--) {
            matrix[top][i] = matrix[top][i - 1];
        }

        // Put the buffered element in its new position
        matrix[top][left + 1] = buffer;

        // Move to the next layer
        left++;
        right--;
        top++;
        bottom--;
    }
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
    rotate_matrix(matrix,n,m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}