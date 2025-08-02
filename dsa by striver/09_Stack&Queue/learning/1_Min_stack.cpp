#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
  stack<pair<int, int>> st; 

public:
  void push(int val) {
    if(st.empty()){
      st.push({val, val});
    }
    else {
      st.push({val, min(val,st.top().second)});
    }
  }

  int top(){
    return st.top().first;
  }

  int getMin(){
    return st.top().second;
  }

  void pop(){
    st.pop();
  }
};

int main(){
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