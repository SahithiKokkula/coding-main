#include<bits/stdc++.h>

#include <sstream>
using namespace std;
struct Node {
    map <string,Node * > links;
    bool end = false;

    bool containsKey(string f) {
        return (links.find(f) != links.end());
    }

    void emptyLinks(){
        links.clear();
    }

    void setEnd(){
        end = true;
    }

    bool isEnd(){
        return end;
    }

    Node * get(string f) {
        return links[f];
    }
    
    void put(string f,Node * node){
        links[f] = node;
    }


};

class Trie {
private:
    Node * root;
public:
    Trie() {
        root = new Node();
    }

    void insert(vector<string>folders) {
        Node * node = root;
        for (int i = 0; i < folders.size(); i++) {
            if (!node->containsKey(folders[i])) {
                node->put(folders[i], new Node());
            }
            node = node->get(folders[i]);
        }
        node->setEnd();
    }

    

    bool path_exist(vector<string>folders){
        Node * node = root;
        for(int i = 0 ; i< folders.size() ; i++){
            if(node->containsKey(folders[i])){
                node  = node->get(folders[i]);
            }
            else{
                return false;
            }
        }
        node->emptyLinks();
        node->setEnd();
        return true;
    }
    
    void getFolders(vector<vector<string>>&ans,vector<string>&tempStr,Node * node){
        if(node == NULL) node = root;
        if(node->isEnd()){
            ans.push_back(tempStr);
        }

        for(auto it : node->links){
            tempStr.push_back(it.first);
            getFolders(ans,tempStr,it.second);
            tempStr.pop_back();
        }

    }
};

class Solution {
private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }
private:
    static bool compare(const string & a , const string & b){
        return a.length() > b.length();
    }

private:
    string mergeWithDelimiter(const vector<string>& vec, const char& delimiter) {
        string result = "/";
        for (size_t i = 0; i < vec.size(); ++i) {
            result += vec[i];
            if (i != vec.size() - 1) {
                result += delimiter;
            }
        }
        return result;
    }


public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        sort(folder.begin(),folder.end(), compare);
        for(auto it : folder){
            vector<string>folders = split(it, '/');
            if(!trie.path_exist(folders)){
                trie.insert(folders);
            }
        }
        vector<string>temp;
        vector<vector<string>>ans;
        vector<string>fans;
        trie.getFolders(ans,temp,NULL);
        for(auto it : ans){
            fans.push_back(mergeWithDelimiter(it, '/'));
        }
        return fans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<string>folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string>ans = solution.removeSubfolders(folder);
    for(string it : ans){
        cout<<it<<" ";
    }
    return 0;
}