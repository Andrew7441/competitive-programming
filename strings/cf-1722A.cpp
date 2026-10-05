// Codeforces 1722A — Spell Check
// https://codeforces.com/problemset/problem/1722/A
// Topic: strings | Tags: sorting
// Complexity (yours): O(n log n) time (n <= 10), O(1) space
#include <bits/stdc++.h>
#include <set>
using namespace std;
//https://codeforces.com/problemset/problem/1722/A Spell Check 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t; 
    cin >> t; 

    while(t--){
        size_t n;
        cin >> n;

        string s;
        cin >> s;

        size_t len = s.size();

        if(len != n){
            cout << "NO" << endl;
            continue;
        }

        const string target = "Timru";

        sort(s.begin(),s.end());

        if(s == target){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
💭 First Idea: Length must be 5 and sorted(s) must equal sorted("Timru").
🧩 Key Property / Invariant: Anagram check = compare sorted strings.
✅ Key insight: "Timru" is already sorted in ASCII ('T' < lowercase), so comparing to it directly works.
🔁 Recognition cue for next time: 'Is s a permutation of t' -> sort both (or count chars).
⏱  Speed fix for next time: Sort the target too (sort(target)) so you don't rely on it being pre-sorted.
🛠  Review: correct; Already optimal.
*/
