// Codeforces 2044B — Normal Problem
// https://codeforces.com/problemset/problem/2044/B
// Topic: strings
// Complexity (yours): O(|s|) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        reverse(s.begin(), s.end());
                
        for(char& c: s){
            if(c == 'q') c = 'p';
            else if(c == 'p') c = 'q';
        }
        cout << s << "\n";
    }

    return 0;
}

/*
💭 First Idea: Reverse the string and swap p <-> q; w stays.
🧩 Key Property / Invariant: Seen from the other side of glass: order reverses and p/q mirror, w is symmetric.
✅ Key insight: Mirror image = reverse + character mapping.
🔁 Recognition cue for next time: "Viewed from the other side / mirror" -> reverse + map each char.
⏱  Speed fix for next time: Write the char map first, then reverse.
🛠  Review: correct; Already optimal.
*/
