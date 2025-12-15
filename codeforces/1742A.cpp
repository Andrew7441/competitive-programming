#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/1742/A Sum


int main() {

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a + b == c || a + c == b || b + c == a || b + a == c || c + a == b || c + b == a){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }



    return 0;
}