// Codeforces 2036B — Startup
// https://codeforces.com/problemset/problem/2036/B
// Topic: greedy | Tags: sorting, hashing
// Complexity (yours): O(k log k) per test
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, k;
    cin >> n >> k;

    map<int, int> mp;

    for(int i = 0; i < k; i++){
        int b, c;
        cin >> b >> c;
        mp[b] += c;
    }

    vector<int> sums;
    int ans = 0;

    for(auto& [k, v] : mp){
        sums.push_back(v);
    }

    sort(sums.rbegin(), sums.rend());

    for(int i = 0; i < min(n, (int)sums.size()); i++){
        ans += sums[i];
    }

    cout << ans << "\n";
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
💭 First Idea: Sum costs per brand in a map, sort sums descending, take the top n.
🧩 Key Property / Invariant: A shelf holds one brand, so each brand is all-or-nothing on one shelf (put all its bottles together).
✅ Key insight: Answer = sum of the n largest brand totals (all brands if fewer than n).
🔁 Recognition cue for next time: "Group items, choose at most n groups" -> aggregate per group, sort, take top n.
⏱  Speed fix for next time: Use a vector<long long> of size k+1 indexed by brand instead of map.
🛠  Review: correct; O(k log k), Already optimal.
*/