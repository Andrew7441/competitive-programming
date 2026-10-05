// Codeforces 2185C — Shifted MEX
// https://codeforces.com/problemset/problem/2185/C
// Topic: sorting | Tags: arrays
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

        vector<long long> a(n);
        
        for(long long& i : a) cin >> i;

        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        int ans = 0;
        int cur = 1;

        for(int i = 1; i < (int)a.size(); i++){
            if(a[i] == a[i-1] + 1){
                cur++;
            }else{
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);

        cout << ans << "\n";
    }

    return 0;
}

/*
💭 First Idea: Sort, dedupe, and take the longest run of consecutive values; shift that run so it starts at 0.
🧩 Key Property / Invariant: Adding x to all elements keeps differences, so the MEX after shifting = length of a run of consecutive values mapped to 0.
✅ Key insight: Best MEX = longest block v, v+1, ..., v+k-1 of distinct values present in the array.
🔁 Recognition cue for next time: "Add the same x to every element, maximize MEX" -> longest consecutive run after sort + unique.
⏱  Speed fix for next time: sort + unique + one linear scan; no need to try every x.
🛠  Review: correct; O(n log n) -> Already optimal.
*/
