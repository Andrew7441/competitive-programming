// Codeforces 1850A — To My Critics
// https://codeforces.com/problemset/problem/1850/A
// Topic: math | Tags: sorting
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1850/A To My Critics

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b >= 10 or a + c >= 10 or b + a >= 10 or b + c >= 10 or 
        c + a >= 10 or c + b >= 10){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
💭 First Idea: Check every pair sum >= 10.
🧩 Key Property / Invariant: Only 3 distinct pairs; best pair is the two largest.
✅ Key insight: a+b+c - min(a,b,c) >= 10.
🔁 Recognition cue for next time: 'Some pair reaches X' -> check the two largest.
⏱  Speed fix for next time: Drop the duplicated conditions (a+b and b+a).
🛠  Review: correct; Already optimal.
*/
