#include <bits/stdc++.h>

class Solution {
public:
  int validK(std::vector<int>& piles, int k, int h) {
    long long hours = 0;
    for (int bananas : piles) {
      hours += (bananas + k - 1) / k;
    }
    if (hours <= h) {
      return k;
    } else {
      return INT_MAX;
    }
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int minK = INT_MAX;
    while (low <= high) {
      int mid = (low + high) / 2;
      int speed_of_mid = validK(piles, mid, h);
      if (speed_of_mid == INT_MAX) {
        low = mid + 1;
      } else {
        minK = min(minK, speed_of_mid);
        high = mid - 1;
      }
    }
    return minK;
  }
};
