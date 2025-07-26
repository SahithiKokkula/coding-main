#include<bits/stdc++.h>
using namespace std;
void leaderElements(vector<int>nums){
    int n=nums.size();
    int maxele=INT_MIN;
    vector<int>leader;
    for (int i=n-1;i>=0;i--){
        if (nums[i]>maxele){
            leader.emplace_back(nums[i]);
            maxele=nums[i];
        }
    }
    reverse(leader.begin(),leader.end());
    for(auto it:leader){
        cout<<it<<" ";
    }
}
int main(){
    vector<int>a;
    int n;
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        a.emplace_back(num);
    }
    leaderElements(a);
}