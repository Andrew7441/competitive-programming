#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string keyboard;
        cin >> keyboard;

        string s; 
        cin >> s;
        
        unordered_map<char, int> pos;
        for(int i = 1; i < 27;i++){
            pos[keyboard[i]] = i;
        }

        int res = 0;

        for(size_t i = 1; i < s.length(); i++){
            res += abs(pos[s[i-1]] - pos[s[i]]);
        }

        cout << res << "\n";

    }

    return 0;
}