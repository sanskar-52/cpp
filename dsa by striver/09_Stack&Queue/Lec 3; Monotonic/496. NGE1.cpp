// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
//  If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Input : nums1 = [ 4, 1, 2 ], nums2 = [ 1, 3, 4, 2 ] Output : [ -1, 3, -1 ]

#include <bits/stdc++.h>
using namespace std;

// this solution's Time complexity is O(Nums1.Length ∗ Nums2.Length)

class Solution
{
public:
  int nge(vector<int> nums, int j)
  {
    int ans;
    for (int k = j + 1; k < nums.size(); k++)
    {
      if (nums[k] > nums[j])
      {
        ans = nums[k];
        return ans;
      }
    }
    return -1;
  }
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
      for (int j = 0; j < nums2.size(); j++)
      {
        if (nums1[i] == nums2[j])
        {
          ans.push_back(nge(nums2, j));
          break;
        }
      }
    }

    return ans;
  }
};

// below soltion are for finding nge for whole array, instead of a subset of the array
class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> nums)
  {
    vector<int> ans;
    stack<int> st;
    int size = nums.size();

    for (int i = size - 1; i >= 0; i--)
    {
      if (st.size() == 0)
      {
        ans.push_back(-1);
        st.push(nums[i]);
        continue;
      }
      if (st.top() > nums[i])
      {
        ans.push_back(st.top());
        st.push(nums[i]);
      }
      else if (nums[i] >= st.top())
      {
        while (!st.empty() && (nums[i] >= st.top()))
        {
          st.pop();
        }
        if (st.empty())
        {
          ans.push_back(-1);
          st.push(nums[i]);
          continue;
        }
        else if (!st.empty())
        {
          ans.push_back(st.top());
          st.push(nums[i]);
          continue;
        }
      }
    }
    vector<int> real_ans;
    int ans_size = ans.size();
    for (int i = ans_size - 1; i >= 0; i--)
    {
      real_ans.push_back(ans[i]);
    }

    return real_ans;
  }
};

// solution from  striver
class Solution
{
public:
  vector<int> nextGreater(vector<int> nums)
  {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && nums[i] >= st.top())
      {
        st.pop();
      }
      if (st.empty())
      {
        ans[i] = -1;
      }
      else
      {
        ans[i] = st.top();
      }
      st.push(nums[i]);
    }

    return ans;
  }
};