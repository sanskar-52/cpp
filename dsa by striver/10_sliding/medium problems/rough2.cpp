#include<bits/stdc++.h>
using namespace std;


int main() {
  vector<char> arr = {'a','a','b','b','b','c','b','a','a','b','b'};
  int hash[26] = {0};
  int maxfreq = 0;

  for (char each: arr) {
    hash[each - 'a']++;
    maxfreq = max(maxfreq, hash[each - 'a']);
  }


  cout << "max freq of hash is:" << maxfreq << endl;
}