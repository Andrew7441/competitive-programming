// Codeforces 2141A — Furniture Store
// https://codeforces.com/problemset/problem/2141/A
// Topic: arrays | Tags: implementation
// Complexity (yours): O(n) time, O(n) space
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
        for(int i = 0; i < n; i++) cin >> a[i];

        int cheapest = INT_MAX;
  
        vector<int> ind;

        for(int i = 0; i < n; i++){
            if(a[i] < cheapest){
                cheapest = a[i];
            }else{
                ind.push_back(i+1);
            }
        }
        int size = ind.size();

        cout << size << '\n';
        for(int i : ind){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
💭 First Idea: Keep the running prefix minimum; a sofa is never ordered if a cheaper one comes before it.
🧩 Key Property / Invariant: Sofa i is bought (budget a_i) iff every earlier sofa costs more, i.e. a_i is a new prefix minimum.
✅ Key insight: Answer = indices that are not prefix minima.
🔁 Recognition cue for next time: "First item with price <= m" -> prefix minimum.
⏱  Speed fix for next time: Single pass with a running min.
🛠  Review: correct; O(n) -> Already optimal.
*/
