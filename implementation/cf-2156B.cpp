// Codeforces 2156B — Strange Machine
// https://codeforces.com/problemset/problem/2156/B
// Topic: implementation | Tags: math, brute-force
// Complexity (yours): O(q * a) worst case (all-A string), O(q) space
// ⚠️ Review: TLE when s is all 'A' (up to 1e9 steps per query); see corrected version below.
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> a(q);

    for(int i = 0; i < q; i++){
        cin >> a[i];
        int Query = a[i];
        int res = 0;
        
        while(Query > 0){
            for(char c : s){
                if(Query <= 0) break;
                if(c == 'A' && Query > 0){
                    Query -= 1;
                    res++;
                }else if(c == 'B' && Query > 0){
                    Query /= 2;
                    res++;
                }
            }
            
        }
        cout << res << "\n";
    }
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
// Fix TLE: if s has no 'B', every step is -1, so the answer is just a (up to 1e9 steps otherwise).
// With at least one 'B', a halves every lap (<= n steps), so simulation is O(n log a) per query.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    bool hasB = s.find('B') != string::npos;
    while (q--) {
        long long a;
        cin >> a;
        if (!hasB) { cout << a << "\n"; continue; }
        long long steps = 0;
        for (int i = 0; a > 0; i = (i + 1) % n) {
            if (s[i] == 'A') a--; else a /= 2;
            steps++;
        }
        cout << steps << "\n";
    }
}
}

/*
💭 First Idea: Simulate each query, looping over the machines until a reaches 0.
🧩 Key Property / Invariant: With at least one B, a is at least halved every lap of <= 20 steps, so ~600 steps per query.
✅ Key insight: If s has no 'B' every step is -1, so the answer is exactly a; only that case needs a formula.
🔁 Recognition cue for next time: "Simulate until 0" with values up to 1e9 -> check the case where nothing shrinks fast.
⏱  Speed fix for next time: Bound the worst-case iteration count before simulating (here: all 'A').
🛠  Review: wrong (TLE): all-'A' string with a = 1e9 and q = 1e4 is 1e13 steps; yours O(q*a) -> optimized O(q*n*log a).
*/
