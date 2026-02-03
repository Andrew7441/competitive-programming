#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        unordered_map<char, int> cnt;

        for(char i : s){
            cnt[i]++;
        }

        string newstr = "";
        for(auto &p : cnt){
            if(p.first != 'T') continue;
            cout << string(p.second, p.first);
        }

        for(auto &p : cnt){
            if(p.first != 'T'){
                cout << string(p.second, p.first);
            }
        }
        cout << '\n';
    }
    return 0;
}