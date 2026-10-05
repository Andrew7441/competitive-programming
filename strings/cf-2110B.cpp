// Codeforces 2110B — Down with Brackets
// https://codeforces.com/problemset/problem/2110/B
// Topic: strings | Tags: greedy, stack
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/2110/B Down with Brackets

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int bal = 0;

        for(size_t i = 1; i < s.length() - 1; i++){
            if(s[i] == '('){
                bal++;
            }else{
                bal--;
            }
            if(bal < 0){
                cout << "YES" << endl;
                break;
            }
        }
        if(bal == 0){
            cout << "NO" << endl;
        }
        

    }

    return 0;
}

/*
💭 First Idea: Drop the first '(' and last ')' and check if the inner prefix balance ever goes negative.
🧩 Key Property / Invariant: Removing s[0] and s[n-1] is the strongest attack; the result is unbalanced iff s is NOT of the form (A) with A balanced.
✅ Key insight: Equivalently: YES iff the prefix balance of s hits 0 before the end (s splits into >= 2 blocks).
🔁 Recognition cue for next time: Balanced brackets + delete one '(' and one ')' -> think prefix balance / primitive blocks.
⏱  Speed fix for next time: Count how often the balance returns to 0; YES iff >= 2.
🛠  Review: correct; O(n) -> Already optimal.
*/
