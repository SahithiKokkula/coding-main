/*Repetedly take ekements from unsorted subarray and insert in sorted subarray at correct position*/
#include<iostream>
#include<vector>
using namespace std;
// void insertion_sort(vector<int>&arr){
//     for(int i=1;i<arr.size();i++){
//         int curr=arr[arr.size()-1];
//         for (int j=0;j<i;j++){
//             if(arr[j]>curr){
//                 for(int k=arr.size()-1;k>j;k--){
//                     arr[k]=arr[k-1];
//                 }
//                 arr[j]=curr;
//                 break;
//             }
//         }
//     }
// }
void insertion_sort(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>curr){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
}
int main(){
    vector<int>arr={48,8,48,4,81,8,94,615,161,864,1,513649,865451,846,51,86,634853489,614,861,4,865132,15654,51,654,65,165,461,51,56,46,51,54,6,156,45,6,15,465,1,654,684,58,6435,156,43,1,65,41,6516,4534,1,65,432,156454,1,6,585,51,546465,64,65,51,845,1,686,4,5,262,99,1,848,1,84,81,84,8,52,2,1};
    insertion_sort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
}