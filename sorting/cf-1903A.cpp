// Codeforces 1903A — Halloumi Boxes
// https://codeforces.com/problemset/problem/1903/A
// Topic: sorting | Tags: constructive
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        if(is_sorted(a.begin(),a.end()) || k > 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}

/*
💭 First Idea: YES if already sorted or k > 1.
🧩 Key Property / Invariant: With k >= 2 you can reverse length-2 segments = adjacent swaps = bubble sort.
✅ Key insight: Adjacent swaps generate any permutation.
🔁 Recognition cue for next time: 'Allowed operation includes swapping neighbours' -> anything can be sorted.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
