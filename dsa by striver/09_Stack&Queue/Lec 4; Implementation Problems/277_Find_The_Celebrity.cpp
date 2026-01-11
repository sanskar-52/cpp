// Problem Statement : A celebrity is a person who is known by everyone else at the party but does not know anyone in return.Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party.
// Return the index of the celebrity or -1 if no such person exists.

// Note that M[i][i] is always 0.

#include <bits/stdc++.h>
using namespace std;

// first we will solve this question by brute-force
// in this method we will use two vectors of size n i.e knowMe and Iknow
// let arr[i][j] == 1 then, knowMe[j]++ and iKnow[i]++;
// after building knowMe and iKnow vector we will iterate over it and find the element
// which knowMe[i] == n -1 and iKnow[i] == 0 and return the i.

class Solution
{
public:
  int findTheCeleb(vector<vector<int>> &arr)
  {
    int n = arr.size();
    vector<int> knowMe(n);
    vector<int> iKnow(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[i][j] == 1)
        {
          knowMe[j]++;
          iKnow[i]++;
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (iKnow[i] == 0 && knowMe[i] == n - 1)
      {
        return i;
      }
    }
    return -1;
  }
};

// Time Complexity : O(N²) + O(N), since we are using two nested loops to traverse the square matrix to populate the lists and then another loop to find the celeb at last.
// Space Complexity : O(2N), since we are using two lists of size N to store the count of how many people each person knows and how many people know each person.

// Two-Pointer Elimination Technique
// This method eliminates non-celebrities in linear time and constant space.
class Solution
{
public:
  int celebrity(vector<vector<int>> &arr)
  {
    int n = arr.size();

    int top = 0, down = n - 1;
    while (top < down)
    {
      if (arr[top][down] == 1)
      {
        top = top + 1;
      }
      else if (arr[down][top] == 1)
      {
        down = down - 1;
      }
      else
      {
        top++;
        down--;
      }
    }

    if (top > down)
      return -1;

    for (int i = 0; i < n; i++)
    {
      if (top == i)
        continue;
      else if (arr[top][i] == 1 || arr[i][top] == 0)
      {
        return -1;
      }
    }

    return top;
  }
};
// time complexity:- candidate elimination O(n) + candidate verification O(n) = O(n)

// now solving it using stack.
int getCelebrity(vector<vector<int>> &arr)
{
  stack<int> st;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    st.push(i);
  }

  while (st.size() > 1)
  {
    int i = st.top();
    st.pop();
    int j = st.top();
    st.pop();

    if (arr[i][j] == 0)
    {
      st.push(i);
    }
    else
    {
      st.push(j);
    }
  }

  int celeb = st.top();

  for (int i = 0; i < n; i++)
  {
    if (i == celeb)
      continue;
    if (arr[celeb][i] == 1 || arr[i][celeb] == 0)
    {
      return -1;
    }
  }

  return celeb;
}