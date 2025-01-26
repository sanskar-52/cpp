#include <iostream>
using namespace std;

int main(){

    int * myp;

    myp = new int [100];
    cout << "memory space allocated\n";

    delete [] myp;
    return 0;
}