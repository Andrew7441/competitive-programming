// Codeforces 996A — Hit the Lottery
// https://codeforces.com/problemset/problem/996/A
// Topic: greedy | Tags: math
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    int count = 0;
    int bills[] = {100, 20, 10, 5, 1};

    for(int b: bills){
        count += n / b;
        n %= b;
    }

    cout << count << '\n';



    return 0;
}

/*
💭 First Idea: Use largest bills first: n/100, then remainder by 20, 10, 5, 1.
🧩 Key Property / Invariant: Each denomination divides the next larger one (canonical coin system), so greedy is optimal.
✅ Key insight: Greedy change-making works for {1,5,10,20,100}.
🔁 Recognition cue for next time: Coin change with canonical denominations → greedy largest first.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(1) — Already optimal.
*/
