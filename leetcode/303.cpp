#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> numbers; 

    NumArray(vector<int>& nums) : numbers{nums} {
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        while(left <= right){
            sum += numbers[left++];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums{-2, 0, 3, -5, 2, -1};

    NumArray* array = new NumArray(nums);

    vector<int> res; 
    
    int p1 = array->sumRange(0,2);
    int p2 = array->sumRange(2,5);
    int p3 = array->sumRange(0,5);
    
    res.push_back(p1);
    res.push_back(p2);
    res.push_back(p3);

    cout << "[ ";
    for(int i : res){
        cout << i << ", ";
    }
    cout << "]";


    
}