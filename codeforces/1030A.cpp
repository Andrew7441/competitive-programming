#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/1030/A In Search of an Easy Problem

int main() {
    
    int n; 
    cin >> n;

    for(int i =0; i < n; i++){
        int a; 
        cin >> a; 
        if(a == 1){
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
    return 0;
}