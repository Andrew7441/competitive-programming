// LeetCode 2011 — Final Value of Variable After Performing Operations
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Topic: implementation | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string op : operations){
            if(op == "X++" || op == "++X") x++;
            else x--;
        }
        return x;
    }
};

int main() {

    Solution Sol;

    vector<string> operations{"--X","X++","X++"};

    cout << Sol.finalValueAfterOperations(operations);
    
}

/*
💭 First Idea: Compare each operation to "X++"/"++X" and increment, otherwise decrement.
🧩 Key Property / Invariant: The middle character op[1] is always the sign of the operation.
✅ Key insight: x += (op[1] == '+') ? 1 : -1 avoids string comparisons.
🔁 Recognition cue for next time: "simulate simple commands" -> direct loop.
⏱  Speed fix for next time: Iterate by const string& to avoid copying each op.
🛠  Review: correct; O(n) -> Already optimal.
*/
