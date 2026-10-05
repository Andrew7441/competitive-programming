// Codeforces 2229C1 — We Be Flipping (Easy Version)
// https://codeforces.com/problemset/problem/2229/C1
// Topic: greedy | Tags: implementation
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll& i : a) cin >> i;

    vector<int> ops;
    bool flipped = false;

    for(int i = n - 1; i >= 0; i--){
        bool isPositive = (a[i] > 0);

        if(flipped) isPositive = !isPositive;

        if(isPositive){
            flipped = !flipped;
            ops.push_back(i + 1);
        }
    }
    
    cout << ops.size() << '\n';
    for(int& i  : ops) cout << i << " ";
    cout << '\n';
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
💭 First Idea: Go from right to left tracking the flip parity; flip at i whenever the current value there is positive.
🧩 Key Property / Invariant: An operation at i never touches indices > i, so once the suffix is negative it stays negative.
✅ Key insight: Processing right to left makes every element negative, giving the minimum sum -sum|a_i| with at most n operations.
🔁 Recognition cue for next time: "Prefix flips, fix elements one by one" -> process from the right, keep a lazy flip flag.
⏱  Speed fix for next time: Use a boolean flip flag instead of actually negating prefixes.
🛠  Review: correct; O(n) -> Already optimal (validated with a simulator checker).
*/