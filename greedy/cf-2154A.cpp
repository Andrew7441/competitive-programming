// Codeforces 2154A — Notelock
// https://codeforces.com/problemset/problem/2154/A
// Topic: greedy | Tags: strings
// Complexity (yours): O(n) time, O(1) space
// Note: File had no index; it is CF 2154A (Notelock). Correct, already optimal.
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;
    int lastOne = -1000000000;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(i - lastOne >= k){
                ans++;
            }
            lastOne = i;
        }    
    }

    cout << ans << "\n";
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
💭 First Idea: Count the '1's with no other '1' among the previous k-1 positions.
🧩 Key Property / Invariant: If nothing may change, the string stays original, so a '1' is changeable iff the k-1 cells before it (original) hold no '1'.
✅ Key insight: Exactly those '1's must be protected; all other '1's are safe automatically.
🔁 Recognition cue for next time: "Prevent all changes" -> final string = original, so evaluate conditions on the original.
⏱  Speed fix for next time: Track the last '1' index and compare the gap with k.
🛠  Review: correct (stress-tested vs brute force); O(n) -> Already optimal.
*/
