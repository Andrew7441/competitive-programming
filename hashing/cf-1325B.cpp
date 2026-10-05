// Codeforces 1325B — CopyCopyCopyCopyCopy
// https://codeforces.com/problemset/problem/1325/B
// Topic: hashing | Tags: sorting, greedy
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1325/B CopyCopyCopyCopyCopy
/*
Greedy approach
Objective
    determine the length of the longest strictly increasing subsequence (LIS) 
    of the array formed by concatenating the original array n times.
Constraint
    LIS is strictly increasing, duplicates cannot contribute to making it longer.
    take all distinct elements in sorted order.
    The length of the LIS = number of distinct elements.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        int n;
        cin >> n;
        set<int> st;

        while(n--){
            int a;
            cin >> a;
            st.insert(a); 
        }
        cout << st.size() << "\n";

    }
    return 0;
}

/*
💭 First Idea: Answer = number of distinct values (set size).
🧩 Key Property / Invariant: With n copies you can pick one distinct value per copy in increasing order.
✅ Key insight: LIS of n concatenated copies = count of distinct elements.
🔁 Recognition cue for next time: "Array repeated n times, LIS" → each copy contributes one element.
⏱  Speed fix for next time: sort + unique also works; set is fine.
🛠  Review: correct; O(n log n) — Already optimal.
*/
