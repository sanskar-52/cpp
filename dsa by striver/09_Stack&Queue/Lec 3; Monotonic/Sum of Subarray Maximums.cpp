// You are given an integer array arr of length n.

//     A subarray is a contiguous non -
//     empty part of the array.For each subarray,
//     determine its maximum element.

//     Your task is to compute the sum of the maximum elements of all possible subarrays of the given array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<int> findNGE(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] <= arr[i])
      {
        st.pop();
      }

      ans[i] = st.empty() ? n : st.top();

      st.push(i);
    }
    return ans;
  }

  vector<int> findPGEE(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] < arr[i])
      {
        st.pop();
      }

      ans[i] = st.empty() ? -1 : st.top();

      st.push(i);
    }
    return ans;
  }

public:
  long long sumSubarrayMax(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
      long long left = i - pgee[i];
      long long right = nge[i] - i;

      sum += left * right * arr[i];
    }
    return sum;
  }
};