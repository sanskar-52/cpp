// Problem Statement : Design a stack that supports the following operations in constant time : push, pop, top, and retrieving the minimum element.
// Implement the MinStack class :

// MinStack() : Initializes the stack object.
// void push(int val) : Pushes the element val onto the stack.
// void pop() : removes the element on the top of the stack.
// int top() : gets the top element of the stack.
// int getMin(): retrieves the minimum element in the stack.

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
  // we will be storing val as well as the smallest val seen till now in the stack.
  stack<pair<int, int>> st;

public:
  void push(int val)
  {
    if (st.empty())
    {
      st.push({val, val});
    }
    else
    {
      st.push({val, min(val, st.top().second)});
    }
  }

  int top()
  {
    return st.top().first;
  }

  int getMin()
  {
    return st.top().second;
  }

  void pop()
  {
    st.pop();
  }
};

int main()
{
  Stack s;

  s.push(5);
  s.push(3);
  s.push(1);

  cout << "top: " << s.top() << endl;
  cout << "min: " << s.getMin() << endl;

  s.pop();

  cout << "top: " << s.top() << endl;
  cout << "min: " << s.getMin() << endl;
}

// time complexity -> O(1)
// but the space complexity will be O(2N) bcz we are storing a pair