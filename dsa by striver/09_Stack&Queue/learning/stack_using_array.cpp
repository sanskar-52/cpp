#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
  int size;
  int* st;
  int top;
public:
  Stack(int data){
    top = -1;
    this->size = data;
    st = new int[this->size];
  }

  void push(int x){
    if(top == size-1) {
      cout << "stack Overflow\n";
      return;
    }
    top++;
    st[top] = x;
  }

  int pop(){
    if(top == -1){
      cout << "stack underflow\n";
      return -1;
    }
    int x = st[top];
    top--;
    return x;
  }

  int Top(){
    if(top == -1){
      cout << "stack is empty";
      return -1;
    }

    return st[top];
  }

  int getSize(){
    return top+1;
  }

  ~Stack() {
    delete[] st;
  }
};


int main(){
  Stack s(10);
  s.push(1);
  s.push(2);
  s.push(3);

  cout << s.getSize() <<endl;

}
