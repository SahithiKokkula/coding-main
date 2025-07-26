#include<bits/stdc++.h>
using namespace std;

// defining the TreeNode
class TreeNode{
    public:
    int val;
    TreeNode * left;
    TreeNode * right;

    public:
    TreeNode(int val1){
        val = val1;
        left = nullptr;
        right = nullptr;
    }

    public:
    TreeNode(int val1, TreeNode * left1, TreeNode * right1){
        val = val1;
        left = left1;
        right = right1;
    }
};

class Solution{
public:
    vector<int>top_view(TreeNode * root){
        map<int,int>nodes;
        vector<int>ans;
        if (!root ) return ans;
        queue<pair<TreeNode * ,int>>todo;
        todo.push({root,0});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            int x = p.second;
            nodes[x]= p.first->val;
            if (p.first->left){
                todo.push({p.first->left , x -1});
            }
            if (p.first->right){
                todo.push({p.first->right , x +1});
            }
        }
        for(auto it : nodes){
            ans.emplace_back(it.second);
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    Solution solution;
    vector<int> result = solution.top_view(root);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}