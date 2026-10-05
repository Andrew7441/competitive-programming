// Codeforces 1972B — Coin Games
// https://codeforces.com/problemset/problem/1972/B
// Topic: game-theory | Tags: math, parity
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
        
        int res = 0;
        for(size_t i = 0; i < s.length(); i++){
            if(s[i] == 'U'){
                res++;
            }
        }
        if(res % 2 == 0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }


    return 0;
}

/*
💭 First Idea: Count facing-up coins; Alice wins iff that count is odd.
🧩 Key Property / Invariant: Each move changes #U by an odd amount (-1 plus two flips), so #U parity alternates every turn.
✅ Key insight: Winner depends only on parity of the count of 'U'.
🔁 Recognition cue for next time: Small coin/flip games with YES/NO winner -> look for a parity invariant.
⏱  Speed fix for next time: count(s.begin(), s.end(), 'U') % 2.
🛠  Review: correct; Already optimal.
*/
