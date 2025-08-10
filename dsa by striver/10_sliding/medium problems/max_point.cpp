// There are several cards arranged in a row,
//     and each card has an associated number of
//             points.The points are given in the integer array cardPoints.

//         In one step,
//     you can take one card from the beginning or
//         from the end of the row.You have to take exactly k cards
//             .

//         Your score is the sum of the points of the cards you have taken.

//         Given the integer array cardPoints and the integer k,
//     return the maximum score you can obtain.

#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &nums, int k) {
  int maxsum = 0;
  int lsum = 0;
  int rsum = 0;
  for (int i = 0; i < k; i++) {
    lsum += nums[i];
  }
  maxsum = lsum;
  int rindex = nums.size() - 1;
  for (int i = k - 1; i >= 0; i--) {
    lsum -= nums[i];
    rsum += nums[rindex];
    rindex--;
    maxsum = max(maxsum, lsum + rsum);
  }
  return maxsum;
}