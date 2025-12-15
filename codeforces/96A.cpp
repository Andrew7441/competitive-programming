#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/96/A Football


int main() {

    string s; 
    cin >> s;


    int count = 1; 
    for(size_t i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]){
            count++;
            if(count == 7){
                cout << "YES";
                return 0;
            }
        }else{
            count = 1;
        }
    }
    cout << "NO";
    return 0;
}