#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int max=0;
    int curr=0;
    for(int i=0;i<nums.size();i++){
        if (nums[i]==1){
            curr++;
        }
        else{
            curr=0;
        }
        if (curr>max){
            max=curr;
        }
    }
    return max;
}

int main(){

    vector<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.emplace_back(num);
    }
    cout<<findMaxConsecutiveOnes(a);

}