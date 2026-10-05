// Codeforces 266A — Stones on the Table
// https://codeforces.com/problemset/problem/266/A
// Topic: strings | Tags: greedy
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/266/A Stones on the Table

int main() {

    int n;
    string s; 
    cin >> n >> s; 
    
    int res = 0; 

    for(int i = 0; i < n; i++){
        if(s[i] == s[i+1]){
            res++;
        }
    }
    
    cout << res; 

 
    return 0;
}

/*
💭 First Idea: Count i where s[i] == s[i+1].
🧩 Key Property / Invariant: Each pair of equal neighbours needs exactly one removal.
✅ Key insight: Answer = number of adjacent equal pairs.
🔁 Recognition cue for next time: 'Remove so no two neighbours are equal' -> count equal adjacent pairs.
⏱  Speed fix for next time: Loop i + 1 < n; your s[n] read is legal only because std::string has a '\0' there.
🛠  Review: correct; Already optimal.
*/
