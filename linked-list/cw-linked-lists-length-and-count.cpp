// Codewars — Linked Lists - Length & Count
// https://www.codewars.com/kata/55beec7dd347078289000021
// Topic: linked-list | Tags: traversal
// Complexity (yours): O(n) time, O(1) space

// NOTE (reorg): Codewars preloads this Node struct; added here only so the file compiles standalone.
#include <cstddef>
struct Node {
  Node *next;
  int data;
};

//Feb 24
/*

Linked Lists - Length & Count

Implement `length` to count the number of nodes in a linked list.  

Length(null) => 0
Length(1 -> 2 -> 3 -> null) => 3


Implement Count() to count the occurrences of an integer in a linked list.


Count(null, 1) => 0
Count(1 -> 2 -> 3 -> nullptr, 1) => 1
Count(1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 3 -> nullptr, 2) => 4

Node Definition:
struct Node {
  Node *next;
  int data;
}

*/

int Length(Node *head)
{
  int count = 0;
  while(head!= NULL){
    count++;
    head= head->next;
  }
  return count;
  
}

int Count(Node *head, int data)
{
  int count = 0;
  while(head != NULL){
    if(head->data==data){
      count++;
    }
    head= head->next;
  }
  return count;
  
  return 0;
}
/*
[Training on Linked Lists - Length & Count | Codewars](https://www.codewars.com/kata/55beec7dd347078289000021/train/cpp)
	this is the kata i worked on but has more examples i will refer back to
*/


/*
💭 First Idea: Walk the list with head = head->next, counting nodes (or matching data).
🧩 Key Property / Invariant: Traversal ends when the pointer becomes NULL.
✅ Key insight: Standard linear traversal; recursion is possible but the loop avoids stack depth.
🔁 Recognition cue for next time: "length / count in a singly linked list" -> while (head) { …; head = head->next; }
⏱  Speed fix for next time: Use nullptr instead of NULL; the trailing `return 0;` in Count is unreachable.
🛠  Review: correct; O(n) — Already optimal.
*/
