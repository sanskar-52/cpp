// Problem Statement: Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents
// the number of pages in the ‘i-th’ book. There are ‘m’ number of students,
// and the task is to allocate all the books to the students.
// Allocate books in such a way that:
// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the books to ‘m’ students such that
// the maximum number of pages assigned to a student is minimum.
// If the allocation of books is not possible, return -1.

#include<bits/stdc++.h>
using namespace std;


// BS approach

bool valid_page(vector<int>& books, int m, int pages) {
  int n = books.size();
  int student_count = 1;
  int load = 0;

  for(int i = 0; i < n; i++) {
    if(books[i] > pages) return false; // single book exceeds pages
    if(load + books[i] <= pages) {
      load += books[i];
    }
    else {
      student_count++;
      load = books[i];
      if(student_count > m) return false;
    }
  }

  return true;
}

int min_max_pages(vector<int>& books, int m) {
  int n = books.size();
  if (m > n) return -1;
  int low = *max_element(books.begin(), books.end());
  int high = accumulate(books.begin(), books.end(), 0);

  while(low <= high) {
    int mid = (low + high)/2;
    if(valid_page(books, m, mid) ) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return low;

}
