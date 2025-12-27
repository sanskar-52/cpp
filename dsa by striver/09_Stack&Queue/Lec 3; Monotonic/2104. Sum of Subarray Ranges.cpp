// You are given an integer array nums.The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

#include <bits/stdc++.h>
using namespace std;

// first using bruteforce, i will generate each and every sub array and keep track of the smallest as well as the largest element.
// after that i will cal range of each subarray and sum it to the total.
class Solution
{
public:
  long long subArrayRanges(vector<int> &nums)
  {
    int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      int smallest = nums[i];
      int largest = nums[i];
      for (int j = i; j < n; j++)
      {
        smallest = nums[j] < smallest ? nums[j] : smallest;
        largest = nums[j] > largest ? nums[j] : largest;
        sum += largest - smallest;
      }
    }

    return sum;
  }
};

// sum of subarray ranges = max of subarray - min of subarray for each subarray; we already know how to find the sum of subarray minimums
// and sum of subarray maximums,

class Solution
{
private:
  vector<int> findNSE(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
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

  vector<int> findPSEE(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] > arr[i])
      {
        st.pop();
      }

      ans[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    return ans;
  }
  long long sumSubarrayMins(vector<int> &arr)
  {
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);
    int n = arr.size();

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
      int left = i - psee[i];
      int right = nse[i] - i;

      long long freq = left * right * 1LL;

      long long contri = freq * arr[i] * 1LL;

      sum += contri;
    }

    return sum;
  }

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

  long long sumSubarrayMaxs(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
      int left = i - pgee[i];
      int right = nge[i] - i;

      long long freq = left * right * 1LL;

      long long contribution = freq * arr[i] * 1LL;

      sum += contribution;
    }

    return sum;
  }

public:
  long long subArrayRanges(vector<int> &nums)
  {
    return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
  }
};