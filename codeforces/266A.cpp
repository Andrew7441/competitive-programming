#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/266/A Stones on the Table

int main() {

    int n;
    string s; 
    cin >> n >> s; 
    
    int res = 0; 

    for(int i = 0; i < n; i++){
        if(s[i] == s[i+1]){
            res++;
        }
    }
    
    cout << res; 

 
    return 0;
}