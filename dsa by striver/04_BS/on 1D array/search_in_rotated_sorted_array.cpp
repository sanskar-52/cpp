//all nums in array is unique

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int n, int target) {
  int low = 0;
  int high = n - 1;
  int mid;
  while(low <= high) {
    mid = (low + high)/2;
    if(nums[mid] == target) return mid;
    //if left part is sorted.
    if(nums[low] <= nums[mid]) {
      if(nums[low] == target) return low;
      else if(target > nums[low] && target < nums[mid]) {
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }
    //if the right part is sorted.
    else {
      if(nums[high] == target) return high;
      else if(target > nums[mid] && target < nums[high]){
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
  }

  return -1;


}