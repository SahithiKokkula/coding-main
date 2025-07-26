#include<bits/stdc++.h>
using namespace std;
int second_largest(vector<int>arr){
    int largest=arr[0];
    int slargest=arr[1];
    if (slargest>largest) swap(largest,slargest);
    for (auto it: arr){
        if (it>largest){
            slargest=largest;
            largest=it;
        }
        else if (it>slargest && it < largest){
            slargest=it;
        }
    }
    return slargest;
}
void reverse(vector<int>&arr,int l,int r){
    while (l<r){
        swap(arr[l++],arr[r--]);
    }
}
void moveZeros(vector<int> a) {
    int numzero=0;
    int n=a.size();
    for(int i=0;i<n-numzero;i++){
        if (a[i]==0){
            numzero++;
            a.erase(a.begin()+i);
            i--;
        }
    }
    for(int i=0;i<numzero;i++){
        a.emplace_back(0);
    }
}
void rotate(vector<int>&arr,int k){
    int n=arr.size();
    k=k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
}
bool check_sorted(vector<int>arr){
    bool sorted =true;
    for(int i=0;i<arr.size()-1;i++){
        if (arr[i+1]<arr[i]){
            sorted=false;
            break;
        }
    } 
    if (not(sorted)){
        for (int i=0;i<arr.size();i++){
            sorted = true;
            arr.emplace_back(arr[0]);
            arr.erase(arr.begin(),arr.begin()+1);
            
            for(int i=0;i<arr.size()-1;i++){
                if (arr[i+1]<arr[i]){
                    sorted=false;
                }
            }
            if (sorted){
                return sorted;
            }
        }
    }
    return sorted;
}
void remove_dublicate(vector<int>arr){  
    int k=1;
    int lastele=arr[0];
    int popped=0;
    for (int i=1;i<arr.size()-popped;i++){
        if (arr[i]==lastele){
            arr.erase(arr.begin()+k);
            arr.emplace_back(0);
            popped++;
            i--;
        }
        else{
            k++;
            lastele=arr[i];
        }
    }

    // print
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"k: "<<k;
}
bool searchInSorted(vector<int> arr, int k) {
    for (int i=0;i<arr.size();i++){
        if (arr[i]==k){
            return true;
        }
    }
    return false;
}


int main(){
    int n;
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.emplace_back(num);
    }
    // cout<<second_largest(arr);
    // cout<<check_sorted(arr);
    // remove_dublicate(arr);
    // moveZeros(arr);
    cout<<searchInSorted(arr,5);

}