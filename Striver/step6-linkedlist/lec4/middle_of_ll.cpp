// Tortoise and Hare algorithm

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

ListNode * middle_of_ll(ListNode * head){
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print_ll(ListNode * head){
    ListNode * temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main(){
    vector <int>arr={1,2,3,4,5,6,7,8,9};
    ListNode * head = arr_to_linked_list(arr);
    ListNode * middle = middle_of_ll(head);
    cout<<middle->val;
    return 0;
}