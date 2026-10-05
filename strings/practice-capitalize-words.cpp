// Practice — Capitalize Every Word
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) extra space
// Source: split from codeforces/practice.cpp (original problem statement below)
// Write a function that capitalizes the first letter of every word in a string
//  without using built-in title-case methods. Input:  "hello world from python"

#include <bits/stdc++.h>
using namespace std;

string solve(string& s){
    bool newWord = true;

    for(char& c : s){
        if(newWord){
            c = toupper(c);
            newWord = false;
        }

        if(c == ' ') newWord = true;
    }

    return s;
}

int main(){
    string s = "hello world from python";

    cout << solve(s);
    return 0;
}

/*
💭 First Idea: Keep a newWord flag; uppercase the first character after a space.
🧩 Key Property / Invariant: A character starts a word iff it is the first char or follows a space.
✅ Key insight: One pass with a boolean flag is enough; toupper leaves non-letters unchanged.
🔁 Recognition cue for next time: "Title-case / capitalize words manually" -> flag set by the previous character.
⏱  Speed fix for next time: Check i == 0 || s[i-1] == ' ' directly instead of carrying a flag.
🛠  Review: correct; O(n) -> Already optimal.
*/
