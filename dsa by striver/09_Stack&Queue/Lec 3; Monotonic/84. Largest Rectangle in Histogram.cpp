// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include <bits/stdc++.h>
using namespace std;

// first solving it using pse, nse at each i'th index to find the length of each i'th rectangle.
// then finding the max area.
class Solution
{
private:
  vector<int> findNSE(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; n >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
        st.pop();
      }
      ans[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    return ans;
  }

  vector<int> findPSE(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
        st.pop();
      }

      ans[i] = st.empty() ? -1 : st.top();

      st.push(i);
    }

    return ans;
  }

public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    vector<int> nse = findNSE(heights);
    vector<int> pse = findPSE(heights);

    int largestArea = 0;
    for (int i = 0; i < n; i++)
    {
      int val = (nse[i] - pse[i] - 1) * heights[i];
      largestArea = max(largestArea, val);
    }

    return largestArea;
  }
};