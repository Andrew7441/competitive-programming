// Codeforces 1669B — Triple
// https://codeforces.com/problemset/problem/1669/B
// Topic: hashing | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
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

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        unordered_map<int, int>freq;
        bool found = false; 

        for(int i = 0; i < n; i++){
            freq[a[i]]++;
        }

        for(auto &p : freq){
            if(p.second >= 3){
                cout << p.first << "\n";
                found = true; 
                break;
            }
        }
        if(!found) cout << -1 << "\n";
    }

    return 0;
}


/*
💭 First Idea: Count frequencies in a hash map, print any value with count >= 3.
🧩 Key Property / Invariant: Only counts matter, not positions.
✅ Key insight: One pass of frequency counting answers 'does some value appear k times'.
🔁 Recognition cue for next time: 'Find a value appearing at least k times' -> frequency map/array.
⏱  Speed fix for next time: a_i <= n, so a plain vector<int> cnt(n+1) is faster and unhackable vs unordered_map.
🛠  Review: correct; Already optimal.
*/
