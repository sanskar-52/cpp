// 1011. Capacity To Ship Packages Within D Days
// A conveyor belt has packages that must be shipped from one port to another
//     within days days
//         .

//     The ith package on the conveyor belt has a weight of weights[i]
//         .Each day,
//     we load the ship with packages on the conveyor
//     belt(in the order given by weights)
//         .We may not load more weight than the maximum weight capacity of the
//     ship.

//     Return the least weight capacity of the ship that will result in all the
//     packages on the conveyor belt being shipped within days days.

#include <bits/stdc++.h>
using namespace std;

// bruteforce approch  //TC n square
int findDays(vector<int> &weights, int cap) {
  int load = 0;
  int day = 1;
  int n = weights.size();
  for (int i = 0; i < n; i++) {
    if (load + weights[i] > cap) {
      day = day + 1;
      load = weights[i];
    } else {
      load = load + weights[i];
    }
  }
  return day;
}

int leastWeightCapacity(vector<int> &weights, int days) {

  int max = *max_element(weights.begin(), weights.end());  // O(n)
  int sum = accumulate(weights.begin(), weights.end(), 0); // O(n)

  for (int i = max; i <= sum; i++) {
    if (findDays(weights, i) <= days) {
      return i;
    }
  }
  return -1;
}

// now using BS on answers

int leastWeightCapacity(vector<int> &weights, int days) {

  int low = *max_element(weights.begin(), weights.end());   // O(n)
  int high = accumulate(weights.begin(), weights.end(), 0); // O(n)

  while (low <= high) {
    int mid = (low + high) / 2;
    if (findDays(weights, mid) <= days) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}