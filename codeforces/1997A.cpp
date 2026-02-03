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

        int idx = -1;

        for(int i = 0; i < (int)s.length()-1; i++){
            if(s[i] == s[i+1]){
                idx = i;
            }
        }

        if(idx == -1){
            if(s.back() == 'a'){
                s += "b";
            }else{
                s += "a";
            }
            cout << s << "\n";
        }else{
            string t = "a";
            if(s[idx] == 'a') t = "b";
            cout << s.substr(0, idx + 1) + t + s.substr(idx+1) << "\n";
        }

    }

    return 0;
}