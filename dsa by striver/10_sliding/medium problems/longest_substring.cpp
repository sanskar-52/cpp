// longest substring without repeating characters
// Given a string s, find the length of the longest substring without duplicate
// characters.

#include <bits/stdc++.h>
using namespace std;

// brute force

int lengthOfLongestSubstring(string s) {
  int maxlen = 0;
  for (int i = 0; i < s.size(); i++) {
    int hash[256] = {0};
    for (int j = i; j < s.size(); j++) {
      if (hash[s[j]] == 1)
        break;
      hash[s[j]] = 1;
      int len = j - i + 1;
      maxlen = max(len, maxlen);
    }
  }
  return maxlen;
}
// TC -> N^2

// two pointer and sliding window

int lengthOfLongestSubstring(string s) {
  int hash[256] = {0};
  int l = 0;
  int r = 0;
  int maxlen = 0;
  int len = 0;

  while (r < s.size()) {
    if (hash[s[r]] == 0) {
      hash[s[r]] = 1;
      len = r - l + 1;
      maxlen = max(maxlen, len);
    } else {
      while (hash[s[r]] == 1) {
        hash[s[l]] = 0;
        l = l + 1;
      }
    }

    r = r + 1;
  }

  return maxlen;
}

// we can still improve the algo

int lengthOfLongestSubstring(string s) {
  int l = 0;
  int r = 0;
  int maxlen = 0;
  int len = 0;
  int hash[256];
  fill(hash, hash + 256, -1);

  while (r < s.size()) {
    if (hash[s[r]] == -1) {
      hash[s[r]] = r;
      len = r - l + 1;
      maxlen = max(maxlen, len);
    } else if (hash[s[r]] != -1 && hash[s[r]] >= l) {
      l = hash[s[r]] + 1;
    }
    hash[s[r]] = r;
    maxlen = max(maxlen, r - l + 1);
    r = r + 1;
  }

  return maxlen;
}
