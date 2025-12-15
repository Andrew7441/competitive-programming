#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1367/B Even Array
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int wrongodd = 0;
        int wrongeven = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % 2 != i % 2){
                if(i % 2 ==0){
                    wrongeven++;
                }else{
                    wrongodd++;
                }   
            }
        }
        if(wrongeven != wrongodd){
            cout << -1 << "\n";
        }else{
            cout << wrongeven << "\n";
        }
    }

    return 0;
}