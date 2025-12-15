#include <iostream>
#include <string>
using namespace std;

//https://codeforces.com/problemset/problem/1676/A Lucky?

int main() {

    int t; 
    cin >> t; 

    for(int i = 0; i < t; i++){
        string s; cin >> s; 
        int res1=0;
        int res2=0; 

        for(size_t i = 0; i < s.length()/2;i++){
            res1 += s[i] - '0';
        }
        for(size_t i = s.length()/2; i < s.length(); i++){
            res2 += s[i] - '0';
        }

        if(res1 == res2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}