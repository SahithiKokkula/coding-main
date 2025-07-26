#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val1) {
        val = val1;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int val1, TreeNode *left1, TreeNode *right1) {
        val = val1;
        left = left1;
        right = right1;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void buildParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == NULL) return;
        if (root->left) {
            parent[root->left] = root;
            buildParentMap(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            buildParentMap(root->right, parent);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        // Build parent map to traverse upwards
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParentMap(root, parent);
        
        // BFS queue
        queue<TreeNode*> q;
        q.push(target);
        
        // Visited set to avoid revisiting nodes
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        
        int distance = 0;
        
        while (!q.empty()) {
            int size = q.size();
            if (distance == k) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                break;
            }
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check left child
                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                // Check right child
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                // Check parent
                if (parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end()) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            distance++;
        }
        
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution solution;
    vector<int>ans = solution.distanceK(root,root->left->right,3);
    return 0;
}