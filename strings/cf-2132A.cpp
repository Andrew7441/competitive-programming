// Codeforces 2132A — Homework
// https://codeforces.com/problemset/problem/2132/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n + m) time, O(n + m) space
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

        string a;
        cin >> a;
        
        int m;
        cin >> m;

        string b;
        cin >> b;

        string c;
        cin >> c;

        list<char> res;
        for(char i : a){
            res.push_back(i);
        }

        for(int i = 0; i < m; i++){
            if(c[i] == 'D'){
                res.push_back(b[i]);
            }else{
                res.push_front(b[i]);
            }
        }

        std::string z(res.begin(), res.end());

        cout << z << "\n";

    }

    return 0;
}

/*
💭 First Idea: Simulate with a linked list: push_front for 'V', push_back for 'D'.
🧩 Key Property / Invariant: Characters of b are added in order, each to the front (Vlad) or back (Dima).
✅ Key insight: A deque/list gives O(1) per insertion; with n, m <= 10 anything works.
🔁 Recognition cue for next time: "Add to beginning or end" -> deque simulation.
⏱  Speed fix for next time: std::deque<char> is the usual tool; std::list is fine too.
🛠  Review: correct; O(n + m) -> Already optimal.
*/
