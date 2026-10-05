// Codeforces 1367B — Even Array
// https://codeforces.com/problemset/problem/1367/B
// Topic: math | Tags: greedy
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1367/B Even Array
 
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

        int wrongodd = 0;
        int wrongeven = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % 2 != i % 2){
                if(i % 2 ==0){
                    wrongeven++;
                }else{
                    wrongodd++;
                }   
            }
        }
        if(wrongeven != wrongodd){
            cout << -1 << "\n";
        }else{
            cout << wrongeven << "\n";
        }
    }

    return 0;
}

/*
💭 First Idea: Count even positions holding odd values and odd positions holding even values; equal → that count, else −1.
🧩 Key Property / Invariant: A swap fixes exactly one wrong-even and one wrong-odd position.
✅ Key insight: Answer = mismatch count if both mismatch types are equal, else impossible.
🔁 Recognition cue for next time: Parity must match index parity with swaps → count both kinds of mismatch.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
