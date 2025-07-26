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
ListNode * remove_last_nth(ListNode * head, int n){
    if (n<1) return head;
    ListNode * head2 = new ListNode(-1);
    head2->next = head;
    ListNode * fast = head2->next;
    ListNode * slow = head2;
    int c = 0;
    while(fast){
        if (c==n) break;
        fast = fast->next;  
        c++;
    }
    if (c==n){
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode * nextListNode = slow->next;
        slow->next = nextListNode->next;
        free(nextListNode);
    }
    return head2->next;
}
void print_ll(ListNode * head){
    ListNode * temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main(){
    vector <int>arr={5,4,3,2,1};
    ListNode * head = arr_to_linked_list(arr);
    head = remove_last_nth(head,3);
    print_ll(head);
    return 0;
}