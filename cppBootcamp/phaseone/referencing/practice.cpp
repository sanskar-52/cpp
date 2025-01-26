#include <iostream>
using namespace std;

int main(){
    
    int *pointeer;
    int x = 32;
    pointeer = &x;
    cout << pointeer << endl;

    int arrr[] = {21,32,43,76,21};
    int *pointer_of_arrr = arrr; // *pointer_of_arrr = &arrr[0];
    // int *pointer_of_arrr = &arrr; // &arrr is the address of entire array;
    cout << pointer_of_arrr << endl;
    
    int *myp;
    try{
        myp = new int [800];
        cout << "memory is allocated";
    } catch (...) {
        cout << "failed to allocate memory";
    }
    //memory is allocated but sometime it fails so allocate in try catch block
    delete [] myp;
    return 0;
}