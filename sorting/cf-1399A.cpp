// Codeforces 1399A — Remove Smallest
// https://codeforces.com/problemset/problem/1399/A
// Topic: sorting | Tags: greedy
// Complexity (yours): O(n log n) per test
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1399/A Remove Smallest
// greedy, sortings
// objective : reduce array to one element
// constraint: i may remove one element if i pick 2 indices i != j  such that ∣ai​−aj​∣≤1
// i must remove the smaller of the two (or either one if equal)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;

        sort(a.begin(),a.end());

        bool ok = true;
        for(int i = 1; i < n; i++){
            if(abs(a[i-1] - a[i]) > 1){
                ok = false; 
                break;
            }
        }
        
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

/*
💭 First Idea: Sort and check every adjacent difference is ≤ 1.
🧩 Key Property / Invariant: After sorting, any gap > 1 splits the array into parts that can never merge.
✅ Key insight: Removing the smaller each time works iff the sorted array has no gap > 1.
🔁 Recognition cue for next time: "Reduce to one element with |a_i − a_j| ≤ 1" → sort and check adjacent gaps.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n log n) — Already optimal.
*/
