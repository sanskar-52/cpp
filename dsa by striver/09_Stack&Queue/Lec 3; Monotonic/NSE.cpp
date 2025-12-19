// NEAREST SMALLER ELEMENT
// have to return a vector containing nearest smaller element to the left of each element in the given vector

// Input : [4, 5, 2, 10, 8] Output: [-1, 4, -1, 2, 2]

// bruteforce:- stand at each element in the vector and traverse to the left till 0 and when you find a smaller element
// nge[i] will be assigned otherwise -1

// using monotonic stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nearestSmallerELement(vector<int> nums)
  {
    // trying to maintain a montonic stack in a decreasing order
    stack<int> st;
    int n = nums.size();
    vector<int> res(n);

    // starting loop from 0 to n - 1
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && nums[i] <= st.top())
      {
        st.pop();
      }
      res[i] = st.empty() ? -1 : st.top();
      st.push(nums[i]);
    }

    return res;
  }
};

// TC -> O(2N)
