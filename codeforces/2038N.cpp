#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n1 = s[0] - '0';
    char e = s[1];
    int n2 = s[2] - '0';

    string res = "";

    if(e == '<'){
        if(n1 < n2){
            res = to_string(n1) + e + to_string(n2);
        }else if(n1 > n2){
            res = to_string(n1) + '>' + to_string(n2);
        }else{
            res = to_string(n1) + '=' + to_string(n2);
        }
    }else if(e == '>'){
        if(n1 > n2){
            res = to_string(n1) + e + to_string(n2);
        }else if(n1 == n2){
            res = to_string(n1) + '=' + to_string(n2);
        }else{
            res = to_string(n1) + '<' + to_string(n2);
        }
    }else if(e == '='){
        if(n1 == n2){
            res = to_string(n1) + e + to_string(n2);
        }else if(n1 > n2){
            res = to_string(n1) + '>' + to_string(n2);
        }else{
            res = to_string(n1) + '<' + to_string(n2);
        }
    }
    cout << res << "\n";
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