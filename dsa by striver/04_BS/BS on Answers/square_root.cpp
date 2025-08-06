// we have to find the square root of given number n
// so the square root of n must lie in the range between 1 to n

#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int SquareRoot(int n) {
  int low = 1;
  int high = n;
  int ans;
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long val = mid * mid;

    if (val <= n) {
      ans = val;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  // return ans or high
  return high;
}