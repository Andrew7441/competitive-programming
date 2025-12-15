#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/977/A Wrong Subtraction

int main() {
    
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        if(n % 10 == 0){
            n/=10;
        }else{
            n--;
        }
    }
    
    cout << n; 
 
    return 0;
}