#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/703/A Mishka and Game

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int r1=0,r2=0;

    while(t--){
        int m,c;
        cin >> m >> c;

        if(m > c){
            r1++;
        }else if(m < c){
            r2++;
        }
    
    }
    if(r1 > r2){
        cout << "Mishka" << endl;
    }else if(r1 < r2){
        cout << "Chris" << endl;
    }else{
        cout << "Friendship is magic!^^" << endl;
    }

    return 0;
}