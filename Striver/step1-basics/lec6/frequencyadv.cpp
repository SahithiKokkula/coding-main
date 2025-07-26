#include<bits/stdc++.h>
using namespace std;
int frequencyCount(vector<int>& arr,int k){
    sort(arr.begin(),arr.end());
    long curr=0;
    int left=0;
    int ans=0;
    for(int right=0;right<arr.size();right++){
        long target=arr[right];
        curr+=target;
        while (((right-left+1)*target-curr)>k){
            curr-=arr[left];
            left++;
        }
        ans = max(ans,right-left+1);
    }
    return ans;
}
int main(){
    int n,k;
    cin>>k;
    cin>>n;
    
    vector<int>arr(n);
    while (n--){
        cin>>arr[n];
    }

    int ans = frequencyCount(arr,k);
    cout<<ans;
    return 0;
}