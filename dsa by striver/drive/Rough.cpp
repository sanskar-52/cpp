#include <iostream>
using namespace std;

int main()
{
  int *arr = new int[2]{5, 5};
  // arr[0] = 1;
  // arr[1] = 2;

  cout << *(arr + 1);
  return 0;
}