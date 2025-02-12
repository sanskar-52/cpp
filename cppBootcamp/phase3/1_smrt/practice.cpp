#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    int *ptr1 = new int();
    cout <<*ptr1 << endl; //print out garbage value
    *ptr1 = 12;
    cout << "value of *ptr1 after storing the value " << *ptr1 <<endl;
    delete ptr1;

    //what if we access the pointer after deleting it?
    cout << "value of *ptr1 after deleting the ptr1 " << *ptr1 <<endl;

    ptr1 = nullptr; //prevents dangling pointer.
    cout << "declaring ptr1 as null pointer " <<*ptr1 <<endl;

    return 0;
}