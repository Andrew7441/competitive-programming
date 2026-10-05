// Codeforces 1900A — Cover in Water
// https://codeforces.com/problemset/problem/1900/A
// Topic: greedy | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s; 
        cin >> s;

        bool con = false; 
        for(int i = 2; i < n; i++){
            if(s[i - 2] == '.' && s[i] == '.' && s[i-1] == '.'){
                con = true;
                break;
            }
        }

        if(con){
            cout << 2 << "\n";
            continue;
        }

        int c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '.'){
                c++;
            }
        }
        cout << c << "\n";

    }

    return 0;
}

/*
💭 First Idea: If there are 3 consecutive empty cells answer 2, otherwise count the empty cells.
🧩 Key Property / Invariant: With 2 water cells around an empty one you can draw infinitely from the middle; that needs a run of >= 3.
✅ Key insight: Any run >= 3 makes the answer 2; else each cell needs its own action.
🔁 Recognition cue for next time: 'Infinite source if X' -> find the trigger pattern, else count.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
