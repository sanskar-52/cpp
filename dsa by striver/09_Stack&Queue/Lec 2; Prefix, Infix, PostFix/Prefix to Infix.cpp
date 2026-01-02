#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string prefixToInfix(string prefix)
  {
    stack<string> st;
    int n = prefix.size();

    for (int i = n - 1; i >= 0; i--)
    {
      char ch = prefix[i];
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
      {
        st.push(string(1, ch));
      }

      else
      {
        // if operator is found then,
        string t1 = st.top();
        st.pop();
        string t2 = st.top();
        st.pop();

        st.push("(" + t1 + ch + t2 + ")");
      }
    }

    return st.top();
  }
};