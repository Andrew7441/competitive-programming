#include <bits/stdc++.h>
using namespace std;

/**/

bool matches(const vector<int>& a, string s){
    if((int)a.size() != (int)s.size()) return false;

    unordered_map<int,char> numToChar;
    unordered_map<char,int> charToNum;

    for(int i = 0; i < (int)a.size(); i++){
        int num = a[i]; // 3
        int ch = s[i]; // a

        if(numToChar.count(num) && numToChar[num] != ch) return false;
        if(charToNum.count(ch) && charToNum[ch] != num) return false;

        numToChar[num] = ch;
        charToNum[ch] = num;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;

    vector<int>a(n);
    for(int& i: a) cin >> i;

    int m;
    cin >> m;
    
    while(m--){
        string s;
        cin >> s;

        if(matches(a, s)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
} 