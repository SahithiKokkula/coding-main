#include<bits/stdc++.h>
using namespace std;
int longestSubArray(vector<int> &nums,int target){
	int i=0;
    int j=0;
    int n=nums.size();
    int maxlen=0;
    int curr=0;
    while (i<n && j<n){ 
        if (i>j){
            j++;
        }
        else if (curr<target){
            curr+=nums[j++];
        }
        else if (curr>target){
            curr-=nums[i++];
        }
        if (curr ==  target){
            if (j-i>maxlen){
                maxlen=j-i;
            }
            curr+=nums[j++];
            curr-=nums[i++];
        }
    }
    return maxlen;
}

int main(){
    int target;
    cin>>target;
    vector<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.emplace_back(num);
    }
    cout<<longestSubArray(a,target);
}