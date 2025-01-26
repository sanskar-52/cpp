#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string name,int age){
        cout << "parent constructor" <<endl;
        this->name = name;
        this->age = age;
    }

    // Person(){
    //     cout << "parent constructor" <<endl;
    // }

};

class Student : public Person{
public:
    int rollno;

    Student(string name, int age, int rollno) : Person(name, age){
        cout << "child constructor" << endl;
        this->rollno = rollno;
    }

    void get_info(){
        cout << "name " << name << endl;
        cout << "age " << age << endl;
        cout << "rollno " << rollno << endl;
    }

};

int main(){

    Student s1("shruti kumari",19,34);
    s1.get_info();


    return 0;
}