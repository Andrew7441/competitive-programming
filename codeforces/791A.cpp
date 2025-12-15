#include <iostream>
using namespace std;

// https://codeforces.com/problemset/problem/791/A Bear and Big Brother

int main() {

    int a, b; 
    cin >> a >> b;

    int res = 0; 

    while(a <= b){ 
        a *= 3;    
        b *= 2;    
        res++;    
    }

    cout << res; 
 
    return 0;
}