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
    int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2){
        Trie trie;
        for(int i = 0 ; i< n ; i ++){
            trie.insert(arr1[i]);
        }
        int maxXOR = INT_MIN;

        for(int i = 0 ; i < m ; i++){
            maxXOR = max(maxXOR , trie.getMax(arr2[i]));
        }
        return maxXOR;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 7;
    int m = 7;
    vector<int>arr1 = {6,6,0,6,8,5,6};
    vector<int>arr2 = {1,7,1,7,8,0,2};
    cout<<solution.maxXOR(n,m,arr1,arr2);
    return 0;
}