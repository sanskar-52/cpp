#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // function to find the stock spann for each day in a given vector. we are not implementing next(int val) here.
  vector<int> stockSpan(vector<int> arr)
  {

    int n = arr.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
      int currentSpan = 0;
      for (int j = i; j >= 0; j--)
      {
        if (arr[j] <= arr[i])
        {
          currentSpan++;
        }
        else
          break;
      }
      ans[i] = currentSpan;
    }

    return ans;
  }
};

// now solving it using PGE, we can calculate the span of current element.

class stockSpanner
{
  int index = 0;
  stack<pair<int, int>> st;

  stockSpanner()
  {
  }

  int next(int price)
  {
    int currentSpan = 0;
    while (!this->st.empty() && this->st.top().first <= price)
    {
      st.pop();
    }

    if (st.empty())
    {
      currentSpan = index + 1;
    }
    else
    {
      currentSpan = index - this->st.top().second;
    }
    st.push({price, index});
    index++;

    return currentSpan;
  }
};