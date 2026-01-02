// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int largestRectangleArea(vector<int> heights)
  {
    stack<int> st;
    int n = heights.size();
    vector<int> pse(n);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && heights[st.top()] >= heights[i])
      {
        maxArea = max(maxArea, (i - pse[st.top()] - 1) * heights[st.top()]);
        st.pop();
      }

      pse[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    while (!st.empty())
    {
      maxArea = max(maxArea, (n - pse[st.top()] - 1) * heights[st.top()]);
      st.pop();
    }

    return maxArea;
  }

public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    int row = matrix.size();
    int column = matrix[0].size();
    vector<int> heights(column, 0);
    int maxRectArea = 0;

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
      }
      maxRectArea = max(maxRectArea, largestRectangleArea(heights));
    }
    return maxRectArea;
  }
};