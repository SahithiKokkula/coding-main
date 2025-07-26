#include<bits/stdc++.h>
using namespace std;
class k_algo {
private:
    vector<int>khan_algorithm(vector<vector<int>>&adj_list,int n){
        vector<bool>visited(n,0);
        vector<int>indegree(n,0);
        vector<int>result;
        for (auto it  : adj_list){
            for(auto itt : it){
                indegree[itt]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<n;i++){
            if (indegree[i]==0 ){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            result.push_back(curr);
            q.pop();
            for(auto it : adj_list[curr]){
                indegree[it]--;
                if (indegree[it]== 0){
                    q.push(it);
                }
            }

        }
        return result;
    }

public:
    vector<int> findOrder(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<vector<int>>adj_list(numCourses,vector<int>());
        for(auto it : prerequisites){
            adj_list[it.second].emplace_back(it.first);
        }
        vector<int>topo = khan_algorithm(adj_list , numCourses);
        vector<int>empty;
        return ((topo.size() == numCourses)?topo : empty);
    }
};

class Solution{
public:
int binaryGap(int num) {
    // Write your code here.
    int maxi = 0;
    int cnt = 0;
    while(num > 0){
        int curr = num & 1;
        num = num >> 1;
        if (curr == 1){
            cnt = 1;
        }
        else cnt++;
        maxi = max(maxi,cnt);
    }
    return maxi;
}
public:
int minSubArrayLen(vector<int>& arr, int target, int n) {
    // Write your code here.
    int i = 0;
    int j = 0;
    int currsum = 0;
    int minilen = INT_MAX;
    while(j<n){
        currsum += arr[j];
        while (currsum > target) {
            minilen = min(minilen, j - i + 1);
            currsum -= arr[i];
            i++;
        }
        j++;
    }
    return minilen;
}

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    // cout<<solution.binaryGap(11);
    int target = 8;
    int n = 4;
    vector<int>arr = {5,1,2,1};
    cout<< solution.minSubArrayLen(arr,target,n);
    return 0;
}




