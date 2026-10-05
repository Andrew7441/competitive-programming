// Codeforces 344A — Magnets
// https://codeforces.com/problemset/problem/344/A
// Topic: implementation | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
#include<string>
using namespace std;

//https://codeforces.com/problemset/problem/344/A magnets

int main() {

    int n;
    cin >> n; 

    int g = 1; 

    string prev, curr; 

    cin >> prev; 


    for(int i = 1; i < n; i++){
        cin >> curr; 
        if(prev!=curr){
            g++;
        }
        prev = curr; 
    }
    cout << g; 

    return 0;
}

/*
💭 First Idea: Count positions where a magnet differs from the previous one; groups = 1 + changes.
🧩 Key Property / Invariant: A new group starts exactly when neighbours differ.
✅ Key insight: Count boundaries between runs.
🔁 Recognition cue for next time: 'Number of groups/blocks' -> 1 + number of changes.
⏱  Speed fix for next time: Compare only first chars if you like; strings work too.
🛠  Review: correct; Already optimal.
*/
