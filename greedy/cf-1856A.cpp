// Codeforces 1856A — Tales of a Sort
// https://codeforces.com/problemset/problem/1856/A
// Topic: greedy | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& i: a) cin >> i;

    int ans = 0;

    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i+1]){
            ans = max(ans, a[i]);
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
💭 First Idea: Answer = max a[i] over adjacent pairs with a[i] > a[i+1].
🧩 Key Property / Invariant: After k ops a_i -> max(0, a_i - k), which preserves order except it can flatten values to 0.
✅ Key insight: An inverted pair a[i] > a[i+1] is fixed only when both become 0, i.e. k >= a[i].
🔁 Recognition cue for next time: 'Uniform decrement until sorted' -> look at adjacent inversions only.
⏱  Speed fix for next time: Sortedness is an adjacent-pair property - never compare all pairs.
🛠  Review: correct; Already optimal (verified vs simulation brute force).
*/