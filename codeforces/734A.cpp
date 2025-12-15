#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/734/A Anton and Danik

int main() {


    int n; cin >> n;
    string s; cin >> s;

    int a=0,b=0;

    for(size_t i = 0; i < s.length();i++){
        if(s[i] == 'A'){
            a++;
        }else{
            b++;
        } 
    }
    if(a > b){
        cout << "Anton";
    }else if(a < b){
        cout << "Danik";
    }else{
        cout << "Friendship";
    }

    return 0;
}