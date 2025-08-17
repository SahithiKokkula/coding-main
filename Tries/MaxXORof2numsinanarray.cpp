#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];

    bool containskey(int bit){
        return (links[bit] != NULL);
    }
    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit]=node;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
public:
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(!node->containskey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
public:
    int getMax(int num){
        Node* node = root;
        int maxNum=0;
        for(int i=31; i>=0; i--){
            int bit= (num>>i) & 1;
            if(node->containskey(1-bit)){
                maxNum = maxNum | (1<<i);
                node= node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie(); 
        int ans = 0; 
        for (int num : nums) {
            trie->insert(num); 
            ans = std::max(ans, trie->getMax(num)); 
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}