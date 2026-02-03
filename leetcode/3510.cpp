#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);

        for(int i = 0; i < n; i++){
            a[i] = nums[i];
        }

        set<pair<long long, int>> min_pair;
        vector<int> next(n);
        vector<int> prev(n);

        for(int i = 0; i < n; i++){
            next[i] = i + 1;
            prev[i] = i - 1;
        }

        int ans = 0;
        int count = 0;

        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i+1]){
                count++;
            }
            min_pair.insert({a[i] + a[i+1], i});
        }

        while(count > 0){
            int curidx = min_pair.begin()->second;
            int nextidx = next[curidx];
            int previdx = prev[curidx];
            int next_nextidx = next[nextidx];

            if(a[curidx] > a[nextidx]){
                count--;
            }

            if(previdx >= 0){
                if(a[previdx] > a[curidx] && 
                   a[previdx] <= a[curidx] + a[nextidx]){
                    count--;
                }else if(a[previdx] <= a[curidx] &&
                         a[previdx] > a[curidx] + a[nextidx]){
                    count++;
                }
            }

            if(next_nextidx < n){   
                if(a[next_nextidx] >= a[nextidx] &&
                    a[next_nextidx] < a[curidx] + a[nextidx]){
                    count++;
                }else if(a[next_nextidx] < a[nextidx] && 
                         a[next_nextidx] >= a[curidx] + a[nextidx]){
                    count--;
                }
            }
            min_pair.erase(min_pair.begin());
            if(previdx >= 0){
                min_pair.erase({a[previdx] + a[curidx], previdx});
                min_pair.insert({a[previdx] + a[curidx] + a[nextidx], previdx});
            }
            if(next_nextidx < n){
                min_pair.erase({a[nextidx] + a[next_nextidx], nextidx});
                min_pair.insert({a[next_nextidx] + a[nextidx] + a[curidx], curidx});
                prev[next_nextidx] = curidx;
            }
            next[curidx] = next_nextidx;
            a[curidx] = a[curidx] + a[nextidx];
            ans++;
        }
        return ans;        
    }
};


int main() {
    vector<int> nums{5,2,3,1};

    Solution S;

    cout << S.minimumPairRemoval(nums);
}


/* 
Think in terms of data structures to optimize behavior/lookups

Part 1 i used Brute Force approach because of the constraints were small

but here the problem with the same approach:
    Scan entire array for min sum 
    shifting all elements after merge
        used .erase method - O(n)
    rechecking the whole array order 
        after merge i have to find minsumPair
    
These problems cause TLE

Solution:

- Use set/minheap because i am finding min. sum. 
Only Adjacent Sum matter 

- Use LinkedList (Stop Shifting Elements)
    Using Doubly LL because im basically shifting elements
    After merging pairs for ex 1 2 3, pairs 1,2 are merged into 3
    i have to check merged pair with the next element so merged into
    3 i have to make sure that merged element at position 1 points to 3
    so next->next-> and 3 should point to 1 so prev->prev->, so now 2 no longer
    exists.
    So take care of prev and next elements so i can be able to erase/shift an element
    
- Keep count (stop checking whole array)
    lets say i keep a count of how many bad pairs are there for ex 3, after shifting/merging
    i dont need to iterate over entire array . for ex array [_ (_ _) _] and i merged the pair
    in parenth. now i get the sum S for the pair and the left and right elements become some number x and y
    now i dont need to check entire array because only the adjacent elements matter. So the new pair 
    would be with S,x and S,y. Only few 3 comparisons matter to check whether array is nondecreasing or not

    cur and next are basically getting merged , becoming a single entity so i then compare it with prev element
    and next->next->val

    After making pairs with prev and next next is i have to count whether after merging i have an 
    increment in the bad pair or i have some decrement in the bad pair or the bad pairs remain same. 
    SO i dont need to iterate over entire array. Just comparisons with the neighbor will give us the hint

    So with the help of count variable i will keep track of how many bad pairs are there with us. When
    bad pairs become 0 i would stop iteration and return answer. 

    I just need to apply the operation like how the question says. Whatever answer i get after the bad pairs
    is zero i will get the minimum only. 
       
        idx  0  1  2  3  4
    EX run [10, 6, 5, 3, 7]
                            Bad Pairs:
                            (10, 6)
                            (6, 5)
                            (5, 3)
    Linked list
    prev = [-1, 0, 1, 2, 3]  
    next = [1, 2, 3, 4, 5]

    set[(8,2),(10,3), (11, 1), (16,0)]

    first of all, i need to count how many bad pairs exist. Because i need to make bad pairs = 0, 
    so compare adjacent pairs. 10,6 are non decreasing so ++, same with the others
    bad Pairs = 3 i need to make 0.
    Now while applying operations bad pairs can increase or decrease but overall i need to make it 0.


    how to do that? use DLL, i will not be creating a DLL but i will maintain 2 arrays:
    
    prev = [-1, 0, 1, 2, 3]  
    next = [1, 2, 3, 4, 5]
    these will act as a doubly linked list. I will maintain these arrays which will tell me for a particular
    number which is its prev or next 

    in simulation it would look like im iterating over DLL but ill actually be using these arrays.
    prev element of index 0 is -1, next element its prev is 0, so on... same for next array 
    will also keep check of -1, 5 because they dont exist in array. I will check whether 
    prev >= 0 and next < n 

    now in my operation i need to find the minimum  pair sum and need to do the operation of merging
    and shifting and so on..

    will keep track in a set, for ex (8,2) first is the sum, second is the index of the starting pair
    because next element will get removed. 

    set is ordered set so i will be getting it always sorted. if sum is tied then sort will go to the idx.

    Applying the operations
    0->1->2->3->4
     <- <- <- <-
    
    2 is curr idx with value 5
    3 is next idx with value 3
    1 is the prev index of 2 with value 6
    4 is next next idx of 3 with value 7
    
    a[currindex] > a[nextindex]
          5             3     -> bad pair , now merge bad pair becomes single element 8 so
    
    count--. now check with prev element and next element

    
    0->1->2->3->4
     <- <- <- <-
    
    1 with value 6

    2 with value 5
    3 with value 3

    idx 2 3 become 8

    6 > 8 X (not bad anymore)

    a[previdx] < a[curridx] && a[previdx] <= a[curidx] + a[nextidx]{
        count--
    }

    a[previdx] < a[curridx] -> case before merging for bad pairs

    a[previdx] <= a[curidx] + a[nextidx] -> after merging 6 <= 8


    next element is 7 at index 4

    0->1->2->3->4
     <- <- <- <-
    
    3 < 7 -> case before merging = not bad
    after merge curidx + next idx
    8 > 7 = bad = count++


    if(a[next_nextidx] >= a[nextidx] && a[next_next_idx] < a[curidx] + a[next_idx]){
        count++
    }

    next->next = 7
    7 >= 3 , so yes
    &&
    7 < 5 + 3 = 8 , count++

    i have taken the sum only, now MERGE 

    0->1->2->3->4
     <- <- <- <-

    set[(8,2),(10,3), (11, 1), (16,0)]
    
    now remove 8,2 from the set because 8 is the new pair,

    remove 2,3 indices from array

    so if i merge into 8, it will affect prev entity

    0->1->2->3->4
     <- <- <- <-

    1<->2 will change

    erase prev idx 1 pair from set 
    insert new one for previdx

    set.insert({a[previdx] + a[curidx] + a[nextidx], previdx})

*/