//multiple inheritance
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollno;
};

class Teacher {
public:
    string subject;
    double salary;
};

class TA : public Student , public Teacher {
    void get_info(){
        cout << name << endl;
        cout << rollno << endl;
        cout << subject << endl;
        cout << salary << endl;
    }
};

int main()
{
    TA t1;
    t1.name = "tony stark";
    t1.rollno = 35;
    t1.subject = "cs";
    t1.salary  = 28000;

    return 0;
}