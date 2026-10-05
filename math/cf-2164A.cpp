// Codeforces 2164A — Sequence Game
// https://codeforces.com/problemset/problem/2164/A
// Topic: math | Tags: sorting
// Complexity (yours): O(n log n) time, O(n) space
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
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());


        int x;
        cin >> x;

        long long mn = *min_element(a.begin(), a.end());
        long long mx = *max_element(a.begin(), a.end());

        if(n == 1){
            cout << (a[0] == x ? "YES\n" : "NO\n");
        }else{
            cout << ((mn <= x && mx >= x) ? "YES\n" : "NO\n");
        }

    }

    return 0;
}


/*
💭 First Idea: Answer YES iff min(a) <= x <= max(a).
🧩 Key Property / Invariant: Each merge gives a value between its inputs, so the result always stays in [min(a), max(a)].
✅ Key insight: Every value in [min, max] is reachable: collapse everything towards min and max, then pick y between them.
🔁 Recognition cue for next time: "Replace two neighbours by something between them" -> the global [min, max] interval is the invariant.
⏱  Speed fix for next time: The sort and the n == 1 branch are unnecessary; min/max alone is O(n).
🛠  Review: correct; O(n log n) -> O(n) by dropping the sort (minor, not added).
*/
