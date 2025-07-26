#include<bits/stdc++.h>
using namespace std;
void generate_combination(int index, vector<vector<int>>&ans,vector<int>curr,int target,vector<int>nums,int n){
    if (target == 0){
        ans.emplace_back(curr);
        return;
    }
    if (target < 0) return;
    if (index >= n) return;
    int last_ele = -1;
    for(int i=index;i<n;i++){
        if(nums[index]!=last_ele){
            last_ele = nums[i];
            curr.emplace_back(last_ele);
            generate_combination(i+1,ans,curr,target-last_ele,nums,nums.size());
        }
    }
}
vector<vector<int>> combination_sum_II(vector<int>nums,int target){
    vector<vector<int>>ans;
    vector<int>curr;
    sort(nums.begin(),nums.end());
    generate_combination(0,ans,curr,target,nums,nums.size());
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
    vector<vector<int>>ans = combination_sum_II(nums,target);
    cout<<"ans array\n\n\n\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}