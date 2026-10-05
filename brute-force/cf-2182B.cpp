// Codeforces 2182B — New Year Cake
// https://codeforces.com/problemset/problem/2182/B
// Topic: brute-force | Tags: math, greedy
// Complexity (yours): O(log(a + b)) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int simulate(int a, int b, bool whiteStart){
    int sz = 1;
    int layers = 0;
    bool whiteTurn = whiteStart;

    while(true){
        if(whiteTurn){
            if(a < sz) break;
            a -= sz;            
        }else{
            if(b < sz) break;
            b -= sz;
        }

        sz *= 2;
        layers++;
        whiteTurn = !whiteTurn;
    }

    return layers;
}

void solve(){
    int a, b;
    cin >> a >> b;

    cout << max(simulate(a, b, true), simulate(a,b, false)) << "\n";
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
💭 First Idea: Simulate both choices of the top layer colour and take the better layer count.
🧩 Key Property / Invariant: Layers alternate, so white gets sizes 1,4,16,... or 2,8,32,... depending on the start colour.
✅ Key insight: Only two colourings exist; simulate each until one chocolate runs out.
🔁 Recognition cue for next time: "Alternating fixed sequence, two resources" -> try both starting choices.
⏱  Speed fix for next time: Each simulation is ~20 steps; no formula needed.
🛠  Review: correct; O(log(a+b)) -> Already optimal.
*/
