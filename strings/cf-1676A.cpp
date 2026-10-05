// Codeforces 1676A — Lucky?
// https://codeforces.com/problemset/problem/1676/A
// Topic: strings | Tags: implementation, math
// Complexity (yours): O(1) time, O(1) space
#include <iostream>
#include <string>
using namespace std;

//https://codeforces.com/problemset/problem/1676/A Lucky?

int main() {

    int t; 
    cin >> t; 

    for(int i = 0; i < t; i++){
        string s; cin >> s; 
        int res1=0;
        int res2=0; 

        for(size_t i = 0; i < s.length()/2;i++){
            res1 += s[i] - '0';
        }
        for(size_t i = s.length()/2; i < s.length(); i++){
            res2 += s[i] - '0';
        }

        if(res1 == res2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
💭 First Idea: Sum digits of first half and second half, compare.
🧩 Key Property / Invariant: Ticket has exactly 6 digits -> fixed halves.
✅ Key insight: Digit char -> value with c - '0'.
🔁 Recognition cue for next time: 'Sum of digits equal' on a fixed-length string -> two loops over halves.
⏱  Speed fix for next time: Could compare s[0]+s[1]+s[2] == s[3]+s[4]+s[5] directly.
🛠  Review: correct; Already optimal.
*/
