#include <bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int> arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  int mid;
  int ans = -1;
  while (high >= low) {
    mid = (low + high) / 2;
    if (arr[mid] == target) {
      ans = mid;
      high = mid - 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int lastOccurance(vector<int> arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  int mid;
  int ans = -1;
  while (high >= low) {
    mid = (low + high) / 2;
    if (arr[mid] == target) {
      ans = mid;
      low = mid + 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

pair<int, int> first_lastOccurance(vector<int> arr, int target) {
  int first = firstOccurance(arr, target);
  if (first == -1) return {-1, -1};

  int last = lastOccurance(arr, target);
  return {first, last};
}