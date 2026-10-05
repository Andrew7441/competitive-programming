// Codeforces 1807B — Grab the Candies
// https://codeforces.com/problemset/problem/1807/B
// Topic: greedy | Tags: math
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1807/B Grab the Candies

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        reverse(a.begin(),a.end());

        int m = 0;
        int b = 0;

        for(int i : a){
            if(i % 2 == 0){
                m += i;
            }else{
                b += i;
            }
        }

        if(m > b){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}

/*
💭 First Idea: Sum the even bags (Mihai) and odd bags (Bianca), YES iff even sum > odd sum.
🧩 Key Property / Invariant: Mihai can put all even bags first, so his total is strictly ahead at every step iff total_even > total_odd.
✅ Key insight: Order is ours to choose -> only the totals matter.
🔁 Recognition cue for next time: 'Reorder so A is always ahead' -> put all of A's items first; compare totals.
⏱  Speed fix for next time: The reverse() is unnecessary; no need to store the array.
🛠  Review: correct; Already optimal.
*/
