#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    long int n;
    cin>>n;
    long int stolen_val=0;
    vector<long int> arr;
    for(long int i=0;i<n;i++){
        long int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    while(arr.size()>=2){
        sort(arr.begin(),arr.end());
        long int a=arr[0];
        long int b=arr[1];
        long int s=a+b;
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        stolen_val+=s;
        arr.push_back(s);
    }
    cout<<stolen_val;
    

    return 0;
}