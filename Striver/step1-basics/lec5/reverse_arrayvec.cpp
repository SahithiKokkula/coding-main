#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int> &arr,auto start=arr.begin(),auto end=arr.back()){
    if (start>end) return arr;
    arr.emplace_back(*(start));
    arr.erase(start);
    reverseArray(arr,start+1,end);
}
int main(){
    vector <int> arr;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.emplace_back(num);
    }
    reverseArray(arr,arr.begin(),arr.back());
    for (auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}