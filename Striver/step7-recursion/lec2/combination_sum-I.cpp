#include<bits/stdc++.h>
using namespace std;
void generate_combination(int index, int sum,vector<vector<int>>&ans,vector<int>curr,int target,vector<int>nums){
    if(sum > target){
        return;
    }
    else if (sum == target){
        ans.emplace_back(curr);
        return;
    }
    if (index == nums.size()) {
        return;
    }
    curr.emplace_back(nums[index]);
    generate_combination(index, sum + nums[index], ans, curr, target, nums);
    curr.pop_back();

    generate_combination(index + 1, sum, ans, curr, target, nums);
}
vector<vector<int>> combination_sum_I(vector<int>nums,int target){
    vector<vector<int>>ans;
    vector<int>curr;
    generate_combination(0,0,ans,curr,target,nums);
    return ans;
}
int main(){
    int target;
    cin>>target;
    int n;
    cin>>n;
    int num;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>num;
        nums.emplace_back(num);
    }
    vector<vector<int>>ans = combination_sum_I(nums,target);
    cout<<"ans array\n\n\n\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}