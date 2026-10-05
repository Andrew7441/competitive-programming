// Codeforces 1999C — Showering
// https://codeforces.com/problemset/problem/1999/C
// Topic: implementation | Tags: greedy, sorting
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, s, m;
        cin >> n >> s >> m;

        vector<pair<long long, long long>> segs(n);

        for(int i = 0; i < n; i++){
            cin >> segs[i].first >> segs[i].second;
        }
        bool ok = false;

        if(segs[0].first >= s){
            ok = true;
        }

        for(int i = 1; i < n; i++){
            if(segs[i].first - segs[i-1].second >= s){
                ok = true;
            }
        }

        if(m - segs[n-1].second >= s){
            ok = true;
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}

/*
💭 First Idea: Check the gap before the first task, between consecutive tasks, and after the last.
🧩 Key Property / Invariant: Intervals are given sorted and non-overlapping, so free time = the gaps between them.
✅ Key insight: YES iff some gap (l1-0, l_{i+1}-r_i, m-r_n) >= s.
🔁 Recognition cue for next time: "Is there a free window of length s among sorted intervals" -> scan consecutive gaps.
⏱  Speed fix for next time: Keep prev = 0, update prev = r, check l - prev >= s; final m - prev.
🛠  Review: correct; Already optimal.
*/
