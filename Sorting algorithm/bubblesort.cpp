/*Repetedly swap two adjacent elements if in the wrong order*/
#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int>&arr){
    for (int i=1;i<arr.size();i++){
        for (int j=0;j<arr.size()-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void bubble_sort_optimised(vector<int>&arr){
    for (int i=1;i<arr.size();i++){
        int c=0;
        for (int j=0;j<arr.size()-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                c++;
            }
        }
        if(c==0) break;
    }
}
int main(){
    vector<int>arr={10,9,8,7,6,5,4,3,2,1};
    // bubble_sort(arr);
    bubble_sort_optimised(arr);
    for (int i:arr){
        cout<<i<<" ";
    }
}