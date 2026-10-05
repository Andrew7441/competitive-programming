// Codeforces 2036A — Quintomania
// https://codeforces.com/problemset/problem/2036/A
// Topic: implementation
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int& i : a) cin >> i;

    bool perf = true;

    for(int i = 0; i < n - 1; i++){
        if(abs(a[i] - a[i+1]) != 5 && abs(a[i] - a[i+1]) != 7){
            perf = false;
            break;
        }
    }

    if(perf) cout << "YES\n";
    else cout << "NO\n";
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
💭 First Idea: Check every adjacent difference is 5 or 7.
🧩 Key Property / Invariant: Perfect melody = all adjacent intervals in {5, 7}.
✅ Key insight: One pass over neighbours.
🔁 Recognition cue for next time: "Every adjacent pair must satisfy X" -> single loop with early break.
⏱  Speed fix for next time: Compute d = abs(a[i]-a[i+1]) once.
🛠  Review: correct; Already optimal.
*/
