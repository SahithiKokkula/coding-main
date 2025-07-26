// Tortoise and Hare algorithm

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node * bottom;

    public:
    Node(int data1, Node * next1,Node * bottom1){
        bottom = bottom1;
        data = data1;
        next = next1;
    }
    
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        bottom = nullptr;
    }
};

Node * merge(Node * l1, Node * l2){
    Node * dummynode = new Node(-1);
    Node * dummyNode = dummynode;
    while(l1 && l2){
        if (l1->data < l2->data){
            dummyNode->bottom = l1;
            dummyNode = dummyNode->bottom;
            l1 = l1->bottom;
        }
        else{
            dummyNode->bottom = l2;
            dummyNode = dummyNode->bottom;
            l2 = l2->bottom;
        }
    }
    if (l1) dummyNode->bottom = l1;
    if (l2) dummyNode->bottom = l2;
    return dummynode->bottom;
}

Node * flatten(Node * root){
    if (root == NULL || root->next == NULL) return root;
    root->next = flatten(root->next);
    return merge(root,root->next); 
}

