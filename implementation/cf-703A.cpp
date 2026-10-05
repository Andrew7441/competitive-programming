// Codeforces 703A — Mishka and Game
// https://codeforces.com/problemset/problem/703/A
// Topic: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/703/A Mishka and Game

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int r1=0,r2=0;

    while(t--){
        int m,c;
        cin >> m >> c;

        if(m > c){
            r1++;
        }else if(m < c){
            r2++;
        }
    
    }
    if(r1 > r2){
        cout << "Mishka" << endl;
    }else if(r1 < r2){
        cout << "Chris" << endl;
    }else{
        cout << "Friendship is magic!^^" << endl;
    }

    return 0;
}

/*
💭 First Idea: Count rounds won by each player, compare counts.
🧩 Key Property / Invariant: Ties in a round count for nobody.
✅ Key insight: Only the two win counters matter.
🔁 Recognition cue for next time: "Who wins more rounds" → two counters.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
