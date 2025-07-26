#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList[0].size();
        unordered_set<string>ust(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            string curr = node.first;
            int lvl = node.second;
            if (curr == endWord){
                return lvl;
            }
            for(int i = 0 ; i < n ; i++){
                string nword = curr;
                for(int j = 0 ; j < 26 ;j++){
                    nword[i] = 'a' + j;
                    if(ust.find(nword) != ust.end()){
                        ust.erase(nword);
                        q.push({nword,lvl+1});
                    }
                }

            }
        }
        return 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string beginWord = "hit", endWord = "cog";
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
    cout<<solution.ladderLength(beginWord,endWord,wordList)<<endl;
    return 0;
}