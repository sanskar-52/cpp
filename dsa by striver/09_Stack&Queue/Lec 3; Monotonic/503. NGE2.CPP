// Given a circular integer array nums (i.e., the element after nums[nums.length - 1] is nums[0]),
// return the next greater element for each element in nums.

// The next greater element of a number x is the first greater number that appears
// after it when traversing the array. Since the array is circular, you may continue
// searching from the beginning of the array.

// If no greater element exists for a given number, return -1 for that number.

// Input : nums = [ 1, 2, 3, 4, 3 ] Output : [ 2, 3, 4, -1, 4 ]

#include <bits/stdc++.h>
using namespace std;

// the first solution came in my mind is to for each nums[i] in nums we will traverse from
// i + 1 to  n - 1    then from    0 to i - 1
// in this way we are traversing the array circularly. TC -> O(n^2)

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j <= i + n; j++)
      {
        int index = j % n;
        if (j == i + n)
        {
          res[i] = -1;
        }
        else if (nums[index] > nums[i])
        {
          res[i] = nums[index];
          break;
        }
      }
    }

    return res;
  }
};

// using monotonic stack
// we will be assuming twice the size of the array, to make it circual,
// we are making monotonic stack for the 2nd half so the elements of the 2nd half of array
// are arranged in descending order and we will start saving nge of elements from nth index to 0th index.
// the loop will run from 2n - 1th index to 0.

// TC ->O(N)
class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    stack<int> st;
    int n = nums.size();
    vector<int> res(n);

    for (int i = 2 * n - 1; i >= 0; i--)
    {
      while (!st.empty() && nums[i % n] >= st.top())
      {
        st.pop();
      }
      if (i < n)
      {
        res[i] = st.empty() ? -1 : st.top();
      }
      st.push(nums[i % n]);
    }

    return res;
  }
};