// Codeforces 2152A — Increase or Smash
// https://codeforces.com/problemset/problem/2152/A
// Topic: math | Tags: hashing, greedy
// Complexity (yours): O(n log n) time, O(n) space
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

        set<int> s;

        for(int i = 0; i < n; i++){
            int x; 
            cin >> x;
            s.insert(x);
        }
        cout << s.size() * 2 - 1 << '\n';
        
    }

    return 0;
}

/*
💭 First Idea: Answer = 2 * (#distinct values) - 1.
🧩 Key Property / Invariant: Each distinct value needs its own Increase; consecutive Increases need a Smash in between to separate groups.
✅ Key insight: Handle values from largest down: d increases + d-1 smashes, which is also a lower bound.
🔁 Recognition cue for next time: "Global add + reset a subset" -> each distinct target value costs a separate increase.
⏱  Speed fix for next time: Count distinct with a set (or sort + unique).
🛠  Review: correct; O(n log n) -> Already optimal.
*/
