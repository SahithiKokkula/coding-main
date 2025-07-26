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
// method 1
Node * sort_0_1_2_m_1(Node * head){
    if (head == NULL || head->next == NULL) return head;
    Node * dummy0 = new Node(-1);
    Node * dummy0retain = dummy0;
    Node * dummy1 = new Node(-1);
    Node * dummy1retain = dummy1;
    Node * dummy2 = new Node(-1);
    Node * dummy2retain = dummy2;
    Node * temp = head;
    while (temp){
        if (temp->data == 0){
            Node * newNode = new Node(0);
            dummy0->next=newNode;
            dummy0 = dummy0->next;
        }
        else if (temp->data == 1){
            Node * newNode = new Node(1);
            dummy1->next=newNode;
            dummy1 = dummy1->next;
        }
        if (temp->data == 2){
            Node * newNode = new Node(2);
            dummy2->next=newNode;
            dummy2 = dummy2->next;
        }
        temp = temp->next;
    }
    Node * dummy = new Node(-1);
    Node * dummyretain = dummy;
    if (dummy0->data!=-1){
        dummy->next = dummy0retain->next;
        dummy = dummy0;
    }
    if (dummy1->data!=-1){
        dummy->next = dummy1retain->next;
        dummy = dummy1;
    }
    if (dummy2->data!=-1){
        dummy->next = dummy2retain->next;
        dummy = dummy2;
    }
    return dummyretain->next;
}
Node * sort_0_1_2_m_2(Node * head){
    if (head == NULL || head->next == NULL) return head;
    Node * dummy0 = new Node(-1);
    Node * dummy0retain = dummy0;
    Node * dummy1 = new Node(-1);
    Node * dummy1retain = dummy1;
    Node * dummy2 = new Node(-1);
    Node * dummy2retain = dummy2;
    Node * temp = head;
    while (temp){
        if (temp->data == 0){
            dummy0->next=temp;
            dummy0 = dummy0->next;
        }
        else if (temp->data == 1){
            dummy1->next=temp;
            dummy1 = dummy1->next;
        }
        else if (temp->data == 2){
            dummy2->next=temp;
            dummy2 = dummy2->next;
        }
        temp = temp->next;
    }
    Node * dummy = new Node(-1);
    Node * dummyretain = dummy;
    if (dummy0->data!=-1){
        dummy->next = dummy0retain->next;
        dummy = dummy0;
    }
    if (dummy1->data!=-1){
        dummy->next = dummy1retain->next;
        dummy = dummy1;
    }
    if (dummy2->data!=-1){
        dummy->next = dummy2retain->next;
        dummy = dummy2;
    }
    return dummyretain->next;
}
void print_ll(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    vector <int>arr={2,2,0,0,1,0,2,1,1,0,2,1,0,1,0,1,2};
    Node * head = arr_to_linked_list(arr);
    // head = sort_0_1_2_m_1(head); //method 1
    head = sort_0_1_2_m_2(head); //method 2
    print_ll(head);
    return 0;
}