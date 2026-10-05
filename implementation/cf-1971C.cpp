// Codeforces 1971C — Clock and Strings
// https://codeforces.com/problemset/problem/1971/C
// Topic: implementation | Tags: geometry
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1971/C Clocks and Strings

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        string s; 
        for(int i = 1; i <= 12; i++){
            if(i == a or i == b) s+= 'a';
            if(i == c or i == d) s+= 'b';
        }

        cout << (s == "abab" or s == "baba" ? "YES" : "NO") << endl;
    }

    return 0;
}

/*
💭 First Idea: Walk the clock 1..12, record the order of endpoints of red (a) and blue (b) strings.
🧩 Key Property / Invariant: Two chords of a circle intersect iff their endpoints alternate around the circle.
✅ Key insight: Pattern abab / baba means alternating -> YES.
🔁 Recognition cue for next time: Chords on a circle / intervals on a cycle -> check interleaving of endpoints.
⏱  Speed fix for next time: Equivalent: normalize a<b, then intersect iff exactly one of c,d lies strictly in (a,b).
🛠  Review: correct; Already optimal.
*/
