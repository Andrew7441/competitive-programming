#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i += 2){
        ans = max(ans, a[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea
Simulate the process by deleting pairs from the left or right, trying to keep the larger value.

🧩 Key Property / Invariant
Each operation removes exactly 2 adjacent elements, so the parity of the remaining element's index matters.
Only elements at even 0-based indexes can remain.

✅ Key insight
To keep a[i], there must be an even number of elements before it and after it.
Since n is odd, this is only true when i is even.
So the answer is max(a[0], a[2], a[4], ...).

🔁 Recognition cue for next time
If an operation removes 2 elements until 1 remains, check parity instead of simulating.

⏱ Speed fix for next time
Loop over even indexes only:
for (int i = 0; i < n; i += 2)
    ans = max(ans, a[i]);
*/