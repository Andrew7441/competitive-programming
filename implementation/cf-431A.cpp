// Codeforces 431A — Black Square
// https://codeforces.com/problemset/problem/431/A
// Topic: implementation | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/431/A Black Square

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string s;
    cin >> s;

    int res = 0;



    for(size_t i = 0; i < s.length(); i++){
        if(s[i] == '1') res += a;
        if(s[i] == '2') res += b;
        if(s[i] == '3') res += c;
        if(s[i] == '4') res += d;
    }
    cout << res;


    return 0;
}

/*
💭 First Idea: Add the calorie cost of the strip for each character.
🧩 Key Property / Invariant: Each character maps to a fixed cost.
✅ Key insight: Store costs in an array and use a[c - '1'].
🔁 Recognition cue for next time: 'Lookup cost per symbol' -> array indexed by symbol.
⏱  Speed fix for next time: int a[4]; ... res += a[c - '1'];
🛠  Review: correct; Already optimal.
*/
