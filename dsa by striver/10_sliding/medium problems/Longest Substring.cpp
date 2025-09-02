// Longest Substring with At Most K Distinct Characters
// this problem is very similar to the fruit in basket problem, but here there are K basket instead of 2


#include<bits/stdc++.h>
using namespace std;

// N^2 approach by checking every substring
// using set
int longest_substring1(string &str, int k) {
  int maxlen = 0;
  for(int i = 0; i < str.size(); i++) {
    set<char> st;
    for(int j = i; j < str.size(); j++) {
      st.insert(str[j]);

      if(st.size() <= k) {
        maxlen = max(maxlen, j - i + 1);
      }
      else { break; }
    }
  }
  return maxlen;
}

//using map
int lonegest_substring2(const string &str, int k) {
  int maxlen = 0;
  unordered_map<char,int> um;
  int n = (int)str.size();
  for(int i = 0; i < n; i++) {
    um.clear();
    for(int j = i; i < n; j++) {
      um[str[j]]++;

      if(um.size() <= k) {
        maxlen = max(maxlen,j - i + 1);
      }
      else { break; };
    }
  }
}

// Now O(N) approach , sliding window approach

int longest_substring3(const string &str, int k) {
  int left = 0, right = 0, maxlen = 0;
  unordered_map<char,int> um;

  int n = (int)str.size();
  while(right < n) {

    um[str[right]]++;

    if(um.size() > k) {
      um[str[left]]--;
      if(um[str[left]] == 0) um.erase(str[left]);
      left++;
    }

    if(um.size() <= k) {
      maxlen = max(maxlen, right - left + 1);
    }
    
    right++;
  }

  return maxlen;

}