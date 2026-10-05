// Codeforces 1976A — Verify Password
// https://codeforces.com/problemset/problem/1976/A
// Topic: strings | Tags: sorting, implementation
// Complexity (yours): O(n) per test
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
       
       string s;
       cin >> s;

       bool ok = true;

       for(int i = 0; i < n - 1; i++){
        if(isdigit(s[i]) && isdigit(s[i+1])){
            if((s[i] - '0') > (s[i+1] - '0')){
                ok = false;
                break;
            }
        }else if(isalpha(s[i]) && isalpha(s[i+1])){
            if(s[i] > s[i+1]){
                ok = false;
                break;
            }
       }else if(isalpha(s[i]) && isdigit(s[i+1])){
        ok = false;
        break;
       }
       }   
       if(ok) cout << "YES\n";
       else cout << "NO\n";
    }
    

    return 0;
}

// ===================== ⚡ Optimized =====================
// Same O(n), simpler idea: in ASCII digits < letters, so all 4 rules == "s is sorted".
// To submit: call optimized::solve() once per test case instead of your loop body.
namespace optimized {
void solve() {
    int n; string s;
    cin >> n >> s;
    cout << (is_sorted(s.begin(), s.end()) ? "YES" : "NO") << "\n";
}
}

/*
💭 First Idea: Check every adjacent pair: digit-digit and letter-letter non-decreasing, no letter->digit.
🧩 Key Property / Invariant: All rules together mean: digits first (sorted), then letters (sorted).
✅ Key insight: Since '0'..'9' < 'a'..'z' in ASCII, the password is valid iff s is sorted.
🔁 Recognition cue for next time: Several "must be non-decreasing" rules on mixed chars -> check if they collapse into is_sorted.
⏱  Speed fix for next time: is_sorted(s.begin(), s.end()) replaces all the case work.
🛠  Review: correct; yours O(n) -> optimized O(n) but one line (simpler key idea).
*/
