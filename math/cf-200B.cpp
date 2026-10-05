// Codeforces 200B — Drinks
// https://codeforces.com/problemset/problem/200/B
// Topic: math | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/200/B Drinks

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n; 
    cin >> n;

    double res = 0;
    int p;
    for(int i = 0; i < n; i++){
        cin >> p;
        res += p;
    }
    cout << double(res/n) << endl;

    return 0;
}

/*
💭 First Idea: Average of the n percentages.
🧩 Key Property / Invariant: Equal volumes mixed -> concentration is the arithmetic mean.
✅ Key insight: Answer = sum / n.
🔁 Recognition cue for next time: 'Mix equal amounts' -> mean.
⏱  Speed fix for next time: Print with fixed << setprecision(12); default 6 digits only passes because the error limit is 1e-4.
🛠  Review: correct; Already optimal (file is named 200A but is problem 200B).
*/
