#include<bits/stdc++.h>
using namespace std;

int main() {
  set<int> st;
  st.insert(2);
  st.insert(45);
  st.erase(2);
  if(st.size() == 1) {
    cout << "set contains only one element that is 45" << endl;
    cout << *st.begin() << endl;
  }
  st.erase(2);


  unordered_map<int,int> mpp;
  mpp[2] = 2;
  mpp[2]++;
  int three = mpp[2];
  cout << three << endl;

}