// Codeforces 282A — Bit++
// https://codeforces.com/problemset/problem/282/A
// Topic: implementation | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/282/A

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    int res = 0;

    while(t--){
        string a;
        cin >> a;

        for(size_t i =0; i < a.length();i++){
            if(a[i] == '+'){
                res++;
                break;
            }else if(a[i] == '-'){
                res--;
                break;
            }
        }
    }
    cout << res << "\n";


    return 0;
}

/*
💭 First Idea: For each statement find the first '+' or '-' and add/subtract 1.
🧩 Key Property / Invariant: Every statement has length 3 and the middle char is always the operator sign.
✅ Key insight: Check s[1] == '+'.
🔁 Recognition cue for next time: 'Parse fixed-format statements' -> look at the fixed position.
⏱  Speed fix for next time: x += (s[1] == '+') ? 1 : -1;
🛠  Review: correct; Already optimal.
*/
