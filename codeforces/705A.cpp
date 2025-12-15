#include <iostream>
#include <string> 
using namespace std;
//https://codeforces.com/problemset/problem/705/A Hulk

int main() {

    int n; 
    cin >> n;
    string s; 

    for(int i = 1; i <= n; i++){
        if(i%2==1){
            cout << "I hate";
        }else{
            cout << "I love";
        }

        if(i==n){
            cout << " it";
        }else{
            cout <<  " that ";
        }
    }
 
    return 0;
}