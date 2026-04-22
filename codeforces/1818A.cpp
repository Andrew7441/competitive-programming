#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/problemset/problem/1818/A
*/

void solve(){
    int n, k;
    cin >> n >> k;

    string t[n];
    int ans = n;

    for(int i = 0; i < n; i++){
        cin >> t[i];
        if(t[i] != t[0]){
            ans--;
        }
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
I tried to simulate the Y/N counts each round.

🧩 Key Property / Invariant
Anyone who stays with the president must have the exact same opinion string as him.

✅ Key insight
The problem is just counting how many strings are equal to t[0].

🔁 Recognition cue for next time
If I can choose a subset first, think compatibility/filtering before simulation.

⏱  Speed fix for next time
If I am only simulating for 10-15 minutes, stop and ask what must always be true.
*/