#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string infixToPostfix(string infix)
{
  infix = '(' + infix + ')';
  int n = infix.size();
  string result;
  stack<char> st;

  for (int i = 0; i < n; i++)
  {
    if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9')
    {
      result += infix[i];
    }

    else if (infix[i] == '(')
    {
      st.push('(');
    }

    else if (infix[i] == ')')
    {
      while (st.top() != '(')
      {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    else
    {
      if (infix[i] == '^')
      {
        while (!st.empty() && prec(st.top()) >= prec('^'))
        {
          result += st.top();
          st.pop();
        }
      }
      else
      {
        while (!st.empty() && prec(st.top()) > prec(infix[i]))
        {
          result += st.top();
          st.pop();
        }
      }

      st.push(infix[i]);
    }
  }

  while (!st.empty())
  {
    result += st.top();
    st.pop();
  }

  return result;
}

string infixToPrefix(string s)
{
  // Reverse the infix expression
  reverse(s.begin(), s.end());
  int n = s.size();

  // Replace '(' with ')' and vice versa
  for (int i = 0; i < n; i++)
  {
    if (s[i] = '(')
    {
      s[i] = ')';
    }
    else if (s[i] = ')')
    {
      s[i] = '(';
    }
  }

  string postfix = infixToPostfix(s);

  string prefix;
  reverse_copy(postfix.begin(), postfix.end(), prefix.begin());

  return prefix;
}