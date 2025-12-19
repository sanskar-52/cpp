// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

#include <bits/stdc++.h>
using namespace std;

// first we have to find rmax and lmax for each i in height[i] then we can simply,
// find the water stored at each ith index by min(rmax,lmax) - height[i].
// we can find lmax as we traverse along the arr to find captured water by keeping track of lmax;
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();
    vector<int> rmax(n);
    rmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      rmax[i] = max(height[i], rmax[i + 1]);
    }

    int total = 0;

    int lmax = height[0];

    for (int i = 0; i < n; i++)
    {
      lmax = max(height[i], lmax);

      total += min(rmax[i], lmax) - height[i];
    }
    return total;
  }
};