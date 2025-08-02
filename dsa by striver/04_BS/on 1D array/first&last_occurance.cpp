// @link
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// have to find first and last occurance of an element in an sorted array
// bruteforce ->  we can iterate over the entire array to find first and last occ,  O(n) time
// complexity lets use binary search to find first and last occ of a target in an array.
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  int mid;
  int ans = arr.size();
  while (high >= low) {
    mid = (low + high) / 2;
    if (arr[mid] >= target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int upperBound(vector<int> arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  int mid;
  int ans = arr.size();
  while (high >= low) {
    mid = (low + high) / 2;
    if (arr[mid] > target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
  int lb = lowerBound(nums, target);
  int ub = upperBound(nums, target);
  if (lb == ub) {
    return {-1, -1};
  } else {
    return {lb, ub - 1};
  }
}

// time complexity
// for lower bound log base 2 N and same for upper bound