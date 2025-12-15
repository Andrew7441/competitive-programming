#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/2110/B Down with Brackets

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int bal = 0;

        for(size_t i = 1; i < s.length() - 1; i++){
            if(s[i] == '('){
                bal++;
            }else{
                bal--;
            }
            if(bal < 0){
                cout << "YES" << endl;
                break;
            }
        }
        if(bal == 0){
            cout << "NO" << endl;
        }
        

    }

    return 0;
}