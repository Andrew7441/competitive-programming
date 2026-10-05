// Codeforces 1970A1 — Balanced Shuffle (Easy)
// https://codeforces.com/problemset/problem/1970/A1
// Topic: sorting | Tags: strings, prefix-sum
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

/**/

string solve(){
    string s;
    cin >> s;

    vector<tuple<int,int,char>> prefBal;
    int pref = 0;

    for(int i = 0; i < (int)s.length(); i++){
        prefBal.push_back({pref, i, s[i]});
        if(s[i] == '(') pref++;
        else pref--;
    }

    sort(prefBal.begin(), prefBal.end(), [](const auto& a, 
    const auto& b){
        if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        else return get<0>(a) < get<0>(b);
    });

    string res = "";

    for(auto& p: prefBal){
        res += get<2>(p);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();

    return 0;
}

/*
💭 First Idea: Store (prefix balance before i, i, char) and sort by balance asc, position desc.
🧩 Key Property / Invariant: The shuffle is defined exactly as a stable-ish sort on (balance, -position).
✅ Key insight: Implement the definition: custom comparator on (pref, -idx).
🔁 Recognition cue for next time: "Sort characters by some computed key with a tie-break" -> build tuples, custom comparator.
⏱  Speed fix for next time: Sort pairs (pref, -i) with default operator< to avoid writing a lambda.
🛠  Review: correct; Already optimal (n <= 5e5, sort is fine).
*/
