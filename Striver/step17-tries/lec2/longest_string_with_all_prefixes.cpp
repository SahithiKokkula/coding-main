#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node * links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node * node) {
        links[ch - 'a'] = node;
    }

    Node * get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node * root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node * node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

    bool checkprefixExists(string word){
        bool falg = true;
        Node * node = root;
        for(int i = 0 ; i < word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(!node->isEnd()){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution{
private:
    string completeString(int n, vector<string> &a){
        // Write your code here.
        Trie trie;
        for(int i = 0 ; i < n ; i++){
            trie.insert(a[i]);
        }
        string ans = "";
        for(string it:a){
            if(trie.checkprefixExists(it)){
                if(it.length() > ans.length()){
                    ans = it;
                }
                if(it.length() == ans.length()){
                    ans = min(ans,it);
                }
            }
        }
        return ans.length()?ans:"None";
    }
public:
    void solve(){
        int n;
        cin>>n;
        vector<string>a(n);
        for(int i = 0 ; i < n ; i ++){
            cin>>a[i];
        }
        cout<<completeString(n,a)<<endl;
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