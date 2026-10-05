// Codeforces 2193C — Replace and Sum
// https://codeforces.com/problemset/problem/2193/C
// Topic: prefix-sum | Tags: greedy
// Complexity (yours): O(n + q) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    a[n-1] = max({a[n-1], b[n-1]});
    for(int i = n - 2; i >= 0; i--){
        a[i] = max({a[i], b[i], a[i+1]});
    }

    vector<long long> prefix(n+1, 0);
    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: Each a_i can become any a_j or b_j with j >= i, so take the suffix max of max(a, b), then answer queries with prefix sums.
🧩 Key Property / Invariant: Copies only flow from right to left (a_i := a_{i+1}), and a_i := b_i lets b values enter the chain.
✅ Key insight: Best value at i = max over j >= i of max(a_j, b_j), independent of the query; prefix sums give each range in O(1).
🔁 Recognition cue for next time: "Replace a_i with a_{i+1} any number of times" -> suffix maximum.
⏱  Speed fix for next time: Precompute once per test case; queries are independent and need no simulation.
🛠  Review: correct; O(n + q) -> Already optimal (stress-tested vs BFS brute force).
*/
