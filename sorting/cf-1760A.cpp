// Codeforces 1760A — Medium Number
// https://codeforces.com/problemset/problem/1760/A
// Topic: sorting
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1760/A Medium Number

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> x(3);

    while(t--){
        for(size_t i = 0; i < x.size();i++){
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        cout << x[1] << endl;

    }

    return 0;
}

/*
💭 First Idea: Sort the three numbers, print the middle.
🧩 Key Property / Invariant: The median of 3 is x[1] after sorting.
✅ Key insight: sort is fine for constant size.
🔁 Recognition cue for next time: 'Middle of three' -> sort or a+b+c-max-min.
⏱  Speed fix for next time: a+b+c-max({a,b,c})-min({a,b,c}) avoids the vector.
🛠  Review: correct; Already optimal.
*/
