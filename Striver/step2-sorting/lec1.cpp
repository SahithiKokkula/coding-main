#include<bits/stdc++.h>
using namespace std;
int selection_sort(int arr[],int n){
    for (int left=0;left<n;left++){
        int minele=left;
        for (int right=left+1;right<n;right++){
            if(arr[right]<arr[minele]){
                minele=right;
            }
        }
        swap(arr[minele],arr[left]);
    }
    //print
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int bubble_sort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int didswap=0;
        for (int j=n-1-i;j<0;j--){
            if(arr[j-1]>arr[j]){
                swap(arr[j],arr[j-1]);
                didswap=1;
            }
        }
        if (didswap==0) break;
    }
    //print
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int insersion_sort(int arr[],int n){
    for (int i=1;i<n;i++){
        int curr=i;
        int j=i-1;
        while(arr[curr]<arr[j] && j>=0){
            swap(arr[j--],arr[curr--]);
        }
    }
    //print
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    cout<<endl;
    bubble_sort(arr,n);
    cout<<endl;
    insersion_sort(arr,n);
    cout<<endl;
    return 0;
}