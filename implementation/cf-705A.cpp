// Codeforces 705A — Hulk
// https://codeforces.com/problemset/problem/705/A
// Topic: implementation | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
#include <string> 
using namespace std;
//https://codeforces.com/problemset/problem/705/A Hulk

int main() {

    int n; 
    cin >> n;
    string s; 

    for(int i = 1; i <= n; i++){
        if(i%2==1){
            cout << "I hate";
        }else{
            cout << "I love";
        }

        if(i==n){
            cout << " it";
        }else{
            cout <<  " that ";
        }
    }
 
    return 0;
}

/*
💭 First Idea: Alternate "I hate"/"I love" by parity, join with " that ", end with " it".
🧩 Key Property / Invariant: Odd layers = hate, even layers = love.
✅ Key insight: Separator depends only on whether it is the last layer.
🔁 Recognition cue for next time: Alternating phrases → parity of the index.
⏱  Speed fix for next time: Unused `string s` can be removed.
🛠  Review: correct; O(n) — Already optimal.
*/
