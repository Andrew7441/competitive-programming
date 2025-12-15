#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        
        map<char,int> freq1;
        map<char,int> freq2;

        for(int i = 0; i < n; i++){
            freq1[s[i]]++;
        }

        for(int i = 0; i < n; i++){
            freq2[t[i]]++;
        }

        if(freq1 == freq2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}