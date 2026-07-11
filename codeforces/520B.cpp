#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
   int n, m;
   cin >> n >> m;

   int ans = 0;

   while(m > n){
    if(m % 2 == 0){
        m /= 2; // reverse multipying of 2
    }else m++;  // reverse subtracting by 1

    ans++;
   }

   ans += n - m;

   cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea
Simulate backwards from m to n.

🧩 Key Property / Invariant
Reverse of multiplying by 2 is dividing by 2.
Reverse of subtracting 1 is adding 1.

✅ Key insight
If m is even, divide it by 2.
If m is odd, add 1 so it becomes divisible by 2.

🔁 Recognition cue for next time
When forward greedy has multiple choices, try reversing the operations.

⏱ Speed fix for next time
Reverse simulation reduces m roughly by half each time: O(log m).
*/