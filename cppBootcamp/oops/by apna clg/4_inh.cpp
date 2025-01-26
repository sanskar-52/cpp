//multi level inheritence

#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;
};

class Student : public Person{
public:
    int rollno;
};

class GradStudent : public Student{
public:
    string researchArea;

};


int main()
{
    GradStudent g1;
    g1.name = "sanskar";
    g1.age = 20;
    g1.rollno = 45;
    g1.researchArea = "advanced quantum mechanincs";

    return 0;
}