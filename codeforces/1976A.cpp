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

       bool ok = true;

       for(int i = 0; i < n - 1; i++){
        if(isdigit(s[i]) && isdigit(s[i+1])){
            if((s[i] - '0') > (s[i+1] - '0')){
                ok = false;
                break;
            }
        }else if(isalpha(s[i]) && isalpha(s[i+1])){
            if(s[i] > s[i+1]){
                ok = false;
                break;
            }
       }else if(isalpha(s[i]) && isdigit(s[i+1])){
        ok = false;
        break;
       }
       }   
       if(ok) cout << "YES\n";
       else cout << "NO\n";
    }
    

    return 0;
}