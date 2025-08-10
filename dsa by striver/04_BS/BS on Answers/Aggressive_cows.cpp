// Problem Statement: You are given an array 'arr' of size 'n' which denotes the
// position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive
//     cows.You are given the task of assigning stalls to 'k' cows such that the
//         minimum distance between any two of them is the maximum
//             possible.Find the maximum possible minimum distance.

#include <bits/stdc++.h>
using namespace std;

// brute force

bool possDist(vector<int> &stalls, int k, int dist) {
  int last = 0;
  k--;
  int n = stalls.size();
  for (int i = 1; i < n; i++) {
    if (stalls[i] - stalls[last] >= dist) {
      k--;
      last = i;
    } else {
      continue;
    }

    if (k < 1) {
      return true;
    }
  }
  return false;
}

int max_min_dist(vector<int> &stalls, int k) {
  // the cordinates of stalls are not sorted, so first we will sort the stalls
  sort(stalls.begin(), stalls.end());
  // now we have to find the range for min distance
  // so logically min distance b/w two aggressive can be 1 and max distance can
  // be stalls.end - stalls.begin if there are only two aggressive cows.
  int max = stalls.back() - stalls.front();
  for (int i = 1; i <= max; i++) {
    if (possDist(stalls, k, i)) {
      continue;
    } else {
      return (i - 1);
    }
  }
}

// now implementing BS on answers

int max_min_dist(vector<int> &stalls, int k) {
  sort(stalls.begin(), stalls.end());
  int high = stalls.back() - stalls.front();
  int low = 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (possDist(stalls, k, mid)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high;
}