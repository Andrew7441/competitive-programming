#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1926/A A. Vlad and the Best of Five

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int a=0,b=0;
        string s;
        cin >> s;

        for(char i: s){
            if(i == 'A'){
                a++;
            }else{
                b++;
            }
        }
        if(a > b){
            cout << "A\n";
        }else{
            cout << "B\n";
        }
    }

    return 0;
}