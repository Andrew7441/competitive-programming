// Codeforces 96A — Football
// https://codeforces.com/problemset/problem/96/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/96/A Football


int main() {

    string s; 
    cin >> s;


    int count = 1; 
    for(size_t i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]){
            count++;
            if(count == 7){
                cout << "YES";
                return 0;
            }
        }else{
            count = 1;
        }
    }
    cout << "NO";
    return 0;
}

/*
💭 First Idea: Track the current run length of equal characters; YES at 7.
🧩 Key Property / Invariant: Dangerous iff some run of equal chars has length >= 7.
✅ Key insight: Equivalent: s contains "0000000" or "1111111".
🔁 Recognition cue for next time: 'k identical in a row' -> run-length counter or s.find(string(k,c)).
⏱  Speed fix for next time: s.find("0000000") != npos || s.find("1111111") != npos is a one-liner.
🛠  Review: correct; Already optimal.
*/
