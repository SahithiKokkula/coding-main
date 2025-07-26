#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int a,b;
        cin>>a>>b;
        int num_pizza = (a+1)*4 + b*3;
        cout<< ceil(num_pizza/8)<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    solution.solve();

    return 0;
}