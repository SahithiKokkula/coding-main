// Method 1 (Using Extra Space)


// #include<iostream>
// using namespace std;
// int main(){
//     int n1 ;
//     int m1 ;
//     cout<<"Enter number of rows and colums:";
//     cin>>n1>>m1;
//     int mat[n1][m1];
//     for (int i=0;i<n1;i++){
//         for (int j=0;j<m1;j++){
//             cout<<"Enter element for row "<<i+1<<" and column "<<j+1<<":"<<endl;
//             cin>>mat[i][j];
//         }
//     }
//     int r_matrix[m1][n1];
//     for (int i=0;i<m1;i++){
//         for (int j=0;j<n1;j++){
//             r_matrix[i][j]=mat[n1-j-1][i];
//         }
//     }
//     for (int i=0;i<m1;i++){
//         for (int j=0;j<n1;j++){
//             cout<<r_matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// Method 2 (Without using extra space)


#include<iostream>
using namespace std;
int main(){
    int n1 ;
    cout<<"Enter number of rows and colums for square matrix:";
    cin>>n1;
    int matrix[n1][n1];
    for (int i=0;i<n1;i++){
        for (int j=0;j<n1;j++){
            cout<<"Enter element for row "<<i+1<<" and column "<<j+1<<":"<<endl;
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n1;j++){
            int tmp=matrix[i][j];
            matrix[i][j];
        }
    }
    return 0;
}