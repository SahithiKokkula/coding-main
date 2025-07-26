/*Given an array of integers, print sums of all subsets in it. Output sums can be
printed in any order.*/
#include <iostream>
using namespace std;
void f(int *arr, int n, int ptr=0,int sum=0){
    if(ptr==n) {
        cout<<sum<<" ";
        return;
    }   
    f(arr,n,ptr+1,sum+arr[ptr]);
    f(arr,n,ptr+1,sum);
}
int main(){
    int arr[]={1,3,2};
    f(arr,3);
    return 0;
}