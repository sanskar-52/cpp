#include <iostream>
using namespace std;

int main() {
    
    int numbers[5] = {1, 2, 3, 4, 5};
    cout << numbers << "prints the address from which array starts to allocate numbers into memory" <<endl;
    cout << "prints the address of numbers[0]";
    
    *numbers = 121;
    cout << numbers[0];
    
    //int *ptr = &numbers;//ths is wrong bcz it is address of whole array
    int *ptr = numbers; //this is correct bcz numbers is address of numbers[0]
    
    
    
    return 0;
}