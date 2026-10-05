// Codeforces 1985A — Creating Words
// https://codeforces.com/problemset/problem/1985/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(|a|+|b|) per test
#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a, b;
    cin >> a >> b;

    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    cout << a << " " << b << "\n";
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
💭 First Idea: Swap the first characters of a and b.
🧩 Key Property / Invariant: Only position 0 changes.
✅ Key insight: swap(a[0], b[0]).
🔁 Recognition cue for next time: "Swap the first character" -> direct std::swap.
⏱  Speed fix for next time: Use std::swap instead of a temp variable.
🛠  Review: correct; Already optimal. Duplicate of 1985A.cpp.
*/
