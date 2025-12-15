#include <bits/stdc++.h>
using namespace std;

//Team 
//https://codeforces.com/problemset/problem/231/A
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k; cin >> k;
    int p,v,t;
    int res = 0;
    for(int i = 0; i < k; i++){
        cin >> p >> v >> t; 
         if(p + v + t > 1){
            res += 1; 
        }
    }

    cout << res; 
    
    return 0;
}