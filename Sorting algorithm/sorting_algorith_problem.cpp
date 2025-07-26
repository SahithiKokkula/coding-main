#include<iostream>
#include<vector>
using namespace std;







/*Given an integer array arr, move all 0's to the end of it while
maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the
array.*/
void problem1(vector<int>&arr){
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        int j=0;
        bool flag=false;
        while(j!=i){
            if(arr[j]==0&&arr[j+1]!=0){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
            j++;
        }
        if(!flag) break;
    }
    return;
}






/*Give an array of names of the fruits; you are supposed to sort it in
lexicographical order using the selection sort*/
void problem2(vector<string>&arr){
    int n=arr.size();
    for (int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_idx]>arr[j]) min_idx=j;
        }
        if(min_idx!=i){
            swap(arr[i],arr[min_idx]);
        }
    }
}




int main(){
    vector<int>arr1={0,5,0,0,42,89};
    problem1(arr1);
    for(int i:arr1){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<string>arr2={"papaya","lime","watermelon","nikunj","apple","mango","kiwi"};
    problem2(arr2);
    for(string i:arr2){
        cout<<i<<" ";
    }
    return 0;
}