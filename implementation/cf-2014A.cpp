// Codeforces 2014A — Robin Helps
// https://codeforces.com/problemset/problem/2014/A
// Topic: implementation | Tags: greedy
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        int rb = 0;
        int res = 0;

        for(int i = 1; i <= n; i++){
            if(a[i] >= k){
                rb += a[i];
            }
            if(a[i] == 0 && rb > 0){
                rb--;
                res++;
            }
        }

        cout << res << "\n";

    }

    return 0;
}

/*
💭 First Idea: Simulate: take all gold when a_i >= k, give 1 to each a_i == 0 while gold > 0.
🧩 Key Property / Invariant: Robin's gold only changes by taking or giving 1; order matters, so simulate left to right.
✅ Key insight: Straight simulation of the statement.
🔁 Recognition cue for next time: "Walk through people and update a counter" -> simulation.
⏱  Speed fix for next time: Index from 0 instead of allocating n+1.
🛠  Review: correct; Already optimal.
*/
