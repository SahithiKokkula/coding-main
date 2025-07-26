#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &nums){
	int xorsum= nums[0];
    for(int i=1;i<nums.size();i++){
        xorsum = xorsum^nums[i];
    }
    return xorsum;
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
    cout<<getSingleElement(a);

}