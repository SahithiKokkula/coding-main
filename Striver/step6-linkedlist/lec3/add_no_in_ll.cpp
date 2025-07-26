#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    public:
    Node(int data1, Node * next1){
        data = data;
        next = next;
    }
    
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* arr_to_linked_list(vector<int>arr){
    int n = arr.size();
    Node * head = new Node(arr[0]);
    Node * mover = head;
    for(int i=1;i<n;i++){
        Node * temp = new Node(arr[i]);
        mover->next=temp;
        mover = temp;
    }
    return head;
}

Node * sum_number(Node * head1, Node *head2){
    Node * temp1 = head1;
    Node * temp2 = head2;
    int val;
    Node * dummynode = new Node(-1);
    Node * temp3 = dummynode;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL || carry != 0){
        val = carry;
        // int val1 = temp1?temp1->data:0;
        if (temp1) val +=temp1->data;
        if (temp2) val +=temp2->data;
        // int val2 = temp2?temp2->data:0;
        Node * newnode = new Node(val % 10);
        carry = val/10;
        temp3->next = newnode;
        if (temp1) temp1 = temp1->next;
        if (temp2) temp2 = temp2->next;
        temp3 = temp3->next;
    }
    return dummynode->next;
    
}
void print_ll(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    vector <int>arr1={4,5,9,9};
    vector<int>arr2={3,5};
    Node * head1 = arr_to_linked_list(arr1);
    Node * head2 = arr_to_linked_list(arr2);
    Node * head3 = sum_number(head1,head2);
    print_ll(head3);
    return 0;
}