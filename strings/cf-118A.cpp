// Codeforces 118A — String Task
// https://codeforces.com/problemset/problem/118/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/118/A String task

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    cin >> s;

    for(char &c:s){
        c = tolower(c);
    }

    string res = s;

    res.erase(remove_if(res.begin(),res.end(), [](char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';}),
        res.end());

    string out;
    for(char i: res){
        out.push_back('.');
        out.push_back(i);
    }
    

    cout << out;

    return 0;
}

/*
💭 First Idea: Lowercase, erase vowels (including y), then put '.' before every consonant.
🧩 Key Property / Invariant: Each character is handled independently.
✅ Key insight: One pass: skip vowels, otherwise append '.' + tolower(c).
🔁 Recognition cue for next time: 'Transform each char by a rule' -> single pass building the output.
⏱  Speed fix for next time: Remember that 'y' counts as a vowel here.
🛠  Review: correct; Already optimal.
*/
