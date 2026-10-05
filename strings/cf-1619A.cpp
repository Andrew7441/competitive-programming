// Codeforces 1619A — Square String?
// https://codeforces.com/problemset/problem/1619/A
// Topic: strings
// Complexity (yours): O(|s|) per test
#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/1619/A Square String?
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        if(s.length() % 2 != 0){
            cout << "NO" << endl;
            continue;
        }

        string a = s.substr(0, s.length() / 2);
        string b = s.substr(s.length() / 2);

        if(a == b) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}

// another solution ( tutorial )
/*
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        string s;
        cin >> s;
        bool ok = true;
        if (s.length() % 2 == 0) {
            forn(i, s.length() / 2)
                if (s[i] != s[i + s.length() / 2])
                    ok = false;
        } else
            ok = false;
        cout << (ok ? "YES" : "NO") << endl;
   
*/

/*
💭 First Idea: Odd length → NO; else compare the two halves.
🧩 Key Property / Invariant: A square string is t+t, so halves must be equal.
✅ Key insight: Compare s.substr(0,n/2) with s.substr(n/2).
🔁 Recognition cue for next time: "Is s = t + t" → length even and halves equal.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
