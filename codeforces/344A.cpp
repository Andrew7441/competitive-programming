#include <iostream>
#include<string>
using namespace std;

//https://codeforces.com/problemset/problem/344/A magnets

int main() {

    int n;
    cin >> n; 

    int g = 1; 

    string prev, curr; 

    cin >> prev; 


    for(int i = 1; i < n; i++){
        cin >> curr; 
        if(prev!=curr){
            g++;
        }
        prev = curr; 
    }
    cout << g; 

    return 0;
}