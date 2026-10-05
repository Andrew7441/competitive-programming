// Codeforces 1791A — Codeforces Checking
// https://codeforces.com/problemset/problem/1791/A
// Topic: strings | Tags: hashing
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1791/A . Codeforces Checking

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        char a;
        cin >> a;
        unordered_set<char> n{'c', 'o', 'd', 'e', 'f', 'r', 's'};

        if(n.count(a)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}

/* another way
string s = "codeforces";
if (s.find(c) != string::npos)
    cout << "YES\n";
else
    cout << "NO\n";
*/

/*
💭 First Idea: Put the letters of "codeforces" in a set and check membership.
🧩 Key Property / Invariant: Only membership matters, not order.
✅ Key insight: Set lookup (or string::find).
🔁 Recognition cue for next time: 'Is char in a fixed word' -> string::find or set.
⏱  Speed fix for next time: Your alternative with s.find(c) is shorter.
🛠  Review: correct; Already optimal.
*/
