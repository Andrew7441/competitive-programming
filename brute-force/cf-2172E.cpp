// Codeforces 2172E — Number Maze
// https://codeforces.com/problemset/problem/2172/E
// Topic: brute-force | Tags: strings, backtracking
// Complexity (yours): O(t * m! * m log m!) time (m <= 4), O(m!) space
#include <bits/stdc++.h>
using namespace std;

/**/

void permute(string& s, int index, vector<string>& permutations){
    if(index == (int)s.size()){
        permutations.push_back(s);
        return;
    }

    for(size_t i = index; i < s.size(); i++){
        swap(s[index], s[i]);
        permute(s, index + 1, permutations);
        swap(s[index], s[i]);
    }
}

void solve(){
    string n;
    int j, k;

    cin >> n >> j >> k;

    vector<string> permutations;
    permute(n, 0, permutations);
    sort(permutations.begin(), permutations.end());

    string s1 = permutations[j-1];
    string s2 = permutations[k-1];

    int a = 0, b = 0;

    for(size_t i = 0; i < s1.size(); i++){
        for(size_t j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                if(i == j) a++;
                else b++;
            }
        }
    }

    cout << a << "A" << b << "B\n"; 
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
💭 First Idea: Generate all permutations recursively, sort, take the j-th and k-th, count A and B.
🧩 Key Property / Invariant: Digits are distinct, so an equal digit at the same index is an A, at another index a B.
✅ Key insight: With m <= 4 there are at most 24 permutations; brute force is trivial.
🔁 Recognition cue for next time: "k-th permutation" with tiny length -> generate them all.
⏱  Speed fix for next time: std::next_permutation on the sorted string yields them in order without recursion + sort.
🛠  Review: correct; tiny input -> Already optimal (next_permutation would be shorter).
*/
