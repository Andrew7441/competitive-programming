// Codeforces 2166B — Tab Closing
// https://codeforces.com/problemset/problem/2166/B
// Topic: math | Tags: implementation
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int a, b, n;
        cin >> a >> b >> n;

        if((long long)b*n <= a || b >= a){
            cout << "1\n";
        }else{
            cout << "2\n";
        }
    }


    return 0;
}

/*
💭 First Idea: Answer 1 if b*n <= a (tabs never shrink) or b >= a (last x always at a), else 2.
🧩 Key Property / Invariant: While m*b <= a the tab length is b (first x at b); once a/m < b the last x is at a.
✅ Key insight: Two cursor positions (b and a) always suffice; one suffices only in the two extreme cases.
🔁 Recognition cue for next time: "Lengths depend on the remaining count" -> find the phase change at m = a/b.
⏱  Speed fix for next time: Use long long for b*n (up to 1e18).
🛠  Review: correct; O(1) -> Already optimal.
*/
