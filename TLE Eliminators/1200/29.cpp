#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int cat_cycle_odd(long long n, long long k){
        long long hit = 0;
        long long lenght_dublicate = (n * (n-1)/2);
        k = k % lenght_dublicate;
        if (k == 0) k = lenght_dublicate;
        long long recursive_length = (n -1)/2;
        hit  = (k-1)/recursive_length;
        long long calc = (k + hit) % n;
        return (calc)? calc:n;
    }
    int cat_cycle_even(long long n, long long k){
        k = k % n;
        return (k == 0)?n:k;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin >> t;
    while(t--){
        long long n , k;
        cin>>n>>k;
        Solution solution;
        int result = (n&1)?solution.cat_cycle_odd(n,k):solution.cat_cycle_even(n,k);
        cout<<result<<endl;
    }
    return 0;
}
