// Codeforces 110A — Nearly Lucky Number
// https://codeforces.com/problemset/problem/110/A
// Topic: strings | Tags: math
// Complexity (yours): O(d) time, O(d) space
#include <iostream>
#include <string> 

using namespace std;

//https://codeforces.com/problemset/problem/110/A Nearly Lucky Number

int main() {

    string s;
    cin >> s; 

    int c = 0; 

    for(size_t i = 0; i < s.length();i++){
        if(s[i] == '4' or s[i] == '7'){
            c++;
        }
    }   

    if(c == 4 or c == 7){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}

/*
💭 First Idea: Count digits 4/7, then check if the count is 4 or 7.
🧩 Key Property / Invariant: n <= 10^18 has at most 19 digits, so the count is a lucky number only if it is 4 or 7.
✅ Key insight: Read the number as a string to inspect digits; the count is small.
🔁 Recognition cue for next time: 'Property of the digit count' -> read as string and count.
⏱  Speed fix for next time: Read big numbers as strings to avoid overflow worries.
🛠  Review: correct; Already optimal.
*/
