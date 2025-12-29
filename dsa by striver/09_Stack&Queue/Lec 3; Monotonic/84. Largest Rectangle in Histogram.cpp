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

// now we will try to find pse as well as nse as we traverse the heights and as soon as we get nse we will calculate it's area
// and max it

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    stack<int> st;
    // vector<int> nse(n);
    vector<int> pse(n);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && heights[st.top()] >= heights[i])
      {
        // nse[st.top()] = i;
        maxArea = max((i - pse[st.top()] - 1) * heights[st.top()], maxArea);
        st.pop();
      }

      pse[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    while (!st.empty())
    {
      // nse[st.top()] = n;
      maxArea = max((n - pse[st.top()] - 1) * heights[st.top()], maxArea);
      st.pop();
    }

    return maxArea;
  }
};