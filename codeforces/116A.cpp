#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/116/A Tram

int main() {

    int n; 
    cin >> n; 

    int res = 0; 
    int min = 0; 

    for(int i = 0; i < n; i++){
        int a, b; 
        cin >> a >> b; 
        res -= a; 
        res += b; 
        if(min < res){
            min = res;
        }
    }
    cout << min; 

    return 0;
}