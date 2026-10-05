// Codeforces 977A — Wrong Subtraction
// https://codeforces.com/problemset/problem/977/A
// Topic: implementation | Tags: math
// Complexity (yours): O(k) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/977/A Wrong Subtraction

int main() {
    
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        if(n % 10 == 0){
            n/=10;
        }else{
            n--;
        }
    }
    
    cout << n; 
 
    return 0;
}

/*
💭 First Idea: Simulate k steps: drop last digit if 0, else decrement.
🧩 Key Property / Invariant: k ≤ 50 so simulation is trivial.
✅ Key insight: Just follow Tanya's rule literally.
🔁 Recognition cue for next time: "Apply this operation k times" with small k → simulate.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(k) — Already optimal.
*/
