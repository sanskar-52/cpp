//we will find the lowest indexed element in the arr which is equal to or greater than the target.
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int lower_Bound(vector<int> &arr, int target){
  int low = 0;
  int high = arr.size() - 1;
  int mid;
  int ans = arr.size();
  while(high >= low) {
    mid = (low + high)/2;

    if(arr[mid] >= target) {
      ans = mid;
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return ans;
}

// You should definitely use STL for:
// Binary search in coding exams:

// lower_bound(arr.begin(), arr.end(), target)

// upper_bound(arr.begin(), arr.end(), target)