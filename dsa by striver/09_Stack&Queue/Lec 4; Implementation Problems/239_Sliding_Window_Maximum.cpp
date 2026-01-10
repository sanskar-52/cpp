// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.
// Each time the sliding window moves right by one position.
// Return the max sliding window.

// first we will solve by checking each and every window from the start to the last valid window

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> result(n - k + 1);

    for (int i = 0; i <= n - k; i++)
    {
      int maxOfCrr = nums[i];
      for (int j = i; j < i + k; j++)
      {
        maxOfCrr = max(maxOfCrr, nums[j]);
      }
      result[i] = maxOfCrr;
    }

    return result;
  }
};

// Time Complexity : O(n *k) Each of the(n - k + 1) windows is scanned completely to find its maximum.In worst - case, each window of size k requires O(k) operations.

// Space Complexity: O(1) We are only using output list which does not count as extra space in space complexity analysis.No additional data structures used.

// now we will use a decreasing DEqueue for each window to find the maximum for each window
// and that will be front of DEqueue for each window

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
      if (!dq.empty() && dq.front() < i - k + 1)
      {
        dq.pop_front();
      }

      while (!dq.empty() && dq.back() <= nums[i])
      {
        dq.pop_back();
      }

      dq.push_back(i);

      if (i >= k - 1)
      {
        result.push_back(nums[dq.front()]);
      }
    }
    return result;
  }
};

// Time Complexity: O(n) Each element is pushed and popped from the deque at most once, so overall traversal is linear.

// Space Complexity: O(k) Deque stores at most k elements at any time, one for each index in the window.