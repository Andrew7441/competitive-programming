// Codeforces 2169B — Drifting Away
// https://codeforces.com/problemset/problem/2169/B
// Topic: implementation | Tags: greedy, strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        std::string s;
        cin >> s;

        bool inf = false; 

        for(int i = 0; i < (int)s.length() - 1; i++){
            if(s[i] != '<' && s[i+1] != '>'){
                cout << -1 << '\n';
                inf = true;
                break;
            }
        }

        if(!inf){
            int cntL = 0, cntR = 0;
            for(char c : s){
                if(c == '<') cntL++;
                else if(c == '>') cntR++;
            }
            cout << s.size() - min(cntL,cntR) << '\n';
        }

    }


    return 0;
}

/*
💭 First Idea: Infinite if some neighbours let you bounce (s_i != '<' and s_{i+1} != '>'); else answer n - min(#'<', #'>').
🧩 Key Property / Invariant: A pair like '><', '**', '*<', '>*' forms a 2-cycle -> -1.
✅ Key insight: Otherwise the string is <<<[*]>>>; best start gives max(#<, #>) + (has '*' ? 1 : 0).
🔁 Recognition cue for next time: "Can you move forever" -> look for a 2-cycle between neighbours.
⏱  Speed fix for next time: n - min(L, R) == max(L, R) + #star; write the readable form.
🛠  Review: correct (stress-tested vs graph brute force); O(n) -> Already optimal.
*/
