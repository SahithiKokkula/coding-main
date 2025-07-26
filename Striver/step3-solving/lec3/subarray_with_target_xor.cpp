#include<bits/stdc++.h>
using namespace std;
int number_of_xor_subarray(vector<int>nums,int target){
    unordered_map<int,int>mp;
    int n= nums.size();
    int xornum;
    int num = 0;
    for (int i = 0;i<n;i++){
        if (i==0) xornum = nums[i];
        else xornum = xornum^nums[i];
        
        if (xornum==target){
            num++;
        }
        else{
            if (mp.find(target^xornum)==mp.end()){
                mp[xornum]=i;
            }
            else{
                num++;
            }
        }
    }
    return num;
}
int main(){
    int target;
    cin>>target;
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<number_of_xor_subarray(nums,target);
    return 0;
    
}