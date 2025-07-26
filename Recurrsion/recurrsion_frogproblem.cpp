/*
There are N stones, numbered 1,2, ... ,N. For each i (1sisN), the height of Stone i is hi.There
is a frog who is initially on Stone 1. He will repeat the following action some number of
times to reach Stone N:

If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of | hi - hj
is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.
10
*/
#include<iostream>
using namespace std;
int f1(int num,int arr[],int i=1){
    if(i>=num) return 0;
    int cst1=f1(num,arr,i+1)+abs(arr[i]-arr[i-1]);
    int cst2=f1(num,arr,i+2)+abs(arr[i+1]-arr[i-1]);
    if(cst1<cst2) return cst1;
    return cst2;
}
// int f2(int *h, int n, int i) {
// // base case
//     if(i=n-1) return 0;
//     if(i=n-2) return f2(h, n, i+1) + abs(h[i] -h[i+1]);

//     return min((f2(h, n, i+1) + abs(h[i] - h[i+1])), (f2(h, n, i+2) + abs(h[i] - h[i+2])));
// }
int main(){
    int arr[]={10,30,40,20};
    int num=sizeof(arr)/sizeof(arr[0]);
    cout<<f1(num,arr)<<endl;
    // cout<<f2(arr,num,0);
    return 0;
}