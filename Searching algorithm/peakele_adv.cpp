/*A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -o. In other words, an element is
always considered to be strictly greater than a neighbor that is outside the array.

Input :
Array = [1,2,1,2,6, 10,3]

Output :
Either index 1 or index 5 are the correct output. At index
1, 2 is the peak element and at index 5, 10 is the peak
element.*/


#include<iostream>
#include<vector>
using namespace std;
int peakele(vector<int>&arr){
    int l=0;
    int h=arr.size()-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(mid==0){
            if(arr[mid]>=arr[mid+1]) return arr[mid];
            else return arr[mid+1];
        }
        else if (mid==arr.size()-1){
            if(arr[mid]>=arr[mid-1]) return arr[mid];
            else return arr[mid-1];
        }
        else{
            if(arr[mid]>=arr[mid-1]&&arr[mid]>=arr[mid+1]){
                return arr[mid];
            }
            else if(arr[mid]>=arr[mid-1]){
                l=mid+1;
            }
            else h=mid-1;
        }
    }
}
int main(){
    vector<int> arr={64,864,16,868,46,186,4,5168,451,65,466,4894,4865,894,69,848,4,654,453};
    cout<<peakele(arr);
    return 0;
}