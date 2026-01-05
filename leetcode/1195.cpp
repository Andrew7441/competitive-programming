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