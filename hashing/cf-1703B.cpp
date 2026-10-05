// Codeforces 1703B — ICPC Balloons
// https://codeforces.com/problemset/problem/1703/B
// Topic: hashing | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
#include <set>
using namespace std;

//https://codeforces.com/problemset/problem/1703/B ICPC Balloons

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;

        unordered_set<char> s;
        int res = 0;

        for(int i = 0; i < n; i++){
            if(!s.count(str[i])){
                res+=2;
                s.insert(str[i]);
            }else{
                res++;
            }
        }
        cout << res << endl; 
    }



    return 0;
}
// proud of myself for this one here

/*
💭 First Idea: Each solve gives 1 balloon, the first solve of a problem gives 1 extra.
🧩 Key Property / Invariant: Answer = n + (number of distinct letters).
✅ Key insight: A set tracks 'first time seen'.
🔁 Recognition cue for next time: 'Bonus on first occurrence' -> set / seen[26] array.
⏱  Speed fix for next time: cout << n + distinct << '\n' with a bool seen[26].
🛠  Review: correct; Already optimal.
*/
