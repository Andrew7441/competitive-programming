// LeetCode 1195 — Fizz Buzz Multithreaded
// https://leetcode.com/problems/fizz-buzz-multithreaded/
// Topic: design | Tags: concurrency, mutex, condition-variable
// Complexity (yours): O(n) total time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class FizzBuzz {
private:
    int n;
    int i = 1;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){
                return i > n || (i % 3 == 0 && i % 5 != 0);
            });

            if(i > n) return;

            printFizz();

            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){
                return i > n || (i % 5 == 0 && i % 3 != 0);
            });

            if(i > n) return;

            printBuzz();

            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){
                return i > n || (i % 3 == 0 && i % 5 == 0);
            });

            if(i > n) return;
            
            printFizzBuzz();
            
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){
                return i > n || (i % 3 != 0 && i % 5 != 0);
            });

            if(i > n) return;

            printNumber(i);

            i++;
            cv.notify_all();
        }
    }
};

int main() {
    FizzBuzz Sol(15);

    auto printFizz = [](){ cout << "Fizz "; };
    auto printBuzz = [](){ cout << "Buzz "; };
    auto printFizzBuzz = [](){ cout << "FizzBuzz "; };
    auto printNumber = [](int x){ cout << x << " "; };

    thread t1(&FizzBuzz::fizz, &Sol, printFizz);
    thread t2(&FizzBuzz::buzz, &Sol, printBuzz);
    thread t3(&FizzBuzz::fizzbuzz, &Sol, printFizzBuzz);
    thread t4(&FizzBuzz::number, &Sol, printNumber);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    
}

/*
💭 First Idea: One mutex + condition_variable; each thread waits until the shared i matches its rule (or i > n), prints, increments, notify_all.
🧩 Key Property / Invariant: Only the thread whose predicate matches i may proceed; i > n wakes everyone so they can exit.
✅ Key insight: The wait predicate must include the termination condition or threads block forever.
🔁 Recognition cue for next time: "Threads must take turns in a fixed order" → mutex + condition_variable over a shared counter.
⏱  Speed fix for next time: notify_all (not notify_one) is required because 4 different predicates share one cv.
🛠  Review: correct; O(n) — Already optimal.
*/
