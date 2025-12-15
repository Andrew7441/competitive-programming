#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/236/A Boy or Girl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    unordered_set<char> u(s.begin(), s.end());

    cout << (u.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");

    return 0;
}

/* freq array
int main() {
    string username;
    cin >> username;

    int freq[26] = {0};
    int distinct = 0;

    for (char c : username) {
        int idx = c - 'a';
        if (freq[idx] == 0) {
            distinct++;
        }
        freq[idx]++;
    }

    if (distinct % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;

    return 0;
}

*/