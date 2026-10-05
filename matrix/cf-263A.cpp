// Codeforces 263A — Beautiful Matrix
// https://codeforces.com/problemset/problem/263/A
// Topic: matrix | Tags: math
// Complexity (yours): O(1) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/263/A Beautiful Matrix

int main() {

    int x=0, y=0, a; 

    for(int i = 1; i<=5;i++){
        for(int j = 1; j <= 5; j++){
            cin >> a;
            if(a == 1){
                x = i; 
                y = j;
            }
        }
    }
    cout << abs(x-3) + abs(y-3);

    return 0;
}

/*
💭 First Idea: Find the 1's position and print its Manhattan distance to (3,3).
🧩 Key Property / Invariant: Each adjacent row/column swap moves the 1 by one step.
✅ Key insight: Moves = |r-3| + |c-3|.
🔁 Recognition cue for next time: 'Swap adjacent rows/columns to move a cell' -> Manhattan distance.
⏱  Speed fix for next time: Include <cstdlib> (or bits/stdc++) for abs.
🛠  Review: correct; Already optimal.
*/
