//how to store entire array in a pointer
//you need pointer to an array of same size of the array

#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    //Here’s how you declare and use such a pointer:
    int (*ptr)[5] = &arr;
    
    for (int i = 0 ; i < 4 ; i++){
        cout << *ptr[i] << endl;
        printf("%p\n",&arr[i]);
    }
    
    return 0;
}