// Codeforces 2042B — Game with Colored Marbles
// https://codeforces.com/problemset/problem/2042/B
// Topic: game-theory | Tags: greedy, counting
// Complexity (yours): O(n) per test
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

        vector<int> c(n);
        for(int i = 0; i < n; i++) cin >> c[i];
        
        vector<int> freq(n+1, 0);

        for(int x : c) freq[x]++;

        int single = 0, multi = 0;

        for(int i = 1; i <= n; i++){
            if(freq[i] == 1) single++;
            else if(freq[i] > 1) multi++;
        }


        int alice = multi + ((single + 1) / 2) * 2;

        cout << alice << '\n';
    }

    return 0;
}

/*
💭 First Idea: Count unique colors u and repeated colors k; answer = 2*ceil(u/2) + k.
🧩 Key Property / Invariant: Both players first fight over unique marbles (worth 2 each); afterwards Bob can mirror so Alice gets exactly 1 per remaining color.
✅ Key insight: Alice takes ceil(u/2) uniques (2 points each) + 1 point for every color with cnt >= 2.
🔁 Recognition cue for next time: Two-player taking game with per-color scores -> separate singletons from multiples, think mirroring.
⏱  Speed fix for next time: Count freq once, then plug into the formula.
🛠  Review: correct; Already optimal (verified vs minimax brute force).
*/
