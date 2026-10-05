// Codeforces 1926A — Vlad and the Best of Five
// https://codeforces.com/problemset/problem/1926/A
// Topic: strings
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1926/A A. Vlad and the Best of Five

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int a=0,b=0;
        string s;
        cin >> s;

        for(char i: s){
            if(i == 'A'){
                a++;
            }else{
                b++;
            }
        }
        if(a > b){
            cout << "A\n";
        }else{
            cout << "B\n";
        }
    }

    return 0;
}

/*
💭 First Idea: Count 'A's and print A if they are the majority.
🧩 Key Property / Invariant: Length is 5 (odd), so there is no tie.
✅ Key insight: count(s.begin(), s.end(), 'A') > 2.
🔁 Recognition cue for next time: 'Majority of a fixed small string' -> count one letter.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
