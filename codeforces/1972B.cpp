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
        
        int res = 0;
        for(size_t i = 0; i < s.length(); i++){
            if(s[i] == 'U'){
                res++;
            }
        }
        if(res % 2 == 0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }


    return 0;
}