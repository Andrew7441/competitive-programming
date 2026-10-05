// Codeforces 467A — George and Accommodation
// https://codeforces.com/problemset/problem/467/A
// Topic: implementation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/467/A George and Accommodation

int main() {

    int n;
    cin >> n;

    int res = 0;

    for(int i = 0; i < n; i++){
        int p, q;
        cin >> p >> q;
        
        if(p+2 <= q){
            res++;
        }
    }

    cout << res; 

    return 0;
}

/*
💭 First Idea: Count rooms where q - p >= 2.
🧩 Key Property / Invariant: Room fits both iff at least 2 free places.
✅ Key insight: Simple condition per room.
🔁 Recognition cue for next time: 'Count items meeting a condition' -> loop + counter.
⏱  Speed fix for next time: Read and count on the fly.
🛠  Review: correct; Already optimal.
*/
