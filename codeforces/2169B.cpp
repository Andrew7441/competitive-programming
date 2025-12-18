#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        std::string s;
        cin >> s;

        bool inf = false; 

        for(int i = 0; i < (int)s.length() - 1; i++){
            if(s[i] != '<' && s[i+1] != '>'){
                cout << -1 << '\n';
                inf = true;
                break;
            }
        }

        if(!inf){
            int cntL = 0, cntR = 0;
            for(char c : s){
                if(c == '<') cntL++;
                else if(c == '>') cntR++;
            }
            cout << s.size() - min(cntL,cntR) << '\n';
        }

        

    }


    return 0;
}