// Codeforces 427A — Police Recruits
// https://codeforces.com/problemset/problem/427/A
// Topic: implementation | Tags: greedy, simulation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/427/A Police Recruits

int main() {

    int n;
    cin >> n;
    
    int officers = 0; 
    int untreated = 0;

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;

        if(x>0) officers+=x;
        else if(officers>0) officers--;
        else untreated++;
    }

    cout << untreated;

    return 0;
}

/*
💭 First Idea: Simulate: add recruits, a crime uses a free officer or goes untreated.
🧩 Key Property / Invariant: Free officers can always be used greedily for the current crime.
✅ Key insight: Keep one counter of free officers.
🔁 Recognition cue for next time: 'Events in time order with a resource' -> simulate with a counter.
⏱  Speed fix for next time: Process online while reading.
🛠  Review: correct; Already optimal.
*/
