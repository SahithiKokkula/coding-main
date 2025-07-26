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

class Solution{
public:
    void printInorder(TreeNode* cur)  { 
    if (cur == nullptr) 
        return; 
    
    printInorder(cur->left); 
    cout<<cur->val<<" ";
    printInorder(cur->right); 
} 
private:
    int sol1(TreeNode * root){
        if(root == NULL) return 0;
        int sum = 0;
        if(root->left) sum+=root->left->val;
        if(root->right) sum+=root->right->val;
        if(sum >= root->val){
            root->val = (root->left)?sol1(root->left):0 + (root->right)?sol1(root->right):0;
        }
        else{
            if (root->left) root->left->val = root->val;
            if (root->right) root->right->val = root->val;
        }
        return sum;
    }
public:
    TreeNode * convert_valid_children_sum_tree(TreeNode * root){
        int sum = sol1(root);
        return root;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    TreeNode *root = new TreeNode(50); 
    root->left = new TreeNode(7); 
    root->right = new TreeNode(2); 
    root->left->left = new TreeNode(3); 
    root->left->right = new TreeNode(5); 
    root->right->left = new TreeNode(1); 
    root->right->right = new TreeNode(30); 
    root = solution.convert_valid_children_sum_tree(root);
    solution.printInorder(root);
    return 0;
}