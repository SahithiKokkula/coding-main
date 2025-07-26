/*Given an array of n integers and a target value x.Print whether x exists in the array or not.*/
#include<iostream>
using namespace std;
bool f(int *arr,int x,int len,int ptr=0){
    if (ptr==len) return 0;
    if (arr[ptr]==x) return 1;
    return arr[ptr]==x||f(arr,x,len,ptr+1);
}
int main(){
    int arr[]={1,2,3,4,9};
    cout<<f(arr,2,5);
    return 0;
}