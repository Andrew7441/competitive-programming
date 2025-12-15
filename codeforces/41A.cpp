#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

//https://codeforces.com/problemset/problem/41/A Translation

int main() {

    
    string s, t; 
    cin >> s >> t;

    bool isequal = true; 

    for(size_t i = 0; i < s.length();i++){
        if(s[i] != t[t.length()-1-i] || s.length() != t.length()){
            isequal = false;
            break;
        }
    }

    

    if(isequal){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}



/*
int main() {

    
    string s, t; 
    cin >> s >> t;

    std::reverse(t.begin(), t.end());

    if(s==t){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
*/