#include <iostream>
#include <string>
using namespace std;

class Teacher{
private:
        double salary;
public:
    //properties
    string name;
    string dept;
    string subject;


    //non-parameterized constructor
    Teacher(){
        cout << "hi i am a constructor and is called when declaring an object" << endl;
        dept = "Computer Science";
    }

    //parameterized constructor
    Teacher(string name,string dept,string subject,double salary){
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    //custom cpoy-constructor
    Teacher(Teacher &obj){
        cout << "this is a custom copy constructor" << endl;
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }

    //methods
    void changeDept(string newDept){
        dept = newDept;
    }
    //salary main function se access nahi kar sakte kyunki it is in private and private ko class se hi access kar sakte hai
    //to class -> public me function banate hai jo ki access ho sakta hai in main function.
    //setter
    void set_Salary(double new_salary){
        salary = new_salary;
    }
    //getter
    void print_salary(){
        cout << "salary is " << salary << endl;
    }

private:
    string khazana = "gf ka number";

};

int main(){
    Teacher t1; //constructor call
    t1.name = "paeae tripathi";
    cout << t1.name << endl;
    cout << t1.dept << endl;

    //t1.khazana = "9383635127";
    t1.set_Salary(12323);
    //salary to set kardi hamne magar ab print kaise karenge?
    t1.print_salary();


    //parameterized constructor
    Teacher t2("avay","maths","mething",50000);
    t2.print_salary();
    cout << t2.name << endl;


    Teacher t3(t2); //custom copy constructor
    cout << "old name of t3" <<t3.name << endl;
    t3.name = "sudhesh";
    cout << "new name of t3 is " << t3.name << endl;
    cout << "name of t2 " << t2.name << endl;
    return 0;
}