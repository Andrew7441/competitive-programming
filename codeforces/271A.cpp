
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/271/A A. Beautiful Year


int main() {

    int y;
    cin >> y;

    
    while(true){
        y++;
        int temp = y;
        unordered_set<int> r;
        
        while(temp>0){
            r.insert(temp%10);
            temp/=10;
        }
        
        if(r.size()==4){
            cout << y;
            break;
        }
    }

    return 0;
}