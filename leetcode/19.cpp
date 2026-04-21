#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n){
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for(int i = 0; i < n + 1; i++){
            fast = fast->next;
        }

        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};

void printList(ListNode* p){
    cout << "[ ";
    while(p){
        cout << p->val << " "; 
        p = p->next;
    }
    cout << "]";
}

int main() {
    //head = [1,2,3,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution S;

    head = S.removeNthFromEnd(head, 2);

    printList(head);
    
    return 0;
}