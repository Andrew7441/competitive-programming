#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s; 
        cin >> s;

        bool con = false; 
        for(int i = 2; i < n; i++){
            if(s[i - 2] == '.' && s[i] == '.' && s[i-1] == '.'){
                con = true;
                break;
            }
        }

        if(con){
            cout << 2 << "\n";
            continue;
        }

        int c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '.'){
                c++;
            }
        }
        cout << c << "\n";

    }

    return 0;
}