// Codeforces 228A — Is your horseshoe on the other foot?
// https://codeforces.com/problemset/problem/228/A
// Topic: hashing | Tags: implementation
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int res = 0;
    unordered_set<int> s;

    for(int i = 0; i < 4; i++){
        int a;
        cin >> a;
        if(s.count(a)) res++;
        s.insert(a);
    }

    cout << res;

    return 0;
}

/*
💭 First Idea: Insert colors into a set; count values already seen.
🧩 Key Property / Invariant: Answer = 4 - number of distinct colors.
✅ Key insight: A set gives the number of distinct values.
🔁 Recognition cue for next time: 'How many to replace to make all distinct' -> total - distinct.
⏱  Speed fix for next time: cout << 4 - set<int>{a,b,c,d}.size();
🛠  Review: correct; Already optimal.
*/
