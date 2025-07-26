#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int m_arrays(int n ,int m){
        vector<int>array(m,0);
        int num;
        for(int i = 0;i <n;i++){
            cin>>num;
            array[num%m]++;
        }
        
        if (n == 1) return 1;

        int no_af_arrays = (array[0] == 0)? 0 : 1;
        int i = 1 ,j = m - 1;
        while(i<=j){
            if (array[i] == array[j] && array[i]!=0){
                no_af_arrays ++;
            }
            else {
                no_af_arrays += (max(array[i],array[j]) - (min(array[i],array[j])+1)) + 1;
            }
            i++;j--;
        }
        return no_af_arrays;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin >> t;
    while(t--){
        long long n , m;
        cin>>n>>m;
        Solution solution;
        int result = solution.m_arrays(n,m);
        cout<<result<<endl;
    }
    return 0;
}
