/*Search the 'target' value in a 2d integer matrix of dimensions n x m and
return 1 if found, else return 0. This matrix has the following properties:
1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the
previous row.

Input :
Matrix = [[1,3,5,7], [10, 11, 16, 20], [23,30, 34, 60] ],
target = 3

Output :
1*/
#include<iostream>
#include<vector>
using namespace std;
int findrow(vector<vector<int>>arr,int n,int m,int target){
    int t=0;
    int b=n-1;
    while(t<=b){
        int mid=t+(b-t)/2;
        if(target<=arr[mid][m-1]&&target>=arr[mid][0]){
            return mid;
        }
        else if(target<arr[mid][0]) b=mid-1;
        else if(target>arr[mid][m-1]) t=mid+1;
    }
    return -1;
}
int rowsearch(vector<vector<int>>arr,int n,int m,int target){
    int row=findrow(arr,n,m,target);
    if(row==-1) return 0;
    int l=0;
    int r=m-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[row][mid]==target) return 1;
        else if(arr[row][mid]>target) r=mid-1;
        else if(arr[row][mid]<target) l=mid+1;
    }
    return 3;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int ele;
            cin>>ele;
            arr[i][j]=ele;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int num;
    cout<<"Enter number to find";
    cin>>num;
    cout<<rowsearch(arr,n,m,num);
    return 0;
}