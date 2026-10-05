// Codeforces 2192A — String Rotation Game
// https://codeforces.com/problemset/problem/2192/A
// Topic: strings | Tags: brute-force
// Complexity (yours): O(n^2) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;

    for(int i = 0; i < (int)s.size(); i++){
        int blocks = 1;
        std::rotate(s.rbegin(), s.rbegin() + 1, s.rend());
        for(int j = 0; j < (int)s.size() - 1; j++){
            if(s[j] != s[j+1]){
                blocks++;
            }
        }
        ans = max(ans, blocks);
    }
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


// ===================== ⚡ Optimized =====================
// O(n) instead of O(n^2): count cyclic boundaries once instead of re-counting after every rotation.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n; string s;
    cin >> n >> s;
    int c = 0;                              // cyclic boundaries s[i] != s[i+1 mod n]
    for (int i = 0; i < n; i++) c += s[i] != s[(i + 1) % n];
    int ans;
    if (c == 0) ans = 1;                    // all characters equal
    else if (c < n) ans = c + 1;            // cut between two equal neighbours -> keep every boundary
    else ans = c;                           // every cut destroys one boundary
    cout << ans << "\n";
}
}

/*
💭 First Idea: Try all n rotations and count blocks in each one.
🧩 Key Property / Invariant: Blocks of a linear string = (#adjacent changes) + 1; a rotation only decides which cyclic boundary is cut.
✅ Key insight: Answer = c+1 if some cyclic neighbours are equal (cut there), c if all differ, 1 if c = 0.
🔁 Recognition cue for next time: "Best cyclic rotation" -> think about the cyclic string and where the single cut goes.
⏱  Speed fix for next time: Count cyclic boundaries once; simulating rotations is only fine because n is small.
🛠  Review: correct; yours O(n^2) -> optimized O(n).
*/