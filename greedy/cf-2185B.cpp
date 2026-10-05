// Codeforces 2185B — Prefix Max
// https://codeforces.com/problemset/problem/2185/B
// Topic: greedy | Tags: math
// Complexity (yours): O(n) time, O(n) space
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

        vector<int> a(n);
        for(int& i : a) cin >> i;

        int maximum = *max_element(a.begin(), a.end());

        int res = 0;
        for(int i = 0; i < n; i++){
            res += maximum;
        }
        cout << res << "\n";
    }

    return 0;
}

/*
💭 First Idea: Swap the global maximum to the front; every prefix max then equals max, so answer = n * max.
🧩 Key Property / Invariant: Every prefix max is <= max(a), and with max at position 1 all n prefixes reach that bound.
✅ Key insight: One swap is enough to put the maximum first, so the upper bound n * max is always reachable.
🔁 Recognition cue for next time: "Sum of prefix maxima with one swap" -> move the maximum to the front.
⏱  Speed fix for next time: Print n * max directly (fits in int: n <= 50, a_i <= 10^4).
🛠  Review: correct; O(n) -> Already optimal.
*/
