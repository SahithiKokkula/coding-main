// Shortest Job first algorithm

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int sjf(vector<int>&jobs){
        int n = jobs.size();
        sort(jobs.begin(),jobs.end());
        int net_waiting_time = 0;
        int prev_time = 0;
        for(int i = 1 ; i < n ; i++){
            prev_time += jobs[i-1];
            net_waiting_time += prev_time;
        }
        return net_waiting_time/n;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>jobs = {3, 1, 4, 2, 5};
    cout<<solution.sjf(jobs)<<endl;
    return 0;
}