// Codeforces 1997A — Strong Password
// https://codeforces.com/problemset/problem/1997/A
// Topic: strings | Tags: greedy
// Complexity (yours): O(n) per test
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

        int idx = -1;

        for(int i = 0; i < (int)s.length()-1; i++){
            if(s[i] == s[i+1]){
                idx = i;
            }
        }

        if(idx == -1){
            if(s.back() == 'a'){
                s += "b";
            }else{
                s += "a";
            }
            cout << s << "\n";
        }else{
            string t = "a";
            if(s[idx] == 'a') t = "b";
            cout << s.substr(0, idx + 1) + t + s.substr(idx+1) << "\n";
        }

    }

    return 0;
}

/*
💭 First Idea: Insert a different letter inside an equal adjacent pair; else append a letter != last.
🧩 Key Property / Invariant: Breaking an equal pair gains +3 seconds; any other insertion gains at most +2.
✅ Key insight: Prefer splitting a pair "xx" -> "xyx"; otherwise add a different letter at the end.
🔁 Recognition cue for next time: "Insert one char to maximize cost of equal/unequal neighbours" -> look for an equal pair first.
⏱  Speed fix for next time: Use s.insert(idx+1, 1, c) instead of substr concatenation.
🛠  Review: correct; Already optimal (stress-tested vs brute force).
*/
