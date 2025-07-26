#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(int n,int m){
        int num;
        vector<int>zeroes(n);
        for(int i = 0; i < n ; i++){
            cin>>num;
            int zero = 0;
            int dig = 0;
            while(num%10 == 0) {
                zero++;
                num = num/10;
            }
            while(num){
                dig++;
                num/=10;
            }
            zeroes[i] = zero;
            m = m-dig;
        }
        sort(zeroes.begin(),zeroes.end(),greater<int>());
        for(int i = 1; i<n; i+=2){
            m = m-zeroes[i];
        }
        cout<<((m<0)?"Sasha":"Anna")<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        solution.solve(n,m);
    }
    return 0;
}