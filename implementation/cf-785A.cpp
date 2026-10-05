// Codeforces 785A — Anton and Polyhedrons
// https://codeforces.com/problemset/problem/785/A
// Topic: implementation | Tags: hashing
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/785/A  Anton and Polyhedrons

int main() {

    int n;
    cin >> n;

    int res = 0;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "Icosahedron"){
            res += 20;
        }else if(s == "Dodecahedron"){
            res += 12;
        }else if(s == "Octahedron"){
            res += 8;
        }else if(s == "Cube"){
            res += 6;
        }else{
            res += 4;
        }
    }
    cout << res;

    return 0;
}

/*
💭 First Idea: Map each polyhedron name to its face count and sum.
🧩 Key Property / Invariant: Fixed lookup: 4/6/8/12/20 faces.
✅ Key insight: A tiny name→value table is all that's needed.
🔁 Recognition cue for next time: Fixed name→value mapping → if-chain or unordered_map.
⏱  Speed fix for next time: unordered_map<string,int> faces{{"Tetrahedron",4},...} keeps it compact.
🛠  Review: correct; O(n) — Already optimal.
*/
