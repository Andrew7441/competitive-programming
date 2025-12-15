#include <iostream>
#include<string>
using namespace std;

//https://codeforces.com/problemset/problem/281/A Word Capitalization

int main() {

    string s; 
    cin >> s; 

    s[0] = toupper(s[0]);

    cout << s;

    return 0;
}