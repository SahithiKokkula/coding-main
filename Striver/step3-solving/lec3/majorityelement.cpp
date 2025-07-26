#include<bits/stdc++.h>
using namespace std;
vector<int> majority_element(vector<int> nums,int n){
    int c1=0;
    int c2=0;
    int ele1,ele2;
    for(int i=0;i<n;i++){
        if (c1==0&& ele2!=nums[i]){
            ele1=nums[i];
            c1++;
        }
        else if (nums[i]==ele1){
            c1++;
        }
        else if (c2==0 && ele1!=nums[i]){
            ele2=nums[i];
            c2++;
        }
        else if (nums[i]==ele2){
            c2++;
        }
        else {
            c1--;
            c2--;
        }
    }
    c1=0;
    c2=0;
    int mini = (n/3)+1;
    vector<int>ls;
    for (int i=0;i<n;i++){
        if (nums[i]==ele1) c1++;
        if (nums[i]==ele2) c2++;
    }
    if (c1>=mini) ls.emplace_back(ele1);
    if (c2>=mini) ls.emplace_back(ele2);
    return ls;



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
    vector<int>ls=majority_element(nums,n);
    for(auto it:ls){
        cout<<it<<" ";
    }
    return 0;
}