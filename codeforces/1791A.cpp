#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1791/A . Codeforces Checking

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        char a;
        cin >> a;
        unordered_set<char> n{'c', 'o', 'd', 'e', 'f', 'r', 's'};

        if(n.count(a)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}

/* another way
string s = "codeforces";
if (s.find(c) != string::npos)
    cout << "YES\n";
else
    cout << "NO\n";
*/