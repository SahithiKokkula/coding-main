#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>prices){
    int low=0;
    int high=0;
    int maxprofit=INT_MIN;
    int curr=0;
    while(high<prices.size()){
        curr = prices[high]-prices[low];
        if (curr>=0){
            maxprofit=max(curr,maxprofit);
            high++;
        }
        else{
            low=high;
        }
    }
    return maxprofit;
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
    cout<<maxProfit(a);
}