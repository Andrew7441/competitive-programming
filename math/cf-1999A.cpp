// Codeforces 1999A — A+B Again?
// https://codeforces.com/problemset/problem/1999/A
// Topic: math
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1999/A

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    
    while(t--){
        int res = 0;
        string s;
        int x;
        cin >> x;
        s = to_string(x);

        for(size_t i = 0; i < s.length();i++){
            res += s[i] - '0';
        }
        cout << res << endl;; 
    }


    return 0;
}

/*
💭 First Idea: Convert n to string and sum the digits.
🧩 Key Property / Invariant: n is two-digit, so the answer is n/10 + n%10.
✅ Key insight: Digit sum of a 2-digit number = tens + ones.
🔁 Recognition cue for next time: "Sum of digits" -> repeated %10 and /10 (no strings needed).
⏱  Speed fix for next time: cout << n/10 + n%10.
🛠  Review: correct; Already optimal.
*/
