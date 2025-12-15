#include <iostream>
#include<string>
using namespace std;

//https://codeforces.com/problemset/problem/61/A Ultra-Fast Mathematician

int main() {

    string s, n;
    cin >> s >> n;

    string res = "";

    for(size_t i = 0; i < s.length(); i++){
        if((s[i] == '1' && n[i] == '0') || (s[i] == '0' && n[i] == '1') ){
            res+= "1";
        }else{
            res += "0";
        }
    }

    cout << res; 

    return 0;
}