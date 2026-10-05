// Codeforces 2102B — The Picky Cat
// https://codeforces.com/problemset/problem/2102/B
// Topic: sorting | Tags: math, greedy
// Complexity (yours): O(n log n) time, O(n) space
// ⚠️ Review: only checks a_1 = +|a_1|; for even n a_1 = -|a_1| also works (fails sample 3); see corrected version below.
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

        for(int i = 0; i < n; i++) a[i] = abs(a[i]);

        vector<int> b = a;
        sort(b.begin(), b.end());

        int mid = (n+1) / 2 - 1;
        if(a[0] <= b[mid]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}

// ===================== ⚡ Optimized =====================
// Fixes even n: a1 may also become -|a1|, so the real condition is
// #(|a_i| < |a_1|) <= floor(n/2)  <=>  |a_1| <= b[n/2] (b = sorted abs values, 0-indexed).
// To submit: replace the body of your while(t--) loop with optimized::solve().
namespace optimized {
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) { cin >> x; x = llabs(x); }
    vector<long long> b = a;
    sort(b.begin(), b.end());
    cout << (a[0] <= b[n / 2] ? "YES\n" : "NO\n");
}
}

/*
💭 First Idea: Take |a_i|, sort, and compare |a_1| with the ceil(n/2)-th smallest absolute value.
🧩 Key Property / Invariant: Values with |a_i| < |a_1| always land between -|a_1| and |a_1|; values with bigger |a_i| can go to either side.
✅ Key insight: a_1 can be +|a_1| (needs c <= ceil(n/2)-1) OR -|a_1| (needs c <= floor(n/2)), c = #(|a_i| < |a_1|); the second is looser, so answer is c <= floor(n/2).
🔁 Recognition cue for next time: "Flip signs freely, make X the k-th smallest" -> only absolute values matter; count which are forced below/above.
⏱  Speed fix for next time: Check both sign choices of the target element; sample "4 2 0 -5" (YES via -4) catches the bug.
🛠  Review: wrong for even n (only tests a_1 = +|a_1|); yours O(n log n) -> optimized O(n log n) with index b[n/2].
*/
