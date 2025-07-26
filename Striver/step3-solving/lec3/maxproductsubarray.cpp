#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    int n=nums.size();
    int pref=1;
    int suff=1;
    int ans = INT_MIN;
    for (int i=0;i<n;i++){
        if (pref==0) pref =1;
        if (suff==0) suff=1;

        pref *= nums[i];
        suff *= nums[n-i-1];
        ans = max(ans,max(pref,suff));
    }
    return ans;
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
    cout<<maxProduct(arr);
    return 0;
}