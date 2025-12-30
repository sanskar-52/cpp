#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string postfix)
{
  stack<string> st;
  string infix;
  int n = postfix.size();

  for (int i = 0; i < n; i++)
  {
    char c = postfix[i];
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
    {
      // have to push a string instead of a character
      st.push(string(1, c));
    }
    else
    {
      string op2 = st.top();
      st.pop();
      string op1 = st.top();
      st.pop();

      string temp = "(" + op1 + string(1, c) + op2 + ")";
      st.push(temp);
    }
  }

  return st.top();
}