#include <iostream>
#include <string> 

using namespace std;

//https://codeforces.com/problemset/problem/110/A Nearly Lucky Number

int main() {

    string s;
    cin >> s; 

    int c = 0; 

    for(size_t i = 0; i < s.length();i++){
        if(s[i] == '4' or s[i] == '7'){
            c++;
        }
    }   

    if(c == 4 or c == 7){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}