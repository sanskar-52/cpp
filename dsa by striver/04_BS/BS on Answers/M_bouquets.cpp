// You are given an integer array bloomDay,
// an integer m and an integer k.

// You want to make m bouquets.To make a bouquet,
// you need to use k adjacent flowers from the garden.

// The garden consists of n flowers,
// the ith flower will bloom in the bloomDay[i] and
// then can be used in exactly one bouquet

// Return the minimum number of days you need to wait to be able to make m
// bouquets from the garden.If it is impossible to make m bouquets return -1.

#include <bits/stdc++.h>

#include <iostream>

using namespace std;

// returns the day back if it is a valid answer
int ValidDay(vector<int> &bloomday, int m, int k, int day) {
  int no_of_bouquets = 0;
  int counter = 0;
  for (int flower : bloomday) {
    if (flower <= day) {
      counter++;
    } else {
      no_of_bouquets += (counter / k);
      counter = 0;
    }
  }
}

int minDays(vector<int> &bloomday, int m, int k) {
  int size = bloomday.size();

  if ((m * k) > size)
    return -1;
  int low = *min_element(bloomday.begin(), bloomday.end());
  int high = *max_element(bloomday.begin(), bloomday.end());

  while (low <= high) {
    int mid = low + (high - low) / 2;
    ValidDay(bloomday, m, k, mid);
  }
}