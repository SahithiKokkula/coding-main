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

void create_tree(TreeNode * root0, vector <int> &vec){
    queue <TreeNode *>q;
    int n = vec.size();
    q.push(root0);
    root0->val = vec[0];
    int index=1;
    while(!q.empty() && index < n){
        TreeNode * currTreeNode = q.front();
        q.pop();
        if(index < n) {
            currTreeNode->left = new TreeNode(vec[index++]);
            q.emplace(currTreeNode->left);
        }
        if(index < n) {
            currTreeNode->right = new TreeNode(vec[index++]);
            q.emplace(currTreeNode->right);
        }
    }
}
void find_height(TreeNode * root, int h,int & maxi){
    if(root->left == NULL && root->right == NULL) {
        maxi = max(maxi,h);
        return;
    }
    if (root->left != NULL) find_height(root->left,h+1,maxi);
    if (root->right != NULL) find_height(root->right,h+1,maxi);
}
int height(TreeNode * root){
    if (root == NULL) return 0;
    int maxi = 1;
    find_height(root,1,maxi);
    return maxi;
}
int height_2(TreeNode * root){
    if(root == NULL) return 0;
    int lh = height_2(root->left);
    int rh = height_2(root->right);
    return 1 + max(lh,rh);
}
int main(){
    TreeNode * root;
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    create_tree(root,arr);
    cout<<height(root)<<endl<<height_2(root);
    return 0;
}