// Codeforces 734A — Anton and Danik
// https://codeforces.com/problemset/problem/734/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/734/A Anton and Danik

int main() {


    int n; cin >> n;
    string s; cin >> s;

    int a=0,b=0;

    for(size_t i = 0; i < s.length();i++){
        if(s[i] == 'A'){
            a++;
        }else{
            b++;
        } 
    }
    if(a > b){
        cout << "Anton";
    }else if(a < b){
        cout << "Danik";
    }else{
        cout << "Friendship";
    }

    return 0;
}

/*
💭 First Idea: Count 'A' and 'D' characters and compare.
🧩 Key Property / Invariant: Every game is won by exactly one of them.
✅ Key insight: Compare count('A') with n − count('A').
🔁 Recognition cue for next time: Character frequency comparison → count().
⏱  Speed fix for next time: int a = count(s.begin(), s.end(), 'A');
🛠  Review: correct; O(n) — Already optimal.
*/
