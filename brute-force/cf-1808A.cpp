// Codeforces 1808A — Lucky Numbers
// https://codeforces.com/problemset/problem/1808/A
// Topic: brute-force | Tags: math
// Complexity (yours): O(100 * digits) per test, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;

    int largestdiff = -1;
    int largestnum = l;

    for(int i = l; i <= min(r, l + 100); i++){
        int largest = INT_MIN, smallest = INT_MAX;
        string s = to_string(i);
        for(char& c: s){
            int d = c - '0';
            largest = max(largest, d);
            smallest = min(smallest, d);
        }

        int diff = largest - smallest;
        
        if(diff > largestdiff){
            largestdiff = diff;
            largestnum = i;
        }
    }

    cout << largestnum << "\n";
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
💭 First Idea: Brute-force numbers from l up to l+100, take the max (max digit - min digit).
🧩 Key Property / Invariant: Max possible luckiness is 9; any 100 consecutive numbers contain one ending in '90' (digits 9 and 0).
✅ Key insight: So checking at most ~100 numbers is enough even when r-l is huge.
🔁 Recognition cue for next time: Huge range + answer bounded by small constant -> brute force a small window.
⏱  Speed fix for next time: Break early once diff == 9.
🛠  Review: correct; Already optimal.
*/
