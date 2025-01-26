#include <iostream>
using namespace std;

int main() {

    int _array[4] = {1, 2, 3 ,4};
    //0 , 1 , 2, 3
    //intialising array as well as assign values in it.
    cout << _array[0] << endl;
    cout << _array << endl;
    // prints address from where array started to allocate the memory
    
    int another_array[4];
    another_array[0]=9;
    
    printf("another_array[3] is %d\n",another_array[3]); 
    //it will contain whatever value happened to be at that memory location
    //unpredictable and could differ each time
    cout << another_array[0] << "  and  " << another_array[2] << endl;
    
    
    return 0;
}