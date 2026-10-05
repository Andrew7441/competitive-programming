// Codeforces 2175A — Little Fairy's Painting
// https://codeforces.com/problemset/problem/2175/A
// Topic: math | Tags: hashing
// Complexity (yours): O(n log n) time, O(n) space
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

        vector<int> a(n);
        set<int> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }

        int d = s.size();
        int ans = INT_MAX;
        for(int x : a){
            if(x >= d){
                ans = std::min(ans, x);
            }
        }
        
        std::cout << ans << '\n';
    }

    return 0;
}

/*
💭 First Idea: d = #distinct colours; answer = smallest existing colour >= d.
🧩 Key Property / Invariant: If colour c = #distinct is new, the count becomes c+1 and the next cell gets c+1; it stops once it hits an existing colour.
✅ Key insight: The walk d, d+1, ... stops at the first existing colour >= d (exists, since d distinct positive values have max >= d).
🔁 Recognition cue for next time: Huge index like 10^18 -> the process must stabilise; find the fixed point.
⏱  Speed fix for next time: Simulate a few steps by hand to see the walk d, d+1, ...
🛠  Review: correct (stress-tested vs simulation); O(n log n) -> Already optimal.
*/
