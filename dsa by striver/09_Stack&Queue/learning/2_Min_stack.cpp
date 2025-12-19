// previously we got SC -> O(2N) now we are optimizing it to O(1);
#include <bits/stdc++.h>
using namespace std;
class MinStack
{
private:
  stack<int> st;
  int mini;

public:
  MinStack() {}
  void push(int val)
  {
    if (st.empty())
    {
      st.push(val);
      mini = val;
    }

    // if val is greater than mini.
    if (val > mini)
    {
      st.push(val);
    }
    else
    {
      st.push(2 * val - mini);
      mini = val;
    }
  }

  void pop()
  {
    if (st.top() > mini)
    {
      st.pop();
    }
    else
    {
      int x = st.top();
      st.pop();
      mini = 2 * mini - x;
    }
  }

  int top()
  {

    if (st.empty())
      return;

    if (st.top() > mini)
      return st.top();

    else
      return mini;
  }

  int getMin()
  {
    return mini;
  }
};

int main()
{
  MinStack s;
  s.push(10);

  return 0;
}