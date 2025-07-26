#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,s,num;
    cin>>n>>s;
    int step = 0;
    int sum = 0;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>num;
        step +=1;
        if (num == 1){
            arr.emplace_back(step);
            sum++;
        }
    }
    if (s>sum){
        cout<<-1<<endl;
        return;
    }
    if (s==sum){
        cout<<0<<endl;
        return;
    }
    int left = 0;
    int right = sum;
    int v = 0;
    while(sum>s){
        if ()
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}