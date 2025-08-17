#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2] = {nullptr, nullptr};

    bool containskey(int bit) {
        return (links[bit] != NULL);
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containskey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containskey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else if (node->containskey(bit)) {
                node = node->get(bit);
            } else {
                return -1; // no valid element
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<tuple<int,int,int>> OQ; 
        for (int i = 0; i < queries.size(); i++) {
            int xi = queries[i][0];
            int mi = queries[i][1];
            OQ.push_back({mi, xi, i});  // (mi, xi, query_index)
        }

        sort(OQ.begin(), OQ.end());

        vector<int> ans(queries.size(), 0);
        Trie trie;
        int idx = 0;

        for (int i = 0; i < OQ.size(); i++) {
            int mi = get<0>(OQ[i]);
            int xi = get<1>(OQ[i]);
            int qidx = get<2>(OQ[i]);

            while (idx < nums.size() && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }

            if (idx == 0) {
                ans[qidx] = -1;
            } else {
                ans[qidx] = trie.getMax(xi);
            }
        }

        return ans;
    }
};
