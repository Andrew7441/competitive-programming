#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/118/A String task

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    cin >> s;

    for(char &c:s){
        c = tolower(c);
    }

    string res = s;

    res.erase(remove_if(res.begin(),res.end(), [](char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';}),
        res.end());

    string out;
    for(char i: res){
        out.push_back('.');
        out.push_back(i);
    }
    

    cout << out;

    return 0;
}