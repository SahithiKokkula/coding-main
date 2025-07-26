#include<bits/stdc++.h>
using namespace std;
void recursive_bubble_sort(vector <int>&arr,int i,int j,int n){
    if (i==n-1) return;
    if (arr[j]>arr[j+1]){
        int tmp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=tmp;
    }
    j++;
    if (j==n-1-i) {
        i++;
        j=0;
    }
    recursive_bubble_sort(arr,i,j,n);
}
void recursive_insertion_sort(vector <int>&arr,int i,int j){
    if (i>=arr.size()) return;
    if (arr[j+1]<arr[j] && j>=0){
        int tmp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=tmp;
        j--;
    }
    else{
        j=i;
        i++;
    }
    recursive_insertion_sort(arr,i,j);
}
void merge(vector <int> &arr, int l,int mid ,int r){
    vector <int> temp;
    int left=l;
    int right=mid+1;

    while (left<=mid && right <=r)
    {
        if(arr[left]<arr[right]){
            temp.emplace_back(arr[left++]);
        }
        else
        {
            temp.emplace_back(arr[right++]);
        }
    }
    while (left<=mid){
        temp.emplace_back(arr[left++]);
    }
    while (right <=r){
        temp.emplace_back(arr[right++]);
    }
    for(int i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }
    return;
}
void merge_sort(vector <int>&arr,int l,int r){ 
    if (l>=r) return;
    int mid = (l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int partition(vector<int>&arr,int left,int right){
    int pivot = arr[left];
    int i=left;
    int j= right;
    while (i<j){
        while(arr[i]<=pivot && i<=right-1){
            i++;
        }
        while(arr[j]>pivot && j>=left+1){
            j--;
        }
        if (i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[left]);
    return j;
}
void quick_sort(vector <int> &arr,int left,int right){
    if (left<right){
        int pindex=partition(arr,left,right);
        quick_sort(arr,left,pindex-1);
        quick_sort(arr,pindex+1,right);
    }
}
int main(){
    // int n;
    // cin>>n;
    vector <int> arr = {5,4,3,10,2,1,1};
    // for(int i=0;i<n;i++){
    //     int num;
    //     cin>>num;
    //     arr.emplace_back(num);
    // }
    // recursive_bubble_sort(arr,0,0,n);
    // recursive_insertion_sort(arr,1,0);
    merge_sort(arr,0,arr.size()-1);
    // quick_sort(arr,0,arr.size()-1);
    for (auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}