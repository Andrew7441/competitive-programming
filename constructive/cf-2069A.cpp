// Codeforces 2069A — Was there an Array?
// https://codeforces.com/problemset/problem/2069/A
// Topic: constructive | Tags: implementation
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> b(n-2);
 

        for(int i = 0; i < n - 2; i++){
            cin >> b[i];
        }

        bool valid = true;

        for(int i = 1; i < n - 3; i++){
            if(b[i - 1] == 1 && b[i] == 0 && b[i + 1] == 1){
                valid = false;
            }
        }

        if(valid){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

        
    }

    return 0;
}

/*
💭 First Idea: Answer NO iff b contains the pattern 1 0 1.
🧩 Key Property / Invariant: b_{i-1}=1 and b_{i+1}=1 force a_{i-1..i+2} all equal, contradicting b_i = 0.
✅ Key insight: Only the 1-0-1 pattern is impossible; any other b is constructible.
🔁 Recognition cue for next time: "Does an array exist for these local equal flags" -> look for a contradicting local pattern.
⏱  Speed fix for next time: Loop i from 1 to n-4 (indices of b) and check b[i-1], b[i], b[i+1].
🛠  Review: correct; Already optimal (verified vs brute force).
*/
