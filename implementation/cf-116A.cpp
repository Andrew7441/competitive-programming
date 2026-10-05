// Codeforces 116A — Tram
// https://codeforces.com/problemset/problem/116/A
// Topic: implementation | Tags: simulation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/116/A Tram

int main() {

    int n; 
    cin >> n; 

    int res = 0; 
    int min = 0; 

    for(int i = 0; i < n; i++){
        int a, b; 
        cin >> a >> b; 
        res -= a; 
        res += b; 
        if(min < res){
            min = res;
        }
    }
    cout << min; 

    return 0;
}

/*
💭 First Idea: Simulate: subtract exits, add entries, track the max passengers.
🧩 Key Property / Invariant: Capacity needed = max prefix sum of (b_i - a_i).
✅ Key insight: Running max of the current load.
🔁 Recognition cue for next time: 'Minimum capacity' -> max of the running total.
⏱  Speed fix for next time: Don't name a variable 'min' when it stores a maximum (shadows std::min).
🛠  Review: correct; Already optimal.
*/
