#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

ex:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while(cur){
            if(cur->next && cur->val == cur->next->val){
                int dup = cur->val;

                while(cur && cur->val == dup){
                    cur = cur->next;
                }
                prev->next = cur;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy.next;
    }

    void printList(ListNode* head){
        cout << "[ ";
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << "]";
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution S;

    head = S.deleteDuplicates(head);

    S.printList(head);
    
    return 0;
}