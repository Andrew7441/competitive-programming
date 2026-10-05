// Codeforces 61A — Ultra-Fast Mathematician
// https://codeforces.com/problemset/problem/61/A
// Topic: strings | Tags: bit-manipulation
// Complexity (yours): O(n) time, O(n) space
#include <iostream>
#include<string>
using namespace std;

//https://codeforces.com/problemset/problem/61/A Ultra-Fast Mathematician

int main() {

    string s, n;
    cin >> s >> n;

    string res = "";

    for(size_t i = 0; i < s.length(); i++){
        if((s[i] == '1' && n[i] == '0') || (s[i] == '0' && n[i] == '1') ){
            res+= "1";
        }else{
            res += "0";
        }
    }

    cout << res; 

    return 0;
}

/*
💭 First Idea: Build the result digit by digit: 1 if digits differ, else 0.
🧩 Key Property / Invariant: Output digit i = a[i] XOR b[i]; leading zeros must be kept.
✅ Key insight: It is XOR on strings - (s[i] != n[i]) ? '1' : '0'.
🔁 Recognition cue for next time: 'Digit is 1 iff the digits differ' -> XOR.
⏱  Speed fix for next time: Write res += (s[i] != n[i]) ? '1' : '0'; and read numbers as strings to keep leading zeros.
🛠  Review: correct; Already optimal.
*/
