// Codeforces 510A — Fox And Snake
// https://codeforces.com/problemset/problem/510/A
// Topic: implementation | Tags: math
// Complexity (yours): O(n·m) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/510/A Fox and Snake

int main() {

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(i%4==2){
                if(j==m-1) cout << "#";
                else cout << ".";
            }else if(i%4==0){
                if(j==0) cout << "#";
                else cout << ".";
            }else{
                cout << "#";
            }
        }
        cout << endl;
    }

    return 0;
}

/*
💭 First Idea: Print row by row; odd rows full '#', rows ≡2 mod 4 end with '#', rows ≡0 mod 4 start with '#'.
🧩 Key Property / Invariant: The pattern repeats every 4 rows.
✅ Key insight: Use i%4 to decide which of the 3 row shapes to print.
🔁 Recognition cue for next time: Pattern/ASCII-art output → find the period and switch on index mod period.
⏱  Speed fix for next time: Build each row as a string (string(m,'#') etc.) instead of char-by-char.
🛠  Review: correct; O(n·m) — Already optimal.
*/
