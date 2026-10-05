// Codeforces 1669A — Division?
// https://codeforces.com/problemset/problem/1669/A
// Topic: implementation
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n >= 1900){
            std::cout << "Division 1\n";
        }else if(n >= 1600 && n <= 1899){
            std::cout << "Division 2\n";
        }else if(n >= 1400 && n <= 1599){
            std::cout << "Division 3\n";
        }else{
            std::cout << "Division 4\n";
        }
    }

    return 0;
}

/*
💭 First Idea: Compare rating against thresholds 1900/1600/1400.
🧩 Key Property / Invariant: Thresholds are checked top-down so upper bounds are redundant.
✅ Key insight: Simple if-else chain.
🔁 Recognition cue for next time: Ranges → if/else from largest threshold down.
⏱  Speed fix for next time: Drop the redundant `&& n <= 1899` checks.
🛠  Review: correct; O(1) — Already optimal.
*/
