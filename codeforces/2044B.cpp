#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        reverse(s.begin(), s.end());
                
        for(char& c: s){
            if(c == 'q') c = 'p';
            else if(c == 'p') c = 'q';
        }
        cout << s << "\n";
    }

    return 0;
}