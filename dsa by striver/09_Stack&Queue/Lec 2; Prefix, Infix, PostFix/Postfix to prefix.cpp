#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string postfixToPrefix(string postfix)
  {
    int n = postfix.size();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
      char ch = postfix[i];
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
      {
        st.push(string(1, ch));
      }

      else
      {
        string t2 = st.top();
        st.pop();
        string t1 = st.top();
        st.pop();

        st.push(ch + t1 + t2);
      }
    }

    return st.top();
  }
};