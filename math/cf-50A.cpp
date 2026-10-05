// Codeforces 50A — Domino piling
// https://codeforces.com/problemset/problem/50/A
// Topic: math | Tags: constructive
// Complexity (yours): O(1) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/50/A - domino piling


int main() {


    int m , n;
    cin >> m >> n;
    int res = (m * n) / 2;

    cout << res; 

    return 0;
}

/*
💭 First Idea: Answer is floor(m*n/2).
🧩 Key Property / Invariant: Each domino covers 2 cells; a grid can always be tiled leaving at most 1 cell.
✅ Key insight: Area/2 is both an upper bound and achievable.
🔁 Recognition cue for next time: 'Max number of 2-cell pieces' -> area / 2.
⏱  Speed fix for next time: Think upper bound first, then show it is reachable.
🛠  Review: correct; Already optimal.
*/
