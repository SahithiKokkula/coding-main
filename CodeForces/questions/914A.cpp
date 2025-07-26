#include<iostream>
#include<vector>
#include <climits>
#include<cmath>
using namespace std;
int perfsquare(vector<int>&nums,int& n){
    int maximum = INT_MIN;
    for(int i=0;i<n;i++){
        if (pow(int(pow(nums[i],.5)),2)!=nums[i]){
            maximum=max(maximum,nums[i]);
        }
    }
    return maximum;
    
}
int main(){
    int n;
    cin>>n;
    int num;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>num;
        nums[i]=num;
    }
    cout<<perfsquare(nums,n);
    return 0;
}