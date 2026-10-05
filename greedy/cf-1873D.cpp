// Codeforces 1873D — 1D Eraser
// https://codeforces.com/problemset/problem/1873/D
// Topic: greedy | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int res = 0;
    int i = 0;
    while(i < n){
        if(s[i] == 'B'){
            res++;
            i+=k;
        }else{
            i++;
        }
    }

    cout << res << "\n";
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
💭 First Idea: Scan left to right; on the first 'B' erase k cells starting there and jump i += k.
🧩 Key Property / Invariant: The leftmost black cell must be covered; starting the window at it covers the most to the right.
✅ Key insight: Greedy interval covering: place each window as far right as possible.
🔁 Recognition cue for next time: 'Minimum fixed-length windows to cover points on a line' -> greedy from the left.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
