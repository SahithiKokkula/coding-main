/*Repetedly find minimum element in unsorted array and place it in the beginning*/
#include<iostream>
#include <vector>
using namespace std;
int insertion_sort(vector<int>&arr){
    for (int i=0;i<arr.size()-1;i++){
        int min_idx =i;
        for(int j=i;j<arr.size();j++){
            if(arr[min_idx]>arr[j]) min_idx=j;
        }
        if(min_idx!=i){
            swap(arr[i],arr[min_idx]);
        }
    }
}
int main(){
    vector<int> arr={10,9,8,7,6,5,4,3,2,1};
    insertion_sort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}