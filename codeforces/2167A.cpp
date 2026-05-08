#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a == b && a == c && a == d &&
       b == a && b == c && b == d && 
       c == a && c == b && c == d && 
       d == a && d == b && d == c){
        cout << "YES\n";
       }else{
        cout << "NO\n";
       }
 
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
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱  Speed fix for next time
*/