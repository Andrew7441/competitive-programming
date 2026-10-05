// Codeforces 2000C — Numeric String Template
// https://codeforces.com/problemset/problem/2000/C
// Topic: hashing | Tags: strings
// Complexity (yours): O(n + sum|s|) expected time per test
#include <bits/stdc++.h>
using namespace std;

/**/

bool matches(const vector<int>& a, string s){
    if((int)a.size() != (int)s.size()) return false;

    unordered_map<int,char> numToChar;
    unordered_map<char,int> charToNum;

    for(int i = 0; i < (int)a.size(); i++){
        int num = a[i]; // 3
        int ch = s[i]; // a

        if(numToChar.count(num) && numToChar[num] != ch) return false;
        if(charToNum.count(ch) && charToNum[ch] != num) return false;

        numToChar[num] = ch;
        charToNum[ch] = num;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;

    vector<int>a(n);
    for(int& i: a) cin >> i;

    int m;
    cin >> m;
    
    while(m--){
        string s;
        cin >> s;

        if(matches(a, s)) cout << "YES\n";
        else cout << "NO\n";
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
// Same O(n log n + sum|s|), but no unordered_map (anti-hash tests can make it O(n^2)):
// compress a[] to ids 0..k-1 once, then each query uses plain arrays.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<int> vals(a);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int& x : a) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    vector<int> idToChar(vals.size(), -1);
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        bool ok = (int)s.size() == n;
        if (ok) {                          // only O(n) work when |s| == n, so total stays O(sum|s|)
            fill(idToChar.begin(), idToChar.end(), -1);
            int charToId[26];
            fill(charToId, charToId + 26, -1);
            for (int i = 0; i < n && ok; i++) {
                int c = s[i] - 'a', id = a[i];
                if (idToChar[id] == -1 && charToId[c] == -1) idToChar[id] = c, charToId[c] = id;
                else if (idToChar[id] != c || charToId[c] != id) ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
}

/*
💭 First Idea: Two hash maps (num->char, char->num) checking a bijection per query string.
🧩 Key Property / Invariant: Valid iff |s| == n and the mapping a[i] <-> s[i] is one-to-one in both directions.
✅ Key insight: Need both directions: equal numbers -> equal chars AND equal chars -> equal numbers.
🔁 Recognition cue for next time: "Pattern matching / isomorphic strings" -> two maps (or compress + arrays).
⏱  Speed fix for next time: Compress a[] once; then char side is an int[26], number side a vector by id.
🛠  Review: correct; unordered_map is hackable by anti-hash tests -> optimized uses compression + arrays, O(n log n + sum|s|) worst case.
*/
