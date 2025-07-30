#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void markparent(TreeNode* &root,unordered_map <TreeNode*, TreeNode*> &parent_track,     TreeNode* &target){
        queue <TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            TreeNode* cur = qu.front();
            qu.pop();

            if(cur->left){
                parent_track[cur->left]=cur;
                qu.push(cur->left);
            }
            if(cur->right){
                parent_track[cur->right]=cur;
                qu.push(cur->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*, TreeNode*> parent_track;
        markparent(root, parent_track,target);

        unordered_map <TreeNode*, bool> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis[target]= true;
        int dist=0;

        while(!q.empty()){
            int size = q.size();
            if(dist++ == k){
                break;
            }
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && vis[curr->left]==false){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && vis[curr->right]==false){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent_track[curr] && vis[parent_track[curr]]==false){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]]=true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}