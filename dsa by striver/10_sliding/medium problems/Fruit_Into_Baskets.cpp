/**
 * @brief Solves the "Fruit Into Baskets" problem using the sliding window technique.
 *
 * This problem involves finding the length of the longest contiguous subarray containing at most two distinct types of fruits.
 * Each element in the input array represents a type of fruit. You are given two baskets, and each basket can only hold one type of fruit.
 * The goal is to collect the most fruits by picking them consecutively from the array, but you can only pick fruits of at most two types.
 *
 * The sliding window approach is used to efficiently track the current window of fruits that contains at most two distinct types.
 * The window is expanded by moving the right pointer, and contracted by moving the left pointer when more than two types are present.
 * The maximum window size encountered during this process is the answer.
 *
 * Typical use case: Given an array of integers representing fruit types, return the maximum number of fruits that can be collected in two baskets.
 */

#include<bits/stdc++.h>
using namespace std;

// brute force approach :- we will check each and every subarray and find the max len of valid sub array
//using set we are checking no of unique elements in corresponding sub array


int fruit_in_basket(vector<int> &arr) {
  int maxlen = 0;

  for(int i = 0; i < arr.size(); i++) {
    set<int> st;
    for(int j = i; j < arr.size(); j++){
      st.insert(arr[j]);
      if(st.size() <= 2) {
        maxlen = max(maxlen,j - i + 1);
      }
      else {
        break;
      }
    }
  }

  return maxlen;
}

// now using two pointer approach

// @warning this code is wrong
// int fruit_in_basket2(vector<int> arr) {
//   int left = 0;
//   int right = 0;
//   set<int> st;
//   int maxlen = 0;

//   while(left <= right && right < arr.size()) {
//     if(st.size() <= 2) {
//       maxlen = max(maxlen, right - left + 1);
//       st.insert(arr[right]);
//       right++;
//     }
//     else if(st.size() > 2) {
//       st.erase(arr[left]);
//       left++;
//       st.insert(arr[left]);
//     }
//   }

//   return maxlen;
// }



// two pointer approach and using an unordered map
// we are decreasing the size of window when the subarray in invalid and then expanding the window.
// TC -> O(2N)
int fruit_in_basket2 (vector<int> &arr) {
  int left = 0;
  int right = 0;
  int maxlen = 0;
  unordered_map<int,int> um;

  while(right < arr.size()) {
    um[arr[right]]++;

    if(um.size() > 2) {
      while(um.size() > 2) {
        um[arr[left]]--;
        if(um[arr[left]] == 0) {
          um.erase(arr[left]);
        }
        left++;
      }
    }


    if(um.size() <= 2) {
      maxlen = max(maxlen, right - left + 1);
    }

    right++;
  }

  return maxlen;
}


// TC-> O(N)
// we are sliding the window when the subarray is invalid and expanding it when its valid.

// this is wrong? idk

// int fruit_in_basket3(vector<int> &arr) {
  // int left = 0,right = 0, maxlen = 0;
//   unordered_map<int,int> um;

//   while(right < arr.size()) {
//     um[arr[right]]++;

//     if(um.size() > 2) {

//       while(um.size() > 2 && right < arr.size()) {
//         if(right == arr.size() - 1) {
//           return maxlen;
//         }

//         um[arr[left]]--;
//         if(um[arr[left]] == 0) {
//           um.erase(arr[left]);
//         }
//         left++;
//         right++;
//         um[arr[right]]++;
//       }
//     }

//     if(um.size() <= 2) {
//       maxlen = max(maxlen, right - left + 1);
//     }


//     right++;
//   }

//   return maxlen;
// }


int fruit_in_basket3(vector<int> &arr) {
  int left = 0, right = 0, maxlen = 0;
  unordered_map<int,int> um;

  while(right < arr.size()) {
    um[arr[right]]++;

    if(um.size() > 2) {
      um[arr[left]]--;
      if(um[arr[left]] == 0) um.erase(arr[left]);
      left++;
    }

    if(um.size() <= 2) {
      maxlen = max(maxlen,right - left + 1);
    }

    right++;
  }

  return maxlen;
}


int main() {

  vector<int> arr = {0,0,0,1,1,2,3,4,0,0,0,0,1,1,1,1};
  int fib = fruit_in_basket(arr);
  cout << fib;
}