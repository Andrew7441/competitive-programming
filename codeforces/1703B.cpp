#include <bits/stdc++.h>
#include <set>
using namespace std;

//https://codeforces.com/problemset/problem/1703/B ICPC Balloons

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;

        unordered_set<char> s;
        int res = 0;

        for(int i = 0; i < n; i++){
            if(!s.count(str[i])){
                res+=2;
                s.insert(str[i]);
            }else{
                res++;
            }
        }
        cout << res << endl; 
    }



    return 0;
}
// proud of myself for this one here
