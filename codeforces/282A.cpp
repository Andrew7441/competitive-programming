#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/282/A

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    int res = 0;

    while(t--){
        string a;
        cin >> a;

        for(size_t i =0; i < a.length();i++){
            if(a[i] == '+'){
                res++;
                break;
            }else if(a[i] == '-'){
                res--;
                break;
            }
        }
    }
    cout << res << "\n";


    return 0;
}