// Codeforces 2241D — An Alternative Way
// https://codeforces.com/problemset/problem/2241/D
// Topic: greedy | Tags: prefix-sum, math
// Complexity (yours): O(n^3) worst case time, O(n) space
// ⚠️ Review: gave up; simulation is wrong (e.g. a=[2,5], b=[2,4] prints YES, answer NO); see corrected version below.
#include <bits/stdc++.h>
using namespace std;

/*
couldnt solve it gng :/
kol el e7tram to those who done it without ai
*/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for(int& i : a){
        cin >> i;
    }
    
    for(int& i : b){
        cin >> i;
    }

    if(a == b){
        cout << "YES\n";
        return;
    }

    int l = 0, r = n - 1;

    while(l < r){
        vector<int> x = a;
        vector<int> y = b;

        for(int i = l; i <= r; i++){
            if(x[i] != y[i] && (i - l) % 2 == 0){
                x[i]++;
                if(x[i] == b[i]) a = x;
            }else if(x[i] != y[i] && (i - l) % 2 != 0){
                x[i]--;
                if(x[i] == b[i]) a = x;
            }

            if(x == y){
                cout << "YES\n";
                return;
            }
        }
        l++;
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}


// ===================== ⚡ Optimized =====================
// O(n): alternate the signs of d = b - a; then each operation is +-1 on a contiguous range.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    // c_i = (-1)^i (b_i - a_i). One operation on [l, r] adds the constant (-1)^l to c on [l, r].
    // So c must be a sum of +1-ranges starting at even l and -1-ranges starting at odd l (0-indexed).
    // Scan left to right with the (max) number of open + ranges P and open - ranges N.
    long long P = 0, N = 0;
    for (int i = 0; i < n; i++) {
        long long c = (i % 2 == 0 ? 1 : -1) * (b[i] - a[i]);
        if (i % 2 == 0) {               // may open + ranges here, may only close - ranges
            if (c + N < 0) { cout << "NO\n"; return; }
            P = c + N;
        } else {                        // may open - ranges here, may only close + ranges
            if (P - c < 0) { cout << "NO\n"; return; }
            N = P - c;
        }
    }
    cout << "YES\n";
}
}

/*
💭 First Idea: Simulate applying the alternating pattern on shrinking windows (gave up).
🧩 Key Property / Invariant: Multiply d_i = b_i - a_i by (-1)^i: the alternating +1/-1 pattern turns into a constant (-1)^l on [l, r].
✅ Key insight: Then c is a sum of +ranges starting at even indices and -ranges starting at odd ones; a greedy scan keeping the max open counts decides feasibility.
🔁 Recognition cue for next time: "Alternating +1/-1 on a segment" -> multiply by (-1)^i to turn it into a plain range add.
⏱  Speed fix for next time: Look for a sign/difference transform that makes the operation uniform before simulating.
🛠  Review: unfinished (owner gave up, code gives wrong answers); optimized O(n), verified against an exhaustive reachability brute force for n <= 4.
*/