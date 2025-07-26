#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node * links[26];

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node * node) {
        links[ch - 'a'] = node;
    }

    Node * get(char ch) {
        return links[ch - 'a'];
    }

};


class Solution{
private:
    int countDistinctSubstrings(string &s){
        int cnt = 0 ;
        Node * root = new Node();
        int n = s.length();
        for(int i = 0 ; i < n ; i ++){
            Node * node = root;
            for(int j = i ; j < n ; j++ ){
                if(!node->containsKey(s[j])){
                    node->put(s[j], new Node());
                    cnt++;
                }
                node = node->get(s[j]);
            }
        }
        return cnt + 1;
    }
public:
    void solve(){
        string s;
        cin>>s;
        cout<<countDistinctSubstrings(s);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        solution.solve();
    }
    return 0;
}