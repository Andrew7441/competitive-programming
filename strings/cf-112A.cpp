// Codeforces 112A — Petya and Strings
// https://codeforces.com/problemset/problem/112/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
#include <cctype>
using namespace std;

int main() {



    std::string s1, s2;
    cin >> s1 >> s2; 


    for(auto &i : s1){
        i = tolower(static_cast<unsigned char>(i));
    }
    for(auto &i : s2){
        i = tolower(static_cast<unsigned char>(i));
    }

    
    if(s1 == s2){
        cout << 0; 
    }else if(s1 < s2){
        cout << -1;
    }else{
        cout << 1; 
    }

    return 0;
}

/*
💭 First Idea: Lowercase both strings then compare with ==, <.
🧩 Key Property / Invariant: Case-insensitive comparison = compare after normalizing case.
✅ Key insight: std::string comparison is already lexicographic.
🔁 Recognition cue for next time: 'Compare ignoring case' -> tolower both, then compare.
⏱  Speed fix for next time: Use transform(s.begin(), s.end(), s.begin(), ::tolower).
🛠  Review: correct; Already optimal.
*/
