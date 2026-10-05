// Codeforces 2157A — Dungeon Equilibrium
// https://codeforces.com/problemset/problem/2157/A
// Topic: hashing | Tags: greedy
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

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }

        int res = 0;

        for(auto &[x, cnt] : mp){
            if(cnt >= x){
                res += cnt - x;
            }else{
                res += cnt; 
            }
        }

        cout << res << "\n";

    }

    return 0;
}

/*
💭 First Idea: Count each value x: keep exactly x copies if cnt >= x (delete cnt-x), else delete all.
🧩 Key Property / Invariant: Values are independent: each must appear exactly x times or not at all.
✅ Key insight: cnt >= x -> keep x, otherwise remove everything (0 always goes since it can't appear 0 times).
🔁 Recognition cue for next time: "Every x appears exactly x times" -> frequency map, decide per value.
⏱  Speed fix for next time: A frequency array of size n+1 beats unordered_map here.
🛠  Review: correct; O(n) -> Already optimal.
*/
