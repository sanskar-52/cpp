// Longest Repeating Character Replacement
/*
  Problem: Longest Repeating Character Replacement (Sliding Window)

  Description:
  Given a string consisting of uppercase English letters and an integer k, 
  the task is to find the length of the longest substring that can be obtained 
  by replacing at most k characters in the string so that all the characters 
  in the substring are the same.

  Approach:
  This problem is typically solved using the sliding window technique. 
  The window is expanded to include new characters, and if the number of 
  replacements needed exceeds k, the window is shrunk from the left. 
  The goal is to maintain the maximum window size where at most k replacements 
  are required to make all characters in the window identical.

  Example:
  Input: s = "AABABBA", k = 1
  Output: 4
  Explanation: Replace one 'A' with 'B' to obtain "AABBBBA", 
  where the longest substring with repeating characters is "BBBB".
*/

#include<bits/stdc++.h>
using namespace std;

// TC -> O(N^2)  and SC -> O(26)
/**
 * Finds the length of the longest substring in the given string `str` where you can replace at most `k` characters
 * to make all characters in the substring the same.
 *
 * The function uses a brute-force approach by checking all possible substrings starting at each index,
 * counting the frequency of each character, and determining the minimum number of replacements needed.
 *
 * @param str The input string consisting of uppercase English letters ('A'-'Z').
 * @param k The maximum number of character replacements allowed.
 * @return The length of the longest valid substring after at most `k` replacements.
 */
int longest(const string &str, int k) {
  int n = (int)str.size();
  int maxlen = 0;

  for(int i = 0; i < n; i++) {
    
    int maxfreq = 0; 
    int hash[26] = {0};

    for(int j = i; j < n; j++) {
      hash[str[j] - 'A']++;
      maxfreq = max(maxfreq, hash[str[j] - 'A']);

      int changes = (j - i + 1) - maxfreq;
      if(changes <= k) {
        maxlen = max(maxlen, j - i + 1);
      }
      else { break; };
    }

  }

  return maxlen;

}


// Now we will optimize it using two pointer and sliding window.  
// using hash. first expanding the window till it is a valid window and updating the maxlen
// and when it's not a valid window we slide it until its a valid window. if it becomes a valid window
// then we update the maxlen otherwise the function ends and returns maxlen.


int maxf(int hash[]) {
  int maxfreq = 0;
  for(int i =0; i < 26; i++) {
    maxfreq = max(maxfreq, hash[i]);
  }
  return maxfreq;
}

int characterReplacement(string str, int k) {
  int l = 0;
  int r = 0;
  int maxlen = 0;
  int hash[26] = {0};
  int maxfreq = 0;

  while(r < str.size()) {
    hash[str[r] - 'A']++;
    
    maxfreq = maxf(hash);
    int changes = (r - l + 1) - maxfreq;

    if(changes <= k) {
      maxlen = max(maxlen, r - l + 1);
    }
    if(changes > k) {
      hash[str[l] - 'A']--;
      l++;
    }

    r++;
  }

  return maxlen;

}