// Codeforces 214A — System of Equations
// https://codeforces.com/problemset/problem/214/A
// Topic: brute-force | Tags: math
// Complexity (yours): O(n*m) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int res = 0;
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if((i*i) + j == n && i + (j*j) == m){
                res++;
            }
        }
    }

    cout << res;

    return 0;
}

// ===================== ⚡ Optimized =====================
// O(sqrt n) instead of O(n*m): fix a, then b = n - a*a is forced; just check the 2nd equation.
// To submit: replace your main() body with optimized::solve().
namespace optimized {
void solve() {
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int a = 0; a * a <= n; a++) {
        int b = n - a * a;
        if (a + b * b == m) res++;
    }
    cout << res << "\n";
}
}

/*
💭 First Idea: Try every pair (a, b) in [0,n] x [0,m] and check both equations.
🧩 Key Property / Invariant: Small bounds (<= 1000) make brute force safe.
✅ Key insight: Fixing a determines b = n - a^2, so one loop over a <= sqrt(n) is enough.
🔁 Recognition cue for next time: 'Count integer solutions of small equations' -> brute force, then use one equation to eliminate a variable.
⏱  Speed fix for next time: Eliminate a variable before nesting loops.
🛠  Review: correct; yours O(n*m) → optimized O(sqrt n).
*/
