// Codeforces 339A — Helpful Maths
// https://codeforces.com/problemset/problem/339/A
// Topic: sorting | Tags: strings
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> res;
    string r = "";

    for(size_t i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            res.push_back(s[i]);
        }
    }

    sort(res.begin(), res.end());

    for(int i:res){
        r += i;
        r += "+";
    }

    r.pop_back();

    cout << r << '\n';

    return 0;
}

/*
💭 First Idea: Extract digits, sort them, join with '+'.
🧩 Key Property / Invariant: Only digits 1-3 occur; order them non-decreasingly.
✅ Key insight: Sort the digits (or count 1s/2s/3s - counting sort).
🔁 Recognition cue for next time: 'Rearrange to sorted order' -> sort; tiny alphabet -> counting.
⏱  Speed fix for next time: Store digits as char (vector<char> or string) to avoid int->char conversions.
🛠  Review: correct; Already optimal for |s| <= 100.
*/
