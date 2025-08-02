// so when we searched a target in rotated array of unique elements we can determine whether the
// left half or the right half is sorted by checking the low , mid and high elements.
// arr[low] <= arr[mid]  and    arr[mid] <= arr[high]
// but in a rotated array which includes duplicates we can not find the sorted half by checking low,
// mid and high. bcz of duplicates low , mid and high could be the same

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// new edge case is low == mid == high sooo...

bool searchinRotated(vector<int> arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == target) return true;
    if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
      low = low + 1;
      high = high - 1;
      continue;
    }
    // ab ya to left half ya to right half me se koi ek hi sorted hoga.
    // left half sorted
    else if (arr[low] <= arr[mid]) {
      if (target >= arr[low] && target <= arr[mid]) {
        return true;
      } else {
        low = mid + 1;
      }
    }

    // right half sorted
    else {
      if (arr[mid] <= target && target <= arr[high])
        return true;
      else {
        high = mid - 1;
      }
    }
  }
  return false;
}
