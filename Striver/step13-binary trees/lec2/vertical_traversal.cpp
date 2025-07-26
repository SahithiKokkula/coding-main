#include<bits/stdc++.h>
using namespace std;
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
    vector<vector<int>>vertical_traversal(TreeNode * root){
        map<int,map<int,multiset<int>>> nodes; // col level values
        queue<pair<TreeNode*,pair<int,int>>> todo; // node col level
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode * node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            if (node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto p: nodes){
            vector<int>col;
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
int main(){
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;

    vector<vector<int>>result = solution.vertical_traversal(root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j];
            cout<<" ";
        }
        cout<<endl;
    }

}