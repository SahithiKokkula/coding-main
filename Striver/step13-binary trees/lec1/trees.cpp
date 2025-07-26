#include<bits/stdc++.h>
using namespace std;

// defining the node
class Node{
    public:
    int data;
    Node * left;
    Node * right;

    public:
    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }

    public:
    Node(int data1, Node * left1, Node * right1){
        data = data1;
        left = left1;
        right = right1;
    }
};

void create_tree(Node * root0, vector <int> &vec){
    queue <Node *>q;
    int n = vec.size();
    q.push(root0);
    root0->data = vec[0];
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


// traversal in trees
// (BFS): breath first search 
/*
level traversal
*/

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
            level.push_back(newnode->data);
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

// (DSF): depth first search
/*
1. Inorder traversal (left root right)
2. preorder traversal (root left right)
3. post order tarversal (left right root)
*/

void preorder(Node * root){
    if (root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void iterative_preorder(Node * root){
    vector<int>ans;
    if(root == NULL) return;
    stack <Node *> s;
    s.push(root);
    while (!s.empty()){
        Node * newNode = s.top();
        ans.push_back(newNode->data);
        s.pop();
        if(newNode->right) s.emplace(newNode->right);
        if(newNode->left) s.emplace(newNode->left);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

void postorder(Node * root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void iterative_postorder_2_stacks(Node * root){
    vector<int>ans;
    stack<Node *>st1;
    stack<Node *>st2;
    st1.push(root);
    while(!st1.empty()){
        Node * curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }
    while (!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

void iterative_postorder_1_stack(Node * root){
    Node * curr = root;
    stack <Node *> st;
    vector <int> ans;
    while(curr != NULL || !st.empty()){
        if (curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node * temp = st.top()->right;
            if (temp == NULL){
                temp = st.top();
                st.pop();
                ans.emplace_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.emplace_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

void inorder(Node * root){
    if (root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void iterative_inorder(Node * root){
    vector<int>ans;
    if(root == NULL) return;
    stack <Node *> s;
    Node * node = root;
    while (true){
        if(node != NULL){
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    Node * root;
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    create_tree(root,arr);
    preorder(root);
    cout<<endl;
    iterative_preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    iterative_postorder_2_stacks(root);
    cout<<endl;
    iterative_postorder_1_stack(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    iterative_inorder(root);
    cout<<endl;
    level_tarversal(root);
    return 0;
}