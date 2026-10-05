// Codeforces 2209B — Array
// https://codeforces.com/problemset/problem/2209/B
// Topic: math | Tags: counting, binary-indexed tree
// Complexity (yours): loops k from INT_MIN to INT_MAX (~4e9 steps, k++ overflow UB) and prints n*n numbers
// ⚠️ Review: k loop is infinite/overflowing and output format is wrong; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int& i : a) cin >> i;

    int res; 

    for(int i = 0; i < (int)a.size(); i++){
        int k = INT_MIN;
        res = 0;
        for(int j = 0; j < (int)a.size(); j++){
            
            if(i < j){
                while(k != INT_MAX){
                    if(abs(a[i] - k) > abs(a[j] - k)){
                        res++;
                    }
                    k++;
                }
            }
            cout << res << " ";    
        }
    }
    cout << "\n";
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

// ===================== ⚡ Optimized =====================
// O(n log n): best k is "very small" or "very large", so count smaller / larger elements to the right.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    vector<long long> v = a;                 // coordinate compression
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    vector<int> bit(m + 1, 0);
    auto add = [&](int i) { for (i++; i <= m; i += i & -i) bit[i]++; };
    auto query = [&](int i) { int s = 0; for (i++; i > 0; i -= i & -i) s += bit[i]; return s; }; // #values with index <= i
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int id = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        int total = n - 1 - i;
        int smaller = id > 0 ? query(id - 1) : 0;
        int greater = total - query(id);
        ans[i] = max(smaller, greater);      // k -> -inf counts smaller a_j, k -> +inf counts larger a_j
        add(id);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}
}

/*
💭 First Idea: Brute force over every k for every pair (i, j).
🧩 Key Property / Invariant: If k > a_i then |a_i - k| > |a_j - k| forces a_j > a_i; if k < a_i it forces a_j < a_i; k = a_i counts nothing.
✅ Key insight: Taking k -> +inf counts all larger a_j, k -> -inf all smaller ones, so answer_i = max(#greater after i, #smaller after i).
🔁 Recognition cue for next time: "Choose any k to maximize a count of |x - k| comparisons" -> look at k at the extremes.
⏱  Speed fix for next time: Never loop over the value range of k; reason about which side of a_i the k must lie on.
🛠  Review: wrong (infinite/UB loop over k, n*n outputs); optimized O(n log n) (an O(n^2) count also works if n is small), stress-tested vs brute force.
*/
