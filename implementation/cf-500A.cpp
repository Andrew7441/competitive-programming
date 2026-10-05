// Codeforces 500A — New Year Transportation
// https://codeforces.com/problemset/problem/500/A
// Topic: implementation | Tags: graphs, simulation
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, t;
    cin >> n >> t;

    vector<int> a(n + 1);
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }

    int position = 1;

    while(position < t){
        position += a[position];
    }

    cout << (position == t ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea: Start at cell 1 and follow portals (pos += a[pos]) until pos >= t.
🧩 Key Property / Invariant: Portals only go forward, so the path from 1 is unique.
✅ Key insight: Simulate and check if you land exactly on t.
🔁 Recognition cue for next time: 'Unique forward jumps' -> just simulate, no BFS needed.
⏱  Speed fix for next time: Already the fastest approach.
🛠  Review: correct; Already optimal.
*/