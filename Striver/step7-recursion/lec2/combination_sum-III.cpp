#include<bits/stdc++.h>
using namespace std;
void generate_combination(int index, vector<vector<int>>&ans,vector<int>curr,int k,int n,int ele){
    if (n == 0 && index == k){
        ans.emplace_back(curr);
        return;
    }
    if (n < 0) return;
    if (index >= k) return;
    for(int i=ele+1;i<10;i++){
        if (n - i < 0) break;
        curr.emplace_back(i);
        generate_combination(index+1,ans,curr,k,n-i,i);
        curr.pop_back();
    }
}
vector<vector<int>> combination_sum_III(int k,int n){
    vector<vector<int>>ans;
    vector<int>curr;
    generate_combination(0,ans,curr,k,n,0);
    return ans;
}
int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<vector<int>>ans = combination_sum_III(k,n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}