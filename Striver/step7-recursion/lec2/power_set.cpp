#include<bits/stdc++.h>
using namespace std;
void s_fun(vector<int>arr, int index, vector<vector<int>>&ans,int n,vector<int>nums){
    if (index >= n){
        ans.push_back(arr);
        return;
    }
    arr.push_back(nums[index]);
    s_fun(arr,index+1,ans,n,nums);
    arr.pop_back();
    s_fun(arr,index+1,ans,n,nums);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>arr;
    s_fun(arr,0,ans,nums.size(),nums);
    return ans;
}
int main(){
    vector<int>nums = {1,2,3,4,5};
    vector<vector<int>> subarray = subsets(nums);
    cout<<subarray.size()<<endl<<endl;
    for(int i = 0;i<subarray.size();i++){
        for(int j=0;j<subarray[i].size();j++){
            cout<<subarray[i][j]<<" ";
        }
        cout<<endl;
    }
}