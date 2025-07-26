#include<bits/stdc++.h>
using namespace std;
int mooreVotingAlgo(vector<int>v){
    // Moore’s Voting Algorithm
    int ele;
    int count =0;
    for (int i=0;i<v.size();i++){
        if(count==0){
            ele=v[i];
        }
        
        if(v[i]==ele){
            count++;
        }
        else{
            count--;
        }
        
    }
    return ele;
}
int majorityElement(vector<int>v){
    // Moore’s Voting Algorithm
    int MooreNo=mooreVotingAlgo(v);
    int count =0;
    int n=v.size();
    for (int i=0;i<n;i++){
        if(v[i]==MooreNo){
            count++;
        }
        if(count>n/2){
            return MooreNo;
        }
    }
    return -1;
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
    cout<<majorityElement(a);
}