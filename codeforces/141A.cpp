#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t, x;
    cin >> s >> t >> x;

    char freq[26]{0};
    char freq1[26]{0};

    bool ok = true; 
    for(size_t i = 0; i < s.length(); i++){
        freq[s[i] - 'A']++;
    }

    for(size_t i = 0; i < t.length(); i++){
        freq[t[i] - 'A']++;
    }

    for(size_t i = 0; i < x.length(); i++){
        freq1[x[i] - 'A']++;
    }

    for(size_t i = 0; i < 26; i++){
        if(freq[i] != freq1[i]){
            ok = false; 
            break;
        }
    }

    if(ok){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}