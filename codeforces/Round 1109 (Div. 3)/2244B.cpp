#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;

   long long prefSum = 0;
   bool possible = true;

   for(long long k = 1; k <= n; k++){
    int x;
    cin >> x;

    prefSum += x;

    int minNeeded = k * (k + 1) / 2;

    if(prefSum < minNeeded){
        possible = false;
    }
   }

   cout << (possible ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱ Speed fix for next time
*/