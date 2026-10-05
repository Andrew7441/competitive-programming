// Codeforces 231A — Team
// https://codeforces.com/problemset/problem/231/A
// Topic: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//Team 
//https://codeforces.com/problemset/problem/231/A
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k; cin >> k;
    int p,v,t;
    int res = 0;
    for(int i = 0; i < k; i++){
        cin >> p >> v >> t; 
         if(p + v + t > 1){
            res += 1; 
        }
    }

    cout << res; 
    
    return 0;
}

/*
💭 First Idea: Count problems where at least two of three friends are sure (sum > 1).
🧩 Key Property / Invariant: Values are 0/1, so 'at least two' is sum >= 2.
✅ Key insight: Summing booleans replaces case analysis.
🔁 Recognition cue for next time: 'At least k of these flags' -> sum the flags.
⏱  Speed fix for next time: Read and count in one loop.
🛠  Review: correct; Already optimal.
*/
