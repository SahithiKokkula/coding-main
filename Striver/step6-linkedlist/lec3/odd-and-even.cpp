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

Node * odd_even_seggrigate(Node * head){
    if (head == NULL || head->next == NULL) return head;
    Node * odd = head;
    Node * even = head->next;
    Node * evenHead = even;
    while (even && even->next){
        odd->next = odd->next->next;
        even->next= even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
void print_ll(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    vector <int>arr={1,2,3,4,5,6};
    Node * head = arr_to_linked_list(arr);
    head = odd_even_seggrigate(head);
    print_ll(head);
    return 0;
}