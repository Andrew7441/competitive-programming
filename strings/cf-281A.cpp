// Codeforces 281A — Word Capitalization
// https://codeforces.com/problemset/problem/281/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
#include<string>
using namespace std;

//https://codeforces.com/problemset/problem/281/A Word Capitalization

int main() {

    string s; 
    cin >> s; 

    s[0] = toupper(s[0]);

    cout << s;

    return 0;
}

/*
💭 First Idea: Uppercase the first character, print.
🧩 Key Property / Invariant: Only s[0] changes; the rest stays as is.
✅ Key insight: toupper(s[0]).
🔁 Recognition cue for next time: 'Capitalize' -> change only the first letter.
⏱  Speed fix for next time: Don't lowercase the rest - the statement says keep it.
🛠  Review: correct; Already optimal.
*/
