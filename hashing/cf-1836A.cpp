// Codeforces 1836A — Destroyer
// https://codeforces.com/problemset/problem/1836/A
// Topic: hashing | Tags: sorting, greedy
// Complexity (yours): O(n + 100) time, O(100) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> cnt(100, 0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++; 
    }   

    bool f = true;

    for(int i = 1; i < 100; i++){
        if(cnt[i] > cnt[i-1]){
            f = false;
            break;
        }
    }

    cout << (f ? "YES\n" : "NO\n");
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
💭 First Idea: Count occurrences of each l, require cnt[i] <= cnt[i-1] for all i.
🧩 Key Property / Invariant: Every robot reporting i needs a distinct robot reporting i-1 in front of it.
✅ Key insight: Lines exist iff counts are non-increasing in the reported value.
🔁 Recognition cue for next time: 'Group items into chains 0,1,2,...' -> counts must be non-increasing.
⏱  Speed fix for next time: l_i < 100, so cnt(100) is exactly enough; use 101 if unsure of bounds.
🛠  Review: correct; Already optimal.
*/