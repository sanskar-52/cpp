// NEXT SMALLER ELEMENT

// You are given an array of integers arr of size n.
// For each element in the array, find the next smaller element to its right.

// The next smaller element for an element arr[i] is defined as the first element to the right of index i that is strictly smaller than arr[i].

// If no such element exists, output -1 for that position.

// arr = [ 4, 8, 5, 2, 25 ] ans = [ 2, 5, 2, -1, -1 ]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextSmallerElements(vector<int> &nums)
  {
    stack<int> st;
    int n = nums.size();
    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() >= nums[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        res[i] = -1;
      }
      else
      {
        res[i] = st.top();
      }
      st.push(nums[i]);
    }

    return res;
  }
};

// Aspect Complexity
// Time O(n)
// Space O(n)

// Next Smaller Index to the RIGHT (NSR – index)  returns index of next smaller element

class Solution
{
public:
  vector<int> nextSmallerElements(vector<int> nums)
  {
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && nums[st.top()] >= nums[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        res[i] = -1;
      }
      else
      {
        res[i] = st.top();
      }
      st.push(i);
    }
    return res;
  }
};