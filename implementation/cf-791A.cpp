// Codeforces 791A — Bear and Big Brother
// https://codeforces.com/problemset/problem/791/A
// Topic: implementation | Tags: math, brute-force
// Complexity (yours): O(log(b/a)) time, O(1) space
#include <iostream>
using namespace std;

// https://codeforces.com/problemset/problem/791/A Bear and Big Brother

int main() {

    int a, b; 
    cin >> a >> b;

    int res = 0; 

    while(a <= b){ 
        a *= 3;    
        b *= 2;    
        res++;    
    }

    cout << res; 
 
    return 0;
}

/*
💭 First Idea: Simulate years: a*=3, b*=2 until a > b.
🧩 Key Property / Invariant: Ratio a/b grows by 1.5 each year.
✅ Key insight: With a,b ≤ 10 it takes at most 6 years — simulation is instant.
🔁 Recognition cue for next time: Small growth simulation → while loop.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(log) — Already optimal.
*/
