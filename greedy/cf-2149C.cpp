// Codeforces 2149C — MEX rose
// https://codeforces.com/problemset/problem/2149/C
// Topic: greedy | Tags: hashing, math
// Complexity (yours): O(n) time, O(n) space
// ⚠️ Review: ignores that all of 0..k-1 must be present (k=2, a=[0,0] -> prints 0, expected 1); see corrected version below.
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

        int res = 0;

        for(int i = 0; i < n; i++){
            if(a[i] == k){
                a[i]--;
                res++;
            }
        }

        cout << res << "\n";

    }


    return 0;
}

// ===================== ⚡ Optimized =====================
// Fix: besides removing every copy of k, all of 0..k-1 must be present.
// Each operation can do both jobs at once (turn a k into a missing value), so answer = max(cntK, missing).
// To submit: replace the body of your while(t--) loop with optimized::solve().
namespace optimized {
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; i++) { int x; cin >> x; cnt[x]++; }
    int missing = 0;
    for (int v = 0; v < k; v++) if (cnt[v] == 0) missing++;
    cout << max(cnt[k], missing) << "\n";
}
}

/*
💭 First Idea: Count elements equal to k (each must be changed).
🧩 Key Property / Invariant: MEX(a) = k needs every value 0..k-1 present AND k absent.
✅ Key insight: Answer = max(cnt[k], #missing in 0..k-1): each changed k can fill a missing value; extra missing ones cost one op each.
🔁 Recognition cue for next time: "Make MEX exactly k" -> two requirements (all smaller present, k absent); one op can serve both.
⏱  Speed fix for next time: Write down both MEX conditions before coding; test k=2, a=[0,0].
🛠  Review: wrong: ignores missing values 0..k-1 (k=2, a=[0,0] gives 0, expected 1); yours O(n) -> optimized O(n).
*/
