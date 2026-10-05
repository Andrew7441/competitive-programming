// Codeforces 2147B — Multiple Construction
// https://codeforces.com/problemset/problem/2147/B
// Topic: constructive | Tags: math
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    for(int i = n; i >= 1; i--){
        cout << i << " ";
    }

    cout << n << " "; 

    for(int i = 1; i < n; i++){
        cout << i << " ";
    }

    cout << "\n";
    
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
💭 First Idea: Print n, n-1, ..., 1, then n, then 1, 2, ..., n-1.
🧩 Key Property / Invariant: x (< n) sits at positions n-x+1 and n+1+x -> distance 2x; n sits at 1 and n+1 -> distance n.
✅ Key insight: Mirror the numbers around a central n so every x is exactly 2x apart.
🔁 Recognition cue for next time: "Distance between equal elements must be a multiple of x" -> try symmetric (mirror) layouts.
⏱  Speed fix for next time: Try tiny n on paper and look for a mirror pattern.
🛠  Review: correct (verified with a checker for n = 1..59); O(n) -> Already optimal.
*/
