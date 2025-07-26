#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    int h;
    vector<int>k_arr(q);
    vector<long long>heightt(n);
    vector<int>maxi_arr(n);
    int maxi=0;
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin>>h;
        sum+=h;
        maxi = max(maxi,h);
        maxi_arr[i]=maxi;
        heightt[i] = sum;
    }
    for(int i=0;i<q;i++){
        cin>>k_arr[i];
    }
    long long left;
    long long right;
    long long mid;
    for(int i=0;i<q;i++){
        if (k_arr[i]>=maxi){
            cout<<heightt[n-1]<<" ";
            continue;
        }
        long long ans = 0;
        left = 0;
        right = heightt.size();
        while (left <= right){
            mid = left + (right - left)/2;
            if (maxi_arr[mid] > k_arr[i]){
                right = mid - 1;
            }
            else{
                ans = max(ans,heightt[mid]);
                left = mid +1;
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}