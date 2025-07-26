#include<bits/stdc++.h>
using namespace std;
struct job{
    int id;
    int dead;
    int profit;
};

class Solution{
private:
    static bool comp(job j1 , job j2){
        return j1.profit > j2.profit;
    }
public:
    int job_seq(vector<job>&jobs){
        sort(jobs.begin(),jobs.end(),comp);
        int maxdeadline = -1;
        for(auto it : jobs){
            maxdeadline = max(maxdeadline , it.dead);
        }
        int cnt  = 0;
        int prof = 0;
        vector<int>jobseq(maxdeadline+1,-1);
        for(auto it : jobs){
            int dline = it.dead;
            while (dline > 0 && jobseq[dline] != -1){
                dline--;
            }
            if(dline > 0){
                jobseq[dline] = it.id;
                cnt++;
                prof += it.profit;
            }
        }
        return prof;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<job>jobs = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
    cout<<solution.job_seq(jobs);
    return 0;
}