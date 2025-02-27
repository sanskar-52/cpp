#include <iostream>
#include <vector>  // Required for vector and iterator

using namespace std;

int main() {
    // Create a vector of integers
    vector<int> v = {10, 20, 30, 40};

    // Declare an iterator for the vector
    vector<int>::iterator it = v.begin();

    // Use the iterator to access and print the elements of the vector
    cout << "The first element is: " << *it << endl;  // Dereferencing the iterator

    cout << "third element is: " << *(it+2) << endl;

    return 0;
}
