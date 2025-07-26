#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode * next;

    public:
    ListNode(int val1, ListNode * next1){
        val = val;
        next = next;
    }
    
    public:
    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};

ListNode* arr_to_linked_list(vector<int>arr){
    int n = arr.size();
    ListNode * head = new ListNode(arr[0]);
    ListNode * mover = head;
    for(int i=1;i<n;i++){
        ListNode * temp = new ListNode(arr[i]);
        mover->next=temp;
        mover = temp;
    }
    return head;
}

// Iterative 
ListNode * reverse_ll(ListNode * head){
    if (head == NULL || head->next == NULL) return head;
    ListNode * temp = head->next;
    ListNode * prev = head;
    prev->next = nullptr;
    ListNode * next;
    while (temp){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

// Recurrsive
ListNode * reverse_ll_recurrsive(ListNode * head){
    if(head == NULL || head->next == NULL) return head;
    ListNode * newhead = reverse_ll_recurrsive(head->next);
    ListNode * front = head->next;
    front->next = head;
    head->next = nullptr;
    return newhead;
}

void print_ll(ListNode * head){
    ListNode * temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main(){
    vector <int>arr={1,2,3,4,5,6};
    ListNode * head = arr_to_linked_list(arr);
    head = reverse_ll_recurrsive(head);
    print_ll(head);
    return 0;
}