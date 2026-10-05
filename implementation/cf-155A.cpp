// Codeforces 155A — I_love_%username%
// https://codeforces.com/problemset/problem/155/A
// Topic: implementation | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/155/A I_love_%username%

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     int t;
     cin >> t;

     vector<int> con(t);

     for(int i = 0; i < t; i++){
        cin >> con[i];
     }

     int best = con[0], worst = con[0];
     int res = 0;

     for(size_t i = 1; i < con.size();i++){
        if(con[i] < worst){
            worst = con[i];
            res++;
        }else if(con[i] > best){
            best = con[i];
            res++;
        }
     }

     cout << res;


    return 0;
}

/*
💭 First Idea: Keep running best/worst; count each time a new strict max or min appears.
🧩 Key Property / Invariant: A contest is amazing iff it is a strict new max or strict new min.
✅ Key insight: Only two running values needed - no array required.
🔁 Recognition cue for next time: 'Count new records' -> running max/min.
⏱  Speed fix for next time: Read and process on the fly instead of storing the vector.
🛠  Review: correct; Already optimal.
*/
