#include <bits/stdc++.h>
using namespace std;

/**/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> both, twoOnly, threeOnly, neither;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        // Numbers divisible by 6 already contain both factors 2 and 3.
        if (x % 6 == 0) {
            both.push_back(x);
        }
        // Numbers divisible by 2 only.
        else if (x % 2 == 0) {
            twoOnly.push_back(x);
        }
        // Numbers divisible by 3 only.
        else if (x % 3 == 0) {
            threeOnly.push_back(x);
        }
        // Numbers that do not help make product divisible by 6.
        else {
            neither.push_back(x);
        }
    }

    // Optimal order:
    // both factors first, then 2-only, then neutral, then 3-only.
    for (long long x : both) cout << x << ' ';
    for (long long x : twoOnly) cout << x << ' ';
    for (long long x : neither) cout << x << ' ';
    for (long long x : threeOnly) cout << x << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
/*
💭 First Idea
Since product divisible by 6 means the product must contain both factor 2 and factor 3,
classify every number based on whether it gives factor 2, factor 3, both, or neither.

🧩 Key Property / Invariant
A subarray is counted if it contains enough elements to provide both:
- at least one factor 2
- at least one factor 3

✅ Key Insight
Any number divisible by 6 makes every subarray containing it valid, so put all of them at one side.
To minimize subarrays containing both a factor 2 and factor 3, keep 2-only and 3-only groups separated.
Put neutral numbers between them because they do not add factors.

Optimal order:
divisible_by_6 -> divisible_by_2_only -> neutral -> divisible_by_3_only

🔁 Recognition cue for next time
When a problem asks to reorder an array to minimize subarrays with a product divisible by some number,
think about prime factors instead of actual values.

⏱ Speed fix for next time
Immediately split numbers into categories by divisibility:
x % 6 == 0
x % 2 == 0
x % 3 == 0
otherwise neutral
*/