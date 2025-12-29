#include <bits/stdc++.h>
using namespace std;

// function to return the priority of the operators

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

string infixToPost(string s)
{
  stack<char> st; // Stack to hold operators and parentheses
  string result;  // String to hold the resulting postfix expression

  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    char c = s[i];

    // If the scanned character is an operand, add it to the result string
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
    {
      result += c;
    }

    // If the scanned character is an ‘(‘, push it to the stack
    else if (c == '(')
    {
      st.push(c);
    }

    // If the scanned character is a ‘)’, pop from stack until an ‘(‘ is encountered
    else if (c == ')')
    {
      while (st.top() != '(')
      {
        result += st.top();
        st.pop();
      }
      st.pop(); // pop '(' from the stack
    }

    // if the char c is an operator
    else
    {
      while (!st.empty() && prec(st.top()) >= prec(c))
      {
        result += st.top();
        st.pop();
      }

      st.push(c); // push the currenct opearator.
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty())
  {
    result += st.top();
    st.pop();
  }

  return result;
}