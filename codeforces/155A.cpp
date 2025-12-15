#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/155/A I_love_%username%

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     int t;
     cin >> t;

     vector<int> con(t);

     for(int i = 0; i < t; i++){
        cin >> con[i];
     }

     int best = con[0], worst = con[0];
     int res = 0;

     for(size_t i = 1; i < con.size();i++){
        if(con[i] < worst){
            worst = con[i];
            res++;
        }else if(con[i] > best){
            best = con[i];
            res++;
        }
     }

     cout << res;


    return 0;
}