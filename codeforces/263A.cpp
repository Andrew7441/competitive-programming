#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/263/A Beautiful Matrix

int main() {

    int x=0, y=0, a; 

    for(int i = 1; i<=5;i++){
        for(int j = 1; j <= 5; j++){
            cin >> a;
            if(a == 1){
                x = i; 
                y = j;
            }
        }
    }
    cout << abs(x-3) + abs(y-3);

    return 0;
}