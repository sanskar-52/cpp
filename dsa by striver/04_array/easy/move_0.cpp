//move 0's of array to the back without preserving the order.
//move_02.cpp -> moves 0's of array to the back with preserving the order.

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums){
    int size = nums.size();
    int j = size -1;
    for(int i =0;i < size;i++){
        while (j > i && nums[j] == 0){
            j--;
        }
        if(nums[i] == 0){
            swap(nums[i],nums[j]);
            j--;
        }
        if(i>=j){
            return;
        }
    }    
}

int main(){
    vector<int> num = {1,0,23,12,0,51,0,354,56,5,0,6456,0,23,1,341,0,363,7,56,0,69,5,7,0,677,85364,0};
    moveZeroes(num);
    for(int x:num){
        cout << x << endl;
    }
}
// conclusion
// ✅ Optimized Aspects:
// Time Complexity: O(n)
// Space Complexity: O(1)
// Works in-place, using only two pointers (i and j)
// Efficient for scenarios where preserving order doesn’t matter

// ❌ Drawback:
// Order of non-zero elements may change.
// Example:
// Input → [0, 1, 2, 0, 3]
// Output (your code) → [3, 2, 1, 0, 0] or similar
// But expected (order-preserving) → [1, 2, 3, 0, 0]