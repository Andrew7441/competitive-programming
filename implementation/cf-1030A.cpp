// Codeforces 1030A — In Search of an Easy Problem
// https://codeforces.com/problemset/problem/1030/A
// Topic: implementation | Tags: arrays
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/1030/A In Search of an Easy Problem

int main() {
    
    int n; 
    cin >> n;

    for(int i =0; i < n; i++){
        int a; 
        cin >> a; 
        if(a == 1){
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
    return 0;
}

/*
💭 First Idea: If any response is 1 → HARD, else EASY.
🧩 Key Property / Invariant: One '1' is enough to decide.
✅ Key insight: Early exit on first 1.
🔁 Recognition cue for next time: "If anyone says X" → any_of.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
