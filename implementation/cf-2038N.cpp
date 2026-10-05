// Codeforces 2038N — Fixing the Expression
// https://codeforces.com/problemset/problem/2038/N
// Topic: implementation | Tags: strings
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n1 = s[0] - '0';
    char e = s[1];
    int n2 = s[2] - '0';

    string res = "";

    if(e == '<'){
        if(n1 < n2){
            res = to_string(n1) + e + to_string(n2);
        }else if(n1 > n2){
            res = to_string(n1) + '>' + to_string(n2);
        }else{
            res = to_string(n1) + '=' + to_string(n2);
        }
    }else if(e == '>'){
        if(n1 > n2){
            res = to_string(n1) + e + to_string(n2);
        }else if(n1 == n2){
            res = to_string(n1) + '=' + to_string(n2);
        }else{
            res = to_string(n1) + '<' + to_string(n2);
        }
    }else if(e == '='){
        if(n1 == n2){
            res = to_string(n1) + e + to_string(n2);
        }else if(n1 > n2){
            res = to_string(n1) + '>' + to_string(n2);
        }else{
            res = to_string(n1) + '<' + to_string(n2);
        }
    }
    cout << res << "\n";
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
// Same O(1), far less code: keep both digits, recompute the one correct operator.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    string s;
    cin >> s;
    s[1] = s[0] < s[2] ? '<' : (s[0] > s[2] ? '>' : '=');
    cout << s << "\n";
}
}

/*
💭 First Idea: Case work on the operator, rebuilding the string with the correct one.
🧩 Key Property / Invariant: Changing just the middle symbol always fixes it (0 changes if already true).
✅ Key insight: Keep both digits; set s[1] to the true comparison of s[0] and s[2].
🔁 Recognition cue for next time: "Change the fewest chars to make an expression true" -> changing the operator alone suffices.
⏱  Speed fix for next time: Compare the digit chars directly; no to_string or nested branches.
🛠  Review: correct; same O(1) but optimized is 1 line instead of 3 nested blocks.
*/
