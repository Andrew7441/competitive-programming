// Codewars — Playing with digits
// Topic: math | Tags: digits
// Complexity (yours): O(d) time (d digits), O(d) space for the string

#include<iostream>
#include<string>
#include<cmath>
/*
Some numbers have funny properties. For example:

89 --> 8¹ + 9² = 89 * 1
695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2
46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
Given two positive integers n and p, we want to find a positive integer k, if it exists, 
such that the sum of the digits of n raised to consecutive powers starting from p is equal to k * n.

If it is the case we will return k, if not return -1.

Note: n and p will always be strictly positive integers.

Examples:
n = 89; p = 1 ---> 1 since 8¹ + 9² = 89 = 89 * 1

n = 92; p = 1 ---> -1 since there is no k such that 9¹ + 2² equals 92 * k

n = 695; p = 2 ---> 2 since 6² + 9³ + 5⁴= 1390 = 695 * 2

n = 46288; p = 3 ---> 51 since 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
*/
using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p){
  	long long sum = 0;
  	
  	for(auto digit : std::to_string(n)){
  		sum += pow(digit - '0',p++);
	  }
  	return (sum/n)*n==sum ? sum/n : -1;
  }
};


int main(){
	
	DigPow D;
	cout << D.digPow(89,1);
}

/*
💭 First Idea: Sum digit^(p++) over the digits, return sum/n if divisible else -1.
🧩 Key Property / Invariant: k exists iff sum % n == 0.
✅ Key insight: `(sum/n)*n == sum` is just `sum % n == 0`.
🔁 Recognition cue for next time: "digits raised to increasing powers" -> to_string + running exponent.
⏱  Speed fix for next time: std::pow returns double — an integer power loop avoids any rounding risk; use sum % n == 0.
🛠  Review: correct; O(d·log p) — Already optimal (pow-with-double works for the kata's ranges).
*/
