// Codeforces 1692A — Marathon
// https://codeforces.com/problemset/problem/1692/A
// Topic: implementation
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1692/A Marathon

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 

    while(t--){
        int res = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a < b) res++;
        if(a < c) res++;
        if(a < d) res++;
        
        cout << res << endl;
    }

    return 0;
}

/*
💭 First Idea: Count how many of b, c, d are greater than a.
🧩 Key Property / Invariant: Distinct values, so a strict comparison suffices.
✅ Key insight: Just three comparisons.
🔁 Recognition cue for next time: Div-4 A: read, compare, print.
⏱  Speed fix for next time: res = (b>a)+(c>a)+(d>a) in one line.
🛠  Review: correct; Already optimal.
*/
