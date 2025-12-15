#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/677/A Vanya and Fence

int main() {
    

    int n , h; 
    cin >> n >> h;


    int res = 0; 

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        res += a>h ? 2 : 1;
    }

    cout << res; 

    return 0;
}