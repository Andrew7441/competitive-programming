// Codeforces 1923A — Moving Chips
// https://codeforces.com/problemset/problem/1923/A
// Topic: greedy | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int l = -1, r = -1, c = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            if(l == -1) l = i;
            r = i;
        }
    }

    for(int i = l; i <= r; i++){
        if(a[i] == 0) c++;
    }

    cout << c << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

/*
💭 First Idea: Count zeros between the first and the last 1.
🧩 Key Property / Invariant: Each operation can fill exactly one gap, and every gap inside [first1, last1] must be filled.
✅ Key insight: Answer = number of free cells between the leftmost and rightmost chip.
🔁 Recognition cue for next time: 'Make all items contiguous by moving one at a time' -> count holes in the span.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
