#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n= nums.size();
    int freq[n+1]={0};
    for (int i=0;i<n;i++){
        freq[nums[i]]++;
    }
    for(int i=0;i<n+1;i++){
        if(freq[i]==0){
            return i;
        }
    }
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
    cout<<missingNumber(a);

}