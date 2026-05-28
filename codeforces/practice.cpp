#include <bits/stdc++.h>
using namespace std;



///////////////////////////////////////////////////////////////////////////////////////////////////
/*
Given a positive integer, return the
sum of its digits. Input:  1234


int solve(int n){
    string s = to_string(n);
    int sum = 0;

    for(char& c : s){
        sum += c - '0';
    }

    return sum;
}

int main(){

    cout << solve(1234);

    return 0;
}

*/
///////////////////////////////////////////////////////////////////////////////////////////////////
/*
Write a function that capitalizes the first letter of every word in a string
 without using built-in title-case methods. Input:  "hello world from python"


string solve(string& s){
    bool newWord = true;

    for(char& c : s){
        if(newWord){
            c = toupper(c);
            newWord = false;
        }

        if(c == ' ') newWord = true;
    }

    return s;
}

int main(){
    string s = "hello world from python";

    cout << solve(s);
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
Write a function that calculates base raised to the power of exp without using ** or built-in power functions. 
Assume exp is a non-negative integer. Input:  base = 2, exp = 10

int solve(int base, int exp){
    int ans = 1;

    for(int i = 1; i <= exp; i++){
        ans *= base;
    }

    return ans;
}


int main(){

    cout << solve(2, 3);

    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
Binary Search

Write a function that implements binary search on a sorted array. Return the index of the target, or -1 if not found.
Example: binary_search([1, 3, 5, 7, 9], 5) → 2


int BinarySearch(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1;

    while(l < r){
        int mid = (l + r) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    return -1;
}

int main(){

    vector<int> v{1, 3, 5, 7, 9};
    cout << BinarySearch(v, 10);

    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
Check if a Number is Prime

Write a function that returns true if a given number is prime, false otherwise.
Example: is_prime(7) → true, is_prime(12) → false


bool is_prime(int x){
    if(x < 2) return false;

    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }

    return true;
}


int main(){
    cout << boolalpha;
    cout << is_prime(31);

    return 0;
}

*/

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
Fibonacci (nth Number)

Write a function that returns the nth Fibonacci number. The sequence starts: 0, 1, 1, 2, 3, 5, 8, 13, ...
Example: fibonacci(6) → 8 (0-indexed: F(0)=0, F(1)=1, ..., F(6)=8)


//Naive recursion - O(2^n) tc
int RFib(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    return RFib(n - 1) + RFib(n - 2);
}

//memoized recursion - O(n) tc, O(n) sc
int MFib(int n, vector<int>& memo){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    if(memo[n] != -1) return memo[n];

    memo[n] = MFib(n-1, memo) + MFib(n-2, memo);

    return memo[n];
}


//Iterative - O(n) tc , O(1) sc
int Ifib(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    int num1 = 0, num2 = 1;

    for(int i = 2; i <= n; i++){
        int cur = num1 + num2;
        num1 = num2;
        num2 = cur;
    }

    return num2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << Ifib(6);
    cout << RFib(6);

    vector<int> memo(6, -1);

    return 0;
}
*/