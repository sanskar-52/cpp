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

// returns the day back if it is a valid smallest_daywer
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
    if (no_of_bouquets >= m)
      return day;
  }
  no_of_bouquets += (counter / k);

  if (no_of_bouquets >= m)
    return day;
  else {
    return -1;
  }
}

int minDays(vector<int> &bloomday, int m, int k) {
  int size = bloomday.size();
  long long int mk = 1LL * m * k;
  if (mk > size)
    return -1;
  int low = *min_element(bloomday.begin(), bloomday.end());
  int high = *max_element(bloomday.begin(), bloomday.end());
  int smallest_day = INT_MAX;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int day = ValidDay(bloomday, m, k, mid);
    if (day != -1) {
      smallest_day = min(smallest_day, day);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return smallest_day;
}