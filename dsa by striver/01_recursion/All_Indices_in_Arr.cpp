/// Finds all indices of a target value in an array using recursion.

/// An array containing all indices where the target value appears in the original array.
/// Returns an empty array if the target value is not found.

/// This recursive function traverses the array from left to right, collecting the indices
/// of all occurrences of the target value. The recursion stops when the current index
/// reaches the end of the array. Each recursive call checks one element and builds up
/// the result array by adding indices where matches are found.

/// If arr = [1, 2, 3, 2, 4, 2] and target = 2, returns [1, 3, 5]

#include <bits/stdc++.h>
using namespace std;

vector<int> allIndices(vector<int> &arr, int val, int idx, int fsf)
{
  if (idx == arr.size())
  {
    return vector<int>(fsf);
  }

  if (arr[idx] == val)
  {
    vector<int> iarr = allIndices(arr, val, idx + 1, fsf + 1);
    iarr[fsf] = idx;
    return iarr;
  }
  else
  {
    vector<int> iarr = allIndices(arr, val, idx + 1, fsf);
    return iarr;
  }
}

int main()
{
  return 0;
}