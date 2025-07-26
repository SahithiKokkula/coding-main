#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node * links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    Node * get(int bit){
        return links[bit];
    }

    void put(int bit, Node * node){
        links[bit] = node;
    }
};
class Trie{
private:
    Node * root;
public:
    Trie(){
        root = new Node();
    }
public:
    void insert(int num){
        Node * node = root;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
public:
    int getMax(int num){
        int maxNum = 0;
        Node * node = root;
        for(int i = 31 ; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};


class Solution{
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int q = queries.size();
        vector<int>ans(q,-1);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> offlineQueries; // mi , xi , idx
        for(int i = 0 ; i < q; i ++){
            offlineQueries.emplace_back(queries[i][1], make_pair(queries[i][0], i));
        }
        sort(offlineQueries.begin(),offlineQueries.end());

        int idx = 0 ; 
        for(int i = 0 ; i < q; i ++){
            int mi = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int queryIdx = offlineQueries[i].second.second;
            while(idx < n && nums[idx] <= mi){
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx == 0) ans[queryIdx] = -1;
            else ans[queryIdx] = trie.getMax(xi);
        }
        return ans;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {0,1,2,3,4};
    vector<vector<int>>queries = {{3,1},{1,3},{5,6}};
    vector<int>ans = solution.maximizeXor(nums,queries);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}