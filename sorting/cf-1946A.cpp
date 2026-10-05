// Codeforces 1946A — Median of an Array
// https://codeforces.com/problemset/problem/1946/A
// Topic: sorting | Tags: greedy
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int p = (n + 1) / 2 - 1;
    int ans = count(a.begin() + p, a.end(),a[p]);

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
💭 First Idea: Sort, then count how many copies of the median value sit at index p and to its right.
🧩 Key Property / Invariant: To raise the median by 1, every element equal to a[p] at positions >= p must be bumped.
✅ Key insight: Answer = count of a[p] in a[p..n-1] after sorting.
🔁 Recognition cue for next time: "Minimum +1 ops to change median/order statistic" -> sort and look at equal values around it.
⏱  Speed fix for next time: count(a.begin()+p, a.end(), a[p]) is the one-liner; no simulation needed.
🛠  Review: correct; Already optimal (sorting dominates).
*/
