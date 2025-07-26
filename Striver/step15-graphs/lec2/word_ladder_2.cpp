#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList[0].size();
        unordered_set<string>ust(wordList.begin(),wordList.end());
        queue<pair<vector<string>,int>>q;
        vector<vector<string>>ans;
        q.push({{beginWord},1});
        vector<string>string_used;
        int lvl = 0;
        int lst_ans_size = -1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            vector<string> curr = node.first;
            if (lvl < node.second){
                lvl ++;
                for(auto it: string_used){
                    ust.erase(it);
                }
            }
            string lst_word = curr.back();
            if (lst_word == endWord){
                if (lst_ans_size == -1){
                    ans.push_back(curr);
                    lst_ans_size = node.second;
                }
                else if (lst_ans_size == node.second){
                    ans.push_back(curr);
                }
            }
            for(int i = 0 ;i<n;i++){
                string nword = lst_word;
                for(char c = 'a' ; c <= 'z' ;c++){
                    nword[i] = c;
                    if(ust.find(nword) != ust.end()){
                        curr.push_back(nword);
                        q.push({curr,node.second+1});
                        curr.pop_back();
                        string_used.push_back(nword);
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList[0].size();
        unordered_set<string>ust(wordList.begin(),wordList.end());
        // queue<pair<vector<string>,int>>q;
        queue<vector<string>>q;
        vector<vector<string>>ans;
        q.push({beginWord});
        vector<string>string_used;
        int lvl = 0;
        int lst_ans_size = -1;
        while(!q.empty()){
            vector<string> curr = q.front();
            q.pop();
            if (lvl < curr.size()){
                lvl ++;
                for(auto it: string_used){
                    ust.erase(it);
                }
            }
            string lst_word = curr.back();
            if (lst_word == endWord){
                if (lst_ans_size == -1){
                    ans.push_back(curr);
                    lst_ans_size = curr.size();
                }
                else if (lst_ans_size == curr.size()){
                    ans.push_back(curr);
                }
            }
            for(int i = 0 ;i<n;i++){
                string nword = lst_word;
                for(char c = 'a' ; c <= 'z' ;c++){
                    nword[i] = c;
                    if(ust.find(nword) != ust.end()){
                        curr.push_back(nword);
                        q.push(curr);
                        curr.pop_back();
                        string_used.push_back(nword);
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string beginWord = "hit", endWord = "cog";
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ans = solution.findLadders(beginWord,endWord,wordList);
    for(auto it : ans){
        for(auto itt: it){
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}