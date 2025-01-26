//function overriding
//same function in both parent and derived class but the fucntion is called accordingly to class through which object is declared.
#include <iostream>
#include <string>
using namespace std;

class Parent{
public:
    void get_info(){
        cout << "parent class \n";
    }
};

class Child : public Parent{
public:
    void get_info(){
        cout << "child class" << endl;
    }
};

int main()
{
    Child c1;
    c1.get_info();

    Parent p1;
    p1.get_info();

    return 0;
}