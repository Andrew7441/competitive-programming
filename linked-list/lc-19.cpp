// LeetCode 19 — Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Topic: linked-list | Tags: two-pointers
// Complexity (yours): O(L) time, O(1) space
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

/*
💭 First Idea: Dummy node + fast pointer n+1 steps ahead, then move both until fast is null; slow sits just before the target.
🧩 Key Property / Invariant: Gap between fast and slow stays exactly n+1 nodes.
✅ Key insight: The dummy head makes removing the real head (n == length) work with no special case.
🔁 Recognition cue for next time: "k-th node from the end in one pass" → two pointers with a fixed gap.
⏱  Speed fix for next time: Always start both pointers at a dummy node to kill head edge cases.
🛠  Review: correct; O(L) one pass, O(1) space — Already optimal.
*/
