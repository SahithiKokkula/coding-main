#include<bits/stdc++.h>
using namespace std;

// defining the Node
class Node{
    public:
    int val;
    Node * left;
    Node * right;

    public:
    Node(int val1){
        val = val1;
        left = nullptr;
        right = nullptr;
    }

    public:
    Node(int val1, Node * left1, Node * right1){
        val = val1;
        left = left1;
        right = right1;
    }
};

void create_tree(Node * root0, vector <int> &vec){
    queue <Node *>q;
    int n = vec.size();
    q.push(root0);
    root0->val = vec[0];
    int index=1;
    while(!q.empty() && index < n){
        Node * currNode = q.front();
        q.pop();
        if(index < n) {
            currNode->left = new Node(vec[index++]);
            q.emplace(currNode->left);
        }
        if(index < n) {
            currNode->right = new Node(vec[index++]);
            q.emplace(currNode->right);
        }
    }
}

void zigzagtraversal(Node * root){
    vector<vector<int>>ans;
    bool lefttoright = true;
    if (root == NULL ) ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            int index = lefttoright?i:size-i-1;
            Node * newNode = q.front();
            q.pop();
            if(newNode->left != NULL) q.push(newNode->left);
            if(newNode->right != NULL) q.push(newNode->right);
            level[index] = newNode->val;
        }`
        lefttoright = !lefttoright;
        ans.push_back(level);
    }
    for(int i=0;i<ans.size();i++){
        for (int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

void level_tarversal(Node * root){
    vector<vector<int>>ans;
    if (root == NULL ) ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node * newnode = q.front();
            q.pop();
            if(newnode->left != NULL) q.push(newnode->left);
            if(newnode->right != NULL) q.push(newnode->right);
            level.push_back(newnode->val);
        }
        ans.push_back(level);
    }
    
    for(int i=0;i<ans.size();i++){
        for (int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node * root;
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    create_tree(root,arr);
    level_tarversal(root);
    zigzagtraversal(root);
    return 0;
}