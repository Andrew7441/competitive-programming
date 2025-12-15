#include <bits/stdc++.h>
#include <set>
using namespace std;
//https://codeforces.com/problemset/problem/1722/A Spell Check 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t; 
    cin >> t; 

    while(t--){
        size_t n;
        cin >> n;

        string s;
        cin >> s;

        size_t len = s.size();

        if(len != n){
            cout << "NO" << endl;
            continue;
        }

        const string target = "Timru";

        sort(s.begin(),s.end());

        if(s == target){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}