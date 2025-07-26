


#include <bits/stdc++.h>
using namespace std;
int longest_subarray(vector<int>nums){
    unordered_map<int,int>mp;
    int n= nums.size();
    int sum = 0;
    int max_len = 0;
    for (int i =0;i<n;i++){
        sum += nums[i];
        if (sum==0){
            max_len=max(max_len,i+1);
        }
        else{
            if (mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            else{
                max_len=max(max_len,i-mp[sum]);
            }
        }
    }
    return max_len;
}



int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<longest_subarray(nums);
    return 0;
}

