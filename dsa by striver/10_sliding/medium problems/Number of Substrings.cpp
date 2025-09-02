/*
 * Problem: Number of Substrings Containing All Three Characters
 * 
 * Description:
 * Given a string consisting only of the characters 'a', 'b', and 'c', 
 * the task is to count the number of substrings that contain at least one occurrence 
 * of each of the three characters ('a', 'b', and 'c').
 * 
 * Approach:
 * This problem can be efficiently solved using the two pointers technique 
 * (also known as the sliding window approach). The idea is to maintain a window 
 * that contains at least one of each character, and for each valid window, 
 * count the number of substrings ending at the right pointer that satisfy the condition.
 * 
 * Reference:
 * Striver DSA Series - Sliding Window Medium Problems
 */
// L7. Number of Substrings Containing All Three Characters | 2 Pointers and Sliding Window

#include<bits/stdc++.h>
using namespace std;

// N^2 approach , checking all the substring and then increasing the cnt if the substring is valid.

int number_of_substring1(const string &str) {

  int n = (int)str.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    int hash[3] = {0};
    for(int j = i; j < n; j++) {
      hash[str[j] - 'a'] = 1; 
      if(hash[0] + hash[1] + hash[1] == 3) {
        cnt = cnt + 1;
      }
    }
  }

  return cnt;
}

// N^2 apporach, as soon as any substring of i'th iteration is valid then all bigger substring of
// that i'th iteration is also valid so as soon as we find a valid substring we increase the cnt
// by n - j. where n is the size of the string.

int number_of_substring1(const string &str) {

  int n = (int)str.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    int hash[3] = {0};
    for(int j = i; j < n; j++) {
      hash[str[j] - 'a'] = 1; 
      if(hash[0] + hash[1] + hash[1] == 3) {
        cnt = cnt + n - j;
        break;
      }
    }
  }

  return cnt;
}