//move_02.cpp -> moves 0's of array to the back with preserving the order.
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j =0;
    while(j < n && nums[j]!=0){
        j++;
    }
    for(int i=1;i<n;i++){
        if(nums[i]!= 0 && i>j){
            swap(nums[i],nums[j]);
            j++;
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