// Codeforces 910C — Minimum Sum
// https://codeforces.com/problemset/problem/910/C
// Topic: greedy | Tags: sorting, math
// Complexity (yours): O(10·10 log 10) + O(total length) time, O(1) space
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**/

void solve(){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> weight(10, 0);
    vector<int> cantZero(10, false);

    for(int k = 0; k < n; k++){
        string s;
        cin >> s;
        
        // no leading zero
        cantZero[s[0] - 'a'] = true;

        long long place = 1;
        for(int i = (int)s.size() - 1; i >= 0; i--){
            int id = s[i] - 'a';
            weight[id] += place;
            place *= 10;
        }
    }

    long long best = __LONG_LONG_MAX__;

    for(int zero = 0; zero < 10; zero++){
        if(cantZero[zero]) continue;

        vector<int> letters;
        for(int i = 0; i < 10; i++){
            if(i != zero) letters.push_back(i);
        }

        sort(letters.begin(), letters.end(), [&](int a, int b){
            return weight[a] > weight[b];
        });

        long long sum = 0;
        int digit = 1;

        for(int id : letters){
            sum += weight[id] * digit;
            digit++;
        }

        best = min(best, sum);
    }

    cout << best << '\n';


    return 0;
}

/*
💭 First Idea: Weight each letter by its place values, try every allowed letter as 0, give 1..9 to the rest by weight desc.
🧩 Key Property / Invariant: Total sum = Σ weight[letter]·digit[letter], so it's a rearrangement-inequality assignment.
✅ Key insight: Bigger weight → smaller digit; the only twist is 0 can't go to a leading letter.
🔁 Recognition cue for next time: "Assign digits to letters to minimize sum" → compute positional weights, sort.
⏱  Speed fix for next time: Simpler: sort by weight once, give 0 to the heaviest non-leading letter, then 1..9 in order (same result). Empty solve() stub can be removed.
🛠  Review: correct (stress-tested vs brute force); O(1)-ish — Already optimal.
*/
