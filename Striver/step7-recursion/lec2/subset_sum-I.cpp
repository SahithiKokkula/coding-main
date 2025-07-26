#include<bits/stdc++.h>
using namespace std;
void generate_subset(int index, vector<int>&ans, int sum, vector<int>arr, int n){
    if (index >= n){
        ans.emplace_back(sum);
        return;
    }
    generate_subset(index+1, ans, sum + arr[index], arr, n);
    generate_subset(index+1, ans, sum, arr, n);

}
vector<int> subsetSums(vector<int>& arr) {
    vector<int>ans;
    vector<int>curr;
    generate_subset(0, ans, 0, arr, arr.size());
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    int num;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.emplace_back(num);
    }
    vector<int>ans = subsetSums(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}